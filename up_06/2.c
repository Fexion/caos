#include "2.h"

int main() {
    const char qwe[] = "rwxrwxrwx";
    printf("%d\n", parse_rwx_permissions(&(qwe[0])));
    return 0;
}
