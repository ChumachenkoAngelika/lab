#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "../data_structures/matrix/matrix.h"

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







// 3 номер
int getMin(int *a, int n){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(min > a[i])
            min = a[i];
    }
    return min;
}
void sortColsByMinElement(matrix m){
    selectionSortColsMatrixByColCriteria(&m, getMin);
}
//обычный тест
void test_sortColsByMinElement_base(){
    int arr[]= {54,58,57,23,
                0,8,7,63,
                35,45,69,2,
                26,99,16,55};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {54,23,57,58,
                            0,63,7,8,
                            35,2,69,45,
                            26,55,16,99};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    sortColsByMinElement(m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//уже отсортированный
void test_sortColsByMinElement_alreadyOrder(){
    int arr[]= {54,23,57,58,
                0,63,7,8,
                35,2,69,45,
                26,55,16,99};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {54,23,57,58,
                            0,63,7,8,
                            35,2,69,45,
                            26,55,16,99};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    sortColsByMinElement(m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//повторяются минимальные элементы
void test_sortColsByMinElement_moreMin(){
    int arr[]= {54,23,57,58,
                1,63,1,1,
                35,2,69,45,
                26,55,16,99};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {54,57,58,23,
                            1,1,1,63,
                            35,69,45,2,
                            26,16,99,55};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    sortColsByMinElement(m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}










//4 номер
matrix mulMatrices(matrix m1, matrix m2){
    matrix result = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                //для перебора элементов
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return result;
}
void getSquareOfMatrixIfSymmetric(matrix *m){
    //ну если не сииметричная, то выводим просто ошибку
    if(!isSymmetricMatrix(m)) {
        fprintf(stderr, "Error");
        return;
    }
    matrix temp_matrix = getMemMatrix(m->nRows, m->nCols);
    copyMatrix(m, &temp_matrix);
    freeMemMatrix(m);
    *m = mulMatrices(temp_matrix, temp_matrix);
    freeMemMatrix(&temp_matrix);
}

//обычный случай
void test_getSquareOfMatrixIfSymmetric_base(){
    int arr[]= {2,1,6,7,
                1,1,8,10,
                6,8,3,5,
                7,10,5,4};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=   {90,121,73,82,
                           121,166,88,97,
                           73,88,134,157,
                           82,97,157,190};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если есть 0
void test_getSquareOfMatrixIfSymmetric_zero(){
    int arr[]= {2,1,6,0,
                1,1,8,10,
                6,8,3,5,
                0,10,5,4};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {41,51,38,40,
                            51,166,88,90,
                            38,88,134,115,
                            40,90,115,141};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если единичная
void test_getSquareOfMatrixIfSymmetric_single(){
    int arr[] = {1,0,0,
                 0,1,0,
                 0,0,1};
    matrix m = createMatrixFromArray(arr, 3, 3);
    int expected_arr[]=    {1,0,0,
                            0,1,0,
                            0,0,1};
    matrix expected_m = createMatrixFromArray(expected_arr, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}









//5 номер

long long getSum(int *a, int n){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + a[i];
    }
    return sum;
}

bool isUnique(long long *a, int n) {
    long long sums[n];

    // Вычислим суммы элементов строк матрицы
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < n; j++) {
            sums[i] += a[i * n + j];
        }
    }

    // Проверим, что все суммы различны
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sums[i] == sums[j]) {
                return false; // суммы одинаковы возвращаем false
            }
        }
    }

    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m){
    long long arr[m.nCols];
    for(int i = 0; i < m.nCols; i++){
        int* Row = m.values[i];
        arr[i] = getSum(Row, m.nCols);
    }
    if(!isUnique(arr, m.nCols)){
        fprintf(stderr, "sum is not unique");
        return;
    }
    transposeSquareMatrix(&m);
}
//обычный случай
void test_transposeIfMatrixHasNotEqualSumOfRows_base(){
    int arr[]= {54,23,57,58,
                1,63,1,1,
                35,2,69,45,
                26,55,16,99};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {54,1,35,26,
                            23,63,2,55,
                            57,1,69,16,
                            58,1,45,99};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если симетричная
void test_transposeIfMatrixHasNotEqualSumOfRows_IfSymmetric(){
    int arr[]= {54,1,35,26,
                1,63,2,55,
                35,2,69,16,
                26,55,16,99};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_arr[]=    {54,1,35,26,
                            1,63,2,55,
                            35,2,69,16,
                            26,55,16,99};
    matrix expected_m = createMatrixFromArray(expected_arr, 4, 4);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(areTwoMatricesEqual(&m,&expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}











//6 номер

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    matrix result;
    result = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    if(isEMatrix(&result)){
        freeMemMatrix(&result);
        return true;
    }
    freeMemMatrix(&result);
    return false;
}

//обычный случай
void test_isMutuallyInverseMatrices_base(){
    int arr1[]= {2, 5, 7,
                 6, 3, 4,
                 5, -2, -3};
    matrix m1= createMatrixFromArray(arr1, 3, 3);
    int arr2[]=    {1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24};
    matrix m2 = createMatrixFromArray(arr2, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}
//уже единичная матрица
void test_isMutuallyInverseMatrices_alreadySingl(){
    int arr1[]= {1, 0, 0,
                 0, 1, 0,
                 0, 0, 1};
    matrix m1= createMatrixFromArray(arr1, 3, 3);
    int arr2[]=    {1, 0, 0,
                    0, 1, 0,
                    0, 0, 1};
    matrix m2 = createMatrixFromArray(arr2, 3, 3);
    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}










//номер 7
int max(int a, int b){
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m){
    int arr[m.nCols+m.nRows-1];
    for (int i = 0; i < m.nCols+m.nRows-1; i++){
        arr[i] = INT_MIN;
    }
    int index = 0;
    for (int k = 1 - m.nRows; k < m.nCols; k++){
        for (int i = 0; i < m.nRows; i++){
            int j = k + i;
            if (j >= 0 && j < m.nCols){
                arr[index] = max(arr[index], m.values[i][j]);
            }
        }
        index++;
    }
    int sum = 0;
    for (int i = 0; i < m.nCols+m.nRows-1; i++){
        sum+=arr[i];
    }
    return sum;
}
//обычный случай
void test_findSumOfMaxesOfPseudoDiagonal_base(){
    int arr[]= {2, 5, 7, 8,
                6, 3, 4, -9,
                5, -2, -3, 3};
    matrix m= createMatrixFromArray(arr, 3, 4);
    findSumOfMaxesOfPseudoDiagonal(m);
    assert(findSumOfMaxesOfPseudoDiagonal(m)==34);
    freeMemMatrix(&m);
}
//если матрица квадратная
void test_findSumOfMaxesOfPseudoDiagonal_SquareMatrix(){
    int arr[]= {2, 5, 7,
                6, 3, 4,
                5, -2, -3};
    matrix m= createMatrixFromArray(arr, 3, 3);
    findSumOfMaxesOfPseudoDiagonal(m);
    assert(findSumOfMaxesOfPseudoDiagonal(m)==26);
    freeMemMatrix(&m);
}
//матрица 2*2
void test_findSumOfMaxesOfPseudoDiagonal_matrix_2on2(){
    int arr[]= {2, 5,
                6, 3};
    matrix m= createMatrixFromArray(arr, 2, 2);
    findSumOfMaxesOfPseudoDiagonal(m);
    assert(findSumOfMaxesOfPseudoDiagonal(m)==14);
    freeMemMatrix(&m);
}
















//8 номер
int getMinInArea(matrix m){
    position max_el = getMaxValuePos(m);
    int min = m.values[max_el.rowIndex][max_el.colIndex];
    if(max_el.rowIndex!=0){
        for(int i = 1; i <= max_el.rowIndex; i++) {
            for(int j = max_el.colIndex - i; j <= max_el.colIndex+i; j++){
                if(j == m.nCols){
                    break;
                }
                if(j >= 0) {
                    min = min > m.values[max_el.rowIndex - i][j] ? m.values[max_el.rowIndex - i][j] : min;
                }
            }
        }
    }
    return min;
}

//обычный случай
void test_getMinInArea_base(){
    int arr[]= {1,2,3,4,
                5,6,7,8,
                9,10,11,12,
                13,14,16,15};
    matrix m = createMatrixFromArray(arr, 4, 4);

    assert(getMinInArea(m) == 1);
    freeMemMatrix(&m);
}
//максимальное значение у края
void test_getMinInArea_atBorder(){
    int arr[]= {0,2,3,4,
                5,6,7,8,
                9,10,11,12,
                16,14,13,15};
    matrix m = createMatrixFromArray(arr, 4, 4);

    assert(getMinInArea(m) == 0);
    freeMemMatrix(&m);
}
//максимальное значение в первой строке
void test_getMinInArea_inFirstRow(){
    int arr[]= {16,2,3,4,
                5,6,7,8,
                9,10,11,12,
                0,14,13,15};
    matrix m = createMatrixFromArray(arr, 4, 4);

    assert(getMinInArea(m) == 16);
    freeMemMatrix(&m);
}

//максимальное значение у правого края во второй строке
void test_getMinInArea_inSecondRow(){
    int arr[]= {8,2,3,4,
                5,6,7,16,
                9,10,11,12,
                0,14,13,15};
    matrix m = createMatrixFromArray(arr, 4, 4);

    assert(getMinInArea(m) == 3);
    freeMemMatrix(&m);
}













//9 номер
float getDistance(int *a, int n){
    float distance;
    for(int i = 0; i < n; i++){
        distance += a[i]*a[i];
    }
    return sqrtf(distance);
}
void insertionSortRowsMatrixByRowCriteriaF(matrix m,float (*criteria)(int *, int)){
    float arr[m.nRows];
    for(int i = 0; i < m.nRows; i++){
        arr[i] = criteria(m.values[i], m.nCols);
        printf("");
    }
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; j < m.nCols; j++) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapRows(&m, i, j);
            }
        }
    }
}


void sortByDistances(matrix m){
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}
//обычный случай
void test_sortByDistances_base(){
    int arr[]= {3,3,3,1,
                1,1,1,1,
                2,2,2,2,
                0,1,3,4};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {1,1,1,1,
                       2,2,2,2,
                       0,1,3,4,
                       3,3,3,1};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//одинаковые дистанции
void test_sortByDistances_equaleDist(){
    int arr[]= {3,3,3,1,
                1,1,1,0,
                0,1,1,1,
                0,1,3,4};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {1,1,1,0,
                       0,1,1,1,
                       0,1,3,4,
                       3,3,3,1};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//уже отсортирован
void test_sortByDistances_alreadySort(){
    int arr[]= {1,1,1,0,
                0,1,1,1,
                0,1,3,4,
                3,3,3,1};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {1,1,1,0,
                       0,1,1,1,
                       0,1,3,4,
                       3,3,3,1};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &expected_m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}









//номер 10
int countNUnique(long long *arr, int n){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {

                long long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(arr[i] != arr[i+1]){
            ans++;
        }
    }
    return ans;
}
int countEqClassesByRowsSum(matrix m){
    long long arr[m.nRows];
    for(int i = 0; i < m.nRows; i++){
        arr[i] = 0;
        for (int j = 0; j < m.nCols; j++){
            arr[i] += m.values[i][j];
        }
    }
    return countNUnique(arr, m.nRows);
}
//обычный тест, все суммы строк различны
void test_countEqClassesByRowsSum_base(){
    int arr[]= {22,5,
                6,12,
                3,1,
                1,1,
                10,1,
                5,2,
                6,0,
                0,0};
    matrix m = createMatrixFromArray(arr, 8, 2);
    assert(countEqClassesByRowsSum(m) == 8);
    freeMemMatrix(&m);
}
//используя INT_MAX
void test_countEqClassesByRowsSum_INT_MAX(){
    int arr[]= {22,INT_MAX,
                INT_MAX,12,
                3,1,
                INT_MAX,1,
                10,1,
                5,2,
                6,INT_MAX,
                0,INT_MAX};
    matrix m = createMatrixFromArray(arr, 8, 2);
    assert(countEqClassesByRowsSum(m) == 8);
    freeMemMatrix(&m);
}

//нет уникальных
void test_countEqClassesByRowsSum_ALLequale(){
    int arr[]= {1,INT_MAX,
                INT_MAX,1,
                INT_MAX,1,
                INT_MAX,1,
                INT_MAX,1,
                INT_MAX,1,
                INT_MAX,1,
                INT_MAX,1};
    matrix m = createMatrixFromArray(arr, 8, 2);
    assert(countEqClassesByRowsSum(m) == 1);
    freeMemMatrix(&m);
}














//номер 11
int getNSpecialElement(matrix m){
    int count = 0;
    for(int j = 0; j < m.nCols; j++){
        int max_value = INT_MIN;
        int sum = 0;
        for(int i = 0; i < m.nRows; i++){
            max_value = max_value > m.values[i][j] ? max_value : m.values[i][j];
            sum += m.values[i][j];
        }
        if(max_value > sum - max_value)
            count++;
    }
    return count;
}

//обычный случай
void test_getNSpecialElement_base(){
    int arr[]= {3,5,5,4,
                2,3,6,7,
                12,2,1,2};
    matrix m = createMatrixFromArray(arr, 3, 4);
    assert(getNSpecialElement(m) == 2);
    freeMemMatrix(&m);
}
//нет особых чисел
void test_getNSpecialElement_voidValue(){
    int arr[]= {3,5,5,4,
                2,3,6,5,
                4,2,1,2};
    matrix m = createMatrixFromArray(arr, 3, 4);
    assert(getNSpecialElement(m) == 0);
    freeMemMatrix(&m);
}
//в каждом столбце особое число
void test_getNSpecialElement_AllCols(){
    int arr[]= {3,5,5,4,
                2,3,8,7,
                12,10,1,2};
    matrix m = createMatrixFromArray(arr, 3, 4);
    assert(getNSpecialElement(m) == m.nCols);
    freeMemMatrix(&m);
}










//номер 12
position getLeftMin(matrix m){
    return getMinValuePos(m);
}
void swapPenultimateRow(matrix m){
    position min = getLeftMin(m);
    int crossing = m.values[m.nRows-2][min.colIndex];
    for(int i = 0; i < m.nCols; i++){
        m.values[m.nRows-2][i] = m.values[i][min.colIndex];
        if(i == m.nRows-2)
            m.values[m.nRows-2][i] = crossing;
    }

}
//обычный случай
void test_swapPenultimateRow_base(){
    int arr[]= {1,5,1,10,
                2,6,1,0,
                3,7,3,4,
                4,8,3,1};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {1,5,1,10,
                       2,6,1,0,
                       10,0,4,1,
                       4,8,3,1};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    swapPenultimateRow(m);
    assert(areTwoMatricesEqual(&expected_m, &m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если есть максимальное значение int
void test_swapPenultimateRow_MaxInt(){
    int arr[]= {10,5,1,1,
                0,6,1,2,
                INT_MAX,7,3,3,
                1,8,3,INT_MAX};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {10,5,1,1,
                       0,6,1,2,
                       10,0,INT_MAX,1,
                       1,8,3,INT_MAX};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    swapPenultimateRow(m);
    assert(areTwoMatricesEqual(&expected_m, &m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}
//если min в первой колонке
void test_swapPenultimateRow_MinInFirst(){
    int arr[]= {10,5,1,1,
                0,6,1,2,
                3,7,3,3,
                1,8,3,3};
    matrix m = createMatrixFromArray(arr, 4, 4);
    int expected_a[]= {10,5,1,1,
                       0,6,1,2,
                       10,0,3,1,
                       1,8,3,3};
    matrix expected_m = createMatrixFromArray(expected_a, 4, 4);
    swapPenultimateRow(m);
    assert(areTwoMatricesEqual(&expected_m, &m));
    freeMemMatrix(&expected_m);
    freeMemMatrix(&m);
}











// 13 номер
bool isNonDescendingSorted(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1])
            return false;
    }
    return true;
}
bool hasAllNonDescendingRows(matrix m){
    for(int i = 0; i < m.nRows; i++){
        if(!isNonDescendingSorted(m.values[i], m.nCols)){
            return false;
        }
    }
    return true;
}
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){
    int count = 0;
    for(int i = 0; i < nMatrix; i++){
        if(hasAllNonDescendingRows(ms[i])){
            count++;
        }
    }
    return count;
}

//обычный случай
void test_countNonDescendingRowsMatrices_base() {
    int arr[] = {7, 1, 1, 1,
                 1, 6, 2, 2,
                 5, 4, 2, 3,
                 1, 3, 7, 9};

    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
    freeMemMatrices(ms, 4);
}


//если матрица состоит из одинаковых элементов
void test_countNonDescendingRowsMatrices_allEquale(){
    int arr[] = {1, 1, 1, 1,
                 5, 5, 5, 5,
                 3, 3, 3, 3,
                 7, 7, 7, 2};

    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 4) == 3);
    freeMemMatrices(ms, 4);
}











//номер 14
int countZeroRows(matrix m){
    int count = 0;
    for(int i = 0; i < m.nRows; i++){
        bool flag = true;
        for(int j = 0; j < m.nCols; j++){
            if(m.values[i][j] != 0){
                flag = false;
            }
        }
        if(flag){
            count++;
        }
    }
    return count;
}
void chek_printMatrixWithMaxZeroRows(matrix *ms, int nMatrix, int *a, int *n){
    int arr[nMatrix];
    int arr_index[nMatrix];
    for(int i = 0; i < nMatrix; i++){
        arr[i] = countZeroRows(ms[i]);
        arr_index[i] = i;
    }
    for (int i = 0; i < nMatrix; i++) {
        for (int j = i; j < nMatrix; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_index = arr_index[i];
                arr_index[i] = arr_index[j];
                arr_index[j] = temp_index;
            }
        }
    }
    int ind = 0;
    int value = arr[nMatrix-1];
    for(int i = nMatrix - 1; i >=0; i--){
        if(arr[i] != value){
            break;
        }
        a[ind] = arr_index[i];
        ind++;
    }
    *n = ind;
}
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){
    int arr[nMatrix];
    int arr_index[nMatrix];
    for(int i = 0; i < nMatrix; i++){
        arr[i] = countZeroRows(ms[i]);
        arr_index[i] = i;
    }
    for (int i = 0; i < nMatrix; i++) {
        for (int j = i; j < nMatrix; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_index = arr_index[i];
                arr_index[i] = arr_index[j];
                arr_index[j] = temp_index;
            }
        }
    }
    int value = arr[nMatrix-1];
    for(int i = nMatrix - 1; i >=0; i--){
        if(arr[i] != value){
            break;
        }
        //outputMatrix(ms[arr_index[i]]); вывод
    }
}
//базовый тест
void test_printMatrixWithMaxZeroRows_base() {
    int arr[] = {0, 0, 0,
                 0,0, 0,
                 2, 2,0,
                 0, 0, 0,
                 1, 1, 2,
                 3,4, 5,
                 0, 0,0,
                 9, 10, 0,
                 0, 0, 0,
                 30,100, 300,
                 700, 90000, 15,
                 0,0,0};
    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 3, 3);
    int expriment_arr[4];
    int n = 4;
    int expected_arr[]= {0, 2};
    chek_printMatrixWithMaxZeroRows(ms, 4, expriment_arr,&n);
    for(int i = 0; i < n; i++){
        assert(expriment_arr[i] == expected_arr[i]);
    }
    freeMemMatrices(ms, 4);
}
//все матрицы имеют одинаковое кол-во нулевых строк
void test_printMatrixWithMaxZeroRows_zeroRowsIsEquale(){
    int arr[] = {0, 0, 0,
                 0,1, 0,
                 2, 2,0,
                 0, 0, 0,
                 1, 1, 2,
                 3,4, 5,
                 0, 1,0,
                 9, 10, 0,
                 0, 0, 0,
                 30,100, 300,
                 700, 90000, 15,
                 0,0,0};
    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 3, 3);
    int expriment_arr[4];
    int n = 4;
    int expected_arr[]= {3, 2, 1, 0};
    chek_printMatrixWithMaxZeroRows(ms, 4, expriment_arr,&n);
    for(int i = 0; i < n; i++){
        assert(expriment_arr[i] == expected_arr[i]);
    }
    freeMemMatrices(ms, 4);
}









// 16 номер
int max_val(matrix m){
    int max = INT_MIN;
    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(max < (m.values[i][j])) {
                max = (m.values[i][j]);
            }
        }
    }
    return max;
}

void check_print_matrix_minNorm(matrix *ms, int nMatrix, int *a, int *n){
    int arr[nMatrix];
    int arr_index[nMatrix];
    for(int i = 0; i < nMatrix; i++){
        arr[i] = max_val(ms[i]);
        arr_index[i] = i;
    }
    for (int i = 0; i < nMatrix; i++) {
        for (int j = i; j < nMatrix; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_index = arr_index[i];
                arr_index[i] = arr_index[j];
                arr_index[j] = temp_index;
            }
        }
    }
    int min_value = arr[0];
    int ind = 0;
    for(int i = 0; i < nMatrix; i++){
        if(arr[i] != min_value)
            break;
        a[ind] = arr_index[i];
        ind++;
    }
    *n = ind;
}

void print_matrix_minNorm(matrix *ms, int nMatrix){
    int arr[nMatrix];
    int arr_index[nMatrix];
    for(int i = 0; i < nMatrix; i++){
        arr[i] = max_val(ms[i]);
        arr_index[i] = i;
    }
    for (int i = 0; i < nMatrix; i++) {
        for (int j = i; j < nMatrix; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_index = arr_index[i];
                arr_index[i] = arr_index[j];
                arr_index[j] = temp_index;
            }
        }
    }
    int min_value = arr[0];
    for(int i = 0; i < nMatrix; i++){
        if(arr[i] != min_value)
            break;
        outputMatrix(ms[arr_index[i]]);
    }
}
//базовый тест
void test_print_matrix_minNorm_base(){
    int arr[] = {0, 0, 0,
                 0,1, 0,
                 2, 8,0,

                 0, 0, 0,
                 1, 1, 2,
                 3,4, 5,

                 0, 2,0,
                 3, 3, 0,
                 0, 0, 0,

                 3,8, 5,
                 6, 5, 7,
                 0,0,0};
    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 3, 3);
    int expriment_arr[4];
    int n = 4;
    int expected_arr[]= {2};
    check_print_matrix_minNorm(ms, 4, expriment_arr, &n);
    for(int i = 0; i < n; i++){
        assert(expriment_arr[i] == expected_arr[i]);
    }
    freeMemMatrices(ms, 4);
}
//все матрицы подходят
void test_print_matrix_minNorm_AllMatrixsPrint(){
    int arr[] = {0, 0, 0,
                 0,1, 0,
                 2, 8,0,

                 0, 0, 0,
                 1, 1, 2,
                 3,4, 8,

                 0, 2,0,
                 3, 8, 0,
                 0, 0, 0,

                 3,8, 5,
                 6, 5, 7,
                 0,0,0};
    matrix *ms = createArrayOfMatrixFromArray(arr, 4, 3, 3);
    int expriment_arr[4];
    int n = 4;
    int expected_arr[]= {0,1,2,3};
    check_print_matrix_minNorm(ms, 4, expriment_arr, &n);
    for(int i = 0; i < n; i++){
        assert(expriment_arr[i] == expected_arr[i]);
    }
    freeMemMatrices(ms, 4);
}










//16 номер
int min2(int a, int b){
    return a < b ? a : b;
}
int getNSpecialElement2(matrix m){
    int count = 0;
    for(int i = 0; i < m.nRows; i++){
        for(int k = 0; k < m.nCols; k++) {
            bool flag = true;
            for (int j = 0; j < m.nCols; j++) {
                if(j < k && min2(m.values[i][k], m.values[i][j]) == m.values[i][k]){
                    flag = false;
                    break;
                }
                if(j > k && min2(m.values[i][k], m.values[i][j]) == m.values[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
                break;
            }
        }
    }
    return count;
}

//обычный случай
void test_getNSpecialElement2_base(){
    int arr[]= {1,5,8,9,
                10,6,7,5,
                3,7,0,2,
                1,6,8,100};
    matrix m = createMatrixFromArray(arr, 4, 4);
    assert(getNSpecialElement2(m) == 2);
    freeMemMatrix(&m);
}
//если особый элемент на 0 индексе
void test_getNSpecialElement2_in0Index(){
    int arr[]= {1,5,8,9,
                0,6,7,5,
                3,7,0,2,
                1,6,8,100};
    matrix m = createMatrixFromArray(arr, 4, 4);
    assert(getNSpecialElement2(m) == 3);
    freeMemMatrix(&m);
}
//если стоят два одинаковых числа
void test_getNSpecialElement2_EqualeValue(){
    int arr[]= {4,1,5,5,4,
                0,6,7,5,0,
                7,3,10,10,5,
                5,1,6,100,6};
    matrix m = createMatrixFromArray(arr, 4, 5);
    assert(getNSpecialElement2(m) == 0);
    freeMemMatrix(&m);
}
//если справа стоит самое большое число
void test_getNSpecialElement2_MaxValueRight(){
    int arr[]= {4,1,5,5,9,
                0,6,7,5,0,
                7,3,10,10,INT_MIN,
                5,INT_MIN,6,100,INT_MAX};
    matrix m = createMatrixFromArray(arr, 4, 5);
    assert(getNSpecialElement2(m) == 2);
    freeMemMatrix(&m);
}








//17 номер
double getScalarProduct(int *a, int *b, int n){
    double ScalarProduct = 0;
    for(int i = 0; i < n; i++){
        ScalarProduct+= a[i]*b[i];
    }
    return ScalarProduct;
}
double getVectorLength(int *a, int n){
    double VectorLength = 0;
    for(int i = 0; i < n; i++){
        VectorLength += pow(a[i], 2);
    }
    return sqrt(VectorLength);
}
double getCosine(int *a, int *b, int n){
    double cos = getScalarProduct(a,b,n)/(getVectorLength(a,n)*getVectorLength(b,n));
    return cos;
}
int getVectorIndexWithMaxAngle(matrix m, int *b){
    double arr[m.nRows];
    for(int i = 0; i < m.nRows; i++){
        arr[i] = acos(getCosine(m.values[i], b, m.nCols));
    }
    double max = arr[0];
    int indx = 0;
    for(int i = 1; i < m.nRows; i++){
        if(max < arr[i]){
            max = arr[i];
            indx = i;
        }
    }
    return indx;
}

//обычный случай
void test_getVectorIndexWithMaxAngle_base(){
    int arr[]= {1,2,0,
                0,3,4,
                1,2,4,
                5,1,2};
    matrix m = createMatrixFromArray(arr, 4, 3);
    int vec[] = {3,3,3};
    assert(getVectorIndexWithMaxAngle(m, vec) == 0);
    freeMemMatrix(&m);
}
//векторы совпали
void test_getVectorIndexWithMaxAngle_EqualeVec(){
    int arr[]= {0,3,4,
                1,2,0,
                1,2,4,
                3,3,3};
    matrix m = createMatrixFromArray(arr, 4, 3);
    int vec[] = {3,3,3};
    assert(getVectorIndexWithMaxAngle(m, vec) == 1);
    freeMemMatrix(&m);
}















//18 номер
long long getScalarProductRowAndCol(matrix m, int i, int j){
    int vec1[m.nRows];
    int vec2[m.nRows];
    for(int k = 0; k < m.nRows; k++){
        vec1[k] = m.values[i][k];
    }
    for(int k = 0; k < m.nRows; k++){
        vec2[k] = m.values[k][j];
    }

    long long ScalarProduct = 0;
    for(int k = 0; k < m.nCols; k++){
        ScalarProduct+= vec2[k]*vec1[k];
    }
    return ScalarProduct;
}
long long getSpecialScalarProduct(matrix m){
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);
    return getScalarProductRowAndCol(m, max.rowIndex, min.colIndex);
}
//обычный случай
void test_getSpecialScalarProduct_base(){
    int arr[]= {1,5,8,9,
                3,10,20,6,
                12,15,11,2,
                13,14,16,17};
    matrix m = createMatrixFromArray(arr, 4, 4);
    assert(getSpecialScalarProduct(m) == 351);
    freeMemMatrix(&m);
}
//минимальный элемент 0
void test_getSpecialScalarProduct_minElZero(){
    int arr[]= {0,5,8,9,
                3,10,20,6,
                12,15,11,2,
                13,14,16,17};
    matrix m = createMatrixFromArray(arr, 4, 4);
    assert(getSpecialScalarProduct(m) == 348);
    freeMemMatrix(&m);
}

