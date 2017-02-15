#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
} Node;

void printing(Node *nd) {
    if (nd -> right) {
        printing(nd -> right);
        printf("%d ", nd -> value);
    } else {
        printf("%d ", nd -> value);
    }
    if (nd -> left) {
        printing(nd -> left);
    }
    free(nd);
}

void inserting(Node *nd, int value) {
    if (value > nd -> value) {
        if (nd -> right) {
            inserting(nd -> right, value);
        } else {
            nd -> right = calloc(1, sizeof(*(nd -> right)));
            nd -> right -> value = value;
            nd -> right -> left = NULL;
            nd -> right -> right = NULL;
        }
    } else if (value < nd -> value) {
        if (nd -> left) {
            inserting(nd -> left, value);
        } else {
            nd -> left = calloc(1, sizeof(*(nd -> left)));
            nd -> left -> value = value;
            nd -> left -> left = NULL;
            nd -> left -> right = NULL;
        }
    }
}

int main() {
    int inp;
    Node *root;
    root = calloc(1, sizeof(*root));
    root -> value = 0;
    root -> left = NULL;
    root -> right = NULL;
    char f = 0;
    while (scanf("%d", &inp) != EOF) {
        if (inp == 0) {
            if (root -> right) {
                printing(root -> right);
                root -> right = NULL;
            }
            if (root -> left) {
                printing(root -> left);
                root -> left = NULL;
            }
            printf("0 ");
            f = 0;
        } else {
            f = 1;
            inserting(root, inp);
        }
    }
    if (f) {
        if (root -> right) {
            printing(root -> right);
            root -> right = NULL;
        }
        if (root -> left) {
            printing(root -> left);
            root -> left = NULL;
        }
        printf("0 ");
        f = 0;
    }
    printf("\n");
    free(root);
    return 0;
}
