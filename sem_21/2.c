#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

volatile int ctr;
volatile unsigned long LAST;

void
handler(int sn)
{
    if (LAST) {
        printf("%lu", LAST);
        fflush(stdout);
    }
    if (ctr >= 8) {
        exit(0);
    }
    ++ctr;
}

int
main()
{
    signal(SIGVTALRM, handler);
    struct itimerval itv;

    itv.it_value.tv_sec = 0;
    itv.it_value.tv_usec = 8000;

    itv.it_interval.tv_sec = 0;
    itv.it_interval.tv_usec = 8000;

    setitimer(ITIMER_VIRTUAL, &itv, NULL);

    LAST = 1;
    while (1)
        pause();

    return 0;
}
