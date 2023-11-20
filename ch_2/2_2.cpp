#include <string>
#include <iostream>

// std::string global_str;
// int global_int;

// int main()
// {
//     int local_int;
//     std::string local_str;
//     std::cout << global_str << global_int << local_int << local_str << std::endl;


// }

// int i = 42;
// int main()
// {
//     int i = 100;
//     int j = i;
//     std::cout << j;
//     return 0;
// }

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i) {
        sum += i;
    }
    std::cout << i << ' ' << sum << std::endl;
    return 0;
}