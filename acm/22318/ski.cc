#include <iostream>
#include <cmath>


using namespace std;
int main() {
    int N;
    cin >> N;
    int S,A,D,W;
    for(int i = 0; i < N; ++i) {
        cin >> S >> A >> W >> D;
        double sv = S * cos(A * 3.14 / 180);
        double sh = S * sin(A * 3.14 / 180);
        double airtime = 2 * (sh / 10);
        double dist = airtime * (sv + W);
        if(dist < D) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
