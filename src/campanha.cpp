#include "Campanha.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Construtor
Campanha::Campanha() {}

// Adiciona uma batalha à campanha
void Campanha::adicionarBatalha(Batalha* batalha) {
    batalhas.push_back(batalha);
}

// Simula todas as batalhas
void Campanha::simularBatalhas() {
    for (auto& batalha : batalhas) {
        batalha->ataqueExercitoA();
        batalha->ataqueExercitoB();
        cout << batalha->getResultado() << endl;
    }
}

// Gera a tabela de posições
void Campanha::gerarTabelaDePosicoes() {
    map<string, int> resultados; // Mapeia os nomes dos exércitos para pontos

    for (auto& batalha : batalhas) {
        string resultado = batalha->getResultado();
        // Exemplo de parse simplificado
        size_t posA = resultado.find(" ");
        size_t posX = resultado.find("x");
        size_t posB = resultado.rfind(" ");

        string nomeA = resultado.substr(0, posA);
        string nomeB = resultado.substr(posB + 1);

        int pontosA = stoi(resultado.substr(posA + 1, posX - posA - 1));
        int pontosB = stoi(resultado.substr(posX + 1, posB - posX - 1));

        resultados[nomeA] += pontosA;
        resultados[nomeB] += pontosB;
    }

    cout << "Tabela de posições:\n";
    for (const auto& [nome, pontos] : resultados) {
        cout << nome << ": " << pontos << " pontos\n";
    }
}

// Mostra a unidade mais destrutiva
void Campanha::mostrarUnidadeMaisDestrutiva() {
    Unidade* unidadeMaisDestrutiva = nullptr;
    int maxDestruicao = 0;

    for (auto& batalha : batalhas) {
        // Adapte para acessar unidades dos exércitos A e B
        auto unidadesA = batalha->getExercitoA()->getUnidades();
        auto unidadesB = batalha->getExercitoB()->getUnidades();

        for (auto unidade : unidadesA) {
            if (unidade->getDestruicoes() > maxDestruicao) {
                maxDestruicao = unidade->getDestruicoes();
                unidadeMaisDestrutiva = unidade;
            }
        }

        for (auto unidade : unidadesB) {
            if (unidade->getDestruicoes() > maxDestruicao) {
                maxDestruicao = unidade->getDestruicoes();
                unidadeMaisDestrutiva = unidade;
            }
        }
    }

    if (unidadeMaisDestrutiva) {
        cout << "Unidade mais destrutiva:\n";
        cout << "Poder de ataque: " << unidadeMaisDestrutiva->getPoderAtaque() << "\n";
        cout << "Número de destruições: " << unidadeMaisDestrutiva->getDestruicoes() << "\n";
    } else {
        cout << "Nenhuma unidade registrou destruições.\n";
    }
}

// Destrutor
Campanha::~Campanha() {
    for (auto& batalha : batalhas) {
        delete batalha;
    }
}
