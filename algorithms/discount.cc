#include <vector>
#include <iostream>

using namespace std;

void discount(vector<int>& prices) {
    int total = 0;
    vector<int> indexes;

    for(int i = 0; i < prices.size(); ++i) {
        int j = i;
        int tmpTotal = 0;

        while(j < prices.size()) {
            if(prices[i] >= prices[j] && j != i) {
                total += tmpTotal - ((j - i) * prices[j]);   
                i = j - 1;
                break;
            } else {
                tmpTotal += prices[j];
            }
            ++j;
        } 
        if(j == prices.size()) {
            total += prices[i];
            indexes.push_back(i);
        }

        cout << total << endl;
        for(int d : indexes) { cout << d << "   " << endl; }
    }
}

int main() {
    vector<int> d = {5,1,3,4,6,2};
    discount(d);
}
