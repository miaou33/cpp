#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cmath>

// A function to parse a line from the bitcoin price database
bool parseBitcoinPriceLine(const std::string& line, std::string& date, double& rate)
{
    std::stringstream ss(line);
    std::getline(ss, date, ',');
    std::string rateStr;
    if (!std::getline(ss, rateStr, ',')) {
        return false;
    }
    rate = std::atof(rateStr.c_str());
    return true;
}

// A function to parse a line from the input file
bool parseInputLine(const std::string& line, std::string& date, double& value)
{
    std::stringstream ss(line);
    std::getline(ss, date, '|');
    date.erase(0, date.find_first_not_of(" "));
    date.erase(date.find_last_not_of(" ") + 1);
    std::string valueStr;
    if (!std::getline(ss, valueStr, '|')) {
        return false;
    }
    value = std::atof(valueStr.c_str());
    if (value < 0 || value > 1000) {
        return false;
    }
    return true;
}

// A function to find the bitcoin price closest to a given date
double findBitcoinPrice(const std::map<std::string, double>& bitcoinPrices, const std::string& date)
{
    std::map<std::string, double>::const_iterator it = bitcoinPrices.find(date);
    if (it != bitcoinPrices.end()) {
        return it->second;
    }
    if (bitcoinPrices.empty()) {
        return 0.0;
    }
    if (date < bitcoinPrices.begin()->first) {
        return bitcoinPrices.begin()->second;
    }
    if (date > bitcoinPrices.rbegin()->first) {
        return bitcoinPrices.rbegin()->second;
    }
    std::map<std::string, double>::const_iterator upper = bitcoinPrices.upper_bound(date);
    std::map<std::string, double>::const_iterator lower = upper;
    --lower;
    double upperDist = std::abs(std::difftime(std::mktime(std::get_time(&std::tm(), upper->first.c_str())), std::mktime(std::get_time(&std::tm(), date.c_str()))));
    double lowerDist = std::abs(std::difftime(std::mktime(std::get_time(&std::tm(), lower->first.c_str())), std::mktime(std::get_time(&std::tm(), date.c_str()))));
    if (upperDist <= lowerDist) {
        return upper->second;
    } else {
        return lower->second;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " input.txt" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    // Load bitcoin prices into a map
    std::map<std::string, double> bitcoinPrices;
    std::ifstream bitcoinPricesFile("data.csv");
    if (!bitcoinPricesFile.is_open()) {
        std::cout << "Error: could not open bitcoin price database." << std::endl;
        return 1;
   
}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <map>
//#include <sstream>
//#include <cmath>
//
//using namespace std;
//
//// Fonction qui convertit une chaîne de caractères en une date struct tm
//bool parse_date(const string& s, struct tm& date)
//{
//    if (s.length() != 10) return false;
//    stringstream ss(s);
//    ss >> date.tm_year;
//    ss.ignore(1);
//    ss >> date.tm_mon;
//    ss.ignore(1);
//    ss >> date.tm_mday;
//    if (ss.fail() || !ss.eof()) return false;
//    date.tm_year -= 1900;
//    date.tm_mon -= 1;
//    return true;
//}
//
//int main(int argc, char* argv[])
//{
//    if (argc < 2) {
//        cerr << "Usage: " << argv[0] << " input_file" << endl;
//        return 1;
//    }
//
//    // Chargement des données de prix bitcoin depuis le fichier csv
//    map<time_t, double> bitcoin_prices;
//    ifstream data_file(argv[1]);
//    if (!data_file) {
//        cerr << "Error: could not open bitcoin_prices.csv." << endl;
//        return 1;
//    }
//    string line;
//    getline(data_file, line); // Ignorer la première ligne (entêtes de colonnes)
//    while (getline(data_file, line)) {
//        stringstream ss(line);
//        string date_str;
//        double price;
//        getline(ss, date_str, ',');
//        ss >> price;
//        if (ss.fail() ) {
//            cerr << "Error: bad input => " << line << endl;
//            continue;
//        }
//        struct tm date;
//        parse_date(date_str, date);
//        bitcoin_prices[mktime(&date)] = price;
//    }
//    data_file.close();
//
//    // Lecture du fichier d'entrée et calcul des prix en euros
//    ifstream input_file(argv[1]);
//    if (!input_file) {
//        cerr << "Error: could not open file." << endl;
//        return 1;
//    }
//    while (getline(input_file, line)) {
//        stringstream ss(line);
//        string date_str;
//        double value;
//        getline(ss, date_str, '|');
//        ss >> value;
//        if (ss.fail() || value < 0 || value > 1000) {
//            cerr << "Error: not a positive number." << endl;
//            continue;
//        }
//        struct tm date;
//        if (!parse_date(date_str, date)) {
//            cerr << "Error: bad input => " << line << endl;
//            continue;
//        }
//        time_t target_time = mktime(&date);
//        if (bitcoin_prices.empty()) {
//            cerr << "Error: no bitcoin price data available." << endl;
//            continue;
//        }
//        if (target_time < bitcoin_prices.begin()->first) {
//            cout << date_str << " => " << value << " = 0" << endl;
//            continue;
//        }
//        map<time_t, double>::const_iterator it = bitcoin_prices.lower_bound(target_time);
//        if (it == bitcoin_prices.end()) --it;
//        else if (it != bitcoin_prices.begin() && abs(target_time - it->first) > abs(target_time - (--it)->first)) ++it;
//        cout << date_str << " => " << value << " = " << (value * it->second / 1000) << endl;
//    }
//}
