# include "ShrubberyCreationForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) : AForm ("ShrubberyCreationForm", 145, 137) {

	_target = target;
	if (_verbose)
		announce ("Shrubbery Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const& original) : AForm (original) {

	_target = original.getTarget ();
	if (_verbose)
		announce ("Shrubbery Copy constructor");
}

ShrubberyCreationForm::~ShrubberyCreationForm () {

	if (_verbose)
		announce ("Shrubbery Destructor");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (ShrubberyCreationForm const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned coz it is const" << std::endl;
		std::cout << "Warning : sign grade not assigned coz it is const" << std::endl;
		std::cout << "Warning : exec grade not assigned coz it is const" << std::endl;
		_is_signed = rhs.isSigned ();
		_target = rhs.getTarget ();
		if (_verbose)
			announce ("Shrubbery Assignment operator");
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	ShrubberyCreationForm::getTarget () const {

	return (std::string const&) _target;
}

static void			draw_a_tree_on_file (std::string filename) {

	std::fstream	file;
	std::string 	tree =
"            .        +          .      .          .    \n"
"     .            _        .                    .      \n"
"  ,              /;-._,-.____        ,-----.__         \n"
"           .    (_:#::_.:::. `-._   /:, /-._, `._,     \n"
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /      \n"
"                      ,    `./  \\:. `.   )==-'  .     \n"
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o        \n"
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .  \n"
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7 \n"
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
"              \\:  `  X` _| _,\\/'   .-'               \n"
".               \":._:`\\____  /:\'  /      .           .\n"
"                    \\::.  :\\/:'  /              +    \n"
"   .                 `.:.  /:'  }      .               \n"
"           .           ):_(:;   \\           .         \n"
"                      /:. _/ ,  |                      \n"
"                   . (|::.     ,`                  .   \n"
"     .                |::.    {\\                      \n"
"                      |::.\\  \\ `.                    \n"
"                      |:::(\\    |                     \n"
"              O       |:::/{ }  |                  (o  \n"
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\"\n"
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
"      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~)      \n";


	file.open (filename.c_str (), std::ios_base::app);
	if (file.fail ())
	{
		std::perror ("File opening failed");
		throw ShrubberyCreationForm::FileOpeningFailed ();
	}
	file << tree;
}

void				ShrubberyCreationForm::execute (Bureaucrat const& executor) {

	if (!_is_signed)
		throw AForm::FormNotSignedException ();
	if (executor.getGrade () > _grade_to_execute)
		throw AForm::GradeTooLowException ();
	std::string		filename = _target + "shrubbery";
	draw_a_tree_on_file (filename);
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	ShrubberyCreationForm::FileOpeningFailed::what () const throw () {

	return ("\033[31mShrubbery creation form exception reeched\033[0m: cannot be executed for internal reasons");
}


/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, ShrubberyCreationForm const& toDisplay) {

	o << toDisplay.getName () << " form, grade needed to sign : " << toDisplay.getSignGrade () << " | grade needed to exec : " << toDisplay.getExecGrade () << std::endl;
	return o;
}

