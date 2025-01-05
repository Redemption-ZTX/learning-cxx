#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        // 检查请求的索引是否在缓存范围内
        if (i < 0 || i >= 128) {
            std::cerr << "Index out of bounds for cache size." << std::endl;
            return 0;// 或者抛出异常，根据需要处理
        }

        // 计算并缓存斐波那契数
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    fib.cache[0] = 0;
    fib.cache[1] = 1;
    fib.cached = 1;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
