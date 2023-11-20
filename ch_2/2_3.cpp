#include <iostream>

int main()
{
    // 引用

    // int ival = 1.01;
    // int &rvall = ival;
    // std::cout << rvall << std::endl;

    // int i = 0, &ri = i;
    // i = 5; ri = 10;
    // std::cout << i << " " << ri << std::endl;
    // return 0;

    // 指针
    // int i = 0, r = 10;
    // int *ri = &i, b = 99;
    
    // i = 5;
    // int &rri = *ri;

    // // ri = *10;
    // *ri = 100;
    // ri = &r;
    // std::cout << i << " " << ri << " " << *ri << " " << rri << std::endl;
    // return 0;

    // // 指向常量的引用 const &
    // int i = 42;
    // const int &ri = i;
    // // ri = 10;
    // i = 10;
    // std::cout << ri << std::endl;
    // return 0;

    // // 指向常量的指针 const *
    // const int i = 42, j = 24;
    // // const int j = 24;
    // // const int *ptr;
    // // const int *const ptr;
    // int *const ptr;
    // ptr = &j;

    // // *ptr = i;
    // // ptr = &j;
    // std::cout << *ptr << std::endl;
    // return 0;
    
    // auto
    // int i = 0, &r = i;
    // auto a = r;
    // const int ci = i, &cr = ci;
    // auto b = ci;
    // auto c = cr;
    // auto d = &i;
    // auto e = &ci;
    // auto &g = ci;
    // // g = 42; 
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    // std::cout << e << std::endl;
    // std::cout << g << std::endl;
    // return 0;

    // decltype()
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    std::cout << c << d << std::endl;
    return 0;
}