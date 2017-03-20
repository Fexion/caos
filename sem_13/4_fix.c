#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};


void printing_some_tree(int file, int32_t node_idx) {
    struct Node nd;

    lseek(file, sizeof(int) * 3 * node_idx, SEEK_SET); //not magic enough, sizeof int * 3 int
    //about errors, caused by unused argc
    //here are my compile flags
    //"clang
    //--std=gnu11
    //-Werror -Wall -Wextra -O2
    //-fsanitize=address -fsanitize=leak -fsanitize=undefined 
    //-fno-sanitize-recover=undefined,integer -fstack-protector"


    //also, can u fix scores of rejected tasks, they are 50 instead of 100 & 40 instead of 90
    //and what about tasks with 20 score, is it OK for them? they were accepted from the first attempt



    read(file, &nd.key, 4);
    read(file, &nd.left_idx, 4);
    read(file, &nd.right_idx, 4);

    if (nd.right_idx != 0) {
        printing_some_tree(file, nd.right_idx);
    }
    printf("%d ", nd.key);
    if (nd.left_idx != 0) {
        printing_some_tree(file , nd.left_idx);
    }
}

int main(int argc, char const *argv[]) {
    //--argc;
    int file = open(argv[1], O_RDONLY);
    printing_some_tree(file, 0);
    printf("\n");

    close(file);

    return 0;
}
