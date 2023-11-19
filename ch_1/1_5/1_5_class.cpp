#include <iostream>
#include "Sales_item.h"
int main()
{
    // Sales_item book;
    // std::cin >> book;
    // std::cout << book << std::endl;
    // return 0;

    // Sales_item item1, item2;
    // std::cin >> item1 >> item2;
    // std::cout << item1 + item2 << std::endl;

    Sales_item cur_item, item;
    if (std::cin >> cur_item) {
        item = cur_item;
    }

    while (std::cin >> cur_item) {
        item += cur_item;
    }
    std::cout << item << std::endl;
    std::cout << item.isbn() << std::endl;
    return 0;
}