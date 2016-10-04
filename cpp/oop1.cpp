#include <iostream>
using namespace std;

template <typename II, typename OI> 
II copy(II a, II b, II e)
{
    while(a != b)
    {
        *e = *a; 
        e++;
        a++;
    }
    return e;
}

template <typename II>
II fill(II a, II b, II e)
{
    while(a != b)
    {
        *a = *e; 
        a++;
    }
    return a;
}

int main()
{
    int a[] = {2,3,6};
    int b[] = {1,3,8};
    copy(a, a + 3, b);
    
    for(int i = 0; i < 3; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}
