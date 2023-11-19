#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;

    int a, b;
    std::cin >> a >> b;
    std::cout << a << '+' << b << '=' << a + b << std::endl;
    std::cout << a << '*' << b << '=' << a * b << std::endl;
    
    std::cin >> a;
    std::cin >> b;
    std::cout << a << std::endl;
    std::cout << '+' << std::endl;
    std::cout << b << std::endl;
    std::cout << '=' << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a;
    std::cout << '*';
    std::cout << b;
    std::cout << '='
    << a * b << std::endl;
    return 0;
}