#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>


volatile int state = 0;

void handler1(int sig) {
    state = 1;
}
void handler2(int sig) {
    state = 2;
}
void handler3(int sig) {
    state = 3;
}

int main() {
    sigset_t set;

    sigfillset(&set);

    sigdelset(&set, SIGUSR1);
    sigdelset(&set, SIGUSR2);
    sigdelset(&set, SIGTERM);

    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);
    signal(SIGTERM, handler3);

    printf("%d\n", getpid());
    fflush(stdout);

    uint64_t counter1 = 0;
    uint64_t counter2 = 0;
    while (1) {
        while (sigsuspend(&set) != -1) {

        }
        if (state == 2) {
            ++counter2;
        } else if (state == 1) {
            printf ("%" PRIu64 " %" PRIu64 "\n", counter1, counter2);
            fflush(stdout);
            ++counter1;
        } else if (state == 3) {
            exit(0);
        }
    }
    return 0;
}
