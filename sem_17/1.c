#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    --argc;
    char command[512];
    sprintf(command,"%s < %s > %s",argv[1], argv[2], argv[3]);
    system(command);
    return 0;
}
