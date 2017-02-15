#include <stdio.h>

int mystrcmp(const char *str1, const char *str2)
{
    for (; *str1 != '\0' && *str2 != '\0'; ++str1, ++str2) {
        if (*str1 > *str2)
            return 1;
        if (*str1 < *str2)
            return -1;
    }

    if (*str1 == *str2)
        return 0;
    if (*str1 == '\0')
        return -1;
    return 1;
}