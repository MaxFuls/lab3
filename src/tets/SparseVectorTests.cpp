#include <iostream>

#include "../collections/DynamicArray/include/DynamicArray.hpp"
#include "../collections/HashMap/include/HashMap.hpp"
#include "../core/SparseVector/include/SparseVector.hpp"

void test() {
    std::cout << "Testing SparseVector...\n";

    std::cout << "  Using HashTable as storage...\n";

    DynamicArray<double> refernce;
    refernce.Append(0.0);
    refernce.Append(1.0);
    refernce.Append(0.0);
    refernce.Append(2.0);
    refernce.Append(0.0);
    refernce.Append(0.0);
    // std::cout << "Sparse vector size is " << refernce.GetLength() << std::endl;

    // LinkedList<int> list;
    // LinkedList<int>* i = new LinkedList<int>[10];
    // int* i = new int[4];
    SparseVector<double> vector(refernce);

    // std::cout << "Sparse vector size is " << refernce.GetLength() << std::endl;

    // for (int i = 0; i < 6; ++i) {
    //     std::cout << "    Element[" << i << "] = " << vector.Get(i) << "\n";
    // }

    std::cout << "SparseVector tests completed.\n";
}

int main() {
    test();
    return 0;
}