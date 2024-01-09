#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * @brief print out binary representation of number
 * @param val
 */
void print_binary(const uint32_t& _val) {
    std::string out{};
    uint32_t val = _val;
    for (int i = 0; i < 32u; i++) {
        out.push_back(((val & 0x01u) + '0'));
        val = val / 2u;
    }
    std::reverse(out.begin(), out.end());
    std::cout << "0b" << out << std::endl;
}

/**
 * @brief Reverse all bits in a number
 * @param num
 * @return
 */
uint32_t inline reverse_bits(const uint32_t& num) {
    uint32_t out = (num & 0x0000FFFFu) << 16u | (num & 0xFFFF0000u) >> 16u;
    out = (out & 0x00FF00FFu) << 8u | (out & 0xFF00FF00u) >> 8u;
    out = (out & 0x0F0F0F0Fu) << 4u | (out & 0xF0F0F0F0u) >> 4u;
    out = (out & 0x33333333u) << 2u | (out & 0xccccccccu) >> 2u;
    out = (out & 0x55555555u) << 1u | (out & 0xaaaaaaaau) >> 1u;
    return out;
}

/**
 * @brief Reverse endianess [byte]
 * @param num
 * @return
 */
uint32_t inline change_endianess(const uint32_t& num) {
    uint32_t out = (num & 0x0000FFFFu) << 16u | (num & 0xFFFF0000u) >> 16u;
    out = (num & 0x00FF00FFu) << 8u | (num & 0xFF00FF00u) >> 8u;
    return out;
}

/**
 * @brief Count number of set bits
 * @param n
 * @return
 */
inline uint32_t count_set_bits(uint32_t n) {
    uint32_t count = 0u;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main(int argc, char** argv) {
    print_binary(3u);
    print_binary(reverse_bits(3u));
    uint32_t out = change_endianess(change_endianess(3u));
    print_binary(out);

    std::cout << count_set_bits(15u) << std::endl;
    std::cout << count_set_bits(reverse_bits(15u)) << std::endl;
}
