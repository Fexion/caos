#include <ctype.h>

int mystrspccmp(const char *str1, const char *str2) {
    while (isspace(*str1)) {
        str1++;
    }
    while (isspace(*str2)) {
        str2++;
    }
    while (*str1 && *str2 && !((unsigned char)*str1 - (unsigned char)*str2)) {
        str1++;
        str2++;
        while (isspace(*str1)) {
            str1++;
        }
        while (isspace(*str2)) {
            str2++;
        }
    };
    return (int)((unsigned char)*str1 - (unsigned char)*str2);
}
