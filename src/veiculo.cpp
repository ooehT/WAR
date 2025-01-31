#include "Veiculo.h"
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

Veiculo::Veiculo(int poderAtaque, int destruicoes, int forca, int velocidade)
    : Unidade(poderAtaque, destruicoes), blindagem(blindagem), potenciaDeFogo(potenciaDeFogo) {}

double Veiculo::getPoderAtaque() const {
    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
}