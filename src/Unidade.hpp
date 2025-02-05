
#ifndef UNIDADE_HPP
#define UNIDADE_HPP
using namespace std;
 // Mantemos aqui porque precisamos da definição completa
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Exercito.hpp" 
class Unidade {
protected:
    int poderAtaque;
    int destruicoes;

public:
    Unidade();
    Unidade(int poderAtaque, int destruicoes);
    virtual ~Unidade();

    virtual double getPoderAtaque() const = 0;
    virtual void somaDestruicao();
};

#endif