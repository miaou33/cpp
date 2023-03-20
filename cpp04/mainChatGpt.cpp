#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal() {
        std::cout << "Creating an Animal." << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Deleting an Animal." << std::endl;
    }

    virtual void makeSound() const = 0;
};

class Brain {
private:
    std::string ideas[100];

public:
    Brain() {
        std::cout << "Creating a Brain." << std::endl;
    }

    ~Brain() {
        std::cout << "Deleting a Brain." << std::endl;
    }
};

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog() : brain(new Brain()) {
        type = "Dog";
        std::cout << "Creating a Dog." << std::endl;
    }

    ~Dog() {
        std::cout << "Deleting a Dog." << std::endl;
        delete brain;
    }

    Dog(const Dog& other) : brain(new Brain(*other.brain)) {
        type = other.type;
        std::cout << "Copying a Dog." << std::endl;
    }

    Dog& operator=(const Dog& other) {
        if (this != &other) {
            type = other.type;
            delete brain;
            brain = new Brain(*other.brain);
            std::cout << "Assigning a Dog." << std::endl;
        }
        return *this;
    }

    void makeSound() const {
        std::cout << "Bark bark!" << std::endl;
    }
};

class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat() : brain(new Brain()) {
        type = "Cat";
        std::cout << "Creating a Cat." << std::endl;
    }

    ~Cat() {
        std::cout << "Deleting a Cat." << std::endl;
        delete brain;
    }

    Cat(const Cat& other) : brain(new Brain(*other.brain)) {
        type = other.type;
        std::cout << "Copying a Cat." << std::endl;
    }

    Cat& operator=(const Cat& other) {
        if (this != &other) {
            type = other.type;
            delete brain;
            brain = new Brain(*other.brain);
            std::cout << "Assigning a Cat." << std::endl;
        }
        return *this;
    }

    void makeSound() const {
        std::cout << "Meow meow!" << std::endl;
    }
};

int main() {
    const int numAnimals = 6;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < numAnimals; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    return 0;
}
