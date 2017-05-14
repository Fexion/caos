#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


volatile int counter = 0;

void handler1(int sig) {

    printf ("%d %d\n",sig, counter);
    fflush(stdout);


    counter += 2;
}

void handler2(int sig) {
    printf("%d %d\n", sig, counter);
    fflush(stdout);
    counter -= 3;
    if (counter < 0) {
        _exit(0);
    }

}


int main() {
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);
    printf("%d\n", getpid());
    fflush(stdout);

    for(;;) {}

    return 0;
}
