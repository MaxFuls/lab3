#pragma once

#include <cstddef>

#include "../../DynamicArray/include/DynamicArray.hpp"
#include "../../LinkedList/include/LinkedList.hpp"

#define INVALID_KEY "There is not key at table"
template <typename Key, typename T, typename Hash = std::hash<Key>>
class HashMap {
   private:
    size_t size;
    size_t cap;
    float load_factor;
    float max_load_factor;
    Hash hash;
    DynamicArray<LinkedList<std::pair<const Key, T>>> storage;

    void resize() {
        size_t new_cap = cap * 2;
        DynamicArray<LinkedList<std::pair<const Key, T>>> new_storage(new_cap);
        for (size_t i = 0, size = storage.GetLength(); i < size; ++i) {
            for (size_t j = 0, ssize = storage[i].GetLength(); j < ssize; ++j) {
                put_value_to_map(storage[i].Get(j).first, storage[i].Get(j).first, new_storage);
            }
        }
        cap = new_cap;
        storage = std::move(new_storage);
    }
    void put_value_to_map(const Key& key, const T& value, DynamicArray<LinkedList<std::pair<const Key, T>>>& str) {
        size_t index = get_bucket_index(key, str.GetLength());
        str[index].Prepend({key, value});
    }
    size_t get_bucket_index(const Key& key, size_t capacity) const { return hash(key) % capacity; }

   public:
    ~HashMap() = default;
    HashMap(size_t capacity = 13) : size(0), cap(capacity), load_factor(0.0), max_load_factor(2.0), storage(capacity) {}
    void Add(const Key& key, const T& value) {
        ++size;
        load_factor = (float)size / cap;
        if (load_factor > max_load_factor) {
            this->resize();
        }
        put_value_to_map(key, value, storage);
    }
    T& Get(const Key& key) {
        size_t index = get_bucket_index(key, cap);
        for (size_t i = 0, size = storage[index].GetLength(); i < size; ++i) {
            if (storage[index].Get(i).first == key) {
                return storage[index].Get(i).second;
            }
        }
        throw std::invalid_argument(INVALID_KEY);
    }

    void Remove(const Key& key) {
        size_t index = get_bucket_index(key, cap);
        for (size_t i = 0, size = storage[index].GetLength(); i < size; ++i) {
            if (storage[index].Get(i).first == key) {
                storage[index].RemoveAt(i);
                --size;
            }
        }
        throw std::invalid_argument(INVALID_KEY);
    }

    void Update(const Key& key, const T& value) {
        size_t index = get_bucket_index(key, cap);
        for (size_t i = 0, size = storage[index].GetLength(); i < size; ++i) {
            if (storage[index].Get(i).first == key) {
                storage[index].Get(i).second = value;
            }
        }
        throw std::invalid_argument(INVALID_KEY);
    }

    size_t GetCount() const { return size; }

    size_t GetCapacity() const { return cap; }

    bool ContainsKey(const Key& key) {
        size_t index = get_bucket_index(key, cap);
        for (size_t i = 0, size = storage[index].GetLength(); i < size; ++i) {
            if (storage[index].Get(i).first == key) {
                return true;
            }
        }
        return false;
    }
};
