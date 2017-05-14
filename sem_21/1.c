#include <sys/time.h>
#include <time.h>
#include <inttypes.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int sn) {
    exit(0);
}

int main() {
    signal(SIGALRM, handler);

    struct timeval timev = {};
    struct itimerval itimerv = {};


    time_t time;
    int64_t nsec;
    scanf("%ld %"SCNd64, &time, &nsec);
    time = time * 1000000 + nsec / 1000;

    time_t cur_time = 0;
    gettimeofday(&timev, NULL);
    cur_time = timev.tv_sec * 1000000 + timev.tv_usec;

    time -= cur_time;
    if (time <= 0) {
        return 0;
    }

    itimerv.it_value.tv_sec = time / 1000000;
    itimerv.it_value.tv_usec = time % 1000000;

    setitimer(ITIMER_REAL, &itimerv, NULL);
    pause();

    return 0;
}
