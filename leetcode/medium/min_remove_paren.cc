#include <stack>
#include <string>
#include <iostream>

using namespace std;

string min_remove_valid(string s)
{
    string res = "";
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (c == '(')
        {
            res += c;
            stk.push(res.size() - 1);
        }
        else if (c == ')')
        {
            if(!stk.empty())
            {
                res += c;
                stk.pop();
            }
        }
        else 
        {
            res += c;
        }
    }

    while (!stk.empty())
    {
        int t = stk.top();
        res[t] = ' ';
        stk.pop();
    }

    // delete all instance of ' '
    string true_res = "";
    for (char c : res)
    {
        if (c != ' ')
        {
            true_res += c;
        }
    }


    return true_res;
}


int main()
{
    std::cout << "\"" <<  min_remove_valid("a(b(c)d") << "\"" << std::endl;
    std::cout << "\"" << min_remove_valid("))((") << "\"" << std::endl;
    std::cout <<  "\"" << min_remove_valid("lee(t(c)o)de)") << "\"" << std::endl;
}
