#include <iostream>

int main()
{
    int sum = 0, val = 1;
    std::cout << sum << val << std::endl;
    while (val <= 100)
    {
        sum += val;
        ++val;
        // std::cout << sum << " " << val << std::endl;
    }
    std::cout << "The sum of 100 is " << sum << std::endl;
    
    int start = 10;
    while (start >= 0)
    {
        std::cout << start << std::endl;
        --start;
    }

    std::cout << "Please input two numbers:" << std::endl;
    
    int a, b;
    std::cin >> a >> b;
    if (a == b) {
        std::cout << "The number you input is equal, there is no number bewteen them." << std::endl;
    }
    else if (a > b) {
        while (a >= b) {
            std::cout << a << " ";
            --a;
        }
        std::cout << std::endl;
    }
    else {
        while (a <= b) {
            std::cout << a << " ";
            ++a;
        }
        std::cout << std::endl;
    }

    return 0;
}