#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int exec_cmd(char const *cmd) {
    pid_t pid;
    int status;
    if (!(pid = fork())) {
        execlp(cmd, cmd, (char *)NULL);
        _exit(1);
    }
    waitpid(pid, &status, 0);
    return (WIFEXITED(status) && !(WEXITSTATUS(status)));
}

int main(int argc, char const *argv[]) {
    --argc;
    //cmd2 | (cmd3 || cmd4) >& file1
    int fds[2];
    pipe(fds);

    int file_d = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0660);

    if (!fork()) {
        dup2(fds[1], 1);

        close(fds[0]);
        close(fds[1]);
        close(file_d);

        exec_cmd(argv[2]);
        _exit(1);
    }

    if (!fork()) {
        dup2(fds[0], 0);

        dup2(file_d, 1); //stdout
        dup2(file_d, 2); //stderr
        
        close(fds[0]);
        close(fds[1]);
        close(file_d);
        if (!exec_cmd(argv[3])) {
            exec_cmd(argv[4]);
        }
        _exit(1);
    }
    close(fds[0]);
    close(fds[1]);
    close(file_d);

    wait(NULL);
    wait(NULL);

    return 0;
}
