#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include <inttypes.h>
#include <mutex>
#include <iostream>
#include <vector>
#include <future>

char is_prime(uint64_t num) {
    if (num < 2) {
        return 0;
    }
    for (uint64_t i = 2; i*i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}



void func(uint64_t low, uint64_t high, uint32_t count,
    std::vector<std::promise<uint64_t>> &promises) {
    uint32_t cnt = 0;
    uint64_t i = low;
    for (; i < high && cnt < count; ++i) {
        if (is_prime(i)) {
            promises[cnt].set_value(i);
            ++cnt;
        }
    }
    if (cnt < count) {
        promises[cnt].set_value(high);
    }

}


int main() {
    uint64_t low, high;
    uint32_t count;

    std::cin >> low >> high >> count;

    std::vector<std::promise<uint64_t>> promises;

    std::vector<std::future<uint64_t>> futures;
    for (uint32_t i = 0; i < count; ++i) {
        promises.push_back(std::promise<uint64_t>());
        futures.push_back(promises[i].get_future());
    }
    std::thread thread1(func, low, high, count, std::ref(promises));

    uint64_t cur_prime = 0;
    for (uint32_t i = 0; i < count && cur_prime != high; ++i) {
        futures[i].wait();
        cur_prime = futures[i].get();
        std::cout << cur_prime << std::endl;
    }
    thread1.join();
    return 0;
}
