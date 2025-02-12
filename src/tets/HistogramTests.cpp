#include <cassert>
#include <cstddef>

#include "../core/Histogram/include/Histogram.hpp"

void test() {
    auto lambda = [](size_t value) { return value; };
    Histogram<size_t> t(0.0, 10.0, 10, lambda);
}

int main() { test(); }