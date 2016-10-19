#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 3;
    int z = 4;
    auto l1 = [&x](int d) -> bool { return ++x & d;  };
    auto l2 = [l1, z](int y) -> bool { return l1(y - z + 1);  };
    cout << boolalpha;
    cout << l2(z++) << endl;
    cout << l1(x) << endl;
    cout << l2(x-- - --z) << endl;

    auto l3 = []() -> int {
        cout << "l3" << endl;
        return 0;
    };
    l3();
    return 0;
}
