#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    --argc;
    int pfd[2];
    pipe(pfd);
    if (!fork()) {
        dup2(pfd[1], 1);
        close(pfd[1]);
        close(pfd[0]);
        execlp(argv[1], argv[1], NULL);
        _exit(0);
    }
    if (!fork()) {
        dup2(pfd[0], 0);
        close(pfd[0]);
        close(pfd[1]);
        execlp(argv[2], argv[2], NULL);
        _exit(0);
    }

    close(pfd[0]);
    close(pfd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
