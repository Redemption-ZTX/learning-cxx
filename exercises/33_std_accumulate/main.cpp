#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;// DataType is float
    int shape[]{1, 3, 224, 224};

    // Calculate the total number of elements
    int num_elements = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());

    // Calculate the total number of bytes
    int size = num_elements * sizeof(DataType);

    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
