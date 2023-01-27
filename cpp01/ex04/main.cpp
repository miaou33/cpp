#include <string>
#include <fstream>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		// OPEN FILE GIVEN AS FIRST ARG
		std::ifstream	file;
		file.open (av[1]);
		if (file.fail ()) {
			std::perror( "File opening failed" );
			return (1);
		}

		// CREATE NEW FILENAME
		std::string	filename = av[1];
		std::string	newfilename = filename + ".replace";
		const char*	newfilename_c = newfilename.c_str ();

		// CREATE NEW FILE		
		std::ofstream	copyfile (newfilename_c);

		// COPY FILE IN COPY FILE
		copyfile << file.rdbuf ();

		// CLOSE FILES
		file.close ();
		copyfile.close ();

	}
	return 0;
}