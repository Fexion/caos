#include <stdio.h>
#include <inttypes.h>

extern int32_t A, B, C, D, R;
void process(void);

int main() {
    R = 0;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    process();
    printf("%d\n", R);
    return 0;
}
