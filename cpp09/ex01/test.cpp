#include <iostream>
#include <stack>
#include <sstream>

int performOperation(int operand1, int operand2, char operation) {
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
            return 0;
    }
}

bool isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isNumeric(const std::string& token) {
    return (token.find_first_not_of("0123456789") == std::string::npos);
}

int evaluateRPN(const std::string& expression) {
    std::stack<int> operandStack;
    std::istringstream iss(expression);

    std::string token;
    while (iss >> token) {
        if (isNumeric(token)) {
			std::cout<< "token = " << token << std::endl;
            int operand;
            std::istringstream(token) >> operand;
            operandStack.push(operand);
			std::cout << "operand = " << operand << std::endl;
			std::cout << "operandStack.top () = " << operandStack.top () << std::endl;
        } else if (isOperator(token)) {
            if (operandStack.size() < 2) {
                std::cout << "Error: Not enough operands." << std::endl;
                return 0;
            }

            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result = performOperation(operand1, operand2, token[0]);
            operandStack.push(result);
        } else {
            std::cout << "Error: Invalid token '" << token << "'." << std::endl;
            return 0;
        }
    }

    if (operandStack.size() != 1) {
        std::cout << "Error: Invalid expression." << std::endl;
        return 0;
    }

    return operandStack.top();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: Format: ./BTC <arg>" << std::endl;
        return 0;
    }

    std::string expression = argv[1];
    int result = evaluateRPN(expression);
    if (result != 0) {
        std::cout << result << std::endl;
    }

    return 0;
}

