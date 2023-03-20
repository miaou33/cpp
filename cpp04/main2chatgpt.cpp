#include <iostream>
#include <string>

class Animal {
public:
    Animal() {
        std::cout << "Constructeur Animal" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Destructeur Animal" << std::endl;
    }
    virtual void makeSound() {
        std::cout << "Je suis un animal" << std::endl;
    }
    virtual void printIdeas() {
        for (int i = 0; i < 100; i++) {
            std::cout << ideas[i] << " ";
        }
        std::cout << std::endl;
    }
protected:
    std::string type;
    std::string ideas[100];
};

class Cat : public Animal {
public:
    Cat() {
        std::cout << "Constructeur Cat" << std::endl;
        type = "Cat";
        for (int i = 0; i < 100; i++) {
            ideas[i] = "Idee du chat";
        }
    }
    virtual ~Cat() {
        std::cout << "Destructeur Cat" << std::endl;
    }
    virtual void makeSound() {
        std::cout << "Miaou" << std::endl;
    }
};

int main() {
    Animal* animalArray[2];
    animalArray[0] = new Cat();
    animalArray[1] = new Cat();
    
    std::cout << "Avant modification des idees :" << std::endl;
    animalArray[0]->printIdeas();
    animalArray[1]->printIdeas();
    
    animalArray[0]->ideas[0] = "Idee modifiee";
    
    std::cout << "Apres modification des idees :" << std::endl;
    animalArray[0]->printIdeas();
    animalArray[1]->printIdeas();
    
    delete animalArray[0];
    delete animalArray[1];
    
    return 0;
}
