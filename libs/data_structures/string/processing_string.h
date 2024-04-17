
#ifndef LAB_PROCESSING_STRING_H
#define LAB_PROCESSING_STRING_H

#include <corecrt.h>
#include "string_.h"
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
typedef struct WordDescriptor {
char *begin;
char *end;
} WordDescriptor;
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;} BagOfWords;

//получает конец
char *getEndOfString(char *s);
bool isspase_(char *s);
//убирает пробелы
void removeNonLetters(char *s);
//Преобразовать строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);
//Сократить количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);
// выражаем слово из строки
int getWord(char *beginSearch, WordDescriptor *word);
// выражаем слова из строки начиная с конца
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);
//цифры записывает в начало слова в обратном порядке,//а буквы в конец слова без изменения порядка
void digitToStart(WordDescriptor word);
void changeWords_numb(char *s);
//буквы записывает в начало слова в обратном порядке,//а цифры в конец слова без изменения порядка
void LettersToStart(WordDescriptor word);

void changeWords_Letters(char *s);

void replaceDigitsWithSpace(char *source);

void replace(char *source, char *w1, char *w2);

int areWordsEqual_comparison(WordDescriptor w1, WordDescriptor w2);

bool OrderedWords(char *s);

void getBagOfWords(BagOfWords *bag, char *s);

void print_string_revers(char *s);

int count_palindrome(char *s);

void switch_words(char *s1, char *s2, char *ans);

void reverse_string(char *s);

void printWordBeforeFirstWordWithA(char *s);



#endif //LAB_PROCESSING_STRING_H
