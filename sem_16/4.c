#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <inttypes.h>

const int buff_size = 100;

void making_some_forks() {
    pid_t branch = fork();
    if (branch == -1) {
        return;
    }
    if (!branch) {
        char buff[buff_size];
        int digit;

        read(0, &buff, buff_size);
        sscanf(buff, "%d", &digit);

        making_some_forks();
        wait(NULL);
        printf(" %d", digit);
        _exit(0);
    }

}


int main() {
    making_some_forks();

    return 0;
}
