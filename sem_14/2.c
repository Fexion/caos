#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <inttypes.h>

int main(int argc, char const *argv[]) {
    uint64_t total_size = 0;
    struct stat st;
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        lstat(argv[i], &st);

        if (errno == 0 && S_ISREG(st.st_mode) && !S_ISLNK(st.st_mode) &&
                st.st_nlink == 1) {
            total_size += st.st_size;
        }
    }
    printf("%lu\n", total_size);
    return 0;
}
