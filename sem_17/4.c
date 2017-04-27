#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int script = open("script.py", O_WRONLY | O_TRUNC | O_CREAT, 0777);
    FILE * file = fdopen(script, "w");
    fprintf (file, "#! /usr/bin/python\nprint(%s", argv[1]);
    for (int i = 2; i < argc; ++i) {
        fprintf(file, " * %s", argv[i]);
    }
    fprintf(file, ")");

    fclose(file);
    

    execlp("./script.py", "script.py", (char *)NULL);
    return 0;
}
