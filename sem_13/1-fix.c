#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char const *argv[]) {
    --argc; //compiler raises error because of unused var, so...
    int file = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0600);
    unsigned short cur;
    unsigned short fix;
    while ((scanf("%hu", &cur)) != EOF) {
        fix = (cur >> 8) | ((cur & 255) << 8);
        write(file, &fix, 2);
    }
    close(file);
    return 0;
}
