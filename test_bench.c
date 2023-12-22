#include <stdio.h>

#include "matrix.h"

int main()
{
    matrix_s* test = init_matrix(10u, 10u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(10u, 1u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(1u, 10u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(0u, 10u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(30u, 0u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(0u, 0u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    test = init_matrix(1u, 30u);
    fill_random(test);
    print_matrix(test);
    deinit_matrix(test);

    return 0;
}