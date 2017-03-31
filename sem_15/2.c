#include <stdio.h>
#include <inttypes.h>

int main() {
    char trash[1024];
    uint64_t start, end, total = 0;

    while((scanf("%lx-%lx", &start, &end) != EOF)) {
        total += (end - start);
        fgets(trash, sizeof(trash), stdin);
    }
    printf("%"PRIu64"\n",total );

    return 0;
}
