#include <stdio.h>
#include <math.h>
int main(void) {
    double x_start, x_end, dx;

    printf("=== Lab 02 - Task 1 (Variant 6) ===\n");
    printf("Enter X_start, X_end and step dx: ");
    
    // Зчитуємо межі та крок з перевіркою формату
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        printf("Error: Invalid input format!\n");
        return 1;
    }

    // Валідація вхідних параметрів
    if (x_start >= x_end || dx <= 0) {
        printf("Error: Invalid range! Ensure X_start < X_end and step dx > 0.\n");
        return 1;
    }
    printf("\n-----------------------------------\n");
    printf("      X      |        Y(X)         \n");
    printf("-----------------------------------\n");

    // Цикл табулювання від x_start до x_end включно
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double y;
        int undefined = 0;

        // Кусочна функція для варіанта №6
        if (x < 0.0) {
            y = 1.0 / (1.0 + x * x);
        } 
        else if (x <= 2.0) {
            y = 1.0 - 2.0 * x;
        } 
        else {
            // Перевірка ОДЗ для квадратного кореня (3 * sqrt(x))
            if (x < 0.0) {
                undefined = 1;
            } else {
                y = 3.0 * sqrt(x);
            }
        }

        // Виведення результату у вигляді таблиці
        if (undefined) {
            printf("%10.2lf |   [Undefined]   \n", x);
        } else {
            printf("%10.2lf | %15.4lf\n", x, y);
        }
    }
    printf("-----------------------------------\n");

    return 0;
}