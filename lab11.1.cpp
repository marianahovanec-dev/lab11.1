#include <iostream>
#include <cmath>
#include <windows.h>
struct CalculationResults {
    double x;
    double a;
    double y;
};

CalculationResults compute_functions(double n, double b) {
    CalculationResults results;

    results.x = std::exp(b) + n;

    results.a = std::sqrt(results.x * results.x + b * b);

    if (b <= 0 || b == 1.0) {
        std::cerr << "Помилка: Неприпустиме значення b для логарифма. Встановлення y = NaN." << std::endl;
        results.y = NAN;
    }
    else {
        results.y = std::log10(results.a) / std::log10(b);
    }

    return results;
}

int main() {
    SetConsoleCP(CP_UTF8); 
    SetConsoleOutputCP(CP_UTF8);
    double n_val = 5.0;
    double b_val = 3.0;

    std::cout << " Обчислення для n = " << n_val << ", b = " << b_val << " " << std::endl;

    CalculationResults final_results = compute_functions(n_val, b_val);

    std::cout << "1. x = " << final_results.x << std::endl;
    std::cout << "2. a = " << final_results.a << std::endl;
    std::cout << "3. y = " << final_results.y << std::endl;

    std::cout << "\n Інший приклад (n = 1.0, b = 10.0) " << std::endl;
    CalculationResults example_2 = compute_functions(1.0, 10.0);
    std::cout << "1. x = " << example_2.x << std::endl;
    std::cout << "2. a = " << example_2.a << std::endl;
    std::cout << "3. y = " << example_2.y << std::endl;

    return 0;
}