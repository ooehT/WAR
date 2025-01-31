#ifndef AERONAVE_H
#define AERONAVE_H

#include "Unidade.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Classe derivada: Aeronave
class Aeronave : public Unidade {
private:
    int manobrabilidade;
    int alcance;

public:
    Aeronave(int poderAtaque, int destruicoes, int manobrabilidade, int alcance)
        : Unidade(poderAtaque, destruicoes), manobrabilidade(manobrabilidade), alcance(alcance) {}

    double getPoderAtaque() const override {
        return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
    }
};
#endif 