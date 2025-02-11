#pragma once

#include <cstddef>
#include <stdexcept>

#include "../../Sequence/include/Sequence.hpp"

#define DYNAMICARRAY_OUT_OF_RANGE "Index out of range"

template <typename T>
class DynamicArray : public Sequence<T> {
   private:
    size_t size;
    size_t capacity;
    T* storage;
    void resize(size_t newcap) {
        T* newstor = new T[newcap];
        std::copy(storage, storage + capacity, newstor);
        delete storage;
        storage = newstor;
    }

   public:
    DynamicArray() : size(0), capacity(0), storage(nullptr) {}
    ~DynamicArray() { delete[] storage; };
    DynamicArray(size_t capacity) : size(capacity), capacity(capacity), storage(new T[capacity]) {};
    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity), storage(new T[capacity]) {
        std::copy(other.storage, other.storage + size, storage);
    }
    DynamicArray(DynamicArray&& other) : DynamicArray() {
        std::swap(other.size, size);
        std::swap(other.capacity, capacity);
        std::swap(other.storage, storage);
    }
    DynamicArray& operator=(const DynamicArray& other) {
        size = other.size;
        capacity = other.capacity;
        delete storage;
        storage = new T[capacity];
        std::copy(other.storage, other.storage + size, storage);
        return *this;
    }
    DynamicArray& operator=(DynamicArray&& other) {
        std::swap(other.size, size);
        std::swap(other.capacity, capacity);
        std::swap(other.storage, storage);
        return *this;
    };
    T& GetFirst() override { return Get(0); }
    const T& GetFirst() const override { return Get(0); }
    T& GetLast() override { return Get(size - 1); }
    const T& GetLast() const override { return Get(size - 1); }
    T& Get(size_t index) override {
        if (index < size) {
            return storage[index];
        }
        throw std::out_of_range(DYNAMICARRAY_OUT_OF_RANGE);
    }
    const T& Get(size_t index) const override {
        if (index < size) {
            return storage[index];
        }
        throw std::out_of_range(DYNAMICARRAY_OUT_OF_RANGE);
    }
    T& operator[](size_t index) {
        std::cout << index << std::endl;

        return storage[index];
    }
    const T& operator[](size_t index) const {
        std::cout << index << std::endl;
        return storage[index];
    }
    size_t GetLength() const override { return size; }
    void Append(const T& value) override { InsertAt(value, size); }
    void Prepend(const T& value) override { InsertAt(value, 0); }
    void InsertAt(const T& value, size_t index) override {
        if (index > size) {
            throw std::out_of_range(DYNAMICARRAY_OUT_OF_RANGE);
        }
        if (capacity == size) {
            auto newcap = capacity == 0 ? 1 : 2 * capacity;
            resize((newcap));
        }
        ++size;
        storage[size] = value;
        for (size_t start = size; start > index; --start) {
            std::swap(storage[start], storage[start - 1]);
        }
    }
    void RemoveAt(size_t index) override {
        if (index > size) {
            throw std::out_of_range(DYNAMICARRAY_OUT_OF_RANGE);
        }
        for (; index < size - 1; ++index) {
            std::swap(storage[index], storage[index + 1]);
        }
        --size;
    }
};