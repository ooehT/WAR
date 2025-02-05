#include "date.hpp"
using namespace std;

#include "Date.hpp"
#include <iomanip>  // Para formatação
#include <sstream>  // Para conversão de número para string

// Construtor da classe Date
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Método para converter a data para string
std::string Date::toString() const {
    std::ostringstream oss;
    oss << (day < 10 ? "0" : "") << day << "/" 
        << (month < 10 ? "0" : "") << month << "/" 
        << year;
    return oss.str();
}
