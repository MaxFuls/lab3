#include <cassert>

#include "HashMap.hpp"

void test() {
    {
        HashMap<int, int> map;
        map.Add(1, 2);
        map.Add(2, 3);
        map.Add(3, 4);
        assert(map.Get(1) == 2);
        assert(map.Get(2) == 3);
        assert(map.Get(3) == 4);
    }
    {
        HashMap<int, int> map;
        map.Add(1, 2);
        map.Add(2, 3);
        map.Add(3, 4);
        map.Update(1, 1);
        assert(map.Get(1) == 1);
        assert(map.Get(2) == 3);
        assert(map.Get(3) == 4);
    }
    {
        HashMap<int, int> map;
        map.Add(1, 2);
        map.Add(2, 3);
        map.Add(3, 4);
        assert(map.GetCount() == 3);
        map.Remove(1);
        map.Remove(2);
        assert(map.GetCount() == 1);
        assert(map.Get(3) == 4);
    }
    {
        HashMap<int, int> map;
        map.Add(1, 2);
        map.Add(2, 3);
        map.Add(3, 4);
        assert(map.ContainsKey(1));
        assert(map.ContainsKey(2));
        assert(!map.ContainsKey(10));
    }
}

int main() { test(); }