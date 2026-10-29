#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    char str[BUFFER_SIZE];

    printf("Введіть рядок тексту: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int max_len = 0;
    int max_start_idx = 0;

    int current_len = 0;
    int current_start_idx = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }

        if (str[i] != ' ' && str[i] != '\t') {
            if (in_word == 0) {
                in_word = 1;
                current_start_idx = i;
                current_len = 1;
            } else {
                current_len++;
            }
        } else {
            if (in_word == 1) {
                if (current_len > max_len) {
                    max_len = current_len;
                    max_start_idx = current_start_idx;
                }
                in_word = 0;
            }
        }
    }

    if (in_word == 1) {
        if (current_len > max_len) {
            max_len = current_len;
            max_start_idx = current_start_idx;
        }
    }

    if (max_len > 0) {
        printf("Довжина найдовшого слова: %d\n", max_len);
        printf("Найдовше слово: ");
        for (int i = max_start_idx; i < max_start_idx + max_len; i++) {
            putchar(str[i]);
        }
        printf("\n");
    } else {
        printf("Слів у введеному тексті не знайдено.\n");
    }

    return 0;
}