#ifndef RPN_HPP
# define RPN_HPP

# include <cstdint>
# include <iostream>
# include <stack>
# include <string>

class RPN {

	public:
		RPN ();
		RPN (RPN const& original);
		RPN& operator= (RPN const& rhs);
		~RPN ();

		std::stack <uint8_t>	getOperandStack () const;
		void	evaluateExpression (std::string expression);

	private:
		std::stack <uint8_t>	_operandStack;
};

# endif
