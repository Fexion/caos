#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    execlp("./a.out", "prog", NULL);

    return 0;
}
