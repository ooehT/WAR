#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.hpp"  // Inclui a definição da classe base Unidade.
#include <iostream>     // Inclui bibliotecas padrão para entrada e saída.
#include <vector>       // Inclui a biblioteca padrão para vetores.
#include <string>       // Inclui a biblioteca padrão para strings.
#include <iomanip>      // Inclui a biblioteca padrão para formatação de saída.

// Declaração da classe Veiculo, que herda da classe Unidade.
class Veiculo : public Unidade {
private:
    int blindagem;       // Representa a resistência do veículo (valor entre 30 e 70, definido no construtor).
    int potenciaDeFogo;  // Representa a potência de ataque do veículo (valor entre 20 e 50, definido no construtor).

public:
    // Construtor da classe Veiculo
    Veiculo();

    // Método sobrescrito (override) para calcular o poder de ataque específico do veículo.
    double getPoderAtaque() override;
};

#endif
