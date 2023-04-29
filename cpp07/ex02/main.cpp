#include "Array.hpp"

int main () {

	Array <int> nullArray ();
	std::cout << "initialized nullArray = " << nullArray << std::endl;
	
	t_ui	n = 4;
	Array <int> intArray (n);
	std::cout << "initialized intArray = " << intArray << std::endl;

    return 0;
}

