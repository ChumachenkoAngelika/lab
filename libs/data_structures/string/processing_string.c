#include <stddef.h>
#include "string_.h"
#include "processing_string.h"
#include <ctype.h>
#include <string.h>



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




void removeExtraSpaces(char *s){
    if(s == NULL){
        return;
    }

    int index = 0;
    int i = 0;
    int spaceCounter = 0;
    while(s[i] != '\0'){
        if(s[i] != ' '){ // если символ не пробел
            s[index] = s[i];
            index++;
            spaceCounter = 0; // сброс счетчика
        } else {
            if(spaceCounter == 0){ // если это первый пробел
                s[index] = s[i];
                index++;
            }
            spaceCounter++;
        }
        i++;
    }
    s[index] = '\0';
}


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

