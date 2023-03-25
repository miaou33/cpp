#include "Bureaucrat.hpp"

int	main (void)
{
	try {
		Bureaucrat	boss ("Boss", 1);
		std::cout << boss << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	try {
		Bureaucrat lowerguy ("Lowman", 150);
		std::cout << lowerguy << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	try {
		Bureaucrat	usurpateur1 ("Usurpateur1", 439);
		std::cout << usurpateur1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	
	try {
		Bureaucrat	usurpateur2 ("Usurpateur2", -1);
		std::cout << usurpateur2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	return 0;
}