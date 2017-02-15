#include <stdio.h>
#include <stdlib.h>

typedef struct El
{
    struct El *next;
    int value;
    int count;
} El;

int main() {
    int inp;
    El *first;
    El *cur;
    first = calloc(1, sizeof(*(first)));
    char f = 1;

    while (scanf("%d", &inp) != EOF) {
        if (f) {
            first -> value = inp;
            first -> count = 1;
            first -> next = NULL;
            f = 0;
        } else {
            cur = first;
            char f_2 = 1;
            while (cur) {
                if (cur -> value == inp) {
                    ++(cur -> count);
                    f_2 = 0;
                }
                cur = cur -> next;
            }

            if (f_2) {
                cur  = calloc(1, sizeof(*(cur)));
                cur -> next = first;
                cur -> value = inp;
                cur -> count = 1;
                first = cur;
            }
        }
    }
    while (first) {
        for (int i = 0; i < first  -> count; ++i) {
            printf("%d\n", first -> value);
        }
        cur = first -> next;
        free(first);
        first = cur;
    }


    return 0;
}
