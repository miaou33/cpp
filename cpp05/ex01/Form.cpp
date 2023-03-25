# include "Form.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Form::Form (std::string name, int signing_grade, int exec_grade) : _name (name) {

	checkGrade (signing_grade);
	_sign_grade = signing_grade;
	checkGrade (exec_grade);
	_exec_grade = exec_grade;
	_is_signed = 0;
}

Form::Form (Form const& original) : _name (original.getName ()) {

	_is_signed = (bool) original.isSigned ();
	_sign_grade = (int) original.getSignGrade ();
	_exec_grade = (int) original.getExecGrade ();
}

Form::~Form () {}

Form& Form::operator= (Form const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned to '" << rhs.getName () << "' coz name is const" << std::endl;
		_is_signed = (bool) rhs.isSigned ();
		_sign_grade = (int) rhs.getSignGrade ();
		_exec_grade = (int) rhs.getExecGrade ();
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	Form::getName () const {

	return (std::string const &)_name;
}

bool const&			Form::isSigned () const {

	return (bool const &) _is_signed;
}

int	const&			Form::getSignGrade () const {

	return (int const&) _sign_grade;
}

int const&			Form::getExecGrade () const {

	return (int const&) _exec_grade;
}

/******************************************************************************************************/
/*	PRIVATE UTILS 																					  */
/******************************************************************************************************/

void	Form::checkGrade (int grade) const {

	if (grade < Bureaucrat::highest_grade)
		throw Form::GradeTooHighException ();
	else if (grade > Bureaucrat::lowest_grade)
		throw Form::GradeTooLowException ();
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	Form::GradeTooHighException::what () const throw () {

	return ("Form: grade too high. Maximum grade = 1");
}

const char*	Form::GradeTooLowException::what () const throw () {

	return ("Form: grade too low. Minimum grade = 150");
}

/******************************************************************************************************/
/*	VERBOSE 																						  */
/******************************************************************************************************/

Form::Verbose = 1;