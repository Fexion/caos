#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>

void ping_pong(int fd_in, int fd_out, int num, int max_i) {
    int cur;
    while (read(fd_in, &cur, sizeof(cur)) == sizeof(cur)) {
        ++cur;
        if (cur <= max_i) {
            printf("%d %d\n", num, cur);
            fflush(stdout);
            write(fd_out, &cur, sizeof(cur));

        }
        if (cur >= max_i) {
            close(fd_in);
            close(fd_out);
            exit(0);
        }
    }

}

int main(int argc, char *argv[]) {
    --argc;
    int n;
    sscanf(argv[1], "%d", &n);

    int pipe1_2[2], pipe2_3[2], pipe3_1[2];

    pipe(pipe1_2);
    pipe(pipe2_3);
    pipe(pipe3_1);

    if (!fork()) {
        if (!fork()) {
            //3
            close(pipe1_2[0]);
            close(pipe1_2[1]);
            close(pipe2_3[1]);
            close(pipe3_1[0]);

            ping_pong(pipe2_3[0], pipe3_1[1], 3, n);
            exit(0);
        }
        //2
        close(pipe1_2[1]);
        close(pipe2_3[0]);
        close(pipe3_1[0]);
        close(pipe3_1[1]);

        ping_pong(pipe1_2[0], pipe2_3[1], 2, n);
        wait(NULL);
        exit(0);
    }
    close(pipe1_2[0]);
    close(pipe2_3[0]);
    close(pipe2_3[1]);
    close(pipe3_1[1]);
    printf("%d %d\n", 1, 1);
    fflush(stdout);
    int cur = 1;
    write(pipe1_2[1], &cur, sizeof(cur));
    ping_pong(pipe3_1[0], pipe1_2[1], 1, n);
    wait(NULL);


    return 0;
}
