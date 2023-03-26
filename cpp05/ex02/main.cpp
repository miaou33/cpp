#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main (void)
{
	try {
		ShrubberyCreationForm	shrub ("jardin");
		RobotomyRequestForm		robotomy ("Randomguy");
		Bureaucrat				lowerguy ("Lowman", 150);
		Bureaucrat				boss ("Boss", 1);
		Bureaucrat				middleguy ("Middleguy", 70);
		std::cout << lowerguy << std::endl;
		std::cout << boss << std::endl;
		lowerguy.signForm (shrub);
		boss.signForm (shrub);
		lowerguy.executeForm (shrub);
		boss.executeForm (shrub);
	//	middleguy.executeForm (robotomy);
		boss.signForm (robotomy);
		middleguy.executeForm (robotomy);
		boss.executeForm (robotomy);
		
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	return 0;
}