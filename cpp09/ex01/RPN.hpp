#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
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

		static int					performOperation (int operand1, int operand2, char operation);
		static bool					isOperator (std::string const& token);
		static bool 				isNumeric (std::string const& token);

		static std::stack <int>		_operandStack;
};

# endif
