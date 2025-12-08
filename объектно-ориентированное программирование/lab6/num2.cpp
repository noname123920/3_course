#include <iostream>
#include <string>

template<typename T1, typename T2>
class Pair {
    public:
        T1 first;
        T2 second;

    Pair() : first{}, second{} {}

    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    Pair(const Pair& other) : first(other.first), second(other.second) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    bool operator==(const Pair& other) const {
        return (first == other.first) && (second == other.second);
    }

};

int main() {
    Pair<int, std::string> p1(42, "hello");
    Pair<int, std::string> p2 = p1;
    Pair<int, std::string> p3;
    p3 = p2;

    if (p1 == p2) {
        std::cout << "p1 == p2: OK\n";
    }

    std::cout << "p1.first = " << p1.first << ", p1.second = " << p1.second << "\n";
    return 0;
}