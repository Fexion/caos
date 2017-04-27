#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    --argc;
    int script = open("script.c", O_WRONLY | O_TRUNC | O_CREAT, 0777);
    FILE * file = fdopen(script, "w");


    fprintf (file, "#include <math.h>\n#include <stdio.h>\nint main() {\
double x;scanf (\"%s\", &x);printf(\"%s\\n\",(%s));return 0;}",\
"%lf", "%.10g", argv[1]);

    fclose(file);
    close(script);

    execlp("/bin/sh","/bin/sh", "-c", "gcc script.c -lm && ./a.out", (char *)NULL);
    return 0;
}
