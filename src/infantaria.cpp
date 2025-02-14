#ifndef EXERCITO_HPP
#define EXERCITO_HPP

#include "infantaria.hpp"  // Inclui o cabeçalho da classe Infantaria
using namespace std;

#include <cstdlib> // Para a função rand()

// Construtor da classe Infantaria
Infantaria::Infantaria() : Unidade(rand() % 31 + 30, 0) { 
    // O construtor chama o construtor da classe base `Unidade` inicializando:
    // - `poderAtaque` (primeiro argumento) com um valor aleatório entre 30 e 60 (rand() % 31 + 30).
    // - Outro atributo (provavelmente resistência ou defesa, segundo argumento) como 0.

    forca = rand() % 31 + 20;    // Define a força da infantaria com um valor aleatório entre 20 e 50.
    velocidade = rand() % 31 + 10; // Define a velocidade da infantaria com um valor aleatório entre 10 e 40.
}

// Função para calcular e retornar o poder de ataque da infantaria
double Infantaria::getPoderAtaque() {
    // Calcula o poder de ataque da unidade de infantaria com uma média ponderada dos atributos:
    // - `poderAtaque` (herdado da classe base) tem peso 5.
    // - `forca` tem peso 3.
    // - `velocidade` tem peso 2.
    // O resultado é dividido por 10 para normalizar.

    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10;
}

#endif // EXERCITO_H
