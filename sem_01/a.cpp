#include <iostream>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    int64_t a1, b1, a2, b2, diff, sum = 0;
    while (std::cin >> a1 >> b1 >> a2 >> b2) {
        diff =std::min(b1, b2) - std::max(a1, a2);
        if (diff >=0) {
            sum += diff;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
