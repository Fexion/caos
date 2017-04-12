#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

const int buff_size = 8;

int main() {
    pid_t first_child_Pid, second_child_Pid, third_child_Pid;
    int num = 0;
    first_child_Pid = fork();

    if (first_child_Pid == 0) {
        num = 1;
    }else {
        second_child_Pid = fork();
    }
    if (num == 0) {
        if (second_child_Pid == 0) {
            num = 2;
        } else {
            third_child_Pid = fork();
        }
    }
    if (num == 0) {
        if (third_child_Pid == 0) {
            num = 3;
        }
    }


    if (num == 0) {
        wait(NULL);
        wait(NULL);
        wait(NULL);
    } else {
        char buff[buff_size];
        int32_t digit;

        read(0, &buff, buff_size);
        sscanf(buff, "%d", &digit);
        printf("%d %d\n", num, digit * digit);
    }
    return 0;
}
