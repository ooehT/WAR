#include "Veiculo.hpp"
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

Veiculo::Veiculo() : Unidade(rand() % 41 + 40, 0) { 

    blindagem = rand() % 41 + 30;   // 30 a 70
    potenciaDeFogo = rand() % 31 + 20;
}
double Veiculo::getPoderAtaque() {
    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
}