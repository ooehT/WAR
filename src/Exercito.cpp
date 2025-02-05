#include "Exercito.hpp"
#include "Infantaria.hpp"
#include "Veiculo.hpp"
#include "Aeronave.hpp"
#include <iostream>


using namespace std;

// Construtor: inicializa o nome e os contadores de resultados
Exercito::Exercito() {
    // Construtor padrão
    nome = "";  // Valor default
    vitorias = 0;
    derrotas = 0;
}

Exercito::Exercito(std::string nome) {
    this->nome = nome;
    vitorias = 0;
    derrotas = 0;
}
// Adiciona uma unidade ao exército
void Exercito::adicionaUnidades() {
    unidades.push_back(new Infantaria());
    unidades.push_back(new Infantaria());
    unidades.push_back(new Veiculo());
    unidades.push_back(new Veiculo());
    unidades.push_back(new Aeronave());
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

    void Exercito::imprimeUnidades() const {
        cout << "Unidades do exército \"" << nome << "\":" << endl;
        for (const auto& unidade : unidades) {
        cout << " - Poder de Ataque: " << unidade->getPoderAtaque() << endl;
        }
}

Exercito::~Exercito() {
    for (auto& u : unidades) {
        delete u;  // Deleta cada ponteiro armazenado no vetor
    }
    unidades.clear();  // Limpa o vetor após deletar os elementos
}
