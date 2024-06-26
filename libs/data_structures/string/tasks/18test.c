#include <stdio.h>
#include "../processing_string.h"


#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)


#define ASSERT_STRING_INT(expected, got) assertStringInt(expected, got, __FILE__, __FUNCTION__, __LINE__)


void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (!strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

void assertStringInt(int expected, int got, char const *fileName, char const *funcName, int line) {
    if (expected != got) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%d\"\n", expected);
        fprintf(stderr, "Got: \"%d\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}
// Task 1
void test_removeNonLetters_first() {
    char words[] = "hello, how are you";
    removeNonLetters(words);
    ASSERT_STRING("hello,howareyou", words);
}

void test_removeNonLetters_second() {
    char words[] = "hi 12 3     25548\n 15 jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}

void test_removeNonLetters_third() {
    char words[] = "hi1232554815jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}

void test_removeNonLetters_fourth() {
    char words[] = "  ";
    removeNonLetters(words);
    ASSERT_STRING("", words);
}

// Task 2.1
void test_removeAdjacentEqualLetters_first() {
    char words[] = "aaaaa";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a", words);
}

void test_removeAdjacentEqualLetters_second() {
    char words[] = "aaa bb bb";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a b b", words);
}

void test_removeAdjacentEqualLetters_third() {
    char words[] = "  ";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING(" ", words);
}

void test_removeAdjacentEqualLetters_fourth() {
    char words[] = "";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("", words);
}

// Task 2.2
void test_removeExtraSpaces_first() {
    char words[] = "aaaaa";
    removeExtraSpaces(words);
    ASSERT_STRING("aaaaa", words);
}

void test_removeExtraSpaces_second() {
    char words[] = "aaa  bb  b";
    removeExtraSpaces(words);
    ASSERT_STRING("aaa bb b", words);
}

void test_removeExtraSpaces_third() {
    char words[] = "  ";
    removeExtraSpaces(words);
    ASSERT_STRING(" ", words);
}

void test_removeExtraSpaces_fourth() {
    char words[] = "";
    removeExtraSpaces(words);
    ASSERT_STRING("", words);
}

// Task 3
void test_digitToStart_first() {
    char s[] = "hello81 F822";
    changeWords_numb(s);
    ASSERT_STRING("18hello 228F", s);
}

void test_digitToStart_second() {
    char s[] = "hello81 zxc123456789 856947";
    changeWords_numb(s);
    ASSERT_STRING("18hello 987654321zxc 749658", s);
}

void test_digitToStart_third() {
    char s[] = "";
    changeWords_numb(s);
    ASSERT_STRING("", s);
}

void test_getWordReverse() {
    WordDescriptor word;
    char s[] = "123 222 8585";
    getWordReverse(s, s + strlen_(s) - 1, &word);
    ASSERT_STRING("8585", word.begin);
}


void test_LettersToStart_first() {
    char s[] = "hello81 tF822";
    changeWords_Letters(s);
    ASSERT_STRING("olleh81 Ft822", s);
}

void test_LettersToStart_second() {
    char s[] = "18hello 987654321zxc 749658";
    changeWords_Letters(s);
    ASSERT_STRING("olleh18 cxz987654321 749658", s);
}

void test_one_fourth(){
    char str2[] = "12";
    replaceDigitsWithSpace(str2);
    ASSERT_STRING("   ", str2);
}
void test_two_fourth(){
    char str3[] = "hhh3dd2f";
    replaceDigitsWithSpace(str3);
    ASSERT_STRING("hhh   dd  f", str3);
}

void test_one_fifth(){
    char source[MAX_STRING_SIZE] = "hello world";
    char w1[MAX_STRING_SIZE] = "hello";
    char w2[MAX_STRING_SIZE] = "hi";
    replace(source, w1, w2);
    ASSERT_STRING("hi world", source);
}
void test_two_fifth(){
    char s[] = "hello hello hello hello hello";
    char s1[] = "hello";
    char s2[] = "RT";
    replace(s, s1, s2);
    ASSERT_STRING("RT RT RT RT RT", s);
}
void test_three_fifth(){
    char s[] = "adfg adfg adfg adfg ,adfg";
    char s1[] = "adfg";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hhh hhh ,adfg", s);
}


void test_areWordsEqual_first(){
    char s1[] = "abc";
    char s2[] = "abcg";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(0, areWordsEqual_comparison(w1, w2));
}
void test_areWordsEqual_second(){
    char s1[] = "abc";
    char s2[] = "abc";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(2, areWordsEqual_comparison(w1, w2));
}
void test_areWordsEqual_third(){
    char s1[] = "bcd";
    char s2[] = "abcd";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(1, areWordsEqual_comparison(w1, w2));
}


void test_OrderedWords_first(){
    int ans;
    char s[100] = "abcdd mdfgh zxc";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(1, ans);
}
void test_OrderedWords_second(){
    int ans;
    char s[100] = "abcdd mdfgh axc";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}
void test_OrderedWords_third(){
    int ans;
    char s[100] = "abcdd abcdd abvc aa";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}
void test_OrderedWords_fourth(){
    int ans;
    char s[100] = "abcdd abcdd abvc abvz aa";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}



void test_one_eighth(){
    char s[MAX_STRING_SIZE] = "pp, aa, bb, cc, dd";
    ASSERT_STRING_INT(5, count_palindrome(s));
}
void test_two_eighth(){
    char s[MAX_STRING_SIZE] = "aa, bb, cac, fghj";
    ASSERT_STRING_INT(3, count_palindrome(s));
}

void test_three_eighth(){
    char s[MAX_STRING_SIZE] = "gyhyt, jkiugf, ptre, kijig";
    ASSERT_STRING_INT(0, count_palindrome(s));
}

void test_switch_words_first(){
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("", ans);
}
void test_switch_words_second(){
    char s1[MAX_STRING_SIZE] = "lll ggg sss";
    char s2[MAX_STRING_SIZE] = "aaa ggg ttt";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("lll aaa ggg ggg sss ttt", ans);
}
void test_switch_words_third(){
    char s1[MAX_STRING_SIZE] = "fff ggg hhh jjj mmmmm fffffffafa";
    char s2[MAX_STRING_SIZE] = "kkk lll qqq www";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("fff kkk ggg lll hhh qqq jjj www mmmmm fffffffafa", ans);
}

void test_reverse_string_first(){
    char s[MAX_STRING_SIZE] = "fff ggg hhh jjj";
    reverse_string(s);
    ASSERT_STRING("jjj hhh ggg fff", s);
}
void test_reverse_string_second(){
    char s[MAX_STRING_SIZE] = "a d f g";
    reverse_string(s);
    ASSERT_STRING("g f d a", s);
}


void test_one_eleventh(){
    char s[MAX_STRING_SIZE] = " qqqq g dfd ahj";
    printWordBeforeFirstWordWithA(s);

}
void test_two_eleventh(){
    char s[MAX_STRING_SIZE] = " tttt g hkldk gggg";
    printWordBeforeFirstWordWithA(s);
    //ответ:нет слова с A, сошлось
}
void test_three_eleventh(){
    char s[MAX_STRING_SIZE] = " ";
    printWordBeforeFirstWordWithA(s);
    //ответ: нет слов вообще, сошлось
}




void test_wordDescriptorToString_first(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char ans[MAX_STRING_SIZE];
    getWord(s,&word);
    wordDescriptorToString(word, ans);
    ASSERT_STRING("hgh", ans);
}
void test_word_in_string_second(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char string[MAX_STRING_SIZE] = "vnev eee edjvj egeg hgh";
    int ans;
    getWord(s,&word);
    if(word_in_string(word,string)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}

void test_wordFromEndFirstLineWhichStayInSecondLine_first(){
    char s1[MAX_STRING_SIZE] = "hgh gg ggg";
    char s2[MAX_STRING_SIZE] = "vnev eee gg egeg ss";
    WordDescriptor ansW = wordFromEndFirstLineWhichStayInSecondLine(s1,s2);
    char ans [MAX_STRING_SIZE];
    wordDescriptorToString(ansW,ans);
    ASSERT_STRING("gg", ans);
}

void test_one_thirteenth(){
    char s2[MAX_STRING_SIZE] = "ss eee sgg egeg ss";
    int ans;
    if(equaleWordsInstring(s2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_two_thirteenth(){
    char s2[MAX_STRING_SIZE] = "s eee sgg egeg s";
    int ans;
    if(equaleWordsInstring(s2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_three_thirteenth(){
    char s2[MAX_STRING_SIZE] = "ss eee sgg egeg sg";
    int ans;
    if(equaleWordsInstring(s2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(0, ans);
}



void test_equaleLettersInwords_first(){
    WordDescriptor w1,w2;
    char s1[MAX_STRING_SIZE] = "asdf";
    char s2[MAX_STRING_SIZE] = "fdsa";
    getWord(s1,&w1);
    getWord(s2,&w2);
    int ans;
    if(equaleLettersInwords(w1,w2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_equaleLettersInwords_second(){
    WordDescriptor w1,w2;
    char s1[MAX_STRING_SIZE] = "dafs";
    char s2[MAX_STRING_SIZE] = "fdsa";
    getWord(s1,&w1);
    getWord(s2,&w2);
    int ans;
    if(equaleLettersInwords(w2,w1)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}

void test_equaleLettersInWordsInstring_first(){
    char s[MAX_STRING_SIZE] = "ddfs jeejjej kkkk fdsa dafs";
    int ans;
    if(equaleLettersInWordsInstring(s)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_equaleLettersInWordsInstring_second(){
    char s[MAX_STRING_SIZE] = "ddfs jeejjej kkkk fdsa drfs";
    int ans;
    if(equaleLettersInWordsInstring(s)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(0, ans);
}


void test_equalewords_first(){
    WordDescriptor w1,w2;
    char s1[MAX_STRING_SIZE] = "ddfs";
    char s2[MAX_STRING_SIZE] = "ddfs";
    getWord(s1,&w1);
    getWord(s2,&w2);
    int ans;
    if(equalewords(w2,w1)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_equalewords_second(){
    WordDescriptor w1,w2;
    char s1[MAX_STRING_SIZE] = "ddfd";
    char s2[MAX_STRING_SIZE] = "ddfs";
    getWord(s1,&w1);
    getWord(s2,&w2);
    int ans;
    if(equalewords(w2,w1)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(0, ans);
}
void test_reverseString(){
    char s1[MAX_STRING_SIZE] = "asdffgg";
    ASSERT_STRING("ggffdsa", reverseString(s1));
}
void test_wordsWhitchNotEqualeWithLast_first(){
    char *s = "ff ggg hh ds fd sssss ll";
    ASSERT_STRING("ff ggg hh ds fd sssss", wordsWhitchNotEqualeWithLast(s));
}


void test_one_sixteenth(){
    char *s1 = "ff ggg hh ds fd hhh hh";
    char *s2 = "ghg hhh hh effff";
    WordDescriptor ans = wordBeforeEqualeWords(s1,s2);
    char ans_str[128];
    wordDescriptorToString(ans,ans_str);
    ASSERT_STRING("hhh", ans_str);
}
void tes_two_sixteenth(){
    char *s1 = "ff ggg hh ds fd hhh hh";
    char *s2 = "ghg hhh ss effff";
    WordDescriptor ans = wordBeforeEqualeWords(s1,s2);
    char ans_str[128];
    wordDescriptorToString(ans,ans_str);
    ASSERT_STRING("ghg", ans_str);
}

void test_three_sixteenth(){
    char *s1 = "ff ggg hh ds fd hfsfs ghg";
    char *s2 = "ghg hhh ss effff";
    WordDescriptor ans = wordBeforeEqualeWords(s1,s2);
    char ans_str[128];
    wordDescriptorToString(ans,ans_str);
    ASSERT_STRING("ff", ans_str);
}



void test_DeletePalindrome_first(){
    char s[MAX_STRING_SIZE] = "fgff ggg hfsh ff ds fd hfsfs ghg";
    DeletePalindrome(s);
    ASSERT_STRING("fgff hfsh ds fd hfsfs", s);
}
void test_DeletePalindrome_second(){
    char s[MAX_STRING_SIZE] = "f fgff ggfg hfsh ffs ds hfsfs ghsg";
    DeletePalindrome(s);
    ASSERT_STRING("f fgff ggfg hfsh ffs ds hfsfs ghsg", s);
}




void test_additionString_first(){
    char s1[MAX_STRING_SIZE] = "fgff ggg hfsh ff";
    char s2[MAX_STRING_SIZE] = "fgggff ff hj ff ds fd";
    additionString(s1,s2,4,6);
    ASSERT_STRING("fgff ggg hfsh ff ds fd", s1);
}
void test_additionString_second(){
    char s1[MAX_STRING_SIZE] = "fgggff ff hj ff ds fd";
    char s2[MAX_STRING_SIZE] = "fgff ggg hfsh ff";
    additionString(s1,s2,6,4);
    ASSERT_STRING("fgff ggg hfsh ff ds fd", s2);
}


void test_allLettersInString_first(){
    char s1[MAX_STRING_SIZE] = "fgggff ff hj ff as fd";
    char s2[MAX_STRING_SIZE] = "aghj";
    int ans;
    if(allLettersInString(s1,s2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_allLettersInString_second(){
    char s1[MAX_STRING_SIZE] = "fgggff ff hj ff s fd";
    char s2[MAX_STRING_SIZE] = "aghj";
    int ans;
    if(allLettersInString(s1,s2)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(0, ans);
}


void test_for_18_laba(){
    test_removeNonLetters_first();
    test_removeNonLetters_second();
    test_removeNonLetters_third();
    test_removeNonLetters_fourth();
    test_removeAdjacentEqualLetters_first();
    test_removeAdjacentEqualLetters_second();
    test_removeAdjacentEqualLetters_third();
    test_removeAdjacentEqualLetters_fourth();
    test_removeExtraSpaces_first();
    test_removeExtraSpaces_second();
    test_removeExtraSpaces_third();
    test_removeExtraSpaces_fourth();
    test_digitToStart_first();
    test_digitToStart_second();
    test_digitToStart_third();
    test_LettersToStart_first();
    test_LettersToStart_second();
    test_one_fourth();
    test_two_fourth();
    test_one_fifth();
    test_two_fifth();
    test_three_fifth();
    test_areWordsEqual_first();
    test_areWordsEqual_second();
    test_areWordsEqual_third();
    test_OrderedWords_first();
    test_OrderedWords_second();
    test_OrderedWords_third();
    test_OrderedWords_fourth();
    test_one_eighth();
    test_two_eighth();
    test_three_eighth();
    test_switch_words_first();
    test_switch_words_second();
    test_switch_words_third();
    test_reverse_string_first();
    test_reverse_string_second();
    test_one_eleventh();
    test_two_eleventh();
    test_three_eleventh();
    test_wordDescriptorToString_first();
    test_word_in_string_second();
    test_wordFromEndFirstLineWhichStayInSecondLine_first();
    test_one_thirteenth();
    test_two_thirteenth();
    test_three_thirteenth();
    test_equaleLettersInwords_first();
    test_equaleLettersInwords_second();
    test_equaleLettersInWordsInstring_first();
    test_equaleLettersInWordsInstring_second();
    test_equalewords_first();
    test_equalewords_second();
    test_reverseString();
    test_wordsWhitchNotEqualeWithLast_first();
    test_one_sixteenth();
    tes_two_sixteenth();
    test_three_sixteenth();
    test_DeletePalindrome_first();
    test_DeletePalindrome_second();
    test_additionString_first();
    test_additionString_second();
    test_allLettersInString_first();
    test_allLettersInString_second();
}
