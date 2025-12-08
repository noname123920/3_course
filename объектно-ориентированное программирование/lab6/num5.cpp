#include <iostream>


class RealFunction{
    public:
        virtual ~RealFunction() = default;
        virtual double operator()(double x) = 0;
    

};

class LinearFunction : public RealFunction {
    private:
        double k;
        double b;
    public:
        LinearFunction() : k{0}, b{0} {}

        LinearFunction(double coeff_a, double coeff_b) : k{coeff_a}, b{coeff_b} {}
        
        LinearFunction(const LinearFunction& other) : k{other.k}, b{other.b} {}  

        LinearFunction& operator=(const LinearFunction& other) {
            if (this != &other) {
                k = other.k;
                b = other.b;
            }
            return *this;
        }
        
        bool operator==(const LinearFunction& other) const{
            return k == other.k && b == other.b;
        }

        double operator()(double x) override {
            return k * x + b;
        }
};


int main() {
    LinearFunction f(2.0, 3.0);      // f(x) = 2x + 3
    std::cout << "f(5) = " << f(5) << "\n";  // 13

    LinearFunction g = f;            // копирование
    std::cout << "g(5) = " << g(5) << "\n";  // 13

    LinearFunction h;
    h = f;                           // присваивание
    std::cout << "h == f? " << (h == f ? "yes" : "no") << "\n";

    RealFunction* p = new LinearFunction(1.0, 0.0); // f(x) = x
    std::cout << "p(10) = " << (*p)(10) << "\n";    // 10
    delete p;

    return 0;
}