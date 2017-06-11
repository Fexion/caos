#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

const int N = 3;
const int iter = 1000000;

pthread_t *id;
volatile double elements[3];

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *func(void *arg) {
    int n = *((int *)arg);
    int next = (n + 1) % N;
    for (int i = 0; i < iter; ++i) {
        pthread_mutex_lock(&m);
        elements[n] += (n + 1) * 100;
        elements[next] -= ((n + 1) * 100 + 1);
        pthread_mutex_unlock(&m);
    }
    pthread_exit(arg);
}


int main() {
    id = calloc(N, sizeof(*id));
    int num[N];

    for (int i = 0; i < N; ++i) {
        num[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        pthread_create(&id[i], NULL, func, &num[i]);
    }
    for (int i = 0; i < N; ++i) {
        pthread_join(id[i], NULL);
    }
    for (int i = 0; i < N; ++i) {
        printf("%.10g\n", elements[i]);
    }

    free(id);

    return 0;
}
