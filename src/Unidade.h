#ifndef UNIDADE_H
#define UNIDADE_H
#include "Exercito.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Unidade : public Exercito {
protected:
    int poderAtaque;
    int destruicoes;

public:
    // Construtor
    Unidade(int poderAtaque, int destruicoes);

    // Método virtual puro
    virtual double getPoderAtaque();

    // Incrementar destruições
    virtual void somaDestruicao();

    // Destrutor virtual
    virtual ~Unidade();
};

#endif