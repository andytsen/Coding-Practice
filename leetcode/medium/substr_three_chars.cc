// Leetcode :  https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//
//
//
//

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int num_substr(string s)
{
    unordered_map<char,int> tracker;
    int res = 0;
    int start = 0;
    tracker['a'] = 0;
    tracker['b'] = 0;
    tracker['c'] = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        tracker[s[i]]++;

        while(tracker['a'] > 0 && tracker['b'] > 0 && tracker['c'] > 0)
        {
            res += s.size() - i;
            tracker[s[start]]--;
            start++;
        }
    }
    return res;
}

int main()
{
    cout << num_substr("abcabc") << endl;
    cout << num_substr("aaabc") << endl;
    cout << num_substr("abc") << endl;
}
