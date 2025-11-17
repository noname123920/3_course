#include <iostream>
#include "complex.h"

int main() {
    // Создаем экземпляры комплексных чисел разными способами
    Complex a;                // 0 + 0i (конструктор по умолчанию)
    Complex b(3.0);           // 3.0 + 0i (конструктор с одной действительной частью)
    Complex c(2.0, 4.0);      // 2.0 + 4.0i (полноценный конструктор)
    Complex d(c);             // копия c (копирующий конструктор)
    
    // Проверяем геттеры
    std::cout << "Действительная часть b: " << b.getReal() << ", мнимая часть b: " << b.getImag() << std::endl;
    std::cout << "Действительная часть c: " << c.getReal() << ", мнимая часть c: " << c.getImag() << std::endl;
    
    // Проверяем арифметические операторы
    Complex sum = b + c;              // сумма
    Complex diff = c - b;             // разность
    Complex prod = c * d;             // произведение
    Complex div;                      // деление
    try {
        div = c / b;                  // деление
    } catch(std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }
    
    std::cout << "b + c = " << sum << std::endl;
    std::cout << "c - b = " << diff << std::endl;
    std::cout << "c * d = " << prod << std::endl;
    std::cout << "c / b = " << div << std::endl;
    
    // Проверяем составные операторы
    Complex e(1.0, 1.0);
    e += c;                           // инкрементальное сложение
    std::cout << "e += c = " << e << std::endl;
    
    e -= c;                           // инкрементальное вычитание
    std::cout << "e -= c = " << e << std::endl;
    
    e *= c;                           // инкрементальное умножение
    std::cout << "e *= c = " << e << std::endl;
    
    try {
        e /= c;                       // инкрементальное деление
    } catch(std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }
    std::cout << "e /= c = " << e << std::endl;
    
    // Проверяем операторы сравнения
    std::cout << "c == d? " << (c == d ? "Да" : "Нет") << std::endl;
    std::cout << "b == c? " << (b == c ? "Да" : "Нет") << std::endl;
    
    // Проверяем оператор присваивания
    Complex f = c;                    // проверка оператора =
    std::cout << "f = " << f << std::endl;
    
    return 0;
}