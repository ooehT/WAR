
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


#ifndef EXERCITO_H
#define EXERCITO_H

class Unidade;

class Exercito {
private:
    std::string nome;                      // Nome do exército
    int vitorias;                          // Número de vitórias
    int derrotas;                          // Número de derrotas
    int empates;                           // Número de empates
    std::vector<Unidade*> unidade;        // Lista de unidades do exército

public:
    // Construtor que recebe apenas o nome do exército
    Exercito(const std::string& nome);

    const std::vector<Unidade*>& getUnidades() const { return unidade; }

    // Adiciona uma unidade ao exército
    void adicionaUnidade(Unidade* unidade);

    // Atualiza o histórico de batalhas
    void registraVitoria();
    void registraDerrota();
    void registraEmpate();

    // Retorna o histórico de resultados no formato especificado
    std::string getResultados() const;

    // Imprime todas as unidades do exército
    const std::string& imprimeUnidades() const;


    std::string getNome() const;

    
    // Destrutor para liberar as unidades
    ~Exercito();
};

#endif