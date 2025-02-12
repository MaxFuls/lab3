#include <cassert>

#include "../collections/DynamicArray/include/DynamicArray.hpp"
#include "../core/SparseMatrix/include/SparseMatrix.hpp"

void test() {
    {
        DynamicArray<double> firstrow;
        firstrow.Append(0.0);
        firstrow.Append(1.0);
        firstrow.Append(0.0);
        DynamicArray<double> secondrow;
        secondrow.Append(1.0);
        secondrow.Append(0.0);
        secondrow.Append(1.0);
        DynamicArray<double> thirdrow;
        thirdrow.Append(1.0);
        thirdrow.Append(1.0);
        thirdrow.Append(1.0);
        DynamicArray<DynamicArray<double>> m;
        m.Append(firstrow);
        m.Append(secondrow);
        m.Append(thirdrow);
        SparseMatrix<double> matrix(m);
        for (short i = 0; i < 3; ++i) {
            for (short j = 0; j < 3; ++j) {
                assert(matrix.Get(i, j) == m[i][j]);
            }
        }
    }
}

int main() { test(); }