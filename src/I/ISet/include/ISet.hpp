#pragma once

#include "../../../collections/HashTable/include/HashTable.hpp"

template <typename T>
class ISet {
   private:
    HashMap<T, T> HashMap;

   public:
    void Add(const T& value) { HashMap.Add(value, value); }
    void Get(const T& value) { HashMap.Get(value); }
    void Remove(const T& value) { HashMap.Remove(value); }
};