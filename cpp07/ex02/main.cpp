#include "Array.hpp"

int main () {

	try {

		Array <int> nullArray;
		std::cout << "initialized nullArray =\n" << nullArray << std::endl;
		//std::cout << nullArray [8] << std::endl;

		t_ui	n = 3;
		Array <int> intArray (n);
		Array <int> intArrayCopy (intArray);
		std::cout << "intArray =\n" << intArray << std::endl;
		std::cout << "intArrayCopy=\n" << intArrayCopy << std::endl;
		std::cout << "changing intArray [0] to 1, intArray [1] to 4 and intArray [2] to 3... " << std::endl;
		intArray [0] = 1;
		intArray [1] = 4;
		intArray [2] = 3;
		std::cout << "intArray =\n" << intArray << std::endl;
		std::cout << "intArrayCopy=\n" << intArrayCopy << std::endl;

		Array <std::string> strArray (n);
		for (t_ui i = 0; i < n; ++i) { strArray [i] = "blablablablablabla"; }
		Array <std::string> strArrayCopy (strArray);
		std::cout << "strArray =\n" << strArray << std::endl;
		std::cout << "strArrayCopy =\n" << strArrayCopy << std::endl;
		std::cout << "changing strArray [0] to 'ddd' and strArray [2] to 'miao'... " << std::endl;
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

