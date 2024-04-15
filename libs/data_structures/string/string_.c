#include "string_.h"
#include <memory.h>


char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}


char* findNonSpace(char *begin){
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin){
    while (!isspace(*begin) && *begin != '\0'){
        begin++;
    }
    return begin;
}



char* findNonSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend){
        if(!(isspace(*rbegin))){
            return rbegin;
        }
        rbegin--;
    }
    return rbegin;
}

//– возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден,
// возвращается адрес rend

char* findSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend){
        if(isspace(*rbegin)){
            return rbegin;
        }
        rbegin--;
    }
    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}



char* copy(const char* beginSource, const char* endSource, char* beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return beginDestination + (endSource - beginSource);
}


char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(char*)){
    while (beginSource < endSource){
        if (f(beginSource)){
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

// Функция, которая определяет, является ли символ буквой
int isLetter(int f){
    return (f >= 'a' && f <= 'z') && (f >= 'A' && f <= 'Z');
}

int isDigit(int f){
    return (f >= '0' && f <= '9');
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(char*)){
    while (rbeginSource >= rendSource) {
        if (f(rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

int isVowel(int f){
    return f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'y';
}

int isOddDigits(int f) {
    return f == '1' ||  f == '3' || f == '5' || f == '7' || f == '9';

}