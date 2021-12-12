#include <iostream>     // std::cout, std::left

int main () {
    std::cout << 100 << '\n';
    std::cout.width(5);
    std::cout.fill('0');
    std::cout << 100 << '\n';
    
    std::cout.width(15);
    std::cout << std::left << 100 << '\n';
    return 0;
}