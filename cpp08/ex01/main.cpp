# include <iostream>
# include "Span.hpp"

int main()
{
	Span	span (3);

	try {
		std::cout << span.getSpan () . size () << std::endl;
		span.addNumber ();
		span.addNumber ();
		span.addNumber ();
		std::cout << span.shortestSpan () << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
    return 0;
}

