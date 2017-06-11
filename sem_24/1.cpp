#include <stdio.h>
#include <thread>
#include <mutex>
#include <stdlib.h>

const int N = 3;
const int iter = 1000000;

volatile double elements[N];

std::mutex m;

void func(int num, int plus, int minus) {
    int next = (num + 1) % N;
    for (int i = 0; i < iter; ++i) {
        // Начало критической секции
        std::lock_guard<std::mutex> lock(m);
        elements[num] += plus;
        elements[next] -= minus;
    }
    return;
}


int main() {
    std::thread threads[N];

    threads[0] = std::thread(func, 0, 80, 90);
    threads[1] = std::thread(func, 1, 100, 110);
    threads[2] = std::thread(func, 2, 120, 130);

    for (int i = 0; i < N; ++i) {
        threads[i].join();
    }

    for (int i = 0; i < N; ++i) {
        printf("%.10g\n", elements[i]);
    }

    return 0;
}
