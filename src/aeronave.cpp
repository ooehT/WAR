#include "aeronave.hpp"
using namespace std;

Aeronave::Aeronave() : Unidade( rand() % 41 + 50, 0) {
    manobrabilidade = rand() % 41 + 30;
    alcance = rand() % 31 + 20;
}

double Aeronave::getPoderAtaque() const {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}