#include "libs/data_structures/matrix/matrix.h"
#include "string/tasks/string_.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "libs/algorithms/test_matrix.h"
//номер 1
// символ найден внутри заданного диапазона
void test_find_char_within_range() {
    char str[] = "Hello, World!";
    char *result = find(str, str + 10, 'e');

    if (*result == 'e') {
        printf("found within range\n");
    } else {
        printf("not found within range\n");
    }
}

//символ не найден внутри заданного диапазона
void test_find_char_not_in_range() {
    char str[] = "Hello, World!";
    char *result = find(str, str + 5, 'A');

    if (result == str + 5) {
        printf("not found within range\n");
    } else {
        printf("found within range\n");
    }
}


//указатели на начало и конец диапазона совпадают:
void test_find_char_same_begin_end() {
    char str[] = "Hello, World!";
    char *result = find(str, str, 'r');

    if (result == str) {
        printf("Test passed: \n");
    } else {
        printf("Test failed: \n");
    }
}














//2 номер
//begin содержит только пробелы
void test_only_spaces(){
    char input[] = "    ";
    char *result = findNonSpace(input);
    if (*result == '\0') {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
}
//начало с пробелов, но есть и другие символы
void test_it_starts_with_spaces_and_other_characters(){
    char input[] = "    Hello";
    char *result = findNonSpace(input);
    if (*result == 'H') {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
}
//входная строка не содержит пробелов
void test_no_spaces(){
    char input[] = "Hello";
    char *result = findNonSpace(input);
    if (*result == 'H') {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
}













//3 номер
//Тест на обычный случай:
void test_findSpace_normalCase() {
    char input[] = "Hello world";
    char *result = findSpace(input);
    if (*result == ' '){
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
}
//Тест на случай, когда пробела нет:
void test_findSpace_noSpace() {
    char input[] = "Hello,world";
    char *result = findSpace(input);

    if(*result == 'w'){
        printf("Passed\n");
    }else {
        printf("Failed\n");
    }

}

//когда строка пустая:
void test_findSpace_emptyString(){
    char input[] = "";
    char *result = findSpace(input);

    if(*result == '\0'){
        printf("Passed:\n");
    }else{
        printf("Failed\n");
    }

}












//4 номер
//тест без пробелов
void test_without_spaces(){
    char input[] = "HelloWorld";
    char *result = findNonSpaceReverse( input + strlen(input) - 1, input);
    if (result != input){
        printf("Passed\n");
    }else{
        printf("Failed\n");
    }

}

//тестирование на пустой строке
void test_empty_line(){
    char input[] = "";
    char *result = findNonSpaceReverse(input + strlen(input) - 1, input);
    if (result == input){
        printf("passed\n");
    }else{
        printf("failed\n");
    }
}



//тесты
void test_17laba(){
    test_find_char_within_range();
    test_find_char_not_in_range();
    test_find_char_same_begin_end();
    test_only_spaces();
    test_it_starts_with_spaces_and_other_characters();
    test_no_spaces();
    test_findSpace_normalCase();
    test_findSpace_noSpace();
    test_findSpace_emptyString();
    test_without_spaces();
    test_empty_line();
}
int main(){
    test_17laba();



    return 0;
}