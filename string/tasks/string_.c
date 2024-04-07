#include "string_.h"



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
    while (rbegin >= rend && isspace(*rbegin)){
        rbegin--; //так сказать, чтобы двигаться в обратном направлении
    }
    if (rbegin < rend){
        return rend;
    }
    return rbegin;
}

//– возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден,
// возвращается адрес rend

char* findSpaceReverse(char *rbegin, const char *rend){
    char *result = rbegin;
    while (result != rend){
        if (*result == ' '){
            return result;
        }
        result--;
    }
    return rend;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}
