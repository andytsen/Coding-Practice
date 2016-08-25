#include <iostream>
#include <sstream>
using namespace std;

int compareVersion(string version1, string version2);

int main() {
    cout << "COMPARE " << compareVersion("1.0", "01") << endl;
    return 0;
}


int compareVersion(string version1, string version2) {
    stringstream ss1(version1), ss2(version2);
    int num1=0, num2=0;
    char op;

    while(!ss1.fail() || !ss2.fail()){
        ss1>>num1;
        ss2>>num2;
        if(ss1.fail())
            num1=0;
        if(ss2.fail())
            num2=0;
        if(num1 > num2)
            return 1;
        else if(num1 < num2)
            return -1;
        ss1>>op;
        ss2>>op;
    }
    cout << op << " " <<  endl; 
    return 0;
}
