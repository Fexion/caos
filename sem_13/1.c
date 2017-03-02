#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char const *argv[]) {
    --argc;
    int file = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0600);
    unsigned short cur;
    unsigned short fix;
    while ((scanf("%hu", &cur)) != EOF) {
        fix = cur >> 8;
        write(file, &fix, 1);
        write(file, &cur, 1);
    }
    close(file);
    return 0;
}
