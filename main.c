#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdio.h>

//1 номер
void test_change_min_max_base() {
    int a[] = {0, 8, 7, 63, 54, 58, 57, 23, 26, 99, 16, 55, 35, 45, 69, 2};
    matrix m = createMatrixFromArray(a, 4, 4);
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);
    swapRows(&m, max.rowIndex, min.rowIndex);
    int expected_a[] = {26, 99, 16, 55, 54, 58, 57, 23, 0, 8, 7, 63, 35, 45, 69, 2};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m, &expected_m));
}

void test_change_min_max_oneRow() {
    int a[] = {55, 8, 7, 63, 54, 58, 57, 23, 0, 99, 16, 55, 35, 45, 69, 2};
    matrix m = createMatrixFromArray(a, 4, 4);
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);
    swapRows(&m, max.rowIndex, min.rowIndex);
    int expected_a[] = {55, 8, 7, 63, 54, 58, 57, 23, 0, 99, 16, 55, 35, 45, 69, 2};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m, &expected_m));
}

void test_change_min_max_border() {
    int a[] = {55, 8, 7, 63, 54, 58, 57, 0, 33, 99, 16, 55, 35, 45, 69, 2};
    matrix m = createMatrixFromArray(a, 4, 4);
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);
    swapRows(&m, max.rowIndex, min.rowIndex);
    int expected_a[] = {55, 8, 7, 63, 33, 99, 16, 55, 54, 58, 57, 0, 35, 45, 69, 2};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m, &expected_m));
}











void test_matrix() {
    test_change_min_max_base();
    test_change_min_max_oneRow();
    test_change_min_max_border();

}

int main() {
    test_matrix();
    return 0;
}

