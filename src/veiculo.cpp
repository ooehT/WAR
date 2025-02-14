#include "Veiculo.hpp"  // Inclui o cabeçalho da classe Veiculo
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Construtor da classe Veiculo
Veiculo::Veiculo() : Unidade(rand() % 41 + 40, 0) { 
    // O construtor chama o construtor da classe base `Unidade` inicializando:
    // - o poder de ataque (primeiro argumento) com um valor aleatório entre 40 e 80 (rand() % 41 + 40).
    // - a resistência ou outro atributo (segundo argumento) como 0.

    blindagem = rand() % 41 + 30;  // Define a blindagem do veículo como um valor aleatório entre 30 e 70.
    potenciaDeFogo = rand() % 31 + 20;  // Define a potência de fogo como um valor aleatório entre 20 e 50.
}

// Função para calcular e retornar o poder de ataque do veículo
double Veiculo::getPoderAtaque() {
    // A fórmula calcula o poder de ataque do veículo com base em seus atributos:
    // - `poderAtaque` tem peso 5.
    // - `blindagem` tem peso 4.
    // - `potenciaDeFogo` tem peso 1.
    // O resultado é uma média ponderada dos valores, dividida por 10.

    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
}
