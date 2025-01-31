#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>   
#include "Unidade.h"
#include "Infantaria.h"
#include "Veiculo.h"
#include "Aeronave.h" 
using namespace std;

class Unidade : Exercito {
protected:
    int poderAtaque;
    int destruicoes;

public:
    Unidade(int poderAtaque, int destruicoes);
    virtual ~Unidade();  // Destrutor virtual para evitar memory leaks
    virtual double getPoderAtaque() const { return poderAtaque; }
    void somaDestruicao();
};

//Unidade :: Unidade(int poderAtaque, int destruicoes) : poderAtaque(poderAtaque), destruicoes(destruicoes) {}

Unidade::~Unidade() {}

void Unidade::somaDestruicao() {
    destruicoes++;
}

int gerarAleatorio(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    vector<Unidade*> exercito;

    // Criando unidades com valores aleatórios
    exercito.push_back(new Infantaria(gerarAleatorio(30, 60), 0, gerarAleatorio(20, 50), gerarAleatorio(10, 40)));
    exercito.push_back(new Veiculo(gerarAleatorio(40, 80), 0, gerarAleatorio(30, 70), gerarAleatorio(20, 50)));
    exercito.push_back(new Infantaria(gerarAleatorio(30, 60), 0, gerarAleatorio(20, 50), gerarAleatorio(10, 40)));
    exercito.push_back(new Veiculo(gerarAleatorio(40, 80), 0, gerarAleatorio(30, 70), gerarAleatorio(20, 50)));
    exercito.push_back(new Aeronave(gerarAleatorio(50, 90), 0, gerarAleatorio(30, 70), gerarAleatorio(20, 50)));

    // Exibindo poder de ataque de cada unidade
    for (const auto& unidade : exercito) {
        cout << "Poder de Ataque: " << unidade->getPoderAtaque() << endl;
    }

    // Limpando memória
    for (auto& unidade : exercito) {
        delete unidade;
    }

    return 0;
}
