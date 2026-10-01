#pragma once
#include "Figura.h"

class Circulo : public Figura {
public:
    Circulo(int x, int y, int diametro, int r, int g, int b, bool relleno, int numero)
        : Figura(x, y, diametro, diametro, r, g, b, relleno, numero) {
    }

    void dibujar(Graphics^ graphics) override {
        Color color = Color::FromArgb(r, g, b);
        SolidBrush^ brush = gcnew SolidBrush(color);
        Pen^ pen = gcnew Pen(Color::Black, 2);

        if (relleno) {
            graphics->FillEllipse(brush, x, y, ancho, alto);
        }
        graphics->DrawEllipse(pen, x, y, ancho, alto);

        Font^ fuente = gcnew Font("Arial", 12, FontStyle::Bold);
        SolidBrush^ brochaTexto = gcnew SolidBrush(Color::White);
        graphics->DrawString(numero.ToString(), fuente, brochaTexto, x + (ancho / 4), y + (alto / 4));

        delete brush;
        delete pen;
        delete fuente;
        delete brochaTexto;
    }
};