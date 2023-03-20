#include <iostream>
#include <string>

class Brain {
public:
    Brain() {
        for (int i = 0; i < 100; i++) {
            ideas[i] = "Idea " + std::to_string(i);
        }
    }

    std::string ideas[100];
};

class Animal {
public:
    Animal() {
        std::cout << "Animal created" << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Animal destroyed" << std::endl;
    }

    virtual void makeSound() = 0;


protected:
    std::string type;
};

class Dog : public Animal {
public:
    Dog() {
        type = "Dog";
        brain = new Brain();
        std::cout << "Dog created" << std::endl;
    }

    Dog(const Dog& other) {
        type = other.type;
        brain = new Brain(*other.brain);
        std::cout << "Dog copied" << std::endl;
    }

    virtual ~Dog() {
        delete brain;
        std::cout << "Dog destroyed" << std::endl;
    }

    virtual void makeSound() {
        std::cout << "Woof!" << std::endl;
    }

private:
    Brain* brain;
};

class Cat : public Animal {
public:
    Cat() {
        type = "Cat";
        brain = new Brain();
        std::cout << "Cat created" << std::endl;
    }

    Cat(const Cat& other) {
        type = other.type;
        brain = new Brain(*other.brain);
        std::cout << "Cat copied" << std::endl;
    }

    virtual ~Cat() {
        delete brain;
        std::cout << "Cat destroyed" << std::endl;
    }

    virtual void makeSound() {
        std::cout << "Meow!" << std::endl;
    }

private:
    Brain* brain;
};

int main() {
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    // Change the first idea of the brain of the first dog
    animals[0]->ideas[0] = "New idea 0";

    // Print the first idea of the brain of each animal
    for (int i = 0; i < 4; i++) {
        std::cout << "Animal " << i << " first idea: " << animals[i]->ideas[0] << std::endl;
    }

    // Delete the animals
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    return 0;
}
