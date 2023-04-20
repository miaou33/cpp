#include "iter.hpp"

template <typename T>
void addOne (T& value) { value += 1; }

template <typename T>
void addMEH (T& value) { value += "MEH"; }

int main () {

    int			intArray[] = {1, 2, 3, 4, 5};
    double		doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	stringArray[] = {"bla", "coucou", "meow"};

    std::cout << "   Int array before iter: ";
    for (int i = 0; i  < 5; i++) { std::cout << intArray[i] << " "; }
    std::cout << std::endl;
    std::cout << "Double array before iter: ";
    for (int i = 0; i  < 5; i++) { std::cout << doubleArray[i] << " "; }
    std::cout << std::endl;
    std::cout << "String array before iter: ";
    for (int i = 0; i  < 3; i++) { std::cout << stringArray[i] << " "; }
    std::cout << std::endl;

    std::cout << std::endl;

    iter (intArray, 5, addOne <int>);
    iter (doubleArray, 5, addOne <double>);
    iter (stringArray, 3, addMEH <std::string>);

    std::cout << "   Int array before iter: ";
    for (int i = 0; i  < 5; i++) { std::cout << intArray[i] << " "; }
    std::cout << std::endl;
    std::cout << "Double array before iter: ";
    for (int i = 0; i  < 5; i++) { std::cout << doubleArray[i] << " "; }
    std::cout << std::endl;
    std::cout << "String array before iter: ";
    for (int i = 0; i  < 3; i++) { std::cout << stringArray[i] << " "; }
    std::cout << std::endl;

    return 0;
}

