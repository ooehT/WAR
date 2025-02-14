#include <iostream>     // Biblioteca padrão para entrada e saída.
#include <vector>       // Biblioteca padrão para uso de vetores.
#include <cstdlib>      // Biblioteca para uso de funções rand() e srand().
#include <ctime>        // Biblioteca para manipulação de tempo.
#include "Unidade.hpp"  // Inclui o cabeçalho da classe Unidade.
#include "Exercito.hpp" // Inclui o cabeçalho da classe Exercito (provavelmente para futuras implementações).
#include "Infantaria.hpp" // Inclui o cabeçalho da classe Infantaria (provavelmente para futuras implementações).

using namespace std;

// Implementação do construtor parametrizado da classe Unidade.
Unidade::Unidade(int poderAtaque, int destruicoes) {
    // Inicializa os atributos com os valores passados como argumentos.
    this->poderAtaque = poderAtaque;
    this->destruicoes = destruicoes;
}

// Implementação do método getPoderAtaque().
// Retorna o poder de ataque da unidade.
double Unidade::getPoderAtaque() {
    return poderAtaque;
}

// Implementação do destrutor da classe Unidade.
// Não realiza nenhuma operação, mas foi declarado como virtual na classe base
// para garantir que as subclasses possam liberar recursos adequadamente.
Unidade::~Unidade() {}

// Implementação do método somaDestruicao().
// Incrementa o contador de destruições realizadas pela unidade.
void Unidade::somaDestruicao() {
    destruicoes++;
}


