# include <iostream>
# include "Span.hpp"

int main()
{
	Span	span (3);

	try {
		span.addNumber (3);
		span.addNumber (1);
		span.addNumber (32);
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

