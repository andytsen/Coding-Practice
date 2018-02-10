#include <iostream>
#include <string>

using namespace std;

int main() {
    string date;
    string cur;
    string wanted;
    cin >> date >> cur >> wanted;

    int month;
    int day;
    int year;
    char special;

    if(wanted[0] == 'y') special = cur[4];
    else special = cur[2];

    if(cur[0] == 'y') {
        date[4] = special;
        date[7] = special;
    } else {
        date[2] = special;
        date[5] = special;
    }

    int ychar = cur.find("y");
    int mchar = cur.find("m");
    int dchar = cur.find("d");
 
    int yw = wanted.find("y");
    int mw = wanted.find("m");
    int dw = wanted.find("d");   

    for(int i = ychar; i < ychar + 4; ++i) {
    }
      
}
