#include <iostream>
#include <list>

void merge(std::list<int>& list, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            list.push_back(*leftIt);
            ++leftIt;
        } else {
            list.push_back(*rightIt);
            ++rightIt;
        }
    }

    // Ajouter les elements restants de la liste de gauche
    while (leftIt != left.end()) {
        list.push_back(*leftIt);
        ++leftIt;
    }

    // Ajouter les elements restants de la liste de droite
    while (rightIt != right.end()) {
        list.push_back(*rightIt);
        ++rightIt;
    }
}

// Fonction de tri par insertion fusionne
void mergeInsertionSort(std::list<int>& list) 
{
    if (list.size() <= 1) {
        return; // La liste est deja triee (ou vide)
    }

    std::list<int> left;
    std::list<int> right;

    // Diviser la liste en deux moities
    bool switchList = false;
    std::list<int>::iterator it = list.begin();
    while (it != list.end()) {
        if (switchList) {
            right.push_back(*it);
        } else {
            left.push_back(*it);
        }
        switchList = !switchList;
        ++it;
    }

    // Recursivement trier les deux moities
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Fusionner les deux moities triees
    list.clear();
    merge(list, left, right);
}

void printList(const std::list<int>& list) {
    std::list<int>::const_iterator it = list.begin();
    while (it != list.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> myList;
    myList.push_back(7);
    myList.push_back(2);
    myList.push_back(5);
    myList.push_back(3);
    myList.push_back(9);
    myList.push_back(1);
    myList.push_back(4);
    myList.push_back(6);
    myList.push_back(8);

    std::cout << "Liste originale: ";
    printList(myList);

    mergeInsertionSort(myList);

    std::cout << "Liste triee: ";
    printList(myList);

    return 0;
}

