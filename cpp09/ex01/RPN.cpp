# include "RPN.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

RPN::RPN () {}

RPN::RPN (RPN const& original) { *this = original; }

RPN& RPN::operator= (RPN const& rhs) { if (this != &rhs) {} return *this; }

RPN::~RPN () {}

/******************************************************************************************************/
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/

int RPN::performOperation (int operand1, int operand2, char operation) {

    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            throw RPN::Error ("Operation invalid");
    }
}

bool RPN::isOperator (std::string const& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumeric (std::string const& token) {
    return (token.find_first_not_of ("0123456789") == std::string::npos);
}

void	RPN::evaluateExpression (std::string const& expression) {

	std::istringstream	iss (expression);
	std::string			token;
	int					new_operand, operand1, operand2 = 0;
	int			res;

	while (iss >> token)
	{
		if (isNumeric (token))
		{
			std::istringstream (token) >> new_operand;
			_operandStack.push (new_operand);
		}
		else if (isOperator (token)) {

			if (_operandStack.size () < 2) {
				throw RPN::Error ("Not enough operands");
			}
			operand2 = _operandStack.top ();
			_operandStack.pop ();
			operand1 = _operandStack.top ();
			_operandStack.pop ();

			res = performOperation (operand1, operand2, token [0]);
			_operandStack.push (res);
		}
		else
			throw RPN::Error("Invalid expression");
	}
	if (_operandStack.size () != 1)
		throw RPN::Error("Invalid expression");
	std::cout << _operandStack.top () << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

RPN::Error::Error (std::string const& error_desc)

	: _errorMessage ("Error: " + error_desc) {}

RPN::Error::~Error () throw () {}

const char*	RPN::Error::what () const throw () {

	return (_errorMessage.c_str ());
}

