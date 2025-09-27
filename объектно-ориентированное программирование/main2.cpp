#include <iostream>
#include <vector>

bool isPerfect(int n) {
    if (n < 2) return false;
    int sum = 1;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main() {
    std::vector<int> perfects;
    for (int i = 1; i <= 1000000; i++) {
        if (isPerfect(i)) perfects.push_back(i);
    }
    
    std::cout << "Совершенные числа: ";
    for (int num : perfects) {
        std::cout << num << " ";
    }
}