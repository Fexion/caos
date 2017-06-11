#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <inttypes.h>

pthread_t  *id;

void *func(void *arg) {
    int64_t sum = 0;
    int64_t inp;

    while ((scanf("%"SCNd64, &inp)) != EOF) {
        sum+=inp;
        sched_yield();
    }
    return (void *)sum;

}

int main(int argc, char const *argv[]) {
    --argc;
    int64_t N;
    sscanf(argv[1], "%"SCNd64, &N);

    id = calloc(N, sizeof(*id));

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, sysconf(_SC_THREAD_STACK_MIN));

    for (int64_t i = 0; i < N; ++i) {
        pthread_create(&id[i], &attr, func, NULL);
    }

    int64_t sum = 0;
    void *partial_sum;
    for (int64_t i = 0; i < N; ++i) {
        pthread_join(id[i], &partial_sum);
        sum += (int64_t)partial_sum;
    }
    free(id);

    printf("%"PRId64"\n", sum);

    return 0;
}
