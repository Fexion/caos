#include "2.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int inp = open("tmp.dat", O_RDONLY, 0600);
    int out = open("tmp.ans", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    copy_file(inp, out);
    close(out);

    return 0;
}
