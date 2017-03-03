#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define N_b 4096

struct FileContent
{
    ssize_t size;
    char *data;//
};
struct FileContent read_file(int fd) {
    struct FileContent content;
    content.size = 0;
    char *tmp;//

    tmp = calloc(1, sizeof(*tmp));//

    if (tmp) {
        content.data = tmp;
    } else {
        content.data = NULL;
        content.size = -1;

        return content;
    }
    content.data[0] = '\0';
    char a[N_b];

    ssize_t rflag = 1;
    int read_size;
    int new_size;

    while (rflag > 0) {
        rflag = read(fd, a, N_b);
        read_size = rflag;

        if (rflag == -1) {
            free(content.data);
            content.data = NULL;
            content.size = -1;
            return content;
        } else if (read_size) {
            new_size = content.size + read_size;
            tmp = realloc(content.data, new_size + sizeof(*tmp));
            if (tmp) {
                content.data = tmp;
            } else {
                free(content.data);
                content.data = NULL;

                content.size = -1;

                return content;
            }
            memcpy(content.data + content.size, a, read_size);
            content.data[new_size] = '\0';
            content.size = new_size;
        }

    }


    return content;

}
