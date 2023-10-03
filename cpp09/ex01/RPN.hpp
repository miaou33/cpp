#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <iostream>
# include <limits>
# include <sstream>
# include <stack>
# include <string>

class RPN {

	public:
		static void	evaluateExpression (std::string const& expression);

		//exceptions
		class Error : public std::exception {
			public:
				Error (std::string const& error_desc);
				virtual ~Error () throw ();
				virtual const char* what () const throw ();
			private:
				std::string	_errorMessage;
		};

	private:
		RPN ();
		RPN (RPN const& original);
		RPN& operator= (RPN const& rhs);
		~RPN ();

		static long long	performOperation (long long, long long, char);
		static bool			isOperator (std::string const&);
		static bool			isValidNumeric (std::string const&);

		static std::stack <long long>	_operandStack;
};

# endif
