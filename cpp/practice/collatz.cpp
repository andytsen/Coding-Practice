#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <climits> // INT_MAX
#include <utility>

using namespace std;

pair<long,int> binary_search(vector<pair<long,int>>&, long tgt);
pair<int,int> match_bvals(long a, long b, vector<pair<long,int>>&);

void create_vector(long a, vector<pair<long, int>>& list) {
    list.push_back(pair<long,int>(a,0));
    int cycle = 1;
    while(a > 1) {
        if((a & 1) == 0) {
            a = a >> 1;
            list.push_back(pair<long,int>(a,cycle));
            cycle++;
        }
        else {
            a = (a << 1) + a + 1;
            list.push_back(pair<long,int>(a,cycle));
            cycle++;
            a = a >> 1;
            list.push_back(pair<long,int>(a,cycle));
            cycle++;
        }
    }
}

int main() {
    long a,b;
    while(cin >> a >> b) {
        if(a == 0 && b == 0)
            break;
        vector<pair<long,int>> list;
        create_vector(a,list);
        vector<pair<long,int>> copyList = list;
        sort(list.begin(), list.end());
        pair<int,int> res = match_bvals(a, b, list);

        cout << "they meet at " << copyList[res.first].first << endl;
    }
    return 0;
}

pair<long,int> binary_search(vector<pair<long,int>>& list, long tgt) {
    int low = 0;
    int high = list.size() - 1;
    int mid = (high >> 1) + low;
    while(low <= high && list[mid].first != tgt) {
        if(list[mid].first < tgt) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (high+low)/2;
    }
    if(low > high) {
       return pair<long,int>(-1,0);
    }
    return list[mid];
}

pair<int,int> match_bvals(long a, long b, vector<pair<long,int> >& list) {
    int cycle = 0;
    int sA = INT_MAX;
    int sB = INT_MAX;
    bool found = false;
    int old_b = b;

    pair<long,int> res = binary_search(list, b);
    if(res.first > 0) {
        if(res.second == 0 || cycle == 0) {
            sA = res.second;
            sB = cycle;
            found = true;
        }
        if(res.second < sA || cycle < sB) {
            sA = res.second;
            sB = cycle;
        }
    }
    if(found) {
        cout << a << " needs " << sA << " steps, ";
        cout << old_b << " needs " << sB << " steps, ";
        return pair<int,int>(sA,sB);
    }
    while(b > 1) {
        if((b & 1) == 0) {
            b = b >> 1;
            cycle++;
        } else {
            b = (b << 1) + b + 1;
            cycle++;
        }
        res = binary_search(list, b);
        if(res.first > 0) {
            if(res.second == 0 || cycle == 0) {
                sA = res.second;
                sB = cycle;
                found = true;
            }
            if(res.second < sA || cycle < sB) {
                sA = res.second;
                sB = cycle;
            }
        }
        if(found)
            break;
    }
    cout << a << " needs " << sA << " steps, ";
    cout << old_b << " needs " << sB << " steps, ";
    return pair<int,int>(sA,sB);
}
