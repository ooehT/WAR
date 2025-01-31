#include "aeronave.h"
using namespace std;

Aeronave::Aeronave(int poderAtaque, int destruicoes, int forca, int velocidade)
    : Unidade(poderAtaque, destruicoes), manobrabilidade(manobrabilidade), alcance(alcance) {}

double Aeronave::getPoderAtaque() const {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}