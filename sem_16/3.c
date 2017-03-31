#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <inttypes.h>

void making_some_forks(uint64_t i) {
    if (i == 1) {
        return;
    }
    if (!fork()) {
        making_some_forks(i - 1);
        _exit(0);
    }
    wait(NULL);
    printf(" %"PRIu64, i);
    fflush(stdout);

}


int main() {
    uint64_t N;
    scanf("%"SCNu64, &N);
    printf("1");
    fflush(stdout);
    
    making_some_forks(N);
    wait(NULL);
    printf("\n");
    return 0;
}
