#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> getDistinct(string b)
{
    vector <char> db;
    for(int i = 0; i < b.length(); i++)
    {
        if(find(db.begin(), db.end(), b.at(i)) != db.end()) 
        {
            db.push_back(b.at(i));
        }
    }
    return db;
}

int main() {
    string a,b;
    cin >> a >> b; 
    vector <char> db;
    db = getDistinct(b);

    return 0;
}
