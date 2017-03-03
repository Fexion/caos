#include <unistd.h>
#include <stdio.h>
#define N_b 4096
void copy_file(int in_fd, int out_fd) {
    char a[N_b];
    ssize_t rflag = 1;
    ssize_t wflag = 0;
    int read_size;
    int write_size;
    while (rflag > 0 && wflag != -1) {
        rflag = read(in_fd, a, N_b);
        read_size = rflag;
        write_size = 0;
        while (read_size > write_size && wflag != -1) {
            wflag = write(out_fd, a + write_size, read_size - write_size);
            write_size += wflag;
        }
    }
}
