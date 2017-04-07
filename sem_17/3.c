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
    return !((exec_cmd(argv[1]) || exec_cmd(argv[2])) && exec_cmd(argv[3]));
}
