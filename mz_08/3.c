#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <dlfcn.h>
#include <math.h>



int main(int argc, char const *argv[]) {
    --argc;
    int script = open("script.c", O_RDWR | O_TRUNC | O_CREAT, 0777);
    FILE * file = fdopen(script, "w");
    double left, right;
    int n;
    left = atof(argv[1]);
    right = atof(argv[2]);
    n = atoi(argv[3]);

    fprintf (file, "#include <math.h> \n double qwe(double x) {x = (%s); return x;}", argv[4]);

    fclose(file);
    close(script);
    pid_t pid;

    if ((pid = fork())== 0) {
        execlp("gcc","gcc", "-lm","-shared", "-fPIC", "-DPIC", "-ldl","-o", "prog.so", "script.c", (char *)NULL);
        _exit(0);
    }
    wait(NULL);

    void *handle = dlopen("./prog.so", RTLD_NOW);
    double (*func)(double);
    *(void **)(&func) = dlsym(handle, "qwe");

    double dx = (right - left) / n;

    double s = 0;
    for (int i = 0; i < n; ++i) {

        s += (*func)(left + i*dx) * dx;

    }

    printf("%.10g\n", s);
    dlclose(handle);
    return 0;
}
