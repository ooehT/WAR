#ifndef EXERCITO_H
#define EXERCITO_H
#include "infantaria.h"
using namespace std;


Infantaria::Infantaria(int poderAtaque, int destruicoes, int forca, int velocidade)
    : Unidade(poderAtaque, destruicoes), forca(forca), velocidade(velocidade) {}

double Infantaria::getPoderAtaque() const {
    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10.0;

}

#endif // EXERCITO_H