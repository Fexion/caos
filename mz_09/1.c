#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

enum { N = 5 };

pthread_t ids[N];
pthread_t ids2[N];

void *func2(void *arg)
{
    pause();
    return NULL;
}

/* INSERT YOUR CODE HERE */
void handler(int sig) {
}

void *func(void *arg)
{

    int serial = (int) (intptr_t) arg;
    /* INSERT YOUR CODE HERE */

    signal(SIGUSR1, handler);
    if (serial == 1) {
        pthread_join(ids2[4],NULL);
    }
    if (serial == 3) {
        pthread_join(ids2[1],NULL);
    }
    if (serial == 2) {
        pthread_join(ids2[3],NULL);
    }
    if (serial == 0) {
        pthread_join(ids2[2],NULL);
    }

    printf("%d\n", serial);
    pthread_kill(ids2[serial], SIGUSR1);
    ////
    return NULL;
}

int main()
{
    for (int i = 0; i < N; ++i) {
        pthread_create(&ids2[i], NULL, func2, NULL);
    }
    for (int i = 0; i < N; ++i) {
        pthread_create(&ids[i], NULL, func, (void*) (intptr_t) i);
    }


    /* INSERT YOUR CODE HERE */

    pthread_join(ids[0], NULL);
    return 0;
}
