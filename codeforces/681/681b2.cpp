#include <iostream>
using namespace std;

// O(1) sol attempt
int main() 
{
    int n;
    cin >> n;

    // pos1 A B C
    int test0 = n;
    test0 = test0 - (1234567 * (test0/1234567));
    test0 = test0 - (123456 * (test0/123456));
    test0 = test0 - (1234 * (test0/1234));

    // pos2 B A C
    int test1 = n;
    test1 = test1 - (123456 * (test1/123456));
    test1 = test1 - (1234567 * (test1/1234567));
    test1 = test1 - (1234 * (test1/1234));

    // pos3 C B A 
    int test2 = n;
    test2 = test2 - (1234 * (test2/1234));
    test2 = test2 - (123456 * (test2/123456));
    test2 = test2 - (1234567 * (test2/1234567));

    // pos4 A C B
    int test3 = n;
    test3 = test3 - (1234567 * (test3/1234567));
    test3 = test3 - (1234 * (test3/1234));
    test3 = test3 - (123456 * (test3/123456));

    // pos5 B C A
    int test4 = n;
    test4 = test4 - (123456 * (test4/123456));
    test4 = test4 - (1234567 * (test4/1234567));
    test4 = test4 - (1234 * (test4/1234));

    // pos6 C A B
    int test5 = n;
    test5 = test5 - (1234 * (test5/1234));
    test5 = test5 - (1234567 * (test5/1234567));
    test5 = test5 - (123456 * (test5/123456));

    if(test0 || test1 || test2 || test3 || test4 || test5 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
