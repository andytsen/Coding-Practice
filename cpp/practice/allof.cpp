// PSUEDO CODE

#include <iostream>

int main()
{
    return 0;
}

template <typename II, typename BF>
bool alof(II b, II e, BF f) {
    while(b != e) {
        if(!f(*b))
            return false;
        b++;
    }
    return true;
}

template <typename II>
bool equal(II b, II e, II k)
{
    while(b != e)
    {
        if(*b != *k)
        {
            return false;
        }
        b++;
        k++;
    }
    return true;
}
