#include <stdio.h>
#include <stdlib.h>

typedef struct ListEl
{
    struct ListEl *prev, *next;
    int el;
    int num;

} ListEl;


int main() {
    ListEl *head;
    head = NULL;
    ListEl *cur;
    int inp;
    while (scanf("%d", &inp) != EOF) {

        cur = head;
        char f = 1;
        if (!head) {
            head =  calloc(1, sizeof(*head));
            head -> el = inp;
            head -> num = 1;
            head -> prev = NULL;
            head -> next = NULL;
            continue;
        }
        while (cur) {
            if (cur -> el == inp) {
                if (cur -> next) {
                    if (cur -> prev) {
                        cur -> next -> prev = cur -> prev;
                        cur -> prev -> next = cur -> next;

                        head -> prev =  cur;
                        cur -> prev = NULL;
                        cur -> next = head;
                        (cur -> num)++;
                        head = cur;
                        f = 0;
                        break;

                    } else {
                        (cur -> num)++;
                        f = 0;
                        break;
                    }

                } else {
                    if (cur -> prev) {
                        cur -> prev -> next = NULL;

                        head -> prev =  cur;
                        cur -> prev = NULL;
                        cur -> next = head;
                        (cur -> num)++;
                        head = cur;
                        f = 0;
                        break;
                    } else {
                        cur -> num += 1;
                        f = 0;
                        break;
                    }
                }


            }
            cur = cur -> next;
        }
        if (f) {
            head -> prev =  calloc(1, sizeof(*(head -> prev)));
            head -> prev -> next = head;
            head = head -> prev;
            head -> num = 1;
            head -> el = inp;
            head -> prev = NULL;
        }

    }
    if (!head) {
        return 0;
    }
    while (head -> next) {
        head = head -> next;
    }
    cur = head;
    while (cur) {
        printf("%d %d\n", cur -> el, cur -> num);
        cur = head -> prev;
        free(head);
        head = cur;
    }

    return 0;
}
