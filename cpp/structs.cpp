#include <iostream>
using namespace std;

class pokemon {
    public:
        pokemon(int) {
            cout << "pokemon(int) ";
        }
        pokemon& operator = (const pokemon&) {
            cout << " = (const pokemon&)";
            cout << endl;
            return *this;
        }
        pokemon& operator ++() {
            ++type;
            cout << " ++ (const pokemon&)";
            return *this;
        }
        int evolve(const pokemon p) const {
            return p.type;
        }
    private:
        int type;
        
};

int main()
{
    pokemon x = 2;
    ++x = 2;
    cout << endl;
    return 0;
}
