#include <vector>
#include <algorithm>
#include <iostream>

bool isNumberInValidRange(int number) {
    return (number >= 0) && (number <= 100);
}

std::vector<bool> createRangeCheckResult(std::vector<int> numbers) {
    std::vector<bool> validation_results;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(validation_results), isNumberInValidRange);
    return validation_results;
}

void printResults(std::vector<bool> results) {
    for (bool is_valid : results) {
        if (is_valid) {
            std::cout << "true ";
        } else {
            std::cout << "false ";
        }
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> test_numbers = {-1, 3, 101, 55, 100};
    std::vector<bool> check_results = createRangeCheckResult(test_numbers);
    printResults(check_results);
    return 0;
}