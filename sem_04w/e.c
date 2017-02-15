#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

int main() {
    int64_t num;
    int32_t ans[33], neg, r, size;
    while (scanf("%lld", &num) != EOF) {
        size = 0;
        if (num > 0) {
            neg = 1;
        } else if (num < 0){
            neg = -1;
            num = -num;
        } else {
            printf("0\n");
            continue;
        }

        while (num) {
            r = num % 3;
            num /= 3;

            if (r == 0 || r == 1) {
                ans[size++] = r;
            } else {
                ans[size++] = -1;
                ++num;
            }
        }
        for (int32_t i = size - 1; i >= 0; --i) {
            ans[i] *= neg;

            if (ans[i] == 0) {
                printf("0");
            } else if (ans[i] == 1) {
                printf("1");
            } else if (ans[i] == -1) {
                printf("a");
            }
        }
        printf("\n");
    }


    return 0;
}
