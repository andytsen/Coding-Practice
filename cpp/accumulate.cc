// learning accumulate real quick


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main() 
{
    // playing around with accumualte haha
    std::string x = "sometrick";
    std::cout << x << std::endl;
    std::string c = "";
    std::transform(x.begin(), x.end(), x.begin(), ::toupper);
    std::cout << x << std::endl;
    return 0;
}
