#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char const *argv[]) {
    --argc;
    double (*func)(double);
    void *handle = dlopen("/lib/libm.so.6", RTLD_NOW);
    *(void **)(&func)  = dlsym(handle, argv[1]);

    double inp;
    while ((scanf("%lf", &inp)) != EOF) {
        printf("%.10g\n", (*func)(inp));
    }

    dlclose(handle);
    return 0;
}
