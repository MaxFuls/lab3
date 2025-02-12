#include "interface.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Histogram.hpp"
#include "SparseMatrix.hpp"
#include "SparseVector.hpp"

std::vector<Person> LoadPersonsFromFile(const std::string& filename) {
    std::vector<Person> persons;
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open the file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;
        if (iss >> person.name >> person.surname >> person.age >> person.height) {
            persons.push_back(person);
        }
    }

    file.close();
    return persons;
}

void HistogramMenu() {
    std::cout << "\n--- Histogram Menu ---\n";
    std::cout << "Choose data type:\n";
    std::cout << "1. Integer\n";
    std::cout << "2. Double\n";
    std::cout << "3. Person\n";
    size_t choice;
    std::cin >> choice;
    std::cout << "Enter the left and right borders of total range, count of ranges\n";
    double left, right;
    size_t count;
    std::cin >> left >> right >> count;
    if (choice == 1) {
        HistogramSubmenu<int>(left, right, count);
    } else if (choice == 2) {
        HistogramSubmenu<double>(left, right, count);
    } else if (choice == 3) {
        std::string filename = "persons.txt";
        std::vector<Person> persons = LoadPersonsFromFile(filename);
        BuildPersonHistogram(persons, left, right, count);
    }
}

void SparseVectorMenu() {
    SparseVector<double> vector;
    while (true) {
        std::cout << "\n-- Sparse Vector Menu --\n";
        std::cout << "1. Set Element\n2. Get Element\n3. Print Vector\n4. Back to Main Menu\nChoose: ";
        size_t choice, index;
        double value;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter index and value: ";
                std::cin >> index >> value;
                vector.Add(index, value);
                break;
            case 2:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Value: " << vector.Get(index) << std::endl;
                break;
            case 3:
                for (size_t i = 0; i < vector.GetLength(); ++i) {
                    std::cout << vector.Get(i) << ' ';
                }
                std::cout << '\n';
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice!";
        }
    }
}

void SparseMatrixMenu() {
    SparseMatrix<double> matrix;
    while (true) {
        std::cout << "\n-- Sparse Matrix Menu --\n";
        std::cout << "1. Set Element\n2. Get Element\n3. Print Matrix\n4. Back to Main Menu\nChoose: ";
        size_t choice, row, col;
        double value;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter row, column, and value: ";
                std::cin >> row >> col >> value;
                matrix.Add(row, col, value);
                break;
            case 2:
                std::cout << "Enter row and column: ";
                std::cin >> row >> col;
                std::cout << "Value: " << matrix.Get(row, col) << '\n';
                break;
            case 3:
                for (size_t i = 0; i < matrix.GetRows(); ++i) {
                    for (size_t j = 0; j < matrix.GetColumns(); ++j) {
                        std::cout << matrix.Get(i, j) << ' ';
                    }
                    std::cout << '\n';
                }
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice!";
        }
    }
}

void MainMenu() {
    while (true) {
        std::cout << "\n-- Main Menu --\n";
        std::cout << "1. Histogram\n2. Sparse Vector\n3. Sparse Matrix\n4. Exit\nChoose: ";
        size_t choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                HistogramMenu();
                break;
            case 2:
                SparseVectorMenu();
                break;
            case 3:
                SparseMatrixMenu();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return;
            default:
                std::cout << "Invalid choice!";
        }
    }
}

void BuildPersonHistogram(const std::vector<Person>& people, double left, double right, size_t count) {
    std::cout << "choose data type:\n";
    std::cout << "1. age\n";
    std::cout << "2. height\n";
    size_t choice;
    std::cin >> choice;
    if (choice == 1) {  // Возраст
        Histogram<Person> histogram(left, right, count, [](const Person& person) { return person.age; });
        for (const auto& v : people) {
            histogram.Add(v);
        }
        histogram.Print();
    } else if (choice == 2) {  // Рост
        Histogram<Person> histogram(left, right, count, [](const Person& person) { return person.height; });
        for (const auto& v : people) {
            histogram.Add(v);
        }
        histogram.Print();
    }
    std::cout << "Result of histogramm:\n";
}
