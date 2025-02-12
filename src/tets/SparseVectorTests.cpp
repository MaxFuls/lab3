#include <cassert>
#include <iostream>

#include "../collections/DynamicArray/include/DynamicArray.hpp"
#include "../collections/HashMap/include/HashMap.hpp"
#include "../core/SparseVector/include/SparseVector.hpp"

void test() {
    {
        DynamicArray<double> refernce;
        refernce.Append(0.0);
        refernce.Append(1.0);
        refernce.Append(0.0);
        refernce.Append(2.0);
        refernce.Append(0.0);
        refernce.Append(0.0);
        SparseVector<double> vector(refernce, 0.0);
        assert(vector.GetLength() == 2);
        assert(vector.Get(0) == 0.0);
        assert(vector.Get(1) == 1.0);
        assert(vector.Get(2) == 0.0);
        assert(vector.Get(3) == 2.0);
        assert(vector.Get(4) == 0.0);
        assert(vector.Get(5) == 0.0);
    }
    {
    }
}

int main() {
    test();
    return 0;
}