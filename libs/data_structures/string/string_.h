
#ifndef LAB_STRING__H
#define LAB_STRING__H

#include <corecrt.h>
#include <ctype.h>

#define MAX_STRING_SIZE 128
char _stringBuffer[MAX_STRING_SIZE + 1];



char* find(char *begin, char *end, int ch);


char* findNonSpace(char *begin);


char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

int isLetter(int f);

int isDigit(int f);


char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

int isVowel(int f);

int isOddDigits(int f);

#endif //LAB_STRING__H
