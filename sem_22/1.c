#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t *id;

void *func(void *arg) {
    int n = *((int *)arg);
    if (n) {
        pthread_join(id[n - 1], NULL);
    }
    printf("%d\n", n);
    pthread_exit(arg);

}

int main() {
    int N = 10;

    id = calloc(N, sizeof(*id));
    int num[N];

    for (int i = 0; i < N; ++i) {
        num[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        pthread_create(&id[i], NULL, func, &num[i]);
    }
    pthread_join(id[N-1], NULL);

    free(id);

    return 0;
}
