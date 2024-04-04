#include "string_.h"



char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}


char* findNonSpace(char *begin){
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin){
    while (!isspace(*begin) && *begin != '\0'){
        begin++;
    }
    return begin;
}


char* findNonSpaceReverse(char *rbegin, const char *rend){

}
