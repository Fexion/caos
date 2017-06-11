#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sched.h>
#include <unistd.h>
#include <stdatomic.h>


struct Item
{
    struct Item *next;
    long long value;
};

const int N = 100;
const int iter = 1000;

pthread_t *id;
struct Item *_Atomic head;

void *func(void *arg) {
    int n = *((int *)arg);
    for (int i = 0; i < iter; ++i) {
        struct Item *new_el = calloc(1, sizeof(*new_el));
        new_el -> next = atomic_exchange(&head, new_el); //prev_val at_ex(obj, desired)
        new_el -> value = n * iter + i;
        sched_yield();

    }
    pthread_exit(arg);
}


int main() {
    id = calloc(N, sizeof(*id));

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, sysconf(_SC_THREAD_STACK_MIN));
    int num[N];

    for (int i = 0; i < N; ++i) {
        num[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        pthread_create(&id[i], &attr, func, &num[i]);
    }
    for (int i = 0; i < N; ++i) {
        pthread_join(id[i], NULL);
    }
    free(id);


    struct Item *print = head;
    while (print) {

        printf("%lld\n", print -> value);
        print = print->next;
        free(head);
        head = print;
    }

    return 0;
}
