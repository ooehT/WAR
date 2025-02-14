#include "aeronave.hpp"  // Inclui o cabeçalho da classe Aeronave.
using namespace std;

// Construtor da classe Aeronave
Aeronave::Aeronave() : Unidade(rand() % 41 + 50, 0) {
    // Inicializa a manobrabilidade com um valor aleatório entre 30 e 70.
    manobrabilidade = rand() % 41 + 30;

    // Inicializa o alcance com um valor aleatório entre 20 e 50.
    alcance = rand() % 31 + 20;
}

// Método que calcula o poder de ataque da aeronave.
double Aeronave::getPoderAtaque() {
    // Fórmula ponderada para calcular o poder de ataque:
    // - `poderAtaque` contribui com peso 5.
    // - `manobrabilidade` contribui com peso 3.
    // - `alcance` contribui com peso 2.
    // A média ponderada é dividida por 10 para obter o valor final.
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}
