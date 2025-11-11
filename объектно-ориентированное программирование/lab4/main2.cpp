#include <initializer_list>
#include <stdexcept>
#include <iostream>

class Matrix {
private:
    double* data;       // Указатель на массив с элементами матрицы
    size_t rows;        // Количество строк M
    size_t cols;        // Количество столбцов N

public:
    // 1. КОНСТРУКТОР ПО УМОЛЧАНИЮ - создает пустую матрицу
    Matrix() : data(nullptr), rows(0), cols(0) {
        std::cout << "Вызван конструктор по умолчанию" << std::endl;
    }

    // 2. КОНСТРУКТОР КОПИРОВАНИЯ - создает копию другой матрицы
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        std::cout << "Вызван конструктор копирования" << std::endl;
        
        // Если исходная матрица пустая
        if (other.rows == 0 || other.cols == 0) {
            data = nullptr;
            return;
        }
        
        // Выделяем память под копию
        data = new double[rows * cols];
        
        // Копируем все элементы из другой матрицы
        for (size_t i = 0; i < rows * cols; ++i) {
            data[i] = other.data[i];
        }
    }

    // 3. КОНСТРУКТОР С INITIALIZER_LIST - инициализация списком значений
    Matrix(std::initializer_list<std::initializer_list<double>> init) {
        std::cout << "Вызван конструктор с initializer_list" << std::endl;
        
        rows = init.size();  // Количество строк = количество вложенных списков
        
        // Если список пустой
        if (rows == 0) {
            cols = 0;
            data = nullptr;
            return;
        }
        
        // Определяем количество столбцов по первой строке
        cols = init.begin()->size();
        
        // Проверяем, что все строки одинаковой длины
        for (const auto& row : init) {
            if (row.size() != cols) {
                throw std::invalid_argument("Все строки должны быть одинаковой длины!");
            }
        }
        
        // Выделяем память для хранения матрицы
        data = new double[rows * cols];
        
        // Заполняем матрицу значениями из списка
        size_t index = 0;  // Индекс в одномерном массиве data
        for (const auto& row : init) {          // Проходим по каждой строке
            for (const auto& element : row) {   // Проходим по каждому элементу строки
                data[index] = element;          // Записываем элемент в массив
                index++;                        // Переходим к следующей ячейке
            }
        }
    }

    // 4. КОНСТРУКТОР С РАЗМЕРАМИ - создает матрицу заданного размера, заполненную нулями
    Matrix(size_t m, size_t n) : rows(m), cols(n) {
        std::cout << "Вызван конструктор с размерами " << m << "x" << n << std::endl;
        
        // Проверяем размеры
        if (rows == 0 || cols == 0) {
            data = nullptr;
        } else {
            // Выделяем память и заполняем нулями
            data = new double[rows * cols];
            for (size_t i = 0; i < rows * cols; ++i) {
                data[i] = 0.0;
            }
        }
    }

    // 5. ДЕСТРУКТОР - освобождает динамическую память
    ~Matrix() {
        std::cout << "Вызван деструктор для матрицы " << rows << "x" << cols << std::endl;
        delete[] data;  // Освобождаем память
    }

    // 6. МЕТОД AT - доступ к элементу с проверкой границ
    double& at(size_t i, size_t j) {
        // Проверяем, не выходят ли индексы за границы матрицы
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Индексы выходят за границы матрицы!");
        }
        
        // Возвращаем ссылку на элемент
        // Формула: i * cols + j - вычисляет позицию в одномерном массиве
        return data[i * cols + j];
    }

    // Константная версия метода at() для работы с константными матрицами
    const double& at(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Индексы выходят за границы матрицы!");
        }
        return data[i * cols + j];
    }

    // 7. МЕТОДЫ ДЛЯ ПОЛУЧЕНИЯ РАЗМЕРОВ МАТРИЦЫ
    size_t getRows() const { return rows; }   // Возвращает количество строк
    size_t getCols() const { return cols; }   // Возвращает количество столбцов

    // 8. МЕТОД ДЛЯ ПРОВЕРКИ - пустая ли матрица
    bool empty() const {
        return rows == 0 || cols == 0;
    }

    // 9. МЕТОД ДЛЯ ВЫВОДА МАТРИЦЫ НА ЭКРАН (для тестирования)
    void print() const {
        if (empty()) {
            std::cout << "Пустая матрица" << std::endl;
            return;
        }
        
        std::cout << "Матрица " << rows << "x" << cols << ":" << std::endl;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << at(i, j) << " ";  // Выводим каждый элемент
            }
            std::cout << std::endl;  // Переход на новую строку после каждой строки матрицы
        }
    }
};

// ФУНКЦИЯ ДЛЯ ТЕСТИРОВАНИЯ
void testMatrix() {
    std::cout << "\n=== ТЕСТ 1: Конструктор с initializer_list ===" << std::endl;
    // Создаем матрицу 2x3 с конкретными значениями
    Matrix mat1 = {
        {1.5, 2.5, 3.5},
        {4.5, 5.5, 6.5}
    };
    mat1.print();

    std::cout << "\n=== ТЕСТ 2: Конструктор с размерами ===" << std::endl;
    // Создаем матрицу 3x2, заполненную нулями
    Matrix mat2(3, 2);
    mat2.print();

    std::cout << "\n=== ТЕСТ 3: Метод at() - чтение и запись ===" << std::endl;
    // Читаем элемент
    std::cout << "mat1.at(0, 1) = " << mat1.at(0, 1) << std::endl;
    
    // Изменяем элемент
    mat1.at(1, 0) = 99.9;
    std::cout << "После изменения:" << std::endl;
    mat1.print();

    std::cout << "\n=== ТЕСТ 4: Конструктор копирования ===" << std::endl;
    // Создаем копию матрицы
    Matrix mat3 = mat1;
    std::cout << "Копия матрицы:" << std::endl;
    mat3.print();

    std::cout << "\n=== ТЕСТ 5: Проверка границ ===" << std::endl;
    try {
        // Пытаемся обратиться к несуществующему элементу
        mat1.at(10, 10);
    } catch (const std::out_of_range& e) {
        std::cout << "Поймали ошибку: " << e.what() << std::endl;
    }

    std::cout << "\n=== ТЕСТ 6: Конструктор по умолчанию ===" << std::endl;
Matrix emptyMat;
std::cout << "Размер пустой матрицы: " << emptyMat.getRows() 
          << " строк, " << emptyMat.getCols() << " столбцов" << std::endl;
std::cout << "Это пустая матрица? " << (emptyMat.empty() ? "ДА" : "НЕТ") << std::endl;
}

// ОСНОВНАЯ ФУНКЦИЯ
int main() {
    std::cout << "ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА MATRIX" << std::endl;
    testMatrix();
    
    // Дополнительный пример
    std::cout << "\n=== ДОПОЛНИТЕЛЬНЫЙ ПРИМЕР ===" << std::endl;
    Matrix myMatrix(2, 2);
    myMatrix.at(0, 0) = 1.0;
    myMatrix.at(0, 1) = 2.0;
    myMatrix.at(1, 0) = 3.0;
    myMatrix.at(1, 1) = 4.0;
    myMatrix.print();
    
    return 0;
}