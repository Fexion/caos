#include <iostream>
#include <future>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>

std::vector<int> func(unsigned int num, unsigned int iters) {
    int circle = 0;
    int total = 0;
    double mid = RAND_MAX/2.0;

    for (unsigned int i = 0; i < iters; ++i) {
        ++total;
        int64_t a = rand_r(&num) - mid;
        int64_t b = rand_r(&num) - mid;
        //std::cout << a << "   " << b << "\n";
        if (a*a + b*b <= mid*mid) {
            ++circle;
        }
    }

    return {circle, total};


}

int main(int argc, char* argv[]) {
    --argc;
    unsigned int n, iters;
    sscanf(argv[1], "%u", &n);
    sscanf(argv[2], "%u", &iters);

    std::vector<std::future<std::vector<int>>> futures;

    for (unsigned int i = 0; i < n; ++i) {
        futures.push_back(std::async(func, i, iters));
    }
    std::vector<int> res;
    double circle = 0, total = 0;
    for (unsigned int i = 0; i < n; ++i) {
        res = futures[i].get();
        circle += res[0];
        total += res[1];
    }
    double ans = (4.0 * circle) / total;
    printf("%.6g \n", ans);

    return 0;
}
