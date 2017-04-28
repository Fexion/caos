#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


volatile int counter = 0;

void handler(int sig) {
    if (sig == SIGINT) {

        if (counter >= 4) {
            exit(0);
        }
        printf ("%d\n", counter);
        fflush(stdout);
        ++counter;
    }
}


int main() {
    signal(SIGINT, handler);
    printf("%d\n", getpid());
    fflush(stdout);

    for(;;) {}

    return 0;
}
