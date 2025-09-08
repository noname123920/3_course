// Задание 1.
#include <iostream>
#include <limits>

int main(){
    int m = std::numeric_limits<int>::min();
    int M = std::numeric_limits<int>::max();

    std::cout << "Наименьшее int (m): " << m << std::endl;
    std::cout << "Наибольшее int (M): " << M << std::endl;

    std::cout << "M + 1 = " << M + 1 << std::endl;
    std::cout << "2 * M = " << 2 * M << std::endl;

    return 0;
} 

