#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main (void)
{
	try {
		ShrubberyCreationForm	shrub ("jardin");
		Bureaucrat				lowerguy ("Lowman", 150);
		Bureaucrat				boss ("Boss", 1);
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