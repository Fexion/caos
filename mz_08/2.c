#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <inttypes.h>

int
main(int argc, char *argv[])
{
    int pfd[3];
    pipe(pfd);

    if (!fork()) {
        if (!fork()) {

            int tmp;
            int64_t sum = 0;
            close(pfd[1]);
            while (read(pfd[0], &tmp, 4) == 4) {
                sum += tmp;
            }

            printf("%"PRId64"\n", sum);
            fflush(stdout);

            close(pfd[0]);
            _exit(0);
        }

        close(pfd[0]);
        close(pfd[1]);
        wait(NULL);
        _exit(0);
    }

    int tmp;
    while (scanf("%d", &tmp) == 1) {
        write(pfd[1], &tmp, 4);
    }

    close(pfd[0]);
    close(pfd[1]);

    wait(NULL);

    return 0;
}
