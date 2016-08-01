#include <iostream>
using namespace std;

void swap(int* a, int b, int c)
{
    int temp = a[b-1];
    a[b-1] = a[c-1];
    a[c-1] = temp;
}

int main() {
    int n;
    cin >> n;
    int a[3] = {0,0,0};
    a[n-1] = 1; 
    for(int i = 0; i < 3; i++)
    {
        int c,b;
        cin >> c >> b;
        swap(a,b,c);
    }

    for(int i = 0; i < 3; i++)
    {
        if(a[i] == 1)
        {
            cout << i + 1<< endl;
        }
    }
    return 0;
}
