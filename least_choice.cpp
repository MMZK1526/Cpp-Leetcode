#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <string>

// Given a string, find the lexically smallest string that can be formed by
// removing letters from the original string such that each distinct letters
// appears exactly once in the result.
//
// The string is consisted only of uppercase letters.

std::string solution(std::string str) {
    const int alphabet_count = 26;
    const size_t max = std::numeric_limits<size_t>::max();
    size_t length = str.length();
    int letter_count = 0;

    std::array<size_t, alphabet_count> small_index_map;
    small_index_map.fill(max);
    std::array<size_t, alphabet_count> large_index_map;
    large_index_map.fill(max);

    std::string result = "";

    for (size_t i = 0; i < length; i++) {
        if (small_index_map[str[i] - 'A'] == max) {
            small_index_map[str[i] - 'A'] = i;
            letter_count += 1;
        }
        large_index_map[str[i] - 'A'] = i;
    }

    while (letter_count > 0) {
        size_t cutoff_index = max;
        for (int i = 0; i < alphabet_count; i++) {
            cutoff_index = std::min(cutoff_index, large_index_map[i]);
        }

        for (int i = 0; i < alphabet_count; i++) {
            if (small_index_map[i] <= cutoff_index) {
                result += 'A' + i;
                letter_count -= 1;
                small_index_map[i] = max;
                large_index_map[i] = max;
                break;
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    std::cout << "result: " << solution(argv[1]) << std::endl;
    return 0;
}
