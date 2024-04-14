
#ifndef LAB_PROCESSING_STRING_H
#define LAB_PROCESSING_STRING_H

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

char *getEndOfString(char *s);


void removeNonLetters(char *s);


void removeAdjacentEqualLetters(char *s);


void removeExtraSpaces(char *s);

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);


#endif //LAB_PROCESSING_STRING_H
