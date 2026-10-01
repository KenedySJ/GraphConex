#pragma once
#include "Figura.h"

using namespace System::Drawing;

class Arista {
private:
    Figura* origen;
    Figura* destino;

public:
    // Constructor que recibe punteros a los nodos que va a conectar
    Arista(Figura* _origen, Figura* _destino) {
        origen = _origen;
        destino = _destino;
    }

    // Método para dibujar la línea en el Windows Form
    void dibujar(Graphics^ graphics) {
        Pen^ pen = gcnew Pen(Color::Black, 2);

        // Dibuja la línea tomando las coordenadas de los nodos
        // (Asumiendo que getX() y getY() apuntan al centro de tu figura)
        graphics->DrawLine(pen, origen->getX(), origen->getY(), destino->getX(), destino->getY());

        delete pen; // Liberamos la memoria administrada
    }
};
