#include "../exercise.h"
#include <cmath>
// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template<typename T>
T plus(T a, T b) {
    return a + b;
}
int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // 使用较小的误差范围来比较浮点数
    ASSERT(std::abs(plus(1.25f, 2.5f) - 3.75f) < 1e-6, "Plus two float");
    ASSERT(std::abs(plus(1.25, 2.5) - 3.75) < 1e-6, "Plus two double");

    // 使用误差范围来比较浮点数
    ASSERT(std::abs(plus(0.1, 0.2) - 0.3) < 1e-6, "How to make this pass?");

    return 0;
}
