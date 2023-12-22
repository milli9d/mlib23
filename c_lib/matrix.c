#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "matrix.h"

#include "logging.h"
LOG_TAG(MATRIX);

/**
 * @brief Initialize a new matrix context
 * @param rows 
 * @param cols 
 * @return 
 */
matrix_s* init_matrix(ssize_t rows, ssize_t cols)
{
    if(rows == 0u || cols == 0u) {
        LOG_ERR("invalid dimensions");
        return NULL;
    }

    /* allocate memory for matrix context */
    matrix_s* out = (matrix_s*) calloc(sizeof(matrix_s), 1u);

    /* */
    out->rows = rows;
    out->cols = cols;

    /* allocate memory for matrix */
    out->_data = (uint32_t*) calloc(sizeof(uint32_t), rows * cols);

    return out;
}

/**
 * @brief Fill the matrix with random values
 * @param matrix 
 */
void fill_random(matrix_s* matrix)
{
    if(matrix == NULL) {
        LOG_ERR("invalid matrix pointer");
        return;
    }

    srand(time(0u));

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->_data[get_idx_col_order(i, j, matrix)] = (i * matrix->rows) + j;
        }
    }
}

/**
 * @brief Pretty print out the matrix
 * @param matrix 
 */
void print_matrix(const matrix_s* matrix)
{
    /* sanity checks */
    if (matrix == NULL) {
        LOG_ERR("invalid matrix pointer");
        return;
    }

    /* print out matrix row and cols */
    for (int i = 0; i < matrix->rows; i++) {
        printf("[");
        for (int j = 0; j < matrix->cols; j++) { 
            printf(" %3d ", matrix->_data[get_idx_col_order(i, j, matrix)]);
        }
        printf("]\n");
    }
}

/**
 * @brief De-initialize matrix
 * @param matrix 
 */
void deinit_matrix(matrix_s* matrix)
{
    /* sanity checks */
    if (matrix == NULL) {
        LOG_ERR("invalid matrix pointer");
        return;
    }

    /* if matrix data , then free data elements */
    if (matrix->_data != NULL) {
        free(matrix->_data);
    }

    /* free matrix context structure */
    free(matrix);
    matrix = NULL;
}