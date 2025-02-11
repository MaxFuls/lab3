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
    HashMap(const DynamicArray<DynamicArray<T>>& matrix) {
        for (size_t i = 0, height = matrix.GetLength(); i < height; ++i) {
            for (size_t j = 0, width = matrix[i].GetLength(); j < width; ++j) {
                SparseVector<T> vector(matrix.Get(i));
                storage.Add(i, vector);
            }
        }
    }
};