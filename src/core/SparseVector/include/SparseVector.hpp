#pragma once

#include "../../../collections/DynamicArray/include/DynamicArray.hpp"
#include "../../../collections/HashMap/include/HashMap.hpp"

template <typename T>
class SparseVector {
   private:
    HashMap<size_t, T> storage;
    T nullelem;

   public:
    SparseVector(const DynamicArray<T>& vector) {
               // for (size_t i = 0; i < 1; ++i) {
        //     // vector[i];
        //     // if (vector[i] != nullelem) {
        //     //     // storage.Add(i, vector[i]);
        //     // }
        // }
    }
    void Add(size_t index, const T& element) { storage.Add(index, element); }
    T Get(size_t index) {
        if (storage.ContainsKey(index)) {
            return storage.Get(index);
        }
        return nullelem;
    }
    void Remove(size_t index) { storage.Remove(index); }
    size_t GetLength() const { return storage.GetCount(); }
};