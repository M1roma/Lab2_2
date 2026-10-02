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
    printf("       Numerical Integration in C       \n");
    printf("=========================================\n");
    printf("select method:\n");
    printf("  1 - Left Rectangle Method\n");
    printf("  2 - Right Rectangle Method\n");
    printf("  3 - Simpson's Method (Parabolic)\n");
    printf("You choice (1-3): ");
    scanf("%d", &method);

    printf("Enter the number of subdivisions N: ");
    scanf("%d", &n);

    double h = (b - a) / n;
    double result = 0.0;
    // МЕТОД ЛІВИХ ПРЯМОКУТНИКІВ
    if (method == 1) { 
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        result = sum * h;
      // МЕТОД ПРАВИХ ПРЯМОКУТНИКІВ
    } else if (method == 2) {
        double sum = 0.0;
        for (int i = 1; i <= n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        result = sum * h;
      // МЕТОД СІМПСОНА
    } else if (method == 3) {
        if (n % 2 != 0) {
            n++;
            h = (b - a) / n;
            printf("(Note: N was adjusted to %d because Simpson's method requires an even N)\n", n);
        }

        double sum = f(a) + f(b);
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 2 != 0) {
                sum += 4.0 * f(x);
            } else {
                sum += 2.0 * f(x);
            }
        }
        result = sum * (h / 3.0);

        else if (method == 4) {
        // МЕТОД ТРАПЕЦІЙ 
        double sum = (f(a) + f(b)) / 2.0;
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        result = sum * h;
        
        } else {
        // ПОМИЛКА ЯКЩО ВВЕДЕНО НЕІСНУЮЧИЙ МЕТОД 
        printf("\nError: Invalid method selection!\n");
        return 1;
    }

    double error = fabs(result - exact_value);

    printf("\n-----------------------------------------\n");
    printf("Calculated Result : %.8f\n", result);
    printf("exact value        : %.8f\n", exact_value);
    printf("absolte error   : %.8f\n", error);
    printf("-----------------------------------------\n");

    return 0;
}
