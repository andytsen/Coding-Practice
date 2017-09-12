#include <iostream>
#include <istream>

using namespace std;

int main() {
    auto print_func =
        [](const string& s1, istream is) {
            is << s1 << endl;
        };
     
}
