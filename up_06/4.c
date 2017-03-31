#include <stdio.h>
#include <fcntl.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
    --argc;
    uint64_t N;
    int fd = open(argv[1], O_RDWR);
    sscanf (argv[2],"%"SCNu64,&N);

    if (N <= 1) {
    return 0;
    }

    double prev, cur;
    read(fd, &prev, sizeof(double));

    for (uint64_t i = 1; i < N && read(fd, & cur, sizeof(double)); ++i) {
        cur -= prev;
        lseek(fd, -sizeof(double), SEEK_CUR);
        write(fd, &cur, sizeof(double));
        prev = cur;
    }
    close(fd);

    return 0;
}
