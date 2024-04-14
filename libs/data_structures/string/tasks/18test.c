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



//2 номер
//обычный тест
void test_removeAdjacentEqualLetters_usual(){
    char words[] = "aaabbbcccdddeee";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("abcde", words);
}

void test_removeAdjacentEqualLetters_empty_string(){
    char words[] = "";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("", words);
}


void test_removeAdjacentEqualLetters_one_symbol(){
    char words[] = "a";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a", words);
}


void test_removeExtraSpaces_extra_spaces(){
    char words[] = "   Hello  World   !   ";
    removeExtraSpaces(words);
    ASSERT_STRING(" Hello World ! ", words);
}


void test_removeExtraSpaces_only_spaces(){
    char words[] = "     ";
    removeExtraSpaces(words);
    ASSERT_STRING(" ", words);
}

void test_removeExtraSpaces_without_spaces(){
    char words[] = "Hello,World!";
    removeExtraSpaces(words);
    ASSERT_STRING("Hello,World!", words);
}





void test_for_18_laba(){
    test_removeNonLetters_with_spaces();
    test_removeNonLetters_with_spaces2();
    test_removeNonLetters_only_spaces();
    test_removeNonLetters_without_spaces();
    test_removeAdjacentEqualLetters_usual();
    test_removeAdjacentEqualLetters_empty_string();
    test_removeAdjacentEqualLetters_one_symbol();
    test_removeExtraSpaces_extra_spaces();
    test_removeExtraSpaces_only_spaces();
    test_removeExtraSpaces_without_spaces();

}