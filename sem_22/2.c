#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *func(void *arg) {
    int inp;
    if ((scanf("%d\n", &inp) != EOF)) {
        pthread_t child;
        pthread_create(&child, NULL, func, NULL);
        pthread_join(child, NULL);
        printf ("%d\n", inp);
    }
    pthread_exit(arg);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, func, NULL);
    pthread_join(thread, NULL);

    return 0;
}
