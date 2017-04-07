#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int mysys(const char *str) {
    pid_t pid;
    int status;
    if ((pid = fork()) == -1) {
        return -1;
    } else if (pid == 0) {
        execlp("/bin/sh","/bin/sh", "-c", str, (char *)NULL);
        _exit(-1);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        return 1024 + WTERMSIG(status);
    }

    return -1;
}
