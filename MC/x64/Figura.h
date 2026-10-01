#pragma once
#include "iostream"
using namespace System;
using namespace System::Drawing;

// Clase C++ estándar (nativa)
class Figura {
protected:
    // Coordenadas
    int x;
    int y;
    Color color;

public:
    // Constructor
    Figura(int _x, int _y, Color _color) {
        x = _x;
        y = _y;
        color = _color;
    }

    // IMPORTANTE: En C++ nativo, toda clase base con métodos virtuales debe tener un destructor virtual
    // para asegurar que la memoria de las clases hijas se libere correctamente con "delete".
    virtual ~Figura() {}

    int getX() { return x; }
    int getY() { return y; }
    Color getColor() { return color; }

    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    void setColor(Color _color) { color = _color; }

    // Método virtual puro en C++ estándar.
    // El handle (^) de Graphics se pasa solo como argumento.
    virtual void Dibujar(Graphics^ g) = 0;
};