#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

bool	open_file (std::ifstream *file, char *filename)
{
	file->open (filename);
	if (file->fail ())
	{
		std::perror( "file opening failed" );
		return (0);
	}
	return (1);
}

int	main (int ac, char **av)
{
	
	if (ac != 4)
	{
		std::cout << "wrong nb of args" << std::endl;
		return (0);
	}

	std::ifstream	original_file;
	if (!open_file (&original_file, av[1]))
		return (1);

	std::string		s1 = av[2];
	if (s1.empty ())
	{
		std::cout << "u cant replace 'nothing' by 'something' cause where can i find nothing" << std::endl;
		return (0);
	}

	std::string		filename = av[1];
	std::string		newfilename = filename + ".replace";
	std::ofstream	copyfile (newfilename.c_str ());

	std::string		line;
	std::size_t		s1_i;

	while (std::getline (original_file, line, '\0'))
	{
		s1_i = line.find(av[2]);
		if (s1_i == std::string::npos)
			copyfile << line;
		else
		{
			std::string		s2 = av[3];
			std::string		newline;
			while (s1_i != std::string::npos)
			{
				newline += line.substr (0, s1_i);
				newline += s2;
				line = line.substr(s1_i + s1.length(), line.length());
				s1_i = line.find(av[2]);
			}
			copyfile << newline;
			copyfile << line;
		}
	}

	return (0);
}

