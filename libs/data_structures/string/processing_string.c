#include "processing_string.h"

BagOfWords _bag;
BagOfWords _bag2;

char _stringBuffer[MAX_STRING_SIZE + 1];

//получает конец на \0
char *getEndOfString(char *s){
    while(*s != '\0'){
        s++;
    }
    return s;
}

bool isspase_(char *s){
    return 0 == isspace(*s);
}
//убирает пробелы
void removeNonLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isspase_);
    *destination = '\0';
}

//Преобразовать строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
bool AdjacentLetesIsNotEquale(char *s){
    return *s != *(s-1);
}

void removeAdjacentEqualLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s+1, endSource, s+1, AdjacentLetesIsNotEquale);
    *destination = '\0';
}

//Сократить количество пробелов между словами данного предложения до
//одного (void removeExtraSpaces(char *s))
bool AdjacentSpaseIsNotEquale(char *s){
    if(isspace(*s))
        return ' ' != *(s-1);
    return true;
}
void removeExtraSpaces(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s+1, endSource, s+1, AdjacentSpaseIsNotEquale);
    *destination = '\0';
}

// выражаем слово из строки
int getWord(char *beginSearch, WordDescriptor *word){
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

// выражаем слова из строки начиная с конца
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word){
    word->end = findNonSpaceReverse(rend, rbegin);
    if (*word->end == '\0')
        return false;
    word->begin = findSpaceReverse(word->end, rbegin)+1;
    return true;
}


bool isNumb(char *s){
    return *s > 47 && *s <58;
}
bool isNotNumb(char *s){
    return !(*s > 47 && *s < 58);
}
void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end+1,_stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isNumb);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isNotNumb);
}

//цифры записывает в начало слова в обратном порядке,
//а буквы в конец слова без изменения порядка
void changeWords_numb(char *s){
    char *beginSearch = s;
    WordDescriptor word;
    while(getWord(beginSearch, &word)){
        digitToStart(word);
        beginSearch += (word.end + 1 - beginSearch);
    }
}
//противоположная для digitToStart, задача первая из 3 номера
void LettersToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isNotNumb);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isNumb);
}

//буквы записывает в начало слова в обратном порядке,//а цифры в конец слова без изменения порядка
void changeWords_Letters(char *s){
    char *beginSearch = s;
    WordDescriptor word;
    while(getWord(beginSearch, &word)){
        LettersToStart(word);
        beginSearch += (word.end + 1 - beginSearch);
    }
}