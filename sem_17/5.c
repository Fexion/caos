#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

    execlp("ls", "ls", "-l","-l", (char *)NULL);

    return 0;
}
