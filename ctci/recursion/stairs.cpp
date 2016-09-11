#include <iostream>
using namespace std;

int stairs(int target)
{
    if(target > 0)
    {
        return stairs(target - 1) + stairs(target - 2) + stairs(target - 3);
    }
    else if(target < 0)
        return 0;
    else 
        return 1;
}

int main() 
{
    int n = stairs(3); 
    cout << n << endl;
    return 0;
}
