#ifndef INFANTARIA_HPP
#define INFANTARIA_HPP

#include "Unidade.hpp"

class Infantaria : public Unidade {
private:
    int forca;
    int velocidade;

public:
    Infantaria();  // Construtor
    double getPoderAtaque() const override;
};

#endif
