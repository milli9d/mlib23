#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <time.h>

typedef struct _matrix_s {
    ssize_t rows;
    ssize_t cols;
    uint32_t* _data;
} matrix_s;

/**
 * @brief Get idx for column order matrix entries
 * @param row 
 * @param col 
 * @param matrix 
 * @return 
 */
inline ssize_t get_idx_col_order(ssize_t row, ssize_t col, const matrix_s* matrix)
{
    return (row * matrix->cols) + (col);
}

/**
 * @brief Get idx for row order matrix entries
 * @param row 
 * @param col 
 * @param matrix 
 * @return 
 */
inline ssize_t get_idx_row_order(ssize_t row, ssize_t col, const matrix_s* matrix)
{
    return (col * matrix->rows) + (row);
}

/**
 * @brief 
 * @param rows 
 * @param cols 
 * @return 
 */
matrix_s* init_matrix(ssize_t rows, ssize_t cols);

/**
 * @brief 
 * @param matrix 
 */
void fill_random(matrix_s* matrix);

/**
 * @brief 
 * @param matrix 
 */
void print_matrix(const matrix_s* matrix);

void deinit_matrix(matrix_s* matrix);
