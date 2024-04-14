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





#define MAX_STRING_SIZE 100

char _stringBuffer[MAX_STRING_SIZE + 1];

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = beginSearch;
    while (*beginSearch && !isalnum(*beginSearch)) {
        beginSearch++;
    }

    if (*beginSearch == '\0') {
        return 0;
    }

    word->begin = beginSearch;

    while (*beginSearch && isalnum(*beginSearch)) {
        beginSearch++;
    }

    word->end = beginSearch;

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = strcpy(_stringBuffer, word.begin);
    char *recPosition = endStringBuffer;

    while (endStringBuffer > _stringBuffer) {
        if (isdigit(*endStringBuffer)) {
            *recPosition = *endStringBuffer;
            recPosition++;
        }
        endStringBuffer--;
    }

    while (word.begin < word.end) {
        if (isalpha(*word.begin)) {
            *recPosition = *word.begin;
            recPosition++;
        }
        word.begin++;
    }
}

void reverseString(char *begin, char *end) {
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

void getWordReverse(char *str, char *end, WordDescriptor *word) {
    word->begin = end;
    while (end >= str && *end != ' ') {
        end--;
    }

    if (end >= str) {
        word->begin = end + 1;
    }

    while (end >= str && *end == ' ') {
        end--;
    }

    return;
}

void changeWords_numb(char *s) {
    char *start = s;
    char *finish = s;
    while (*finish != '\0') {
        if (*finish >= '0' && *finish <= '9') {
            while (*finish >= '0' && *finish <= '9') {
                finish++;
            }
            reverseString(start, finish - 1);
            start = finish;
        } else {
            finish++;
        }
    }
}