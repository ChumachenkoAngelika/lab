#include <stdio.h>
#include "../string_.h"
#include "../processing_string.h"


#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


//1 номер
void test_removeNonLetters_with_spaces(){
    char words[] = "hello, hey world";
    removeNonLetters(words);
    ASSERT_STRING("hello,heyworld", words);
}

void test_removeNonLetters_with_spaces2(){
    char words[] = "123            5677 \n hjitg";
    removeNonLetters(words);
    ASSERT_STRING("1235677hjitg", words);
}


void test_removeNonLetters_only_spaces(){
    char words[] = "        ";
    removeNonLetters(words);
    ASSERT_STRING("", words);

}

void test_removeNonLetters_without_spaces(){
    char words[] = "1234567890";
    removeNonLetters(words);
    ASSERT_STRING("1234567890", words);
}






void test_for_18_laba(){
    test_removeNonLetters_with_spaces();
    test_removeNonLetters_with_spaces2();
    test_removeNonLetters_only_spaces();
    test_removeNonLetters_without_spaces();

}