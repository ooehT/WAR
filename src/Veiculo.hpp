#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Veiculo : public Unidade {
private:
    int blindagem;
    int potenciaDeFogo;

public:
    Veiculo();
    double getPoderAtaque() const override;
};

#endif 