#include "easyfind.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
	int intList [] = { 1, 2, 3, 4, 5 }; 
	int	size = sizeof (intList) / sizeof (int);
    std::vector<int> v (intList, intList + size);

    int x = 3;
    try {
        std::vector<int>::iterator it = easyfind(v, x);
        std::cout << "Element found at index " << it - v.begin() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    int y = 9;
    try {
        std::vector<int>::iterator it = easyfind(v, y);
        std::cout << "Element found at indey " << it - v.begin() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

