#include <iostream>
#include <sstream>

#include <exception>
#include <string>

#include <exception>
#include <string>

class MyException : public std::exception
{
public:
    MyException(const std::string& message)
        : errorMessage("Erreur : " + message + " - Raison spécifique de l'exception") {}

    virtual const char* what() const throw()
    {
        return errorMessage.c_str();
    }

    virtual ~MyException() throw() {}

private:
    std::string errorMessage;
};

class MyClass {
public:
    MyClass(int value) {
        myStream << "La valeur est : " << value;
    }

    void printValue() {
        std::cout << myStream.str() << std::endl;
    }

private:
    std::stringstream myStream;
};

int main() {

	try {
		MyClass obj(42);
		obj.printValue();
		throw MyException("Erreur lors du traitement");

	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}

    return 0;
}

