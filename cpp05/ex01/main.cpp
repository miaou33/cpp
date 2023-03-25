#include "Bureaucrat.hpp"

int	main (void)
{
	std::cout << std::endl;

	try {
		Bureaucrat	boss ("Boss", 1);
		std::cout << boss << std::endl;
		boss.upperGrade ();
		boss.lowerGrade ();
		std::cout << boss << std::endl;

	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		Form		form1 ("formulaire 1", 149, 5);
		Bureaucrat lowerguy ("Lowman", 150);
		lowerguy.signForm (form1);
		lowerguy.upperGrade ();
		lowerguy.signForm (form1);
		lowerguy.lowerGrade ();
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;
	return 0;
}