# include "RobotomyRequestForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm ("RobotomyRequestForm", 72, 45) {

	_target = target;
	if (_verbose)
		announce ("Robotomy constructor");
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const& original) : AForm (original) {

	_target = original.getTarget ();
	if (_verbose)
		announce ("Robotomy copy constructor");
}

RobotomyRequestForm::~RobotomyRequestForm () {

	if (_verbose)
		announce ("Robotomy destructor");
}

RobotomyRequestForm& RobotomyRequestForm::operator= (RobotomyRequestForm const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned coz it is const" << std::endl;
		std::cout << "Warning : sign grade not assigned coz it is const" << std::endl;
		std::cout << "Warning : exec grade not assigned coz it is const" << std::endl;
		_is_signed = rhs.isSigned ();
		_target = rhs.getTarget ();
		if (_verbose)
			announce ("Robotomy assignment operator");
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	RobotomyRequestForm::getTarget () const {

	return (std::string const&) _target;
}

void				RobotomyRequestForm::execute (Bureaucrat const& executor) {

	if (!_is_signed)
		throw AForm::FormNotSignedException ();
	if (executor.getGrade () > _grade_to_execute)
		throw AForm::GradeTooLowException ();

	std::cout << "Bzzzzzzzzzzzzz..." << std::endl;
	std::rand () % 2 ?
		throw RobotomyRequestForm::RobotomyFailed ()
		: std::cout << _target << " successfully robotomized" << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	RobotomyRequestForm::RobotomyFailed::what () const throw () {

	return ("\033[31mRobotomy exception reeched\033[0m: robotomy failed sorry");
}


/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, RobotomyRequestForm const& toDisplay) {

	o << toDisplay.getName () << " form, grade needed to sign : " << toDisplay.getSignGrade () << " | grade needed to exec : " << toDisplay.getExecGrade () << std::endl;
	return o;
}

