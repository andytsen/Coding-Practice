// checking something about C++, idk

#include <iostream>
#include <stack>

using namespace std;

class Pancake {
    stack<int> cakes;
    int kindOfSyrup;

    public:
        Pancake() : kindOfSyrup(10) { 
            cout << "Default of pancake" << endl;
        }

        Pancake(stack<int> s) : cakes(s), kindOfSyrup(10) {}
};

int main() {
    Pancake p;
    Pancake q(stack<int>());
    return 0;
}
