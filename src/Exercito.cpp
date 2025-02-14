#include "Exercito.hpp"
#include "Infantaria.hpp"
#include "Veiculo.hpp"
#include "Aeronave.hpp"
#include <iostream>

using namespace std;

// Construtor padrão: inicializa o nome e os contadores de resultados
Exercito::Exercito() {
    nome = "";  // Nome vazio por padrão
    vitorias = 0;  // Inicializa as vitórias com 0
    derrotas = 0;  // Inicializa as derrotas com 0
}

// Define o valor da flag como 1
void Exercito::setFlag(){
    flag = 1;
}

// Reseta o valor da flag para 0
void Exercito::resetFlag(){
    flag = 0;
}

// Construtor que inicializa o nome do exército
Exercito::Exercito(std::string nome) {
    this->nome = nome;  // Atribui o nome passado como parâmetro
    vitorias = 0;  // Inicializa as vitórias com 0
    derrotas = 0;  // Inicializa as derrotas com 0
}

// Adiciona novas unidades ao exército
void Exercito::adicionaUnidades() {
    // Libera memória das unidades existentes
    for (auto& u : unidades) {
        delete u;  // Deleta cada unidade existente
    }
    unidades.clear();  // Limpa o vetor de unidades

    // Adiciona novas unidades ao exército
    unidades.push_back(new Infantaria());  // Adiciona uma unidade do tipo Infantaria
    unidades.push_back(new Infantaria());  // Adiciona outra unidade do tipo Infantaria
    unidades.push_back(new Veiculo());    // Adiciona uma unidade do tipo Veículo
    unidades.push_back(new Veiculo());    // Adiciona outra unidade do tipo Veículo
    unidades.push_back(new Aeronave());   // Adiciona uma unidade do tipo Aeronave
}

// Apaga todas as unidades do exército
void Exercito::apagaVet(){
    for (auto& u : unidades) {
        delete u;  // Deleta cada unidade
    }
    unidades.clear();  // Limpa o vetor de unidades
}

// Registra uma vitória para o exército
void Exercito::registraVitoria() {
    vitorias++;  // Incrementa o contador de vitórias
}

// Registra uma derrota para o exército
void Exercito::registraDerrota() {
    derrotas++;  // Incrementa o contador de derrotas
}

// Registra um empate para o exército
void Exercito::registraEmpate() {
    empates++;  // Incrementa o contador de empates
}

// Imprime o poder de ataque das unidades do exército
void Exercito::imprimeUnidades() const {
    cout << "Unidades do exercito \"" << nome << "\":" << endl;  // Exibe o nome do exército
    for (const auto& unidade : unidades) {  // Para cada unidade do exército
        cout << " - Poder de Ataque: " << unidade->getPoderAtaque() << endl;  // Exibe o poder de ataque da unidade
    }
}

// Destrutor: limpa o vetor de unidades e libera a memória alocada
Exercito::~Exercito() {
    for (auto& u : unidades) {
        delete u;  // Deleta cada unidade armazenada no vetor
    }
    unidades.clear();  // Limpa o vetor de unidades após liberar a memória
}
