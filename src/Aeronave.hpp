#ifndef AERONAVE_HPP
#define AERONAVE_HPP

#include "Unidade.hpp"  // Inclui a classe Unidade, da qual Aeronave herda
#include <iostream>  // Para entrada e saída padrão
#include <vector>    // Para usar vetores
#include <string>    // Para usar strings
#include <iomanip>   // Para manipulação de entrada e saída formatada

class Aeronave : public Unidade {  // Define a classe Aeronave, que herda de Unidade
private:
    int manobrabilidade;  // Atributo que representa a manobrabilidade da aeronave
    int alcance;          // Atributo que representa o alcance da aeronave

public:
    Aeronave();  // Construtor padrão
    double getPoderAtaque() override;  // Método para calcular o poder de ataque da aeronave
};

#endif  // Fim do cabeçalho da classe Aeronave
