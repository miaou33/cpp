#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

// Structure pour stocker les données du fichier CSV
struct BitcoinData
{
    std::string date;
    double exchangeRate;
};

// Fonction pour lire les données du fichier CSV
bool readBitcoinData(const std::string& filename, std::map<std::string, double>& bitcoinMap)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Ignorer la première ligne (entête)

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        double exchangeRate;

        if (!(iss >> date >> exchangeRate))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        bitcoinMap.insert (std::make_pair (date, exchangeRate));
    }

    file.close();
    return true;
}

// Fonction pour remplacer les caractères '|'
void replaceChars(std::string& str, char oldChar, char newChar)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == oldChar)
            str[i] = newChar;
    }
}

// Fonction pour extraire la date et la valeur à partir d'une ligne du fichier d'entrée
bool extractDateValue(const std::string& line, std::string& date, double& value)
{
    std::istringstream iss(line);
    std::string dateString, valueString;

    if (!(iss >> dateString >> valueString))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    replaceChars(dateString, '|', ' ');

    std::istringstream dateIss(dateString);
    if (!(dateIss >> date))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    char* endPtr;
    value = std::strtod(valueString.c_str(), &endPtr);
    if (*endPtr != '\0' || value <= 0 || value > 1000)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    return true;
}

// Fonction pour trouver la date la plus proche dans la map
std::string findClosestDate(const std::map<std::string, double>& bitcoinMap, const std::string& date)
{
    std::map<std::string, double>::const_iterator it = bitcoinMap.lower_bound(date);
    if (it == bitcoinMap.begin())
        return it->first;

    if (it == bitcoinMap.end())
        return (--it)->first;

    std::tm tm1 = {};
    std::istringstream(date) >> std::get_time(&tm1, "%Y-%m-%d");
    time_t t1 = std::mktime(&tm1);

    std::tm tm2 = {};
    std::istringstream(it->first) >> std::get_time(&tm2, "%Y-%m-%d");
    time_t t2 = std::mktime(&tm2);

    double diff1 = std::difftime(t1, t2);

    std::tm tm3 = {};
    std::istringstream((++it)->first) >> std::get_time(&tm3, "%Y-%m-%d");
    time_t t3 = std::mktime(&tm3);

    double diff2 = std::difftime(t3, t1);

    return (diff1 < diff2) ? it->first : (--it)->first;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    std::map<std::string, double> bitcoinMap;
    if (!readBitcoinData("data.csv", bitcoinMap))
        return 1;

    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string date;
        double value;

        if (!extractDateValue(line, date, value))
            continue;

        std::map<std::string, double>::iterator it = bitcoinMap.find(date);
        if (it == bitcoinMap.end())
        {
            std::string closestDate = findClosestDate(bitcoinMap, date);
            it = bitcoinMap.find(closestDate);
            std::cerr << "Using closest date: " << closestDate << std::endl;
        }

        double exchangeRate = it->second;
        double result = value * exchangeRate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    inputFile.close();
    return 0;
}

