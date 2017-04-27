#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    double x0 = strtod(argv[1], NULL);

    for (int i = 2; i < argc; ++i) {
        double (*func)(double);

        void *handle;
        if ((handle = dlopen(argv[i], RTLD_NOW))) {
            ++i;
            func = dlsym(handle, argv[i]);
            if ((func)) {
                x0 = func(x0);
            }

            dlclose(handle);
        }
    }

    printf("%.10g\n", x0);
    return 0;
}
