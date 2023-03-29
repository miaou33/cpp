# include "Intern.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Intern::Intern () {

	if (_verbose)
		announce ("Intern constructor");
}

Intern::Intern (Intern const& original) {

	(void) original;
	if (_verbose)
		announce ("Intern copy constructor");
}

Intern::~Intern () {

	if (_verbose)
		announce ("Intern destructor");
}

Intern& Intern::operator= (Intern const& rhs) {

	if (this != &rhs)
	{
		if (_verbose)
			announce ("Intern assignment operator");
	}
	return *this;
}

/******************************************************************************************************/
/*	PUBLIC MB FUNC																					  */
/******************************************************************************************************/

static AForm*	makeShrubberyForm (std::string target) {
	
	return new ShrubberyCreationForm (target);
}

static AForm*	makeRobotomyForm (std::string target) {
	
	return new RobotomyRequestForm (target);
}

static AForm*	makePresPardonForm (std::string target) {
	
	return new PresidentialPardonForm (target);
}

AForm*	Intern::makeForm (std::string form_name, std::string target) {

	static std::string const	valid_forms [] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	AForm*						(*funcPtr []) (std::string target) = { &makeShrubberyForm, &makeRobotomyForm, &makePresPardonForm };
	size_t						i = 0;

	while (i < valid_forms->size () && valid_forms [i] != form_name)
		i++;
	if (i == valid_forms->size ())
		throw Intern::FormNotMakable ();
	return (funcPtr [i] (target));
}

/******************************************************************************************************/
/*	PRIVATE UTILS 																					  */
/******************************************************************************************************/

void		Intern::announce (std::string const func) const {

	std::cout << _GREY << func << ": " << "no name, no grade" << _END << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

const char*	Intern::FormNotMakable::what () const throw () {

	return ("Intern exception reached: cannot make form : form asked doesnt exist");
}
