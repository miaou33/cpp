#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

bool estDateCorrecte(const std::string& dateStr) {
    std::tm time = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Initialiser la structure tm
    std::istringstream iss(dateStr);
    int year, month, day;
    char delimiter;

    if (iss >> year >> delimiter >> month >> delimiter >> day) {
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;

        std::time_t dateInSeconds = std::mktime(&time);
        return dateInSeconds != -1; // La date est valide si mktime ne renvoie pas -1
    }

    return false; // La conversion a échoué, la date est invalide
}

int main() {
    std::ifstream fichier("data.csv");

    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    std::string ligne;

    while (std::getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        std::string dateStr;
        std::getline(iss, dateStr, ',');

        if (estDateCorrecte(dateStr)) {
            std::cout << "La date " << dateStr << " est valide." << std::endl;
        } else {
            std::cout << "La date " << dateStr << " est invalide." << std::endl;
        }
    }

    fichier.close();

    return 0;
}

