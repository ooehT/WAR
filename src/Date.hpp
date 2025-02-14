#ifndef DATE_HPP
#define DATE_HPP

#include <string>  // Para manipulação de strings

// Definição da classe Date, que representa uma data
class Date {
private:
    int day, month, year;  // Atributos que armazenam o dia, mês e ano da data

public:
    // Construtor da classe Date, inicializa a data com o dia, mês e ano fornecidos
    Date(int d, int m, int y);

    // Método que retorna a data formatada como uma string no formato dd/mm/yyyy
    std::string toString() const;  
};

#endif
