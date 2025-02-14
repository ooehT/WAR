#include "Batalhas.hpp"
#include <iostream>
#include <cstdlib> // Para rand(), que pode ser utilizado em simulações de batalha
#include "Unidade.hpp"
using namespace std;
#include "Batalhas.hpp"
#include "Exercito.hpp"
#include "Date.hpp"
#include "Campanha.hpp"
#include <windows.h>  // Para manipulação de janelas no Windows (se necessário)

// Construtor: inicializa a batalha com a data e os dois exércitos
Batalhas::Batalhas()
    : data(""), exercitoA(nullptr), exercitoB(nullptr), pontuacaoA(0), pontuacaoB(0), exercitos() {}

// Simula um ataque do Exército B e retorna o resultado da batalha em formato de string
string Batalhas::getResultados() const {
    ostringstream resultado;
    resultado << "\nData: " << data << "\n";  // Mostra a data da batalha
    resultado << "\nExercito : " << exercitoA->getNome() << "\n" << endl;  // Nome do Exército A
    resultado << "Exercito : " << exercitoB->getNome() << "\n" << endl;  // Nome do Exército B

    // Verifica se algum dos exércitos venceu com base no flag ou nas pontuações
    if (exercitoA->getFlag() == true || pontuacaoA == 1) {
        resultado << "\nVitoria do " << exercitoA->getNome();  // Se Exército A venceu
    } else if (exercitoB->getFlag() == true || pontuacaoB == 1) {
        resultado << "\nVitoria do " << exercitoB->getNome();  // Se Exército B venceu
    } else if (exercitoA->getFlag() == false && exercitoB->getFlag() == false) {
        resultado << "Empate!";  // Se nenhum dos exércitos venceu
    }

    return resultado.str();  // Retorna o resultado da batalha como string
}

// Atribui os dois exércitos à batalha
void Batalhas::atribuiExercito(Exercito* a, Exercito* b) {
    exercitoA = a;  // Define o Exército A
    exercitoB = b;  // Define o Exército B
    pontuacaoA = a->getFlag();  // Atribui a pontuação do Exército A
    pontuacaoB = b->getFlag();  // Atribui a pontuação do Exército B
}

// Define a data da batalha
void Batalhas::setData(string d) {
    data = d;  // Define a data fornecida
}

// Destrutor: libera memória dos objetos alocados dinamicamente
Batalhas::~Batalhas() {
    for (auto* exercito : exercitos) {  // Para cada ponteiro no vetor de exércitos
        delete exercito;  // Libera a memória alocada para o objeto Exército
    }
    exercitos.clear();  // Esvazia o vetor após deletar os exércitos
}
