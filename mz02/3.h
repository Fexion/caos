void common_dir(const char *d1, const char *d2, char *out) {
    int k = 0;
    while (*d1 && *d2 && ((unsigned char)*d1 == (unsigned char)*d2)) {
        *out = *d1;
        d1++;
        d2++;
        out++;
        k++;
    }
    if (*d1 != *d2 ) {
        while (*out != '/') {
            out--;
            k--;
        }
    }
    if (k == 1) {
        out++;
    }
    *out = '\0';
}
