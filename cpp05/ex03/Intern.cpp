# include "Intern.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Intern::Intern () { }

Intern::Intern (Intern const& original) {

	(void) original;
}

Intern::~Intern () {}

Intern& Intern::operator= (Intern const& rhs) {

	(void) rhs;
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

	size_t						i = 0;
	static std::string const	valid_forms [] = {      "shrubbery creation", 
                                                        "robotomy request", 
                                                        "presidential pardon" };

	AForm*						(*funcPtr []) (std::string target) = { 
                                                        &makeShrubberyForm, 
                                                        &makeRobotomyForm, 
                                                        &makePresPardonForm };

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

