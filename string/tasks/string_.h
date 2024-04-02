
#ifndef LAB_STRING__H
#define LAB_STRING__H

#include <corecrt.h>
#include <ctype.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}



char* find(char *begin, char *end, int ch);


char* findNonSpace(char *begin);


char* findSpace(char *begin);

#endif //LAB_STRING__H
