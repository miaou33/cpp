#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main (void)
{
	try {
		Bureaucrat				lowerguy ("Lowman", 150);
		Bureaucrat				boss ("Boss", 1);
		Bureaucrat				middleguy ("Middleguy", 70);

		std::cout << lowerguy << std::endl;
		std::cout << boss << std::endl;

		ShrubberyCreationForm	shrub ("jardin");
		lowerguy.signForm (shrub);
		boss.signForm (shrub);
		lowerguy.executeForm (shrub);
		boss.executeForm (shrub);
	//	middleguy.executeForm (robotomy);

		std::cout << std::endl;
		RobotomyRequestForm		robotomy ("Randomguy");
		boss.signForm (robotomy);
		middleguy.executeForm (robotomy);
		boss.executeForm (robotomy);

		std::cout << std::endl;
		PresidentialPardonForm	prespard ("prisoner");
		boss.executeForm (prespard);
		middleguy.signForm (prespard);
		boss.signForm (prespard);
		middleguy.executeForm (prespard);
		boss.executeForm (prespard);
		
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	return 0;
}