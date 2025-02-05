#ifndef EXERCITO_HPP
#define EXERCITO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

class Unidade;  // Forward declaration

class Exercito {
private:
    std::string nome;
    int vitorias;
    int derrotas;
    int empates;
    int pontucaoA, pontuacaoB;

protected:
    std::vector<Unidade*> unidades;  // OK agora, porque Unidade foi declarada

public:
    Exercito();
    Exercito(std::string nome);
    virtual ~Exercito();

    std::string getNome() const { return nome; }
    const std::vector<Unidade*>& getUnidades() { return unidades; }

    void adicionaUnidades();
    void registraVitoria();
    void registraDerrota();
    void registraEmpate();
    
    void imprimeUnidades() const;
    void gerarValoresDiferentes();
};

#endif  // EXERCITO_HPP