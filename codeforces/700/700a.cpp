#include <iostream>
using namespace std;

int main() {
    int n,l,v1,v2,k;
    cin >> n >> l >> v1 >> v2 >> k;
    int bus_rides = (n/k) + ((n % k == 0) ? 0 : 1); 

    return 0;   
}
