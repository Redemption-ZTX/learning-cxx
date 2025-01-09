#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>

// TODO: 将下列 `?` 替换为正确的值
int main(int argc, char **argv) {
    auto shared = std::make_shared<int>(10);
    std::shared_ptr<int> ptrs[]{shared, shared, shared};

    std::weak_ptr<int> observer = shared;
    ASSERT(observer.use_count() == 4, "");// 3 from ptrs + 1 from shared

    ptrs[0].reset();
    ASSERT(observer.use_count() == 3, "");// 2 from ptrs + 1 from shared

    ptrs[1] = nullptr;
    ASSERT(observer.use_count() == 2, "");// 1 from ptrs + 1 from shared

    ptrs[2] = std::make_shared<int>(*shared);
    ASSERT(observer.use_count() == 1, "");// Only shared

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    ASSERT(observer.use_count() == 3, "");// 2 from ptrs + 0 from shared after move

    std::ignore = std::move(ptrs[0]);
    ptrs[1] = std::move(ptrs[1]);
    ptrs[1] = std::move(ptrs[2]);
    ASSERT(observer.use_count() == 2, "");// 1 from ptrs[1] + 1 from shared

    shared = observer.lock();
    ASSERT(observer.use_count() == 2, "");// 1 from ptrs[1] + 1 from shared

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == 0, "");// All pointers are now nullptr

    shared = observer.lock();
    ASSERT(observer.use_count() == 0, "");// Locked shared_ptr is null

    return 0;
}
