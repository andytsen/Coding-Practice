#include <string>
#include <iostream>
using namespace std;

bool checkRecord(string s);

int main() {
    // test for fun
    cout << checkRecord("LLLAPPPP");
    cout << checkRecord("PPPAL");
}

bool checkRecord(string s) {
    int absences = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'L') {
            int latecount = 0;
            int temp = i;
            while(s[temp] == 'L') {
                latecount++;
                temp++;
            }
            if(latecount > 2)
                return false;
            i = temp;
        }
        if(s[i] == 'A')
            absences++;
        if(absences > 1)
            return false;
    }
    return true;

}
