#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    if (i < 0 || i >= 16) {
        std::cerr << "Index out of bounds for cache size." << std::endl;
        return 0;
    }

    for (int c = cache.cached + 1; c <= i; ++c) {
        cache.cache[c] = cache.cache[c - 1] + cache.cache[c - 2];
    }
    cache.cached = std::max(cache.cached, i);
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>


        FibonacciCache fib = {{0}, 1};// 初始化缓存的第一个值
    fib.cache[0] = 0;
    fib.cache[1] = 1;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
