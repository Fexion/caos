#include <stdint.h>
#include <stdio.h>

uint32_t sub(int32_t greatest, int32_t latest)
{
    if ((greatest ^ latest) > 0) {
        return greatest - latest;
    }
    return (uint32_t)greatest - latest;
}

int main()
{
    uint32_t max = 0, tmp_max;
    int32_t current, previous_min, previous;
    scanf("%d", &previous);
    previous_min = previous;
    while (scanf("%d", &current) == 1) {
        if (previous > current) {
            tmp_max = sub(previous, previous_min);
            if (max < tmp_max) {
                max = tmp_max;
            }
            previous_min = current;
        }
        previous = current;
    }

    // final check
    tmp_max = sub(previous, previous_min);
    if (max < tmp_max) {
        max = tmp_max;
    }

    printf("%u\n", max);
    return 0;
}
