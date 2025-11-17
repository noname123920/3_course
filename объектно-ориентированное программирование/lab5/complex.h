#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Конструкторы (только то, что нужно)
    Complex();                          // по умолчанию
    Complex(double r, double i);        // с двумя параметрами
    Complex(double r);                  // с одним параметром
    Complex(const Complex& other);      // копирования

    // Методы доступа
    double getReal() const;
    double getImag() const;

    // Арифметические операторы
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // Операторы сравнения
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Оператор присваивания
    Complex& operator=(const Complex& other);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif