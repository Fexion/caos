#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    --argc;
    int script = open("script.c", O_RDWR | O_TRUNC | O_CREAT, 0777);
    FILE * file = fdopen(script, "w");


    fprintf (file, "#include <math.h>\n#include <stdio.h>\nint main() {\
double x;scanf(\" %s\", &x); x = (%s);printf(\"%s\\n\", x);return 0;}",\
    "%lf",argv[1], "%.10g" );

    fclose(file);
    close(script);
    pid_t pid;

    if ((pid = fork())== 0) {
        execlp("gcc","gcc", "-lm", "script.c", "-o", "prog", (char *)NULL);
        _exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        execlp("./prog", "prog", (char *)NULL);
    }
    return 0;
}
