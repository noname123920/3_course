// Задание 2.
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    // Получаем минимальное и максимальное значения double
    double d = std::numeric_limits<double>::min();
    double D = std::numeric_limits<double>::max();
    
    std::cout << "Min double (d): " << d << std::endl;
    std::cout << "Max double (D): " << D << std::endl;
    
    std::cout << "\nTesting double operations:" << std::endl;
    
    // 1. Проверяем, изменится ли D при добавлении 1
    std::cout << "D + 1 == D: " << std::boolalpha << (D + 1 == D) << std::endl;
    
    // 2. Умножаем максимальное значение на 2
    double result2 = 2 * D;
    std::cout << "2 * D = " << result2 << std::endl;
    
    // 3. Проверяем операции с бесконечностью
    double inf_result = 2 * D;
    std::cout << "2*D - D = " << (inf_result - D) << std::endl;
    
    // 4. Infinity - Infinity = NaN
    double result4 = 2*D - 2*D;
    std::cout << "2*D - 2*D = " << result4 << std::endl;
    
    // 5. 2*D - 3*D = -Infinity
    double result5 = 2*D - 3*D;
    std::cout << "2*D - 3*D = " << result5 << std::endl;
    
    return 0;
}