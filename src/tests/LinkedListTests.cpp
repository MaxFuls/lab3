#include <cassert>
#include <iostream>

#include "LinkedList.hpp"

void test() {
    {
        LinkedList<int> list;
        assert(list.GetLength() == 0);
        list.Append(2);
        list.Append(3);
        list.Prepend(1);
        assert(list.GetFirst() == 1);
        assert(list.GetLast() == 3);
        assert(list.Get(1) == 2);
        list.RemoveAt(0);
        assert(list.GetLength() == 2);
        assert(list.GetFirst() == 2);
        list.InsertAt(10, 0);
        assert(list.Get(1) == 10);
    }
}

int main() { test(); }