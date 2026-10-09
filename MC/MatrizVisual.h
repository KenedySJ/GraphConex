#pragma once

#include "Grafo.h"

using namespace System;
using namespace System::Drawing;
using namespace std;

class MatrizVisual {
private:
    int celda = 0;
    int margen = 8;

    Color colorFondo() { return Color::FromArgb(237, 241, 243); }
    Color colorPivote() { return Color::FromArgb(246, 217, 139); }
    Color colorOrigen() { return Color::FromArgb(191, 229, 232); }
    Color colorNueva() { return Color::FromArgb(14, 143, 90); }
    Color colorAlerta() { return Color::FromArgb(194, 65, 12); }
    Color colorTinta() { return Color::FromArgb(20, 35, 43); }
    Color colorSuave() { return Color::FromArgb(91, 107, 115); }

    void dibujarCasilla(Graphics^ graphics, int fila, int columna, String^ texto, Color fondo, Color letra, bool negrita, Color borde, int grosor) {
        int x = margen + columna * celda + 1;
        int y = margen + fila * celda + 1;
        int lado = celda - 2;

        SolidBrush^ brochaFondo = gcnew SolidBrush(fondo);
        graphics->FillRectangle(brochaFondo, x, y, lado, lado);
        delete brochaFondo;

        if (grosor > 0) {
            Pen^ pen = gcnew Pen(borde, (float)grosor);
            graphics->DrawRectangle(pen, x, y, lado, lado);
            delete pen;
        }

        Font^ fuente = gcnew Font("Arial", celda * 0.3f, negrita ? FontStyle::Bold : FontStyle::Regular);
        SolidBrush^ brochaTexto = gcnew SolidBrush(letra);
        StringFormat^ formato = gcnew StringFormat();
        formato->Alignment = StringAlignment::Center;
        formato->LineAlignment = StringAlignment::Center;
        graphics->DrawString(texto, fuente, brochaTexto, RectangleF((float)x, (float)y, (float)lado, (float)lado), formato);

        delete fuente;
        delete brochaTexto;
        delete formato;
    }

public:
    void dibujar(Graphics^ graphics, Grafo* grafo, int ancho) {
        Algoritmo& algoritmo = grafo->getAlgoritmo();
        const Matriz& vista = algoritmo.getVista();
        const Matriz& nuevas = algoritmo.getNuevas();
        const vector<int>& etiquetas = algoritmo.getEtiquetas();
        const vector<vector<int>>& bloques = algoritmo.getBloques();
        int n = grafo->getNumNodos();
        int pivote = algoritmo.getPivote();
        int origen = algoritmo.getOrigen();
        int ventanaInicio = algoritmo.getVentanaInicio();
        int ventanaFin = algoritmo.getVentanaFin();
        bool resumen = algoritmo.getResumenFilas();

        celda = Math::Max(22, Math::Min(48, (ancho - 2 * margen) / (n + 1 + (resumen ? 2 : 0))));

        // Bloque al que pertenece cada posicion de la matriz ya reordenada (-1 si aun no se encontro)
        vector<int> bloqueDePosicion(n, -1);
        int posicion = 0;
        for (size_t b = 0; b < bloques.size(); b++)
            for (size_t x = 0; x < bloques[b].size(); x++)
                bloqueDePosicion[posicion++] = b;

        for (int j = 0; j < n; j++) {
            dibujarCasilla(graphics, 0, j + 1, Convert::ToString(etiquetas[j] + 1),
                pivote == j ? colorPivote() : Color::Transparent, colorSuave(), false, Color::Black, 0);
            dibujarCasilla(graphics, j + 1, 0, Convert::ToString(etiquetas[j] + 1),
                pivote == j ? colorPivote() : (origen == j ? colorOrigen() : Color::Transparent), colorSuave(), false, Color::Black, 0);
        }

        if (resumen) {
            dibujarCasilla(graphics, 0, n + 1, "unos", Color::Transparent, colorSuave(), false, Color::Black, 0);
            dibujarCasilla(graphics, 0, n + 2, L"1ª col", Color::Transparent, colorSuave(), false, Color::Black, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Color fondo = colorFondo();
                Color letra = vista[i][j] == 1 ? colorTinta() : colorSuave();
                Color borde = colorTinta();
                int grosor = 0;

                if (pivote == i || pivote == j) fondo = colorPivote();
                else if (origen == i) fondo = colorOrigen();

                if (ventanaInicio <= i && i <= ventanaFin && ventanaInicio <= j && j <= ventanaFin) fondo = colorPivote();

                if (bloqueDePosicion[i] != -1 && bloqueDePosicion[i] == bloqueDePosicion[j])
                    fondo = Color::FromArgb(110, grafo->colorComponente(bloqueDePosicion[i]));

                if (nuevas[i][j] == 1) {
                    fondo = colorNueva();
                    letra = Color::White;
                }

                if (origen == i && pivote == j) {
                    grosor = 3;
                    if (algoritmo.getCompuerta() == 2) {
                        borde = colorAlerta();
                        letra = colorAlerta();
                    }
                }

                if (i == algoritmo.getMalFila() && j == algoritmo.getMalColumna()) {
                    grosor = 3;
                    borde = colorAlerta();
                }

                dibujarCasilla(graphics, i + 1, j + 1, Convert::ToString(vista[i][j]), fondo, letra, vista[i][j] == 1, borde, grosor);
            }

            if (resumen) {
                dibujarCasilla(graphics, i + 1, n + 1, Convert::ToString(algoritmo.cantidadUnos(vista[i])), Color::Transparent, colorTinta(), false, Color::Black, 0);
                dibujarCasilla(graphics, i + 1, n + 2, Convert::ToString(algoritmo.primeraColumna(vista[i]) + 1), Color::Transparent, colorTinta(), false, Color::Black, 0);
            }
        }
    }

    bool celdaEn(int x, int y, int n, int& fila, int& columna) {
        if (celda == 0 || x < margen || y < margen) return false;
        columna = (x - margen) / celda - 1;
        fila = (y - margen) / celda - 1;
        return fila >= 0 && fila < n && columna >= 0 && columna < n;
    }
};
