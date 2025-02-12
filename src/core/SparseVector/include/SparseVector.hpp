#pragma once

#include "../../../collections/DynamicArray/include/DynamicArray.hpp"
#include "../../../collections/HashMap/include/HashMap.hpp"

template <typename T>
class SparseVector {
   private:
    HashMap<size_t, T> storage;
    T nullelem;
    size_t size;

   public:
    SparseVector(const DynamicArray<T>& vector, const T& nullelem = T())
        : nullelem(nullelem), size(vector.GetLength()) {
        for (size_t i = 0; i < size; ++i) {
            if (vector[i] != nullelem) {
                storage.Add(i, vector[i]);
            }
        }
    }
    SparseVector(const T& nullelem = T()) : nullelem(nullelem), size(0) {}
    void Add(size_t index, const T& element) {
        if (element != nullelem) {
            storage.Add(index, element);
            if (index > size) {
                size = index + 1;
            }
        }
    }
    T Get(size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (storage.ContainsKey(index)) {
            return storage.Get(index);
        }
        return nullelem;
    }
    void Remove(size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        storage.Remove(index);
        --size;
    }
    size_t GetCount() const { return storage.GetCount(); }
    size_t GetLength() const { return size; }
};