# include "PresidentialPardonForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

PresidentialPardonForm::PresidentialPardonForm () : AForm ("PresidentialPardonForm", 25, 5){

	_target = "nobody";
	if (_verbose)
		announce ("Presidential pardon constructor");
}

PresidentialPardonForm::PresidentialPardonForm (std::string target) : AForm ("PresidentialPardonForm", 25, 5) {

	_target = target;
	if (_verbose)
		announce ("Presidential pardon constructor");
}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const& original) : AForm (original) {

	_target = original.getTarget ();
	if (_verbose)
		announce ("Presidential pardon copy constructor");
}

PresidentialPardonForm::~PresidentialPardonForm () {

	if (_verbose)
		announce ("Presidential pardon destructor");
}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned coz it is const" << std::endl;
		std::cout << "Warning : sign grade not assigned coz it is const" << std::endl;
		std::cout << "Warning : exec grade not assigned coz it is const" << std::endl;
		_is_signed = rhs.isSigned ();
		_target = rhs.getTarget ();
		if (_verbose)
			announce ("Presidential pardon assignment operator");
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	PresidentialPardonForm::getTarget () const {

	return (std::string const&) _target;
}

void				PresidentialPardonForm::execute (Bureaucrat const& executor) {

	AForm::checkExecutability (executor);

	std::cout << "Zaphod Beeblebrox forgave " << _target << std::endl;
}
