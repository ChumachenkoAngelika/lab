

#ifndef LAB_TEST_MATRIX_H
#define LAB_TEST_MATRIX_H


void test_change_min_max_base();

void test_change_min_max_oneRow();

void test_change_min_max_border();


void test_sortRowsByMinElement_base();


void test_sortRowsByMinElement_moreMax();

void test_sortRowsByMinElement_alreadyChange();

void test_sortColsByMinElement_base();


void test_sortColsByMinElement_alreadyOrder();


void test_sortColsByMinElement_moreMin();


void test_getSquareOfMatrixIfSymmetric_base();



void test_getSquareOfMatrixIfSymmetric_zero();



void test_getSquareOfMatrixIfSymmetric_single();

void test_transposeIfMatrixHasNotEqualSumOfRows_base();


void test_transposeIfMatrixHasNotEqualSumOfRows_IfSymmetric();


void test_isMutuallyInverseMatrices_base();

void test_isMutuallyInverseMatrices_alreadySingl();

void test_findSumOfMaxesOfPseudoDiagonal_base();



void test_findSumOfMaxesOfPseudoDiagonal_SquareMatrix();


void test_findSumOfMaxesOfPseudoDiagonal_matrix_2on2();



void test_getMinInArea_base();

void test_getMinInArea_atBorder();


void test_getMinInArea_inFirstRow();


void test_getMinInArea_inSecondRow();


void test_sortByDistances_base();

void test_sortByDistances_equaleDist();


void test_sortByDistances_alreadySort();


void test_countEqClassesByRowsSum_base();


void test_countEqClassesByRowsSum_INT_MAX();

void test_countEqClassesByRowsSum_ALLequale();


void test_getNSpecialElement_base();


void test_getNSpecialElement_voidValue();


void test_getNSpecialElement_AllCols();


void test_swapPenultimateRow_base();

void test_swapPenultimateRow_MaxInt();

void test_swapPenultimateRow_MinInFirst();


void test_countNonDescendingRowsMatrices_base();

void test_countNonDescendingRowsMatrices_allEquale();

void test_printMatrixWithMaxZeroRows_base();



void test_printMatrixWithMaxZeroRows_zeroRowsIsEquale();



void test_print_matrix_minNorm_base();

void test_print_matrix_minNorm_AllMatrixsPrint();


void test_getNSpecialElement2_base();


void test_getNSpecialElement2_in0Index();


void test_getNSpecialElement2_EqualeValue();




void test_getNSpecialElement2_MaxValueRight();



void test_getVectorIndexWithMaxAngle_base();


void test_getVectorIndexWithMaxAngle_EqualeVec();



void test_getSpecialScalarProduct_base();



void test_getSpecialScalarProduct_minElZero();



void test_matrix() {
    test_change_min_max_base();
    test_change_min_max_oneRow();
    test_change_min_max_border();
    test_sortRowsByMinElement_base();
    test_sortRowsByMinElement_moreMax();
    test_sortRowsByMinElement_alreadyChange();
    test_sortColsByMinElement_base();
    test_sortColsByMinElement_alreadyOrder();
    test_sortColsByMinElement_moreMin();
    test_getSquareOfMatrixIfSymmetric_base();
    test_getSquareOfMatrixIfSymmetric_zero();
    test_getSquareOfMatrixIfSymmetric_single();
    test_transposeIfMatrixHasNotEqualSumOfRows_base();
    test_transposeIfMatrixHasNotEqualSumOfRows_IfSymmetric();
    test_isMutuallyInverseMatrices_base();
    test_isMutuallyInverseMatrices_alreadySingl();
    test_findSumOfMaxesOfPseudoDiagonal_base();
    test_findSumOfMaxesOfPseudoDiagonal_SquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_matrix_2on2();
    test_getMinInArea_base();
    test_getMinInArea_atBorder();
    test_getMinInArea_inFirstRow();
    test_getMinInArea_inSecondRow();
    test_sortByDistances_base();
    test_sortByDistances_equaleDist();
    test_sortByDistances_alreadySort();
    test_countEqClassesByRowsSum_base();
    test_countEqClassesByRowsSum_INT_MAX();
    test_countEqClassesByRowsSum_ALLequale();
    test_getNSpecialElement_base();
    test_getNSpecialElement_voidValue();
    test_getNSpecialElement_AllCols();
    test_swapPenultimateRow_base();
    test_swapPenultimateRow_MaxInt();
    test_swapPenultimateRow_MinInFirst();
    test_countNonDescendingRowsMatrices_base();
    test_countNonDescendingRowsMatrices_allEquale();
    test_printMatrixWithMaxZeroRows_base();
    test_printMatrixWithMaxZeroRows_zeroRowsIsEquale();
    test_print_matrix_minNorm_base();
    test_print_matrix_minNorm_AllMatrixsPrint();
    test_getNSpecialElement2_base();
    test_getNSpecialElement2_in0Index();
    test_getNSpecialElement2_EqualeValue();
    test_getNSpecialElement2_MaxValueRight();
    test_getVectorIndexWithMaxAngle_base();
    test_getVectorIndexWithMaxAngle_EqualeVec();
    test_getSpecialScalarProduct_base();
    test_getSpecialScalarProduct_minElZero();
}

#endif //LAB_TEST_MATRIX_H
