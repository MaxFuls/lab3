#pragma once

#include "../../../I/IDictionary/include/IDictionary.hpp"

template <typename T>
class Histogram {
   private:
    HashMap<std::pair<size_t, size_t>, T> storage;

   public:
};