#pragma once

#include <cstddef>
#include <stdexcept>

#include "../../../collections/DynamicArray/include/DynamicArray.hpp"
#include "../../../collections/HashMap/include/HashMap.hpp"
#include "../../SparseVector/include/SparseVector.hpp"

template <typename T>
class SparseMatrix {
   private:
    size_t rows;
    size_t columns;
    T nullelem;
    HashMap<size_t, SparseVector<T>> storage;

   public:
    SparseMatrix(const T& nullelem = T()) : nullelem(nullelem) {}
    SparseMatrix(const DynamicArray<DynamicArray<T>>& matrix, const T& nullelem = T())
        : rows(matrix.GetLength()), columns(0), nullelem(nullelem) {
        for (size_t i = 0, height = matrix.GetLength(); i < height; ++i) {
            if (matrix[i].GetLength() > columns) {
                columns = matrix[i].GetLength();
            }
            for (size_t j = 0, width = matrix[i].GetLength(); j < width; ++j) {
                SparseVector<T> vector(matrix.Get(i));
                storage.Add(i, vector);
            }
        }
    }
    void Add(size_t row, size_t column, const T& value) {
        if (storage.ContainsKey(row)) {
            if (column > columns) {
                columns = column;
            }
            storage.Get(row).Add(column, value);
        } else {
            if (row > rows) {
                rows = row;
            }
            SparseVector<T> vector;
            vector.Add(column, value);
            storage.Add(row, vector);
        }
    }
    T& Get(size_t row, size_t column) {
        if (row > rows || column > columns) {
            throw std::out_of_range("indexes out of range");
        }
        if (storage.ContainsKey(row)) {
            return storage.Get(row).Get(column);
        }
        return nullelem;
    }
    void Remove(size_t row, size_t column) {
        if (row > rows || column > columns) {
            throw std::out_of_range("indexes out of range");
        }
        storage.Get(row).Remove(column);
    }
    size_t GetColumns() const { return columns; }
    size_t GetRows() const { return rows; }
};