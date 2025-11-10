// Задание 3.
#include <iostream>
#include <limits>

int main() {
    // Получаем машинное эпсилон для double.
    double epsilon = std::numeric_limits<double>::epsilon();
    
    std::cout << "Машинное эпсилон для double (ε): " << epsilon << std::endl;
    std::cout << std::boolalpha;
    
    // 1 + ε == 1.
    bool result1 = (1 + epsilon == 1);
    std::cout << "1 + ε == 1: " << result1 << std::endl;
    
    // 1 + 0.5 * ε == 1.
    bool result2 = (1 + 0.5 * epsilon == 1);
    std::cout << "1 + 0.5 * ε == 1: " << result2 << std::endl;
    
    return 0;
}