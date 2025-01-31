#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


// Classe derivada: Veiculo
class Veiculo : public Unidade {
private:
    int blindagem;
    int potenciaDeFogo;

public:
    Veiculo(int poderAtaque, int destruicoes, int blindagem, int potenciaDeFogo)
        : Unidade(poderAtaque, destruicoes), blindagem(blindagem), potenciaDeFogo(potenciaDeFogo) {}

    double getPoderAtaque() const override {
        return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
    }
};

#endif 