# include <iostream>
# include "Span.hpp"

int main()
{
	int intList [] = {-1000, 4000, 3000, 0, 90000};
	size_t listLength = sizeof (intList) / sizeof (int);
	std::vector <int> v (intList, intList + listLength);
	t_ull	n = 5;
	Span	span (n);

	try {
		span.addNumbers (n, v.begin (), v.end ());
		for (t_ull i = 0; i < n; i++)
			std::cout << "span [" << i << "] = " << span.getSpan () [i] << std::endl;
		std::cout << "shortest span = " << span.shortestSpan () << std::endl;
		std::cout << "longest span = " << span.longestSpan () << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
    return 0;
}

