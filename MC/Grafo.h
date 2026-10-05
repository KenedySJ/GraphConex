#pragma once
// [CAMBIO GRANDE] Grafo dirigido: usa Algoritmo (sin duplicar su logica) y dibuja flechas

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Circulo.h"
#include "Arista.h"
#include "algoritmo.h"

using namespace System;
using namespace System::Drawing;
using namespace std;

class Grafo {
private:
    int numNodos;
    Matriz matrizAdyacencia;
    vector<Circulo*> nodosVis;
    vector<Arista*> aristas;
    Algoritmo algoritmo;

    void quitarArista(int origen, int destino) {
        matrizAdyacencia[origen][destino] = 0;
        for (size_t i = 0; i < aristas.size(); i++) {
            if (aristas[i]->origen == origen && aristas[i]->destino == destino) {
                delete aristas[i];
                aristas.erase(aristas.begin() + i);
                return;
            }
        }
    }

public:
    Grafo(int n, int panelWidth, int panelHeight) {
        this->numNodos = n;
        matrizAdyacencia = Matriz(n, vector<int>(n, 0));
        srand((unsigned)time(0));
        int radioGrafo = (panelWidth < panelHeight ? panelWidth : panelHeight) / 2 - 40;
        int centroX = panelWidth / 2;
        int centroY = panelHeight / 2;
        int diametroNodo = 40;

        for (int i = 0; i < n; i++) {
            double angulo = i * (2.0 * 3.14159265 / n);
            int posX = centroX + (int)(radioGrafo * cos(angulo)) - (diametroNodo / 2);
            int posY = centroY + (int)(radioGrafo * sin(angulo)) - (diametroNodo / 2);
            nodosVis.push_back(new Circulo(posX, posY, diametroNodo, 0, 0, 255, true, i + 1));
        }
    }

    ~Grafo() {
        for (Circulo* c : nodosVis) delete c;
        for (Arista* a : aristas) delete a;
    }

    Algoritmo& getAlgoritmo() { return algoritmo; }
    int getNumNodos() { return numNodos; }

    Color colorComponente(int indice) {
        cli::array<Color>^ paleta = gcnew cli::array<Color>{
            Color::Red, Color::Green, Color::DarkOrange, Color::Purple,
                Color::DeepPink, Color::Cyan, Color::Brown, Color::Teal, Color::Gold
        };
        return paleta[indice % paleta->Length];
    }

    void generarMatrizAleatoria() {
        int probabilidad = (rand() % 26) + 10; //(rand() % (MAX - MIN + 1)) + MIN y aca es 35 y 10
        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                if (rand() % 100 < probabilidad) {
                    agregarArista(i, j);
                }
            }
        }
    }

    // Dirigida: solo marca origen -> destino; el lazo (origen == destino) y la arista repetida se ignoran
    void agregarArista(int origen, int destino) {
        if (origen >= 0 && origen < numNodos && destino >= 0 && destino < numNodos
            && origen != destino && matrizAdyacencia[origen][destino] == 0) {
            matrizAdyacencia[origen][destino] = 1;
            aristas.push_back(new Arista(origen, destino));
        }
    }

    void alternarArista(int origen, int destino) {
        if (origen == destino) return;
        if (matrizAdyacencia[origen][destino] == 1) quitarArista(origen, destino);
        else agregarArista(origen, destino);
    }

    void cargarMatriz(const Matriz& matriz) {
        for (int i = 0; i < numNodos; i++)
            for (int j = 0; j < numNodos; j++)
                if (matriz[i][j] == 1) agregarArista(i, j);
    }

    void ejecutarPaso(int paso) {
        algoritmo.ejecutar(matrizAdyacencia, paso);
    }

    int totalPasos() {
        return algoritmo.contarPasos(matrizAdyacencia);
    }

    void dibujar(Graphics^ graphics, bool mostrarComponentes) {
        for (Circulo* c : nodosVis) c->setColor(0, 0, 255);

        if (mostrarComponentes) {
            const vector<vector<int>>& componentes = algoritmo.getBloques();
            for (size_t i = 0; i < componentes.size(); i++) {
                Color col = colorComponente(i);
                for (int nodoIndice : componentes[i]) {
                    nodosVis[nodoIndice]->setColor(col.R, col.G, col.B);
                }
            }
        }

        Pen^ penArista = gcnew Pen(Color::Black, 2);
        penArista->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(5, 5);
        for (Arista* a : aristas) {
            Circulo* c1 = nodosVis[a->origen];
            Circulo* c2 = nodosVis[a->destino];
            double centro1X = c1->getX() + (c1->getAncho() / 2.0);
            double centro1Y = c1->getY() + (c1->getAlto() / 2.0);
            double centro2X = c2->getX() + (c2->getAncho() / 2.0);
            double centro2Y = c2->getY() + (c2->getAlto() / 2.0);

            double dx = centro2X - centro1X;
            double dy = centro2Y - centro1Y;
            double largo = sqrt(dx * dx + dy * dy);
            double radio = c1->getAncho() / 2.0;
            double ux = dx / largo;
            double uy = dy / largo;
            // Desplazamiento lateral para que la ida (A->B) y la vuelta (B->A) no se dibujen encima una de otra
            double lateralX = -uy * 6;
            double lateralY = ux * 6;

            graphics->DrawLine(penArista,
                (float)(centro1X + ux * radio + lateralX), (float)(centro1Y + uy * radio + lateralY),
                (float)(centro2X - ux * radio + lateralX), (float)(centro2Y - uy * radio + lateralY));
        }
        delete penArista;

        for (Circulo* c : nodosVis) c->dibujar(graphics);
    }
};
