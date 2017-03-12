#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    --argc;
    int file = open(argv[1], O_RDWR, 0600);
    unsigned short max_odd = 0;
    char f = 0;
    unsigned short cur, tmp;
    ssize_t rflag = 1;
    while (rflag > 0) {
        rflag = read(file, &tmp, 2);
        cur = (tmp >> 8) + (tmp << 8);
        if ((cur % 2 == 1) && cur > max_odd) {
            max_odd = cur;
            f = 1;
        }
    }
    if (f) {
        printf("%hu\n", max_odd);
    }
    return 0;
}
