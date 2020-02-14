#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int all_substr(string haystack, unordered_map<char,bool>& alphabet)
{
    int total = alphabet.size();
    int res = 0;
    int start = 0;

    for (auto it = alphabet.begin(); it != alphabet.end(); ++it)
    {
        it->second = false;    
    }
    for (int i = 0; i < haystack.size(); ++i)
    {
        if (alphabet.find(haystack[i]) != alphabet.end())
        {
            total--;
        }
        while (total == 0)
        {
            if (alphabet.find(haystack[start++]) != alphabet.end())
            {
                total++;
            }
        }
        res += i - start + 1;
    }
    return res; 
}

int main()
{
    unordered_map<char,bool> alphabet;
    alphabet.insert(pair<char,bool>('a', false));
    alphabet.insert(pair<char,bool>('c', false));
    std::cout << all_substr("cab", alphabet) << std::endl;
}
