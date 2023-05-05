#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	int intList [] = { 1, 2, 3, 4, 5 }; 
    std::vector<int> v (intList, intList + sizeof (intList) / sizeof (int));
    int x = 3;
    try {
        std::vector<int>::iterator it = easyfind(v, x);
        std::cout << "Element found at index " << it - v.begin() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

