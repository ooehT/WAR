#include "date.hpp" // Inclui o cabeçalho "date.hpp", que deve conter a declaração da classe Date.
using namespace std;

#include "Date.hpp" // Inclui outro cabeçalho, "Date.hpp". Pode ser redundante se ambos se referirem à mesma coisa.
#include <iomanip>  // Biblioteca padrão C++ usada para formatação de saída.
#include <sstream>  // Biblioteca padrão C++ usada para manipular strings via stream (conversão de número para string).

// Construtor da classe Date
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    // Inicializa os atributos privados da classe `day`, `month` e `year` com os valores fornecidos como argumentos (d, m, y).
}

// Método para converter a data para string no formato "dd/mm/yyyy"
std::string Date::toString() const {
    std::ostringstream oss;  // Cria um objeto string stream para construir a string formatada.

    // Formata o dia, adicionando um zero à esquerda se for menor que 10.
    // Formata o mês, adicionando um zero à esquerda se for menor que 10.
    // Adiciona o ano no final.
    oss << (day < 10 ? "0" : "") << day << "/"  // Verifica se o dia é menor que 10 e adiciona um "0" à esquerda se necessário.
        << (month < 10 ? "0" : "") << month << "/"  // Faz o mesmo para o mês.
        << year;  // Adiciona o ano como está.

    return oss.str();  // Retorna a string formatada.
}
