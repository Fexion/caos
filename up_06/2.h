#include <stdio.h>

int parse_rwx_permissions(const char *str) {
    char templ[] = "rwxrwxrwx";
    int sum = 0;
    int i = 0;
    for (; templ[i] != '\0'; ++i, ++str) {
        if (str == NULL) {
            return -1;
        } if (*str == '\0') {
            return -1;
        } else if (templ[i] == *str) {
            sum = (sum << 1) + 1;
        } else if (*str == '-') {
            sum = sum << 1;
        } else {
            return -1;
        }
    }

    if (str == NULL) {
        return sum;
    } else if (*str == '\0') {
        return sum;
    }

    return -1;
}
