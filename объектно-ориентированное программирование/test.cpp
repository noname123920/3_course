#include<iostream>
class Animal {
public:          // Доступно везде
    std::string name;
    
protected:       // Доступно в Animal и производных классах
    int age;
    
private:         // Доступно ТОЛЬКО в Animal
    std::string secret;
    
public:
    Animal(const std::string& animalName, int animalAge) 
        : name(animalName), age(animalAge), secret("Секретное слово") {
    }
    
    void tellSecret() {
        std::cout << name << " знает: " << secret << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& catName, int catAge) 
        : Animal(catName, catAge) {
    }
    
    void showAccess() {
        // public - доступно
        std::cout << "Имя: " << name << std::endl;
        
        // protected - доступно в производном классе
        std::cout << "Возраст: " << age << " лет" << std::endl;
        
        // private - НЕДОСТУПНО!
        // std::cout << secret; // ОШИБКА компиляции!
        
        // Но можно через публичный метод базового класса
        tellSecret();
    }
};

int main() {
    Cat myCat("Барсик", 3);
    
    // Что доступно снаружи?
    std::cout << "Из main():" << std::endl;
    
    // Public члены базового класса доступны
    std::cout << "Имя кота: " << myCat.name << std::endl;
    
    // Protected - НЕ доступны снаружи
    std::cout << myCat.age; // ОШИБКА!
    
    // Private - тем более не доступны
    std::cout << myCat.secret; // ОШИБКА!
    
    // Но можем через метод
    myCat.tellSecret();
    
    std::cout << "\nИз метода класса Cat:" << std::endl;
    myCat.showAccess();
    
    return 0;
}