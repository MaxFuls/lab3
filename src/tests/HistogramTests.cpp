#include <cassert>
#include <cstddef>

#include "Histogram.hpp"

void test() {
    {
        Histogram<size_t> t(0.0, 10.0, 5, [](size_t value) { return value; });
        t.Add(3);
        t.Add(2);
        t.Add(1);
        t.Add(8);
        t.Add(13);
        t.Print();
        std::cout << '\n';
    }
    {
        Histogram<size_t> t(0.0, 10.0, 5, [](size_t value) { return value; });
        t.Add(3);
        t.Add(2);
        t.Add(1);
        t.Add(8);
        t.Add(13);
        t.Print();
        std::cout << '\n';
        t.Remove(2);
        t.Print();
        std::cout << '\n';
    }
}

int main() { test(); }