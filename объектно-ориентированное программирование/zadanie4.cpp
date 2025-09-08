// Задание 4.
#include <iostream>

bool isPalindrome(int number) {
    // Отрицательные числа не могут быть палиндромами
    // if (number < 0) {
    //     return false;
    // }
    
    int original = number;
    int reversed = 0;
    
    // Полностью разворачиваем число
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    
    // Сравниваем исходное число с развернутым
    return original == reversed;
}

int main() {
    // Тестируем функцию
    std::cout << "12321 -> " << (isPalindrome(12321) ? "Да" : "Нет") << std::endl;
    std::cout << "123321 -> " << (isPalindrome(123321) ? "Да" : "Нет") << std::endl;
    std::cout << "12345 -> " << (isPalindrome(12345) ? "Да" : "Нет") << std::endl;
    std::cout << "0 -> " << (isPalindrome(0) ? "Да" : "Нет") << std::endl;
    std::cout << "10 -> " << (isPalindrome(10) ? "Да" : "Нет") << std::endl;
    
    return 0;
}