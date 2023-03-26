#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main (void)
{
	try {
		ShrubberyCreationForm	shrub ("jardin");
		Bureaucrat				lowerguy ("Lowman", 150);
		std::cout << lowerguy << std::endl;
		Bureaucrat				boss ("Boss", 1);
		std::cout << boss << std::endl;
		lowerguy.signForm (shrub);
		boss.signForm (shrub);
		lowerguy.executeForm (shrub);
		boss.executeForm (shrub);
		
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	return 0;
}