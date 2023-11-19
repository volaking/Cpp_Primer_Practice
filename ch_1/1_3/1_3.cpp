#include <iostream>

/*
简单函数
注释对嵌套
*/


int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << /* "*/" /* "/*" */;
    return 0;
}