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













//2 номер
//tusk 2
int getMax(const int *a, int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max < a[i])
            max = a[i];
    }
    return max;
}
void sortRowsByMinElement(matrix m){
    int arr[m.nRows];
    for(int i = 0; i<m.nRows;i++){
        arr[i] = getMax(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; j < m.nCols; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapRows(&m, i, j);
            }
        }
    }
}

//обычный случай
void test_sortRowsByMinElement_base(){
    int a[]= {0,8,7,63,
              54,58,57,23,
              26,99,16,55,
              35,45,69,2};
    matrix m = createMatrixFromArray(a, 4, 4);
    sortRowsByMinElement(m);
    int expected_a[]= {54,58,57,23,
                       0,8,7,63,
                       35,45,69,2,
                       26,99,16,55};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}

//если max повторяется
void test_sortRowsByMinElement_moreMax(){
    int a[]= {0,8,7,63,
              54,58,57,23,
              26,99,16,55,
              99,45,69,2};
    matrix m = createMatrixFromArray(a, 4, 4);
    sortRowsByMinElement(m);
    int expected_a[]= {54,58,57,23,
                       0,8,7,63,
                       26,99,16,55,
                       99,45,69,2};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если изменения не нужны
void test_sortRowsByMinElement_alreadyChange(){
    int a[]= {54,58,57,23,
              0,8,7,63,
              35,45,69,2,
              26,99,16,55};
    matrix m = createMatrixFromArray(a, 4, 4);
    sortRowsByMinElement(m);
    int expected_a[]= {54,58,57,23,
                       0,8,7,63,
                       35,45,69,2,
                       26,99,16,55};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}










void test_matrix() {
    test_change_min_max_base();
    test_change_min_max_oneRow();
    test_change_min_max_border();
    test_sortRowsByMinElement_base();
    test_sortRowsByMinElement_moreMax();
    test_sortRowsByMinElement_alreadyChange();

}

int main() {
    test_matrix();
    return 0;
}

