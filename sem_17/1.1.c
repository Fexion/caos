#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    argc--;
    if (!fork()) {
        int file_in_d = open(argv[2], O_RDONLY);
        int file_out_d = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);

        dup2(file_in_d, 0);
        dup2(file_out_d, 1);

        execlp(argv[1], argv[1], (char *)NULL);
    }
    wait(NULL);
    return 0;
}
