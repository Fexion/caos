#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t *ids;
int N;
int *pipes;

void *
thread_func(void *ptr)
{
    int n = *((int *) ptr);
    int32_t tmp = 0;
    int32_t next_thread = 0;

    while (1) {
        read(pipes[2 * n], &tmp, sizeof(tmp));
        if (scanf("%d", &next_thread) != 1) {
            next_thread = (n + 1) % N;
            write(
                pipes[2 * next_thread + 1], &next_thread, sizeof(next_thread));
            break;
        }

        printf("%d %d\n", n, next_thread);
        fflush(stdout);

        fflush(stdout);
        next_thread %= N;
        if (next_thread < 0) {
            next_thread += N;
        }
        fflush(stdout);
        write(pipes[2 * next_thread + 1], &next_thread, sizeof(next_thread));
    }

    return NULL;
};

int
main(int argc, char *argv[])
{
    char *pEnd;
    N = strtol(argv[1], &pEnd, 10);

    ids = calloc(N, sizeof(*ids));
    pipes = calloc(2 * N, sizeof(*pipes));
    int *nums = calloc(N, sizeof(*nums));
    for (int i = 0; i < N; ++i) {
        nums[i] = i;
        pipe(&(pipes[2 * i]));
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, sysconf(_SC_THREAD_STACK_MIN));
    for (int i = 0; i < N; ++i) {
        pthread_create(&ids[i], &attr, thread_func, &nums[i]);
    }

    int tmp = 0;
    write(pipes[1], &tmp, sizeof(tmp));
    for (int i = 0; i < N; ++i) {
        pthread_join(ids[i], NULL);
    }

    free(ids);
    free(pipes);
    free(nums);
    for (int i = 0; i < N; ++i) {
        close(pipes[2 * i]);
        close(pipes[2 * i + 1]);
    }

    return 0;
}
