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

    
    
// Simula um ataque do Exército B
    string Batalhas::getResultados()const
    {
    ostringstream resultado;
    resultado << "\nData: " << data << "\n";
    resultado << "\nExercito : " << exercitoA->getNome() <<"\n"<< endl;
    resultado << "Exercito : " << exercitoB->getNome() <<"\n"<< endl;

    if (exercitoA->getFlag() == true || pontuacaoA == 1) {
        resultado << "\nVitoria do "<< exercitoA->getNome();

    } else if (exercitoB->getFlag() == true || pontuacaoB == 1) {
        resultado << "\nVitoria do "<< exercitoB->getNome();

    } else if( exercitoA->getFlag() == false && exercitoB->getFlag() == false){
        resultado << "Empate!";

    }
   

    return resultado.str();
}

void Batalhas::atribuiExercito(Exercito* a, Exercito* b){
    exercitoA = a;
    exercitoB = b;
    pontuacaoA = a->getFlag();
    pontuacaoB = b->getFlag();
}
void Batalhas::setData(string d){
    data = d;
}
/*void Batalhas::registraVitoria(Exercito* a, Exercito *b){
    if (pontuacaoA > pontuacaoB) {
       a->registraVitoria();
       a->registraDerrota();

    } else if (pontuacaoA < pontuacaoB) {
        b->registraVitoria();
        a->registraDerrota();

    } else {
        a->registraEmpate();
        b->registraEmpate();

    }
}
*/
// Destrutor
Batalhas::~Batalhas() {
    for (auto* exercito : exercitos) {  // Para cada ponteiro no vetor
        delete exercito;  // Libera a memória do objeto Batalhas
    }
    exercitos.clear();  // Esvazia o vetor
}

