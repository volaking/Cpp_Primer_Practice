#include <iostream>

int main()
{
    int cur_val = 0, val = 0;
    if (std::cin >> cur_val) {
        int cnt = 1;
        while (std::cin >> val) {
            if (cur_val == val) {
                ++cnt;
            } else {
                std::cout << "The count of " << cur_val << " is " << cnt << std::endl;
                cur_val = val;
                cnt = 1;
            }
        }   
        std::cout << "The count of " << val << " is " << cnt << std::endl; 
    }
    return 0;
}