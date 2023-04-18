# include "ShrubberyCreationForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm () : 
		AForm ("ShrubberyCreationForm", "Nobody", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) :
		AForm ("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const& original) :
		AForm (original) {}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (ShrubberyCreationForm const& rhs) {

	if (this != &rhs)
		std::cout << "Warning : attributes cant be assigned coz they are const\nAssignation not done" << std::endl;
	return *this;
}

/******************************************************************************************************/
/*	METHODS																							  */
/******************************************************************************************************/

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

	AForm::checkExecutability (executor);

	std::string		filename = AForm::getTarget () + "shrubbery";
	draw_a_tree_on_file (filename);
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	ShrubberyCreationForm::FileOpeningFailed::what () const throw () {

	return ("\033[31mShrubbery creation form exception reeched\033[0m: cannot be executed for internal reasons");
}

