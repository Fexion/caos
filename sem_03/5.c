#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

#define Max_stack_size 1001


struct Stack
{
    uint64_t elements[Max_stack_size];
    int size;
};

void push(struct Stack *stack, uint64_t element) {
    stack->elements[stack->size] = element;
    (stack->size) += 1;
}
uint64_t pop(struct Stack *stack) {
    (stack->size) -= 1;
    return stack->elements[stack->size];
}

int main() {
    struct Stack stack;
    stack.size = 0;

    uint64_t tmp = 0, first, second;

    int digit = '0';
    int upper = 'A' - 10;
    int lower = 'a' - 10 - ('Z' - 'A' + 1);

    char mode = 0;



    int f;
    while ((f = getchar_unlocked()) != EOF) {
        if (isspace(f)) {
            if (mode) {
                mode = 0;
                push(&stack, tmp);
            }
            tmp = 0;
        } else if (isalpha(f)){
            mode = 1;
            if (isupper(f)) {
                tmp |= (1ULL<<(f - upper));
            } else {
                tmp |= (1ULL<<(f - lower));
            }
        } else if (isdigit(f)) {
            mode = 1;
            tmp |= (1ULL<<(f - digit));
        } else if (f == '#'){
            mode = 1;
        } else {
            if (f == '|') {
                first = pop(&stack);
                second = pop(&stack);
                push(&stack, first|second);
            } else if (f == '~') {
                first = pop(&stack);
                push(&stack, ~first);
            } else if (f == '^') {
                first = pop(&stack);
                second = pop(&stack);
                push(&stack, first^second);

            } else if (f == '&') {
                first = pop(&stack);
                second = pop(&stack);
                push(&stack, first&second);

            }
        }
    }
    uint64_t ans = stack.elements[stack.size - 1];
    char t = 1;
    for (int i = 0; i < 62; ++i) {
        if (i < 10 && ans & 1ULL<<i) {
            printf("%d", i);
            t = 0;
        } else if (i < 36 && ans & 1ULL<<i) {
            printf ("%c", i + upper);
            t = 0;
        } else if (ans & 1ULL<<i) {
            printf ("%c", i + lower);
            t = 0;
        }
    }
    if (t) {
        printf ("#");
    }
    printf ("\n");
    return 0;
}
