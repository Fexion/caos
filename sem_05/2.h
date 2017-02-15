void normalize_path(char *buf) {
    char* cur = buf;
    for (; *cur; ++cur, ++buf) {
        *buf = *cur;
        if (*cur == '/') {
            for (; *cur && *cur == '/'; ++cur);
            --cur;
        }
    }
    *buf  = '\0';
}
