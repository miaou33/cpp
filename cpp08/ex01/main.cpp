# include <iostream>
# include "Span.hpp"

int main()
{
	int numbers_list [5] = {12, 21, 1, -2, 3};
	std::vector <int> v (numbers_list, numbers_list + 5);
	Span	span (8);

	try {
		span.addNumbers <std::vector<int>::iterator> (8, v.begin (), v.end ());
		std::cout << "span [0] = " << span.getSpan () [0] << std::endl;
		std::cout << "span [1] = " << span.getSpan () [1] << std::endl;
		std::cout << "span [2] = " << span.getSpan () [2] << std::endl;
		std::cout << "shortest span = " << span.shortestSpan () << std::endl;
		std::cout << "longest span = " << span.longestSpan () << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
    return 0;
}

