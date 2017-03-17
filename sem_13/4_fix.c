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

    lseek(file, 4 * 3 * node_idx, SEEK_SET); //not magic enough, 4 bytes per int * 3 int

    //if (read(file, &key, 4) == -1)
    //if (read(file, &left_idx, 4) == -1)
    //if (read(file, &right_idx, 4) == -1)

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
