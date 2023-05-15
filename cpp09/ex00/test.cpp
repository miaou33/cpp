#include <ctime>
#include <string>
#include <iostream>

bool estDateCorrecte(int jour, int mois, int annee) {
    std::tm time = {0, 0, 0, jour, mois - 1, annee - 1900, 0, 0, 0, 0, 0}; // Initialiser la structure tm
    std::mktime(&time); // Convertir la date en un temps valide

    // Vérifier si la date a été modifiée par mktime
    // Par exemple, si vous avez entré un mois de février avec un jour invalide, mktime le corrige
    return time.tm_mday == jour && time.tm_mon == mois - 1 && time.tm_year == annee - 1900;
}

int main() {
    int jour, mois, annee;
    std::cout << "Entrez une date (jj mm aaaa) : ";
    std::cin >> jour >> mois >> annee;

    if (estDateCorrecte(jour, mois, annee)) {
        std::cout << "La date est valide." << std::endl;
    } else {
        std::cout << "La date est invalide." << std::endl;
    }

    return 0;
}

