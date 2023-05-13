# include "Array.hpp"
# include "colors.hpp"
# include <cstdlib>
# include <ostream>

int main(int, char**)
{
	try {

		Array <int> nullArray;
		std::cout << _PURPLE << "initialized nullArray = " << _END << nullArray << std::endl;
		std::cout << nullArray [8] << std::endl;
	}
	catch (std::exception& o) {

		std::cout << o.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		t_ui	n = 3;
		Array <int> intArray (n);
		Array <int> intArrayCopy (intArray);
		std::cout << _PURPLE << "intArray = " << _END << intArray << std::endl;
		std::cout << _PURPLE << "intArrayCopy= " << _END << intArrayCopy << std::endl;
		std::cout << _PURPLE << "changing intArray..." << _END << std::endl;
		intArray [0] = 1;
		intArray [1] = 4;
		intArray [2] = 3;
		std::cout << _PURPLE << "intArray = " << _END << intArray << std::endl;
		std::cout << _PURPLE << "intArrayCopy= " << _END << intArrayCopy << std::endl;
		
		std::cout << std::endl;

		Array <std::string> strArray (n);
		for (t_ui i = 0; i < n; ++i) { strArray [i] = "blablablablablabla"; }
		Array <std::string> strArrayCopy (strArray);
		std::cout << _PURPLE << "strArray = " << _END << strArray << std::endl;
		std::cout << _PURPLE << "strArrayCopy = " << _END << strArrayCopy << std::endl;
		std::cout << _PURPLE << "changing strArray..." << _END << std::endl;
		strArray [0] = "ddd";
		strArray [1] = "aa";
		strArray [2] = "miao";
		std::cout << _PURPLE << "strArray = " << _END << strArray << std::endl;
		std::cout << _PURPLE << "strArrayCopy = " << _END << strArrayCopy << std::endl;

	}
	catch (std::exception& o) {

		std::cout << o.what () << std::endl;
	}

    return 0;
}

