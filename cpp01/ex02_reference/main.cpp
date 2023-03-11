#include <string>
#include <iostream>
#include <iomanip>

int	main (void)
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string	&stringREF = s;

	std::cout << std::endl;
	std::cout << std::setw (20) << "string adress: " << &s << std::endl;
	std::cout << std::setw (20) << "stringPTR adress: " << stringPTR << std::endl;
	std::cout << std::setw (20) << "stringREF adress: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << std::setw (20) << "string value: " << s << std::endl;
	std::cout << std::setw (20) << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << std::setw (20) << "stringREF value: " << stringREF << std::endl;

}