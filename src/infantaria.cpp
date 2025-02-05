#ifndef EXERCITO_HPP
#define EXERCITO_HPP
#include "infantaria.hpp"
using namespace std;

#include <cstdlib> // Para rand()

Infantaria::Infantaria() : Unidade(rand() % 31 + 30, 0) { 
    forca = rand() % 31 + 20;
    velocidade = rand() % 31 + 10;
}

double Infantaria::getPoderAtaque() const {
    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10;
}

#endif // EXERCITO_H