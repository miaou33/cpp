#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

// filesystem library since C++17

bool	open_file (std::ifstream *file, char *filename)
{
	file->open (filename);
	if (file->fail ())
	{
		std::perror( "File opening failed" );
		return (0);
	}
	return (1);
}

int	main (int ac, char **av)
{
	if (ac == 4)
	{
		// OPEN FILE GIVEN AS FIRST ARG
		std::ifstream	original_file;
		if (!open_file (&original_file, av[1]))
			return (1);

		// CREATE NEW FILENAME
		std::string	filename = av[1];
		std::string	newfilename = filename + ".replace";
		const char*	newfilename_c = newfilename.c_str ();
		
		// CREATE NEW FILE		
		std::ofstream	copyfile (newfilename_c);

		// COPY FILE IN COPY FILE : utilisation de l'operator << qui permet d'ecrire dans le fichier
//		copyfile << original_file.rdbuf ();

		std::string	line;
		std::size_t	s1_i;
		std::string	s2 = av[3];
		std::string	newline;
		while (std::getline (original_file, line, '\0'))
		{
			std::cout<<"line read"<<std::endl;
			s1_i = line.find(av[2]);
			if (s1_i == std::string::npos)
				copyfile << line;
			else
			{
				while (s1_i != std::string::npos)
				{
					newline += line.substr (0, s1_i);
					newline += s2;
					line = line.substr(s1_i + s2.length(), line.length());
					s1_i = line.find(av[2]);
				}
				copyfile << newline;
			}
		}

		std::cout << "check if file = dir !!!" << std::endl;
	/* 	// CLOSE FILES
		original_file.close ();
		copyfile.close (); */

	}
	return 0;
}

