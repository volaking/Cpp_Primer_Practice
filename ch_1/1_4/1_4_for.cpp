#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i){
        sum += i;
        std::cout << sum << " " << i << std::endl;
    }
    std::cout << "The sum of 50 to 100 is " << sum << std::endl;
    
    int a, b;
    std::cout << "Please input two numbers:" << std::endl;
    std::cin >> a >> b;
    if (a == b) {
        std::cout << " The number you have input are equal. There is no number between them." << std::endl;
    } else if (a < b) {
        std::cout << "The number between" << a << "and" << b << "are these numbers." << std::endl;
        for (int i = a; i <=b; ++i){
            std::cout << i << std::endl;
        }
    } else {
        std::cout << "The number between" << a << "and" << b << "are these numbers." << std ::endl;
        for (int i = a; i >= b; --i) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}