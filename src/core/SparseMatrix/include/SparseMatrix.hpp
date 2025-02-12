#pragma once

#include "../../../collections/DynamicArray/include/DynamicArray.hpp"
#include "../../../collections/HashMap/include/HashMap.hpp"
#include "../../SparseVector/include/SparseVector.hpp"

template <typename T>
class SparseMatrix {
   private:
    HashMap<size_t, SparseVector> storage;
    T nullelem;

   public:
    SparseMatrix(const DynamicArray<DynamicArray<T>>& matrix, const T& nullelem = T()) {
        for (size_t i = 0, height = matrix.GetLength(); i < height; ++i) {
            for (size_t j = 0, width = matrix[i].GetLength(); j < width; ++j) {
                SparseVector<T> vector(matrix.Get(i));
                storage.Add(i, vector);
            }
        }
    }
    void Add(size_t row, size_t column, const T& value) {
        if (HashMap.ContainsKey(row)) {
            storage.Get(row).Add(column, value);
        } else {
            SparseVector<T> vector;
            vector.Add(column, value);
            storage.Add(row, vector);
        }
    }
    T& Get(size_t row, size_t column) {
        if (storage.ContainsKey(row)) {
            return storage.Get(row).Get(column);
        }
        return nullelem;
    }
    void Remove(size_t row, size_t column) { storage.Get(row).Remove(column); }
};