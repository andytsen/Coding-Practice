#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int a,b,n;
    cin >> a >> b >> n;
    double max = (double) INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        double distance = pow((x - a), 2) + pow((y - b), 2);
        distance = sqrt(distance); 
        double time = distance/v;
        if(time < max)
            max =  time;
    }
    cout << setprecision(16) << max << endl;
    return 0;
}
