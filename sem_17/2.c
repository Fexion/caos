#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "2.h"

int main() {

    mysys("ls -la");
    return 0;
}
