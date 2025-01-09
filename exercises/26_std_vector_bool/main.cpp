#include "../exercise.h"
#include <iostream>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true);// Initialize 100 elements to true
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    // NOTICE: Platform dependent size
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;

    // Typically sizeof(std::vector<bool>) is platform-dependent. On many platforms, it might be 24 bytes.
    // Change 24 to the correct size if needed for your specific platform; common sizes could be 16, 24, or 32.
    ASSERT(sizeof(vec) == 24, "Fill in the correct value.");// Adjust according to platform (24 or 16)

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`");// Initially true
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`");// Now false
        // THINK: WHAT and WHY?
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");// Also false
    }

    return 0;
}
