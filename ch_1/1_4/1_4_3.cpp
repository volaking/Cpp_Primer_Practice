#include <iostream>

int main()
{   
    std::cout << "Please input your numbers (end with ctrl + z and Enter):" << std::endl;
    int sum = 0, value = 0;
    while (std::cin >> value) {
        sum += value;
        // std::cout << sum << " " << value << std::endl;
    }
    std::cout << "The sum of your input is " << sum << std::endl;
    return 0;
} 
