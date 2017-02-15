int mystrcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && !((unsigned char)*str1 - (unsigned char)*str2)) {
        str1++;
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}
