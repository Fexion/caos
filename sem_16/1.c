#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t son_Pid, grandson_Pid;
    son_Pid = fork();
    if (son_Pid == 0) {
        grandson_Pid = fork();
        if (grandson_Pid == 0) {
            printf("3 ");
        }else {
            wait(&grandson_Pid);
            printf("2 ");
        }
    }else {
        wait(&son_Pid);
        printf("1\n");
    }
    return 0;
}
