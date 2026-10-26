#include <stdio.h>
#include <math.h>

int main(void) {
    double x, eps;
    
    printf("=== Lab 02 - Task 2 (Variant 6: sh(X)) ===\n");
    printf("Enter X and precision epsilon (e.g., 0.00001): ");
    
    if (scanf("%lf %lf", &x, &eps) != 2 || eps <= 0) {
        printf("Error: Invalid input format or precision!\n");
        return 1;
    }

    double sum = 0.0;
    double term = x; // Перший член ряду для sh(X) при n = 0
    int n = 0;
    int max_iter = 100000; // Захисний лічильник (Timeout Guard)[cite: 10, 11]

    // Накопичення суми ряду за допомогою циклу while та рекурентного співвідношення
    while (fabs(term) >= eps) {
        sum += term;
        n++;
        
        // Рекурентний перехід від an-1 до an для гіперболічного синуса
        // an = an-1 * (x^2 / ((2*n) * (2*n + 1)))
        term = term * (x * x) / ((2.0 * n) * (2.0 * n + 1.0));

        if (n >= max_iter) {
            printf("Warning: Maximum iteration limit reached! Series might diverge.\n");
            break;
        }
    }

    double exact_value = sinh(x);
    double absolute_error = fabs(sum - exact_value);

    printf("\n--- Results ---\n");
    printf("Series sum:       %.6f\n", sum);
    printf("Exact (math.h):   %.6f\n", exact_value);
    printf("Absolute error:   %.6e\n", absolute_error);
    printf("Iterations spent: %d\n", n);

    return 0;
}