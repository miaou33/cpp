#include "Bureaucrat.hpp"

int	main (void)
{
	Bureaucrat	boss ("Boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat	lowerguy ("Lowman", 150);
	std::cout << lowerguy << std::endl;
	Bureaucrat	usurpateur1 ("Usurpateur1", 439);
	std::cout << usurpateur1 << std::endl;
	Bureaucrat	usurpateur2 ("Usurpateur2", -1);
	std::cout << usurpateur2 << std::endl;
}