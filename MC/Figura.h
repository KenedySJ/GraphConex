#pragma once

using namespace System;
using namespace System::Drawing;

class Figura {
protected:
    int x, y, ancho, alto, r, g, b, numero;
    bool relleno;

public:
    Figura(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno, int numero) {
        this->x = x; this->y = y; this->ancho = ancho; this->alto = alto;
        this->r = r; this->g = g; this->b = b; this->relleno = relleno; this->numero = numero;
    }

    virtual ~Figura() {}

    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }
    int getNumero() { return numero; }

    void setColor(int r, int g, int b) {
        this->r = r; this->g = g; this->b = b;
    }

    virtual void dibujar(Graphics^ graphics) = 0;
};