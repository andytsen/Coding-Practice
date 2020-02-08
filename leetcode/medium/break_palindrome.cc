#include <string>
#include <iostream>

std::string break_palindrome(std::string palindrome)
{
    int len = palindrome.size()/2;  
    for (int i = 0; i < len; ++i)
    {
        if (palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            return palindrome;
        }   
    }
    return "";
}


int main()
{
    std::cout << break_palindrome("abccba") << std::endl;
    return 0;
}
