#include <stdio.h>
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



void replaceDigitsWithSpace(char *source) {
    char dest_array[MAX_STRING_SIZE];
    char *endSource = getEndOfString(source);
    char *dest = dest_array;

    for (char *i = source; i <= endSource; i += sizeof(char)) {
        if (isdigit(*i)) {
            int num = *i - '0' - 1;
            for (int j = 0; j <= num; j++) {
                *dest = ' ';
                dest += sizeof(char);
            }
        } else {
            *dest = *i;
            dest += sizeof(char);
        }
    }

    dest += sizeof(char);
    *dest = '\0';

    copy(dest_array, dest, source);
}
//номер 5
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *end__stringBuffer = copy(source, source+ strlen_(source),
                                   _stringBuffer);
    *end__stringBuffer = '\0';
    char *readPtr, *recPtr;
    char *begin = source;
    if (w1Size >= w2Size) {
        readPtr = _stringBuffer;
        recPtr = _stringBuffer;
        while(*readPtr != '\0'){
            WordDescriptor word;
            getWord(readPtr, &word);
            char temp_word[MAX_STRING_SIZE];
            char *tempbegin = temp_word;
            char *endtempword = copy(word.begin, word.end, tempbegin);
            *endtempword = '\0';
            if (strcmp_(temp_word, w1)) {
                copy(w2, word2.end, begin);
                begin += w2Size;
                *begin = ' ';
                begin++;
                readPtr += w1Size + 1;
            } else {
                copy(word.begin, word.end, begin);
                begin += word.end - word.begin;
                *begin = ' ';
                begin++;
                readPtr += word.end - word.begin;
            }
        }
        *(begin-1) = '\0';
    } else {
        readPtr = _stringBuffer;
        recPtr = _stringBuffer;
        while(*readPtr != '\0'){
            WordDescriptor word;
            getWord(readPtr, &word);
            char temp_word[MAX_STRING_SIZE];
            char *tempbegin = temp_word;
            char *endtempword = copy(word.begin, word.end, tempbegin);
            *endtempword = '\0';
            if (strcmp_(temp_word, w1)) {
                copy(w2, word2.end, begin);
                begin += w2Size;
                *begin = ' ';
                begin++;
                readPtr += w1Size + 1;
            } else {
                copy(word.begin, word.end, begin);
                begin += word.end - word.begin;
                *begin = ' ';
                begin++;
                readPtr += word.end - word.begin;
            }
        }
        *(begin-1) = '\0';
    }
}

//сравнение слов, словов w1 стоит выше чем w2 по алфавиту 0,
//словов w2 стоит выше чем w1 по алфавиту 1, если слова совпали то 2
int areWordsEqual_comparison(WordDescriptor w1, WordDescriptor w2){
    char *beginW1 =w1.begin;
    char *beginW2 =w2.begin;
    while(*beginW1!='\0' && *beginW2!='\0'){
        char temp_letter_W1 = *beginW1;
        char temp_letter_W2 = *beginW2;
        if(temp_letter_W1>64 && temp_letter_W1 < 91){
            temp_letter_W1+=32;
        }
        if(temp_letter_W2>64 && temp_letter_W2 < 91){
            temp_letter_W2+=32;
        }
        if(temp_letter_W1 < temp_letter_W2)
            return 0;
        if(temp_letter_W1 > temp_letter_W2)
            return 1;
        beginW1++;
        beginW2++;
    }
    if(strlen_(w1.begin) != strlen_(w2.begin)){
        return strlen_(w1.begin) > strlen_(w2.begin);
    }
    return 2;
}

bool OrderedWords(char *s){
    WordDescriptor word1;
    WordDescriptor word2;
    char *begin = s;
    while (*begin!='\0'){
        getWord(begin, &word1);
        begin+= (word1.end - word1.begin)+1;
        if(*begin == '\0') {
            if (areWordsEqual_comparison(word2, word1) == 1)
                return false;
            break;
        }
        getWord(begin, &word2);
        if(areWordsEqual_comparison(word1, word2) == 1)
            return false;
        begin+= (word2.end - word2.begin)+1;
        if(*begin == '\0')
            break;
    }
    return true;
}



void getBagOfWords(BagOfWords *bag, char *s){
    char *begin = s;
    while (*begin!='\0'){
        getWord(begin, &bag->words[bag->size]);
        begin += (bag->words[bag->size].end - bag->words[bag->size].begin);
        bag->size++;
        if(*begin == '\0')
            break;
        begin++;
    }
}
//выводит строку с конца
void print_string_revers(char *s){
    getBagOfWords(&_bag, s);
    while(_bag.size>0){
        while (_bag.words[_bag.size-1].begin != _bag.words[_bag.size-1].end){
            printf("%c", *_bag.words[_bag.size-1].begin);
            _bag.words[_bag.size-1].begin++;
        }
        printf("\n");
        _bag.size--;
    }
}



int count_palindrome(char *s){
    char *begin = s;
    WordDescriptor word;
    int count = 0;
    while (*begin != '\0'){
        bool flag = true;
        getWord(begin, &word);
        if(word.end-word.begin>1){
            char *end = copy(word.begin, word.end, _stringBuffer);
            if (*(end - 1) == ',') {
                end -= 2;
                *(end - 1) = '\0';
            } else {
                *end = '\0';
                end--;
            }
            char *start = _stringBuffer;
            for (int i = 0; i < strlen_(_stringBuffer) / 2; i++) {
                if (*start > 64 && *start < 91) {
                    *start += 32;
                }
                if (*end > 64 && *end < 91) {
                    *end += 32;
                }
                if (*start != *end) {
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            if (flag) {
                count++;
            }
        }
        begin+=word.end-word.begin + 1;
    }
    return count;
}


void switch_words(char *s1, char *s2, char *ans){
    WordDescriptor word1, word2;
    int isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    bool flag = true;
    char *ptr_stringBuffer = _stringBuffer;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found == 1 && isW2Found == 1) {
        if(flag){
            ptr_stringBuffer = copy(word1.begin, word1.end,
                                    ptr_stringBuffer);
            *ptr_stringBuffer = ' ';
            ptr_stringBuffer++;
            flag = false;
            beginSearch1+=word1.end-word1.begin+1;
        } else{
            ptr_stringBuffer = copy(word2.begin, word2.end,
                                    ptr_stringBuffer);
            *ptr_stringBuffer = ' ';
            ptr_stringBuffer++;
            flag = true;
            beginSearch2+=word2.end-word2.begin+1;
        }
    }
    *(ptr_stringBuffer-1) = '\0';
    char *end_ans = copy(_stringBuffer,ptr_stringBuffer,ans);
    if(getWord(beginSearch1, &word1) == 1){
        *(ptr_stringBuffer-1) = ' ';
        size_t len1 = strlen_(s1);
        word1.begin--;
        *word1.begin = ' ';
        char *end = copy(word1.begin,s1+len1,end_ans - 1);
        *end = '\0';
    }
    if(getWord(beginSearch2, &word2) == 1){
        *(ptr_stringBuffer-1) = ' ';
        size_t len2 = strlen_(s2);
        word2.begin--;
        *word2.begin = ' ';
        char *end = copy(word2.begin,s2+len2,end_ans - 1);
        *(end) = '\0';
    }
}



void reverse_string(char *s){
    char *end_stringBuffer = copy(s, s+ strlen_(s),_stringBuffer);
    *end_stringBuffer = '\0';
    removeExtraSpaces(_stringBuffer);
    getBagOfWords(&_bag, _stringBuffer);
    char *begin = s;
    while(_bag.size > 0){
        copy(_bag.words[_bag.size-1].begin,_bag.words[_bag.size-1].end,begin);
        begin += _bag.words[_bag.size-1].end - _bag.words[_bag.size-1].begin;
        *begin = ' ';
        begin++;
        _bag.size--;
    }
    *(begin-1) = '\0';
}

