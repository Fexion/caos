#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>


volatile int state = 1;

void handler1(int sig) {
    state = 1;
}
void handler2(int sig) {
    state = 2;
}

int main() {
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);

    printf("%d\n", getpid());
    fflush(stdout);

    int64_t tmp;
    while ((scanf("%"PRId64, &tmp)) == 1) {
        if (state == 1) {
            printf("%"PRId64"\n", -tmp);
            fflush(stdout);
        } else {
            printf("%"PRId64"\n", tmp * tmp);
            fflush(stdout);
        }
    }
    return 0;
}
