#include "Bureaucrat.hpp"

int	main (void)
{
	std::cout << std::endl;

	try {
		Bureaucrat	boss ("Boss", 1);
		Bureaucrat	copy (boss);
		copy.lowerGrade ();
		boss.lowerGrade ();
		Bureaucrat	assigned ("Assigned", 44);
		assigned = boss;
		assigned.lowerGrade ();
		std::cout << boss << std::endl;

	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat lowerguy ("Lowman", 150);
		lowerguy.upperGrade ();
		lowerguy.lowerGrade ();
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat	usurpateur1 ("Usurpateur1", 439);
		usurpateur1.upperGrade ();
		usurpateur1.lowerGrade ();
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat	usurpateur2 ("Usurpateur2", -1);
		usurpateur2.upperGrade ();
		usurpateur2.lowerGrade ();
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	return 0;
}