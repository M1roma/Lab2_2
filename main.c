#include <stdio.h>
#include <math.h>

// Підінтегральна функція: f(x) = x / (x + 2)^2
double f(double x) {
    return x / ((x + 2.0) * (x + 2.0));
}

int main() {
    double a = 0.0; // Нижня межа
    double b = 1.0; // Верхня межа
    int n;          // Кількість розбиттів
    int method;     // Номер методу

    // Точне аналітичне значення: ln(1.5) - 1/3
    double exact_value = log(1.5) - (1.0 / 3.0);

    printf("=========================================\n");
    printf("       Чисельне інтегрування на C        \n");
    printf("=========================================\n");
    printf("Оберіть метод:\n");
    printf("  1 - Метод ЛІВИХ прямокутників\n");
    printf("  2 - Метод ПРАВИХ прямокутників\n");
    printf("  3 - Метод Сімпсона (парабол)\n");
    printf("Ваш вибір (1-3): ");
    scanf("%d", &method);

    printf("Введіть кількість розбиттів N: ");
    scanf("%d", &n);

    double h = (b - a) / n;
    double result = 0.0;

    if (method == 1) {
        // МЕТОД ЛІВИХ ПРЯМОКУТНИКІВ
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        result = sum * h;

    } else if (method == 2) {
        // МЕТОД ПРАВИХ ПРЯМОКУТНИКІВ
        double sum = 0.0;
        for (int i = 1; i <= n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        result = sum * h;
    }

    printf("\nРезультат: %.8f\n", result);
    
    return 0;
}
