#include <stdio.h>
#include "processing_string.h"

BagOfWords _bag;
BagOfWords _bag2;

char _stringBuffer[MAX_STRING_SIZE + 1];
char _stringBuffer1[MAX_STRING_SIZE + 1];


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


void printWordBeforeFirstWordWithA(char *s){
    char *begin_lastWord;
    char *end_lastWord;
    char *end_stringBuffer = copy(s,s+ strlen_(s), _stringBuffer);
    *end_stringBuffer = '\0';
    char *begin = _stringBuffer;
    WordDescriptor word;
    if(getWord(begin, &word) == 0) {
        printf("no one word in string");
        printf("\n");
        return;
    }
    while (*begin != '\0'){
        getWord(begin, &word);
        bool flag = false;
        char *temp_ptr = word.begin;
        while (temp_ptr!=word.end){
            if(*temp_ptr>64 && *temp_ptr < 91){
                *temp_ptr+=32;
            }
            if(*temp_ptr == 97){
                flag = true;
                break;
            }
            temp_ptr++;
        }
        if(flag){
            if (begin == _stringBuffer) {
                printf("word with letter A first");
                printf("\n");
                return;
            } else{
                while(begin_lastWord != end_lastWord){
                    printf("%c", *begin_lastWord);
                    begin_lastWord++;
                }
                printf("\n");
                return;
            }
        }
        begin = word.end;
        flag = false;
        begin_lastWord = word.begin;
        end_lastWord = word.end;
    }
    printf("no one word with A");
    printf("\n");
}




void wordDescriptorToString(WordDescriptor word, char *destination){
    char *end = copy(word.begin,word.end,destination);
    *end = '\0';
}

bool word_in_string(WordDescriptor w, char *s){
    char *end = copy(s, s+ strlen_(s), _stringBuffer);
    *end = '\0';
    removeExtraSpaces(_stringBuffer);
    char *begin = _stringBuffer;
    WordDescriptor word;
    while (*begin!='\0'){
        int check = getWord(begin, &word);
        if(check == 0)
            return false;
        bool flag = w.end-w.begin == word.end - word.begin;
        while(word.begin != word.end && w.end-w.begin == word.end -
                                                         word.begin){
            if(*word.begin!=*w.begin){
                flag = false;
                break;
            }
            word.begin++;
            w.begin++;
        }
        if(flag){
            return true;
        }
        begin = word.end;
    }
    return false;
}
// Определить последнее из слов первой строки, которое есть
//во второй строке, иначе вернёт первое слово в первой строке
WordDescriptor wordFromEndFirstLineWhichStayInSecondLine(char *s1, char *s2){
    getBagOfWords(&_bag, s1);
    while (_bag.size > 0){
        if(word_in_string(_bag.words[_bag.size-1], s2)){
            return _bag.words[_bag.size-1];
        }
        _bag.size--;
    }
    return _bag.words[_bag.size];
}



//есть ли в данной строке одинаковые слова
bool equaleWordsInstring(char *s){
    getBagOfWords(&_bag, s);
    size_t index = 0;
    while (_bag.size > 0){
        char *end_stringBuffer1 = copy(s, s+ strlen_(s), _stringBuffer1);
        *end_stringBuffer1 = '\0';
        char temp[128];
        wordDescriptorToString(_bag.words[_bag.size-1], temp);
        index += strlen_(temp);
        end_stringBuffer1-=index;
        for(int i = 0; i < strlen_(temp); i++) {
            *end_stringBuffer1 = ' ';
            end_stringBuffer1++;
        }
        if(word_in_string(_bag.words[_bag.size-1], _stringBuffer1)){
            _bag.size = 0;
            return true;
        }
        _bag.size--;
        index++;
    }
    return false;
}


bool equaleLettersInwords(WordDescriptor w1, WordDescriptor w2){
    if(w1.end - w1.begin != w2.end - w2.begin){
        return false;
    } else{
        char tempW1[MAX_STRING_SIZE];
        char tempW2[MAX_STRING_SIZE];
        char *end_tempW1 = copy(w1.begin,w1.end,tempW1);
        char *end_tempW2 = copy(w2.begin,w2.end,tempW2);
        *end_tempW1 = '\0';
        *end_tempW2 = '\0';
        char *begin_tempW1 = tempW1;
        while (*begin_tempW1!='\0'){
            bool flag = true;
            char *begin_tempW2 = tempW2;
            while (*begin_tempW2!='\0'){
                if(*begin_tempW2 == *begin_tempW1){
                    flag = false;
                    *begin_tempW2 = ' ';
                    break;
                }
                begin_tempW2++;
            }
            if(flag){
                return false;
            }
            begin_tempW1++;
        }
    }
    return true;
}
//есть ли в данной строке слова состоящие из одинаковых букв
bool equaleLettersInWordsInstring(char *s){
    getBagOfWords(&_bag, s);
    while (_bag.size > 0){
        size_t size = _bag.size;
        int count = 0;
        while (size > 0){
            if(equaleLettersInwords(_bag.words[_bag.size-1],_bag.words[size-1])){
                count++;
                if(count>1){
                    _bag.size = 0;
                    return true;
                }
            }
            size--;
        }
        _bag.size--;
    }
    return false;
}
//равны ли слова
bool equalewords(WordDescriptor w1, WordDescriptor w2){
    if(w1.end - w1.begin != w2.end - w2.begin)
        return false;
    else{
        char *begin_tempW1 = w1.begin;
        char *begin_tempW2 = w2.begin;
        while (begin_tempW1 != w1.end){
            if(*begin_tempW1 != *begin_tempW2){
                return false;
            }
            begin_tempW1++;
            begin_tempW2++;
        }
    }
    return true;
}

char *reverseString(char *s){
    char *end = s + strlen_(s) - 1;
    char *ans_begin = _stringBuffer1;
    while (end!=s){
        *ans_begin = *end;
        end--;
        ans_begin++;
    }
    *ans_begin = *s;
    *(ans_begin+1) = '\0';
    return _stringBuffer1;
}

char *wordsWhitchNotEqualeWithLast(char *s){
    getBagOfWords(&_bag, s);
    size_t last_word = _bag.size - 1;
    char *begin = _stringBuffer1;
    _bag.size--;
    char *end;
    while (_bag.size > 0){
        if(!equalewords(_bag.words[_bag.size-1], _bag.words[last_word])){
            end = copy(_bag.words[_bag.size-1].begin, _bag.words[_bag.size - 1].end, begin);
            *end = '\0';
            begin+=_bag.words[_bag.size-1].end-_bag.words[_bag.size-1].begin;
            *begin = ' ';
            begin++;
        }
        _bag.size--;
    }
    *end = '\0';
    reverse_string(_stringBuffer1);
    return _stringBuffer1;
}


WordDescriptor wordBeforeEqualeWords(char *s1, char *s2){
    char *start_ans = NULL;
    char *begin1 = s1;
    WordDescriptor w1,w2,ans,asnFalse;
    char *begin2 = s2;
    getWord(begin1, &asnFalse);
    while (*begin1!='\0'){
        int i = getWord(begin1, &w1);
        if(i == 0)
            return asnFalse;
        if(word_in_string(w1,s2)){
            while (*begin2!='\0'){
                i = getWord(begin2,&w2);
                if(i == 0)
                    return asnFalse;
                if(equalewords(w1, w2)){
                    if(start_ans == NULL){
                        return asnFalse;
                    } else{
                        return ans;
                    }
                }
                begin2 = w2.end;
                start_ans = w2.begin;
                ans.begin = w2.begin;
                ans.end = w2.end;
            }
            break;
        }
        begin1 = w1.end;
    }
    return asnFalse;
}


void DeletePalindrome(char *s){
    char *begin = s;
    char *beginDest = s;
    WordDescriptor word;
    char *end = _stringBuffer;
    char *begin_str = _stringBuffer;
    while(*begin != '\0'){
        getWord(begin, &word);
        bool flag = true;
        char *tempEnd = word.end;
        char *tempBegin = word.begin;
        int t = (tempEnd-tempBegin);
        for (int i = 0; i < t / 2; i++) {
            if (*word.begin > 64 && *word.begin < 91) {
                *word.begin += 32;
            }
            if (*word.end-1 > 64 && *word.end-1 < 91) {
                *word.end += 32;
            }
            if (*word.begin != *(word.end-1)) {
                flag = false;
                break;
            }
            word.begin++;
            word.end--;
        }
        if (!flag || t == 1) {
            end = copy(tempBegin,tempEnd,end);
            *end = ' ';
            end++;
        }
        begin = tempEnd;
    }
    *(end-1) = '\0';
    end--;
    end = copy(begin_str, end, s);
    *end = '\0';
}




void additionString(char *s1, char *s2, int n1, int n2){
    if(n1 < n2){
        getBagOfWords(&_bag,s2);
        char *end = getEndOfString(s1);
        *end = ' ';
        end++;
        while(n1 < n2){
            end = copy(_bag.words[n1].begin, _bag.words[n1].end, end);
            *end = ' ';
            end++;
            n1++;
        }
        *(end-1) = '\0';
        _bag.size = 0;
    }
    if(n2 < n1){
        getBagOfWords(&_bag,s1);
        char *end = getEndOfString(s2);
        *end = ' ';
        end++;
        while(n2 < n1){
            end = copy(_bag.words[n2].begin, _bag.words[n2].end, end);
            *end = ' ';
            end++;
            n2++;
        }
        *(end-1) = '\0';
        _bag.size = 0;
    }
}

bool allLettersInString(char *s, char *word){
    char *begin_word = word;
    char *begin_str = s;
    bool arr[26];
    bool arr_peter[26];
    int len = 0;
    for(int i = 0; i < 26;i++){
        arr[i] = false;
        arr_peter[i] = false;
    }
    while (*begin_word != '\0'){
        arr[*begin_word-97] = true;
        if(arr_peter[*begin_word-97] == false)
            len++;
        arr_peter[*begin_word - 97] = true;
        begin_word++;
    }
    int count = 0;
    while(*begin_str != '\0'){
        if(arr[*begin_str - 97] == true && arr_peter[*begin_str - 97] ==
                                           true){
            count++;
            arr_peter[*begin_str - 97] = false;
        }
        begin_str++;
    }
    return count == len;
}

