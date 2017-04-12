#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <inttypes.h>

void making_some_forks(uint64_t i, uint64_t N) {
    if (i > N) {
        return;
    }
    printf(" %"PRIu64, i);
    fflush(stdout);

    if (!fork()) {
        making_some_forks(i + 1, N);
        _exit(0);
    }
    wait(NULL);

}


int main() {
    uint64_t N;
    scanf("%"SCNu64, &N);
    printf("1");
    fflush(stdout);

    making_some_forks(2, N);
    wait(NULL);
    printf("\n");
    return 0;
}
