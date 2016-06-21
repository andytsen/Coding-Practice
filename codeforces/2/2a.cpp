#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> mymap;
    std::string winner;
    int high = -1001;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string a;
        std::cin >> a;
        int b;
        std::cin >> b;
        // add key to map
        if(mymap.count(a) > 0)
        {
            mymap.at(a) += b;
        }
        else
            mymap.insert(std::pair<std::string, int>(a, b)); 

        if(high < mymap.at(a))
        {
            winner = a;
            high = mymap.at(a);
        }
    }
    std::cout << winner; 
    return 0;
}
