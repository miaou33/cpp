#include "easyfind.hpp"
#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main ()
{
	int intList [] = { 1, 2, 3, 4, 5 };
	int	size = sizeof (intList) / sizeof (int);
    int x = 3;
    int y = 9;

    std::vector<int> v (intList, intList + size);
    try {
        std::vector<int>::iterator it = easyfind(v, x);
        std::cout << "Element found at index " << it - v.begin () << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(v, y);
        std::cout << "Element found at indey " << it - v.begin () << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
    }

	std::deque<int> d (intList, intList + size);
	try {
		std::deque<int>::iterator it = easyfind (d, x);
        std::cout << "Element found at index " << it - d.begin () << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
	}
	
	std::list<int> l (intList, intList + size);
	try {
		std::list<int>::iterator it = easyfind (l, 5);
        std::cout << "Element found at index " << std::distance (it, l.begin ()) << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
	}
	try {
		std::list<int>::iterator it = easyfind (l, 3);
        std::cout << "Element found at index " << std::distance (it, l.begin ()) << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
	}
	
    return 0;
}

