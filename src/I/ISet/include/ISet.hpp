#pragma once

#include "../../../collections/HashMap/include/HashMap.hpp"

template <typename T>
class ISet {
   private:
    HashMap<T, bool> hashMap;

   public:
    void Add(const T& value) { HashMap.Add(value, true); }
    bool ContainsValue(const T& value) { return hashMap.ContainsKey(value); }
    void Remove(const T& value) { HashMap.Remove(value); }
};