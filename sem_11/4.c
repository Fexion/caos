#include <stdio.h>
#include <inttypes.h>

extern char writechar();
extern void flush();

int main() {
    int32_t a;
    while ((a = getchar()) != EOF) {
        writechar(a);
    }

    flush();
    return 0;
}
