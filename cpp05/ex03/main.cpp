# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main (void)
{
	try {
		Bureaucrat				boss ("grade1man", 1);

		std::cout << std::endl;
		std::cout << boss << std::endl;

		Intern				intern;
		AForm*				forms [3] = { 
										intern.makeForm ("shrubbery creation", "planet"),
										intern.makeForm ("robotomy request", "someone"),
										intern.makeForm ("presidential pardon", "someone"),
									};
		std::cout << std::endl;
		for (size_t i = 0; i < 3; i++)
		{
			boss.signForm (*forms[i]);
			boss.executeForm (*forms[i]);
			delete forms [i];
			std::cout << std::endl;
		}
			
		AForm*	wrongform = intern.makeForm ("wrong form", "djeeji");
		boss.signForm (*wrongform);
		boss.executeForm (*wrongform);
		delete wrongform;


	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	return 0;
}