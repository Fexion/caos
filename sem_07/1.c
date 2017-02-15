#include <stdio.h>
#include <stdlib.h>

typedef struct ListEl
{
    int el;
    struct ListEl *prev;
} ListEl;

int main() {
    ListEl *last;
    ListEl *cur;
    last = calloc(1, sizeof(*last));
    last -> prev = NULL;
    while (scanf("%d", &(last -> el)) != EOF) {
        cur = malloc(sizeof(ListEl));
        cur -> prev = last;
        last = cur;
    }

    cur = last -> prev;
    free(last);
    while (cur) {
        printf("%d\n", cur -> el);
        last = cur;
        cur = cur -> prev;
        free(last);
    }
    return 0;
}
