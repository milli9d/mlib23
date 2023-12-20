#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

static inline void print_vector(std::vector<int>& arr) {
    for (int i: arr) { std::cout << i << " "; }
    std::cout << std::endl;
}

static int32_t binary_search(std::vector<int>& arr, int val) {
    std::sort(arr.begin(), arr.end());

    ssize_t left = 0u;
    ssize_t right = arr.size();

    while (left <= right) {
        ssize_t middle = (left + right) / 2u;

        if (val > arr[middle]) {
            left = middle + 1;
        } else if (val < arr[middle]) {
            right = middle - 1;
        } else if (arr[middle] == val) {
            printf("Found %d at idx %ld\n", val, middle);
            return middle;
        }
    }

    return -1;
}

int main() {

    std::cout << "===================== binary search =====================" << std::endl;
    srand(time(nullptr));

    std::vector<int> arr(50u);
    for (int i = 0; i < 50u; i++) { arr.push_back(rand() % 13u); }

    print_vector(arr);

    binary_search(arr, 10u);
    binary_search(arr, 8u);
    binary_search(arr, 9u);

    print_vector(arr);

    std::cout << "=================== binary search done! ==================" << std::endl;

    return 0;
}
