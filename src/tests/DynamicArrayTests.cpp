#include <cassert>
#include <iostream>

#include "DynamicArray.hpp"

void test() {
    {
        DynamicArray<int> arr;
        arr.Append(1);
        assert(arr.GetLength() == 1);
        arr.RemoveAt(0);
        assert(arr.GetLength() == 0);
        arr.Append(1);
        arr.Append(3);
        arr.Prepend(2);
        assert(arr.GetLength() == 3);
        assert(arr.GetFirst() == 2);
        assert(arr.GetLast() == 3);
        assert(arr.Get(0) == 2);
        assert(arr.Get(1) == 1);
        assert(arr.Get(2) == 3);
    }
    {
        DynamicArray<int> arr(10);
        assert(arr.GetLength() == 10);
        arr.Append(1);
        arr.Append(3);
        arr.Prepend(2);
        assert(arr.GetLength() == 13);
        assert(arr.GetFirst() == 2);
        assert(arr.GetLast() == 3);
        assert(arr.Get(0) == 2);
        assert(arr.Get(1) == 0);
        assert(arr.Get(2) == 0);
    }
    {
        DynamicArray<int> arr1;
        arr1.Append(1);
        arr1.Append(3);
        arr1.Prepend(2);
        assert(arr1.Get(0) == 2);
        assert(arr1.Get(1) == 1);
        assert(arr1.Get(2) == 3);
        DynamicArray<int> arr2(arr1);
        assert(arr2.Get(0) == 2);
        assert(arr2.Get(1) == 1);
        assert(arr2.Get(2) == 3);
    }
    {
        DynamicArray<int> arr1;
        arr1.Append(1);
        arr1.Append(3);
        arr1.Prepend(2);
        assert(arr1.Get(0) == 2);
        assert(arr1.Get(1) == 1);
        assert(arr1.Get(2) == 3);
        DynamicArray<int> arr2(std::move(arr1));
        assert(arr2.Get(0) == 2);
        assert(arr2.Get(1) == 1);
        assert(arr2.Get(2) == 3);
    }
    {
        DynamicArray<int> arr1;
        DynamicArray<int> arr2;
        arr1.Append(1);
        arr1.Append(2);
        arr1.Append(3);
        arr2.Append(4);
        arr2.Append(5);
        arr2.Append(6);
        assert(arr1.Get(0) == 1);
        assert(arr1.Get(1) == 2);
        assert(arr1.Get(2) == 3);
        assert(arr2.Get(0) == 4);
        assert(arr2.Get(1) == 5);
        assert(arr2.Get(2) == 6);
        arr2 = arr1;
        assert(arr2.Get(0) == 1);
        assert(arr2.Get(1) == 2);
        assert(arr2.Get(2) == 3);
    }
    {
        DynamicArray<int> arr1;
        DynamicArray<int> arr2;
        arr1.Append(1);
        arr1.Append(2);
        arr1.Append(3);
        arr2.Append(4);
        arr2.Append(5);
        arr2.Append(6);
        assert(arr1.Get(0) == 1);
        assert(arr1.Get(1) == 2);
        assert(arr1.Get(2) == 3);
        assert(arr2.Get(0) == 4);
        assert(arr2.Get(1) == 5);
        assert(arr2.Get(2) == 6);
        arr2 = std::move(arr1);
        assert(arr2.Get(0) == 1);
        assert(arr2.Get(1) == 2);
        assert(arr2.Get(2) == 3);
    }
}

int main() { test(); }