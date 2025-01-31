#include "Exercito.h"
#include <iostream>
#include "Unidade.h"

using namespace std;

// Construtor: inicializa o nome e os contadores de resultados
Exercito::Exercito(const std::string& nome) : nome(nome), vitorias(0), derrotas(0), empates(0) {}

// Adiciona uma unidade ao exército
void Exercito::adicionaUnidade(Unidade* unidade) {
    unidade.push_back(unidade);
}

// Registra uma vitória
void Exercito::registraVitoria() {
    vitorias++;
}

// Registra uma derrota
void Exercito::registraDerrota() {
    derrotas++;
}

// Registra um empate
void Exercito::registraEmpate() {
    empates++;
}

// Retorna o histórico de resultados
std::string Exercito::getResultados() const {
    return "Vitórias: " + std::to_string(vitorias) + ", Empates: " + std::to_string(empates) + 
           ", Derrotas: " + std::to_string(derrotas);
}

// Imprime todas as unidades do exército
const std::string& Exercito::imprimeUnidades() const {
    cout << "Unidades do exército \"" << nome << "\":" << endl;
    for (const auto& unidade : unidade) {
        cout << " - Poder de Ataque: " << unidade->getPoderAtaque() << endl;
    }
}
std::string Exercito::getNome() const {
    return nome;
}

// Destrutor: libera a memória das unidades
Exercito::~Exercito() {
 for (auto& unidade : unidade) {
    delete unidade;  // Deleta cada ponteiro armazenado no vetor
}
unidade.clear();  // Limpa o vetor após deletar os elementos

}
