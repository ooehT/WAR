#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y); // Construtor
    std::string toString() const; // Retorna a data formatada como string
};

#endif
