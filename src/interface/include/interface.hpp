#include <vector>

#include "../../core/Histogram/include/Histogram.hpp"
#include "person.hpp"

std::vector<Person> LoadPersonsFromFile(const std::string&);

void HistogramMenu();

void SparseVectorMenu();

void SparseMatrixMenu();

void BuildPersonHistogram(const std::vector<Person>&, double, double, size_t);

void MainMenu();

template <typename T>
void HistogramSubmenu(double left, double right, size_t count) {
    Histogram<T> histogram(left, right, count, [](T val) { return val; });
    T value;
    while (true) {
        std::cout << "1. Add\n2. Remove\n3. Print\n4. Back\n";
        size_t action;
        std::cin >> action;
        switch (action) {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                histogram.Add(value);
                break;
            case 2:
                std::cout << "Enter value: ";
                std::cin >> value;
                histogram.Remove(value);
                break;
            case 3:
                histogram.Print();
                break;
            case 4:
                return;
        }
    }
}
