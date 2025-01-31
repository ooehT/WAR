#ifndef INFANTARIA_H
#define INFANTARIA_H

#include "Unidade.h"

class Infantaria : public Unidade {
private:
    int forca;
    int velocidade;

public:
    // Construtor
    Infantaria(int poderAtaque, int destruicoes, int forca, int velocidade);

    double getPoderAtaque() const override;
};

#endif