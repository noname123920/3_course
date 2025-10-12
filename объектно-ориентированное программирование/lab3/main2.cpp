#include <iostream>
#include <vector>

int firstDigit(int n) { while (n >= 10) n /= 10; return n; }
int lastDigit(int n) { return n % 10; }

bool findChain(std::vector<int>& nums, std::vector<int>& chain) {
    if (chain.size() == nums.size()) return true;
    
    for (int i = 0; i < nums.size(); i++) {
        // Проверяем, нет ли этого числа уже в цепочке
        bool alreadyUsed = false;
        for (int num : chain) {
            if (num == nums[i]) {
                alreadyUsed = true;
                break;
            }
        }
        
        if (!alreadyUsed && (chain.empty() || lastDigit(chain.back()) == firstDigit(nums[i]))) {
            chain.push_back(nums[i]);
            if (findChain(nums, chain)) return true;
            chain.pop_back();
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {123, 3456, 678};
    std::vector<int> chain;
    
    if (!findChain(nums, chain))
        throw std::runtime_error("Переупорядочивание невозможно");
    
    for (int num : chain) std::cout << num << " ";
    return 0;
}