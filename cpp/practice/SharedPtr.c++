// -------------
// SharedPtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <vector>

using namespace std;

template <typename T>
class my_shared_ptr {

    private:
        T* ptr;
        int* count;

    public:
        explicit my_shared_ptr(T* p) : ptr(p), count(new int(1)) {}

        my_shared_ptr (const my_shared_ptr& rhs) :
            ptr(rhs.ptr)
        {
            (*(rhs.count))++;
            this->count = rhs.count;
        }

        bool unique() const { return *count == 1; }

        int use_count() const { return *count;}

        const T* get() const {return ptr;}

        my_shared_ptr& operator =(const my_shared_ptr& rhs) {
            (*(this->count))--;
            if(*count == 0)
                delete ptr;
            this->ptr = rhs.ptr;
            this->count = rhs.count;
            (*(this->count))++;
            return *this;
        }

        ~my_shared_ptr() {
            (*(this->count))--;
            if(*count == 0) {
                delete ptr;
            }
        }

};

template <typename T>
my_shared_ptr<T> my_make_shared() {
    return my_shared_ptr<T>(new T);
}

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

int main() {
    cout << "SharedPtr.c++" << endl;

    assert(A::c == 0);

    {
//  shared_ptr<A> x = new A; // error: no viable conversion from 'A *' to 'shared_ptr<A>'
    my_shared_ptr<A> x(new A);
    assert(x.unique());
    assert(x.use_count() == 1);
    assert(A::c          == 1);
    }

    assert(A::c == 0);

    {
    my_shared_ptr<A> x(new A);
    my_shared_ptr<A> y = x;
    assert(!x.unique());
    assert(!y.unique());
    assert(x.use_count() == 2);
    assert(y.use_count() == 2);
    assert(A::c          == 1);
    assert(x.get()       == y.get());
    }

    assert(A::c == 0);

    {
    my_shared_ptr<A> x(new A);
    my_shared_ptr<A> y(new A);
    assert(A::c    == 2);
    assert(x.get() != y.get());
    x = y;
    assert(!x.unique());
    assert(!y.unique());
    assert(x.use_count() == 2);
    assert(y.use_count() == 2);
    assert(A::c          == 1);
    assert(x.get()       == y.get());
    }

    assert(A::c == 0);

    {
    my_shared_ptr<A> x = my_make_shared<A>();
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    auto x = my_make_shared<A>();
    assert(A::c == 1);
    }

    assert(A::c == 0);

    cout << "Done." << endl;
    return 0;}
