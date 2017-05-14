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
    int script = open("script.c", O_RDWR | O_TRUNC | O_CREAT, 0700);
    FILE * file = fdopen(script, "w");

    double left, right;
    int n;

    sscanf(argv[1], "%lf", &left);
    sscanf(argv[2], "%lf", &right);
    sscanf(argv[3], "%d", &n);


    fprintf (file, "#include <math.h> \n double qwe(double x) { return (%s);}", argv[4]);

    fclose(file);


    if (!fork()) {
        execlp("gcc","gcc", "-lm","-shared", "-fPIC", "-DPIC", "-ldl","-o", "prog.so", "script.c", (char *)NULL);
        _exit(0);
    }
    wait(NULL);

    void *handle = dlopen("./prog.so", RTLD_NOW);
    double (*func)(double);
    func = dlsym(handle, "qwe");

    double dx = (right - left) / n;

    double s = 0;
    for (int i = 0; i < n; ++i) {

        s += (*func)(left + i*dx) * dx;

    }

    printf("%.10g\n", s);
    dlclose(handle);
    return 0;
}
