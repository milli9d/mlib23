/**
 * @file decompress.cpp
 *
 * In this exercise, you're going to decompress a compressed string.
 *
 * Your input is a compressed string of the format number[string] and the decompressed output form should be the string
 * written number times.
 *
 * For example: The input
 *      3[abc]4[ab]c
 *
 * Would be output as
 *      abcabcabcababababc
 *
 * Other rules
 *
 *  1. Number can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa
 *  2. One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab
 *  3. Characters allowed as input include digits, small English letters and brackets [ ].
 *  4. Digits are only to represent amount of repetitions.
 *  5. Letters are just letters.
 *  6. Brackets are only part of syntax of writing repeated substring.
 *  7. Input is always valid, so no need to check its validity.
 *
 * Learning objectives
 *
 *  This question gives you the chance to practice with strings, recursion, algorithm, compilers, automata, and loops.
 *  It’s also an opportunity to work on coding with better efficiency.
 */
#include <iostream>
#include <cstdio>
#include <cstring>

#include "decompress.hpp"

namespace g_app {

/**
 * @brief
 * @param str
 * @param str_len
 */
decompress::decompress(const char* str, size_t str_len) : _str(str), _str_len(str_len)
{
    printf("\e[35mINPUT : \e[0m %s Length : %ld\n", _str, _str_len);
    // run();

    print_recursive(_str, _str + _str_len);
}

void decompress::print_recursive(const char* _begin, const char* _end)
{
    if (_begin == nullptr || _end == nullptr || *_begin == '\0' || _begin == _end) {
        return;
    }

    /* place 2 pointers on both ends and traverse till you find [] */
    const char* sub_begin = _begin;
    while (*sub_begin != '\0' && *sub_begin != '[') {
        sub_begin++;
    }
    if (sub_begin) {
        sub_begin++;
    }

    const char* sub_end = _end;
    while (sub_end != _begin && *sub_end != ']') {
        sub_end--;
    }
    if (sub_end) {
        sub_end--;
    }

    print_recursive(sub_begin, sub_end);

    size_t count = _end - _begin;
    printf("%s\n", std::string(_begin, count).c_str());
}

/**
 * @brief
 */
void decompress::run()
{
    /* if string is invalid, throw exception */
    if (_str == NULL || _str_len != std::strlen(_str)) {
        throw std::invalid_argument("Invalid string");
    }

    if (*_str == '\0') {
        printf("ERROR: Empty string!\n");
        return;
    }

    /* if character then find de-limiter [number or string end] */
    const char* traveler = &_str[0u];
    const char* marker = nullptr;

    printf("\e[34mOUTPUT : \e[0m");

    /* traverse through the string */
    while (*traveler != '\0') {
        /* if digit then extract whole number */
        uint32_t num = 0u;
        while (std::isdigit(*traveler)) {
            num = (num * 10u);
            num += std::atoi(traveler);
            traveler++;
        }

        /* find end of string */
        marker = traveler;
        int count = 0u;
        while (std::isalpha(*marker)) {
            count++;
            marker++;
        }

        /* if no number */
        if (!num) {
            num = 1u;
        }

        for (int i = 0; i < num; i++) {
            printf("%s", std::string(traveler, count).c_str());
        }

        traveler = marker;
    }

    printf("\n");
}

} // namespace g_app
