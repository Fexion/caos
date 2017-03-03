#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void printing_some_tree(int file, int32_t node_idx) {
    int32_t key;
    int32_t right_idx;
    int32_t left_idx;

    lseek(file, 4 * 3 * node_idx, SEEK_SET);

    //if (read(file, &key, 4) == -1)
    //if (read(file, &left_idx, 4) == -1)
    //if (read(file, &right_idx, 4) == -1)

    read(file, &key, 4);
    read(file, &left_idx, 4);
    read(file, &right_idx, 4);

    if (right_idx != 0) {
        printing_some_tree(file, right_idx);
    }
    printf("%d ", key);
    if (left_idx != 0) {
        printing_some_tree(file , left_idx);
    }
}

int main(int argc, char const *argv[]) {

    int file = open(argv[1], O_RDONLY);
    printing_some_tree(file, 0);
    printf("\n");

    close(file);

    return 0;
}
