#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <inttypes.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

volatile uint64_t prime_num;
volatile uint64_t base;
volatile uint64_t count;

pthread_t id;

void *func(void *arg) {
    while (1) {
        char is_prime = 1;
        for (uint64_t i = 2; i*i <= base; ++i) {
            if (base % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            pthread_mutex_lock(&m);
            
            prime_num = base;

            pthread_cond_signal(&c);
            pthread_mutex_unlock(&m);
        }
        ++base;
    }
    pthread_exit(arg);
}


int main() {
    scanf("%"SCNu64 " %"SCNu64, &base, &count);
    pthread_create(&id, NULL, func, NULL);

    uint64_t last_prime;

    for(uint64_t primes = 0; primes < count; ++primes) {
        pthread_mutex_lock(&m);
        pthread_cond_wait(&c, &m);

        last_prime = prime_num;

        pthread_mutex_unlock(&m);

        printf("%"PRIu64"\n", last_prime);
    }

    return 0;
}
