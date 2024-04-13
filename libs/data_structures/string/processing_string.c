#include <stddef.h>
#include "string_.h"
#include <ctype.h>


char *getEndOfString(char *s){
    while (*s != '\0'){
        s++;
    }
    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}


void removeAdjacentEqualLetters(char *s){
    if (s == NULL || *s == '\0'){
        return;
    }
    char *new_s = s;
    char previous = *s;

    //если текущий символ не равен предыдущему символу, то увеличиваем значение указателя new_s
    // затем присваиваем текущий символ этой ячейке памяти и обновляем значение previous на текущий символ.
    while (*s != '\0'){
        if (*s != previous){
            *(++new_s) = *s;
        }
        s++;
    }
    //добавляем завершающий нулевой символ к новой строке, чтобы завершить новую строку.
    *(++new_s) = '\0';
}

