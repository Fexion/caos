#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdatomic.h>
#include <unistd.h>
#include <sys/eventfd.h>
#include <math.h>
#include <sys/wait.h>
#include <signal.h>

count = strtol(argv[1], NULL, 10);

// НИТЬ
pthread_t *ids = calloc(count, sizeof (*ids));
pthread_create(&ids[i], NULL, thread_func, (void *) &nums[i]);
pthread_join(ids[id - 1], NULL);
free(ids);


printf("%d\n", id);
fflush(NULL);

sched_yield(); // см 22-3


// STACK
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_setstacksize(&attr, sysconf(_SC_THREAD_STACK_MIN));
pthread_create(&ids[i], &attr, thread_func, &sums[i]);


// SEMAPHORE
fds[0] = eventfd(1, EFD_SEMAPHORE); // открытый
fds[i] = eventfd(0, EFD_SEMAPHORE); // закрытый
wval = 1;
while (read(fds[id], &wval, sizeof(wval)) >= 0) {
    ...
    wval = 1;
    int next = ((numb % count) + count) % count;
    write(fds[next], &wval, sizeof(wval));
    wval = 1;
}

// MUTEX
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&m);
        ...
        pthread_mutex_unlock(&m);
// MULTIPLE
pthread_mutex_lock(&thr_info.m[min_ind]);
pthread_mutex_lock(&thr_info.m[max_ind]);
...
pthread_mutex_unlock(&thr_info.m[max_ind]);
pthread_mutex_unlock(&thr_info.m[min_ind]);

// ATOMIC
struct Item * _Atomic head;
p->next = atomic_exchange_explicit(&head, p, memory_order_release);

// CONDVAR
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_lock(&m);
...
pthread_cond_signal(&c);
pthread_mutex_unlock(&m);
----
pthread_mutex_lock(&m);
pthread_cond_wait(&c, &m);
...
pthread_mutex_unlock(&m);


//gcc -o file file.c -pthread
