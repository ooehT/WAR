#ifndef EXERCITO_HPP
#define EXERCITO_HPP
// Garantia de inclusão única do arquivo de cabeçalho

#include <iostream>  // Para manipulação de entrada e saída
#include <vector>  // Para usar o tipo de dados vetor
#include <string>  // Para manipulação de strings
#include <iomanip>  // Para formatação de saída

using namespace std;

// Declaração antecipada da classe Unidade
class Unidade;

class Exercito {
private:
    string nome;  // Nome do exército
    int vitorias;  // Contador de vitórias
    int derrotas;  // Contador de derrotas
    int empates;  // Contador de empates
    int pontucaoA, pontuacaoB;  // Variáveis para cálculo de pontuação durante as batalhas
    bool flag;  // Flag para indicar o status do exército (ex: ativo ou derrotado)

protected:
    vector<Unidade*> unidades;  // Vetor de ponteiros para as unidades do exército

public:
    // Construtores
    Exercito();  // Construtor padrão
    Exercito(string nome);  // Construtor com nome

    // Destrutor
    virtual ~Exercito();

    // Métodos para obter o número de vitórias, derrotas e empates
    int retornaVitoria() { return vitorias; }
    int retornaDerrota() { return derrotas; }
    int retornaEmpate() { return empates; }

    // Métodos para acessar e modificar o nome e as unidades
    string getNome() const { return nome; }  // Retorna o nome do exército
    const vector<Unidade*>& getUnidades() { return unidades; }  // Retorna o vetor de unidades

    // Métodos de manipulação do exército
    void adicionaUnidades();  // Método para adicionar unidades ao exército
    void registraVitoria();  // Método para registrar vitória do exército
    void registraDerrota();  // Método para registrar derrota do exército
    void registraEmpate();  // Método para registrar empate do exército
    void apagaVet();  // Método para apagar o vetor de unidades
    void imprimeUnidades() const;  // Método para imprimir as unidades do exército
    void gerarValoresDiferentes();  // Método para gerar valores diferentes, possivelmente para os atributos das unidades
    void setFlag();  // Método para setar a flag do exército
    void resetFlag();  // Método para resetar a flag do exército
    bool getFlag() { return flag; }  // Retorna o estado da flag do exército (verdadeiro ou falso)
};

#endif  // Fim da garantia de inclusão única do arquivo de cabeçalho
 EXERCITO_HPP
