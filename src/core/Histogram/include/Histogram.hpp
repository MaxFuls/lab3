#pragma once

#include <cstddef>
#include <functional>

#include "../../../I/IDictionary/include/IDictionary.hpp"
#include "../../../collections/Sequence/include/Sequence.hpp"

template <typename T>
struct pair_hash {
    size_t operator()(std::pair<T, T> pair) const { return std::hash<T>()(pair.first) ^ std::hash<T>()(pair.second); }
};

template <typename T>
class Histogram {
   private:
    IDictionary<std::pair<double, double>, size_t, pair_hash<double>> storage;
    std::pair<double, double> totaldiap;
    size_t diaps_count;
    double elementary_diap;
    std::function<size_t(T)>& func;

    std::pair<double, double> find_diap(const T& value) {
        double left_border = totaldiap.first;
        size_t index = function(value);
        size_t number = (index - left_border) / elementary_diap;
        return {left_border + number * elementary_diap, left_border + (number + 1) * elementary_diap};
    }

    void add_to_storage(const T& value) {
        size_t index = function(value);
        double left_border = totaldiap.first;
        double right_border = totaldiap.second;
        if (index >= left_border && index <= right_border) {
            ++storage.Get(find_diap(value));
        }
    }
    void initialize_storage() {
        double left = totaldiap.first;
        double rigght = totaldiap.second;
        for (size_t i = 0; i < diaps_count; ++i) {
            storage.Add({left + i * elementary_diap, left + (i + 1) * elementary_diap}, 0);
        }
    }

   public:
    ~Histogram() = default;
    Histogram(double left_border, double right_border, size_t diaps_count, std::function<size_t(T)> function)
        : func(function), totaldiap(left_border, right_border), diaps_count(diaps_count) {
        if (left_border > right_border) {
            throw std::invalid_argument("Left border is less them right border\n");
        }
        elementary_diap = (right_border - left_border) / diaps_count;
        initialize_storage();
    }
    Histogram(double left_border, double right_border, size_t diaps_count, std::function<size_t(T)>& function,
              const Sequence<T>& sequence)
        : Histogram(left_border, right_border, diaps_count, function) {
        for (size_t i = 0, index, number; i < sequence.GetLength(); ++i) {
            add_to_storage(sequence.Get(i));
        }
    }
    void Add(const T& value) { add_to_storage(value); }
    void Remove(const T& value) {
        auto diap = find_diap(value);
        storage.Remove(diap);
    }
};