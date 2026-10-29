#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    srand((unsigned int)time(NULL));

    int arr[SIZE];
    printf("Початковий масив:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50;
        printf("%d ", arr[i]);
    }
    printf("\n");

    long long prod_even_indexed = 1;
    for (int i = 0; i < SIZE; i += 2) {
        prod_even_indexed *= arr[i];
    }
    printf("Добуток елементів із парними індексами: %lld\n", prod_even_indexed);

    int min_idx = 0;
    int max_idx = 0;

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }

    int temp = arr[min_idx];
    arr[min_idx] = arr[max_idx];
    arr[max_idx] = temp;

    printf("Масив після перестановки мінімуму (індекс %d) і максимуму (індекс %d):\n", min_idx, max_idx);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
