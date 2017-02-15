#include <stdio.h>
#include "2.h"

int main() {
    char a[]="///zzq/w/e/q//we//asd/";
    normalize_path(a);
    printf("%s\n", a);
    return 0;
}
