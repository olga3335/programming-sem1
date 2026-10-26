#include <stdio.h>
#include <math.h>
int main(void) {
    double x, y;
    const double variant = 21.0; // Ваш індивідуальний варіант №21

    printf("=== Lab 01 - Task 3 (Variant %.0f) ===\n", variant);
    printf("Enter value for x: ");

    // Перевірка коректності введення користувача
    if (scanf("%lf", &x) != 1) {
        printf("Error: Invalid input format!\n");
        return 1;
    }
    // Перевірка Області Допустимих Значень (ОДЗ)
    // Вираз містить квадратний корінь та логарифм із урахуванням варіанта 21
    if (x + variant < 0) {
        printf("Error: Domain error! Expression under square root (x + %.0f) must be >= 0.\n", variant);
        return 1;
    }

    if (x == 0.0) {
        printf("Error: Domain error! Logarithm argument cannot be zero.\n");
        return 1;
    }

    // Обчислення функції за індивідуальним варіантом
    y = sqrt(x + variant) + (log(fabs(x)) / (x - 2.0));

    // Виведення результату з точністю до 4 знаків після коми
    printf("Result for x = %.2f: y = %.4f\n", x, y);

    return 0;
}