#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main(void) {
    srand((unsigned int)time(NULL));
    int matrix[ROWS][COLS];

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            matrix[r][c] = rand() % 100;
        }
    }

    printf("Початкова матриця:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%6d", matrix[r][c]);
        }
        printf("\n");
    }

    printf("\nПошук сідлових точок:\n");
    int found_saddle = 0;

    for (int r = 0; r < ROWS; r++) {
        int min_in_row = matrix[r][0];
        for (int c = 1; c < COLS; c++) {
            if (matrix[r][c] < min_in_row) {
                min_in_row = matrix[r][c];
            }
        }

        for (int c = 0; c < COLS; c++) {
            if (matrix[r][c] == min_in_row) {
                int is_max_in_col = 1;

                for (int k = 0; k < ROWS; k++) {
                    if (matrix[k][c] > min_in_row) {
                        is_max_in_col = 0;
                        break;
                    }
                }

                if (is_max_in_col) {
                    printf("Знайдено сідлову точку: Значення = %d на позиції [%d][%d]\n", matrix[r][c], r, c);
                    found_saddle = 1;
                }
            }
        }
    }

    if (!found_saddle) {
        printf("Сідлових точок у даній матриці не знайдено.\n");
    }

    return 0;
}
