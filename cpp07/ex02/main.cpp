#include "Array.hpp"

int main () {

	try {

		//Array <int> nullArray;
		//std::cout << "initialized nullArray = " << nullArray << std::endl;
		//std::cout << nullArray [8] << std::endl;

		t_ui	n = 5;
		Array <int> intArray (n);
		Array <int> intArrayCopy (intArray);
		intArray [2] = 3;
		std::cout << "intArray = " << intArray << std::endl;
		std::cout << "intArrayCopy= " << intArrayCopy << std::endl;


	}
	catch (std::out_of_range& o) {

		std::cout << o.what () << std::endl;
	}

    return 0;
}

