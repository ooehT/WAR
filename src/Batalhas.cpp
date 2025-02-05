#include "Batalhas.hpp"
#include <iostream>
#include <cstdlib> // Para rand()
#include "Unidade.hpp"
using namespace std;
#include "Batalhas.hpp"
#include "Exercito.hpp"
#include "Date.hpp"
#include "Campanha.hpp"
#include <windows.h>

// Construtor: inicializa a batalha com a data e os dois exércitos
Batalhas::Batalhas()
    : data(""), exercitoA(nullptr), exercitoB(nullptr), pontuacaoA(0), pontuacaoB(0), exercitos() {}



// Simula um ataque do Exército A
void Batalhas::atribuiExercitoA(Exercito* a) { 
    // Calcula o poder total do Exército A
    exercitoA = a;
    a->adicionaUnidades();
    pontuacaoA = 0;
    
    // Agora percorre as unidades e soma seus poderes de ataque
    for (const auto& unidade : exercitoA->getUnidades()) {
        pontuacaoA += unidade->getPoderAtaque();

    }
}
    void Batalhas::resetarPontuacoes() {
    pontuacaoA = 0;
    pontuacaoB = 0;
    }

// Simula um ataque do Exército B
void Batalhas::atribuiExercitoB(Exercito* b) { 
    // Calcula o poder total do Exército B
    exercitoB = b;
    b->adicionaUnidades();
    pontuacaoB = 0;
    
    // Agora percorre as unidades e soma seus poderes de ataque
    for (const auto& unidade : exercitoB->getUnidades()) {
        pontuacaoB += unidade->getPoderAtaque();
    }
}
    string Batalhas::getResultados() const {
    ostringstream resultado;
    resultado << "Data: " << data << "\n";
    resultado << "\nExército A: " << exercitoA->getNome() << " (" << pontuacaoA << " pontos)\n";
    resultado << "Exército B: " << exercitoB->getNome() << " (" << pontuacaoB << " pontos)\n";

    if (pontuacaoA > pontuacaoB) {
        resultado << "\nVitória do "<< exercitoA->getNome();
    } else if (pontuacaoA < pontuacaoB) {
        resultado << "\nVitória do "<< exercitoB->getNome();
    } else {
        resultado << "Empate!";
    }

    return resultado.str();
}


void Batalhas::setData(string d){
    data = d;
}

// Destrutor
Batalhas::~Batalhas() {
    for (auto* exercito : exercitos) {  // Para cada ponteiro no vetor
        delete exercito;  // Libera a memória do objeto Batalhas
    }
    exercitos.clear();  // Esvazia o vetor
}

