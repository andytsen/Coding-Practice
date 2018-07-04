#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> t1 = {5,5,5,10,20};
    lemonade(t1);
}

bool lemonade(vector<int>& customers) {
    int fives = 0;
    int tens = 0;
    int twenties = 0;
    for(int i : customers) {
        if(i == 5) { fives++; }
        if(i == 10) { 
            if(fives == 0) { return false; }
            fives--;
            tens++; 
        }
        if(i == 20) { 
            if(fives - 3 >= 0) {
                fives -= 3;
            } else if(tens - 1 >= 0 && fives - 1 >= 0) {
                tens--;
                fives--;
            } else {
                return false;
            }
            twenties++; 
        }
    }  
    return true;
}
