#pragma once

#include "../../../collections/HashMap/include/HashMap.hpp"

template <typename T, typename Key>
class IDictionary {
   private:
    HashMap<T, Key> hashMap;

   public:
    size_t GetCount() { return hashMap.GetCount(); }
    size_t GetCapacity() { return hashMap.GetCapacity(); }
    T Get(const Key& key) { return hashMap.Get(key) }
    bool ContaisKey(const Key& key) { return hashMap.ContainsKey(key); }
    void Add(const Key& key, const T& value) { hashMap.Add(key, value); }
    void Remove(const Key& key) { hashMap.Remove(key); }
};