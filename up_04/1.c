#include <stdint.h>
#include <stdio.h>

uint32_t A, B, C;
extern uint32_t
process(void);

int
main()
{
    scanf("%u %u %u", &A, &B, &C);
    uint32_t res = process();
    printf("%u\n", res);
    return 0;
}
