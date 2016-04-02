#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    int R, C;
    cin >> cases >> R >> C; 
    for (int i = 0; i < cases; i++) {
        
        // set up grid
        int a[R][C];
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                int num;
                cin >> num; 
                a[r][c] = num;  
            }
        }

        // set up answer
        int subR, subC; 
        cin >> subR >> subC; 
        int b[subR][subC];
        for(int r = 0; r < subR; r++) {
            for(int c = 0; c < subC; c++) {
                int num;
                cin >> num;
                b[r][c] = num;
            }
        }

        int first_num = b[0][0];
        int found = 0;
        for (int r = 0; r < R - subR; r++) {
            for (int c = 0; c < C - subC; c++) {
                if (a[r][c] == first_num) {
                    
                    // look to see if the answer is correct 
                    found = 0;
                    for(int sR = r; sR < r + subR; sR++) {
                        for(int sC = c; sC < c + subC; sC++) {
                            if(a[sR][sC] == b[sR][sC]) {
                                found++; 
                            }
                        }
                    } 
                    if(found == (subR * subC)) { 
                        goto done;  
                    }    
                }
            }
        }
        found = 0;
        cout << "NO" << endl; 

        done: 
        if(found) {
            cout << "YES" << endl; 
        } 
    }
    return 0;
}
