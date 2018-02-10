#include <iostream>

using namespace std;
int main() {
    int min = 101;
    char* min_name;
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int R;
        char* name; 
        cin >> R >> name;
        if(R == 1) { 
            cout << name << endl; 
            return 0;
        }
        if(R < min) {
            min = R;
            min_name = name;
        }
    }    
    cout << min_name << endl;
    return 0;
}
