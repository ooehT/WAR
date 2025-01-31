#include "Batalhas.h"
#include <iostream>
#include <cstdlib> // Para rand()
#include "Unidade.h"
using namespace std;
#include "Batalhas.h"
#include "Exercito.h"

// Construtor: inicializa a batalha com a data e os dois exércitos
Batalha::Batalha(const std::string& data, Exercito* exercitoA, Exercito* exercitoB,)
    : data(data), exercitoA(exercitoA), exercitoB(exercitoB), pontuacaoA(0), pontuacaoB(0) {}


// Simula um ataque do Exército A
void Batalha::ataqueExercitoA() {
    // Calcula o poder total do Exército A
    double poderTotalA = 0.0;
    for (const auto& unidade : exercitoA->imprimeUnidades()) { // Certifique-se de ter um método `imprimeUnidades()` em `Exercito`
        poderTotalA += unidade->getPoderAtaque();
    }

    // Adiciona pontuação aleatória com base no poder de ataque
    pontuacaoA += static_cast<int>(poderTotalA * ((rand() % 101) / 100.0));
}

// Simula um ataque do Exército B
void Batalha::ataqueExercitoB() {
    // Calcula o poder total do Exército B
    double poderTotalB = 0.0;
    for (const auto& unidade : exercitoB->imprimeUnidades()) { // Certifique-se de ter um método `imprimeUnidades()` em `Exercito`
        poderTotalB += unidade->getPoderAtaque();
    }

    // Adiciona pontuação aleatória com base no poder de ataque
    pontuacaoB += static_cast<int>(poderTotalB * ((rand() % 101) / 100.0));
}

// Retorna o resultado da batalha
std::string Batalha::getResultado() const {
    return exercitoA->getNome() + " " + std::to_string(pontuacaoA) + " x " +
           std::to_string(pontuacaoB) + " " + exercitoB->getNome();
}

// Destrutor
Batalha::~Batalha() {
    // Nada para liberar, os exércitos são gerenciados externamente
}
