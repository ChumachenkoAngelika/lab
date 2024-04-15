
#ifndef LAB_STRING__H
#define LAB_STRING__H

#include <corecrt.h>
#include <ctype.h>
#include "processing_string.h"
#include <stdbool.h>



//подсчёт длины строки
size_t strlen_(char *begin);
//возвращает указатель
//на первый элемент с кодом ch,
char* find(char *begin, char *end, int ch);
//возвращает указатель на первый
//символ, отличный от пробельных
char* findNonSpace(char *begin);
//возвращает указатель на первый пробельный символ
char* findSpace(char *begin);
//возвращает указатель на первый справа символ, отличный от пробельных
char* findNonSpaceReverse(char *rbegin, const char *rend);
//возвращает указатель на первый справа пробельный символ
char* findSpaceReverse(char *rbegin, const char *rend);
//сравнение сторк, true если равны
bool strcmp_(const char *lhs, const char *rhs);
//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до
char* copy(const char *beginSource, const char *endSource, char *beginDestination);
// записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с beginSource//заканчивая endSource, удовлетворяющие функции-предикату f
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, bool(*f)(char*));
//// записывает по адресу////beginDestination элементы из фрагмента памяти начиная с rbeginSource
////заканчивая rendSource, удовлетворяющие функции-предикату f
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, bool(*f)(char*));
#endif //LAB_STRING__H
