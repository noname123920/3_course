#include <iostream>
 
int main()
{
    int n{5};
    int&& tempRef{n+3};                // ссылка rvalue
    std::cout << tempRef << std::endl; // 8
}