// A question I saw on HackerRank.

// Given a list of positive and distinct integers, count the number of pairs
// such that the first element is less than the second element, and the XOR of
// the two elements is larger than the AND of the two elements.

#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

uint64_t solution(const std::vector<uint32_t> nums) {
    std::array<uint32_t, 32> leading_zero_count;
    leading_zero_count.fill(0);

    for (uint32_t i = 0; i < nums.size(); i += 1) {
        leading_zero_count[std::countl_zero(nums[i])] += 1;
    }

    uint64_t result = 0;

    for (uint32_t i = 0; i < 32; i += 1) {
        for (uint32_t j = i + 1; j < 32; j += 1) {
            result += leading_zero_count[i] * leading_zero_count[j];
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    std::vector<uint32_t> nums(argc - 1, 0);

    for (uint32_t i = 1; i < static_cast<uint32_t>(argc); i += 1) {
        nums[i - 1] = std::stoi(argv[i]);
    }

    std::cout << "result: " << solution(nums) << std::endl;

    return 0;
}
