#include "Campanha.hpp"
#include "Batalhas.hpp"
#include <iostream>
#include <cstdlib>  // Para rand()
#include <ctime>   
#include "Exercito.hpp" // Para inicializar números aleatórios

using namespace std;

// Construtor
Campanha::Campanha() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios
}

// Sorteia dois exércitos e inicia uma batalha entre eles
void Campanha::simularBatalhas(Batalhas& a) {
    
    if (a.getPontuacaoA() > a.getPontuacaoB()) {
        cout << "\nVitoria do Exercito A! (" << a.getPontuacaoA() << " - " << a.getPontuacaoB() << ")";
        a.resetarPontuacoes();
        
    } else if (a.getPontuacaoA() < a.getPontuacaoB()) {
        cout << "\nVitoria do Exercito B! (" << a.getPontuacaoA() << " - " << a.getPontuacaoB() << ")";
        a.resetarPontuacoes();
        
    } else {
        cout << "\nEmpate! (" << a.getPontuacaoA() << " - " << a.getPontuacaoB() << ")";
        a.resetarPontuacoes();
        
    }

}
void Campanha::adcicionaHistorico(Batalhas a) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(localTime, "%d/%m/%Y %H:%M");
    a.setData(oss.str());  // Primeiro, defina a data corretamente
    batalhas.push_back(a); // Só então adicione ao vetor
        
}


void Campanha::exibirHistorico() const {
    if (batalhas.empty()) {
        cout << "Nenhuma batalha ocorreu ainda." << endl;
        return;
    }

    cout << "\n=== Histórico de Batalhas ===" << endl;
    for (const auto& batalha : batalhas) {
        cout << "\nExércitos envolvidos:" << endl;
        cout << batalha.getResultados() << endl;
        
        }
    }
    

// Destrutor - Libera memória das batalhas
Campanha::~Campanha() {
    batalhas.clear();  // Apenas limpa o vetor (nenhum delete necessário!)
}