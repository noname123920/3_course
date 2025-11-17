#include "complex.h"
#include <stdexcept>

// Конструктор по умолчанию
Complex::Complex() : real(0), imag(0) {}

// Конструктор с двумя параметрами
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Конструктор с одним параметром
Complex::Complex(double r) : real(r), imag(0) {}

// Конструктор копирования
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

// Методы доступа
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

// Сложение
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Вычитание
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Умножение
Complex Complex::operator*(const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

// Деление
Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double r = (real * other.real + imag * other.imag) / denom;
    double i = (imag * other.real - real * other.imag) / denom;
    return Complex(r, i);
}

// Составные операторы
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double new_real = real * other.real - imag * other.imag;
    double new_imag = real * other.imag + imag * other.imag;
    real = new_real;
    imag = new_imag;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double new_real = (real * other.real + imag * other.imag) / denom;
    double new_imag = (imag * other.real - real * other.imag) / denom;
    real = new_real;
    imag = new_imag;
    return *this;
}

// Сравнение
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Присваивание
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

// Вывод
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    return os;
}