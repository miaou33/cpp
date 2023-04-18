#include "Bureaucrat.hpp"

int	main (void)
{
	std::cout << std::endl;

	try {
		Form		form1 ("formulaire 1", 1, 1);
		Bureaucrat	boss ("Boss", 1);
		std::cout << boss << std::endl;
		boss.signForm(form1);
		boss.lowerGrade ();
		std::cout << boss << std::endl;
		boss.signForm(form1);

	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		Form		form2 ("formulaire 2", 149, 5);
		Bureaucrat lowerguy ("Lowman", 150);
		lowerguy.signForm (form2);
		lowerguy.upperGrade ();
		lowerguy.signForm (form2);
		lowerguy.lowerGrade ();
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Trying to create formulaire with wrong values..." << std::endl;
		Form		wrongform1 ("wformulaire 1", 1000, 500);
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	return 0;
}
