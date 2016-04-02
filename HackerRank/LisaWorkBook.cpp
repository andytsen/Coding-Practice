#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int chapters;
    int probs_per_page;
    cin >> chapters >> probs_per_page; 

    int magic = 0;
    int page = 0; 
    for (int i = 0; i < chapters; i++) {
        int problem; 
        cin >> problem; 
        for (int j = 0; j < problem; j++) {
            if(j % probs_per_page == 0) {
                page++;
            }
            if((j + 1) == page) {
                magic++;
            }
        }
    }
    cout << magic << endl; 
    return 0;
}
