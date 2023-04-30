#include "Array.hpp"

int main () {

	try {

		Array <int> nullArray;
		std::cout << "initialized nullArray =\n" << nullArray << std::endl;
		//std::cout << nullArray [8] << std::endl;

		t_ui	n = 3;
		Array <int> intArray (n);
		Array <int> intArrayCopy (intArray);
		intArray [2] = 3;
		std::cout << "intArray =\n" << intArray << std::endl;
		std::cout << "intArrayCopy=\n" << intArrayCopy << std::endl;

		Array <std::string> strArray (n);
		Array <std::string> strArrayCopy (n);
		std::cout << "strArray =\n" << strArray << std::endl;
		std::cout << "strArrayCopy =\n" << strArrayCopy << std::endl;
		strArray [0] = "ddd";
		strArray [2] = "miao";
		//strArray [4] = "bla";
		std::cout << "strArray =\n" << strArray << std::endl;
		std::cout << "strArrayCopy =\n" << strArrayCopy << std::endl;

	}
	catch (std::out_of_range& o) {

		std::cout << o.what () << std::endl;
	}

    return 0;
}

