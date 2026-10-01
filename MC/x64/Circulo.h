#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Circulo : public Figura {
private:
    int radio;
    int id; // Identificador numérico del vértice

public:
    // Constructor que inicializa la clase base Figura y los atributos propios
    Circulo(int _x, int _y, int _radio, Color _color, int _id)
        : Figura(_x, _y, _color) {
        radio = _radio;
        id = _id;
    }

    // Sobreescritura del método virtual para dibujar en Windows Forms
    void Dibujar(Graphics^ g) override {
        // 1. Dibujar el fondo del círculo
        SolidBrush^ brochaFondo = gcnew SolidBrush(color);
        g->FillEllipse(brochaFondo, x - radio, y - radio, radio * 2, radio * 2);
        delete brochaFondo; // Liberación de memoria

        // 2. Dibujar el borde negro
        Pen^ lapizBorde = gcnew Pen(Color::Black, 2.0f);
        g->DrawEllipse(lapizBorde, x - radio, y - radio, radio * 2, radio * 2);
        delete lapizBorde;

        // 3. Dibujar el número del nodo centrado
        Font^ fuente = gcnew Font("Arial", 12, FontStyle::Bold);
        SolidBrush^ brochaTexto = gcnew SolidBrush(Color::Black);
        StringFormat^ formato = gcnew StringFormat();
        formato->Alignment = StringAlignment::Center;
        formato->LineAlignment = StringAlignment::Center;

        g->DrawString(id.ToString(), fuente, brochaTexto, x, y, formato);

        // Limpieza de herramientas de texto
        delete fuente;
        delete brochaTexto;
        delete formato;
    }
};