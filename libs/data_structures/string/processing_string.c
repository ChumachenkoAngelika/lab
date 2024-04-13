#include <stddef.h>
#include "string_.h"
#include <ctype.h>


int strlen(char *s);

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
    if(s == NULL){
        return;
    }

    int index = 0, length = strlen(s);

    for(int i = 0; i < length; i++){
        if(i == 0 || s[i] != s[i-1]){
            s[index] = s[i];
            index++;
        }
    }

    s[index] = '\0';
}

