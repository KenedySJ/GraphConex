#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm> // OBLIGATORIO para count, find, sort
#include "Circulo.h"
#include "Arista.h"

using namespace System;
using namespace System::Drawing;
using namespace std;

using Matriz = vector<vector<int>>;

class Grafo {
private:
    int numNodos;
    Matriz matrizAdyacencia;
    vector<Circulo*> nodosVis;
    vector<Arista*> aristas;
    vector<vector<int>> componentesFinales;

    // ============================================================
    // MÉTODOS MATEMÁTICOS PRIVADOS (Antes estaban en algoritmo.h)
    // ============================================================
    int cantidadUnos(const vector<int>& fila) {
        return count(fila.begin(), fila.end(), 1);
    }

    int primeraColumna(const vector<int>& fila) {
        return find(fila.begin(), fila.end(), 1) - fila.begin();
    }

    bool bloqueCompleto(const Matriz& m, int inicio, int fin) {
        for (int f = inicio; f <= fin; f++)
            for (int c = inicio; c <= fin; c++)
                if (m[f][c] != 1) return false;
        return true;
    }

    Matriz construirMatrizCaminos(const Matriz& ady) {
        int n = ady.size();
        Matriz caminos = ady;
        for (int i = 0; i < n; i++) {
            if (caminos[i][i] == 0) caminos[i][i] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (caminos[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (caminos[k][j] == 1 && caminos[i][j] == 0) {
                        caminos[i][j] = 1;
                    }
                }
            }
        }
        return caminos;
    }

    vector<int> obtenerOrdenFilas(const Matriz& caminos) {
        int n = caminos.size();
        vector<int> orden(n);
        for (int i = 0; i < n; i++) orden[i] = i;

        sort(orden.begin(), orden.end(), [&](int a, int b) {
            int unosA = cantidadUnos(caminos[a]);
            int unosB = cantidadUnos(caminos[b]);
            if (unosA != unosB) return unosA > unosB;

            int colA = primeraColumna(caminos[a]);
            int colB = primeraColumna(caminos[b]);
            if (colA != colB) return colA < colB;

            if (caminos[a] != caminos[b]) return caminos[a] > caminos[b];

            return a < b;
            });
        return orden;
    }

    Matriz reordenarMatriz(const Matriz& m, const vector<int>& orden) {
        int n = orden.size();
        Matriz nueva(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                nueva[i][j] = m[orden[i]][orden[j]];
        return nueva;
    }

    vector<vector<int>> obtenerBloques(const Matriz& ordenada, const vector<int>& orden) {
        int n = ordenada.size();
        vector<vector<int>> bloques;
        int inicio = 0;
        while (inicio < n) {
            int fin = inicio + 1;
            while (fin < n && bloqueCompleto(ordenada, inicio, fin)) fin++;
            bloques.push_back(vector<int>(orden.begin() + inicio, orden.begin() + fin));
            inicio = fin;
        }
        return bloques;
    }

public:
    // ============================================================
    // CONSTRUCTOR Y MÉTODOS PÚBLICOS
    // ============================================================
    Grafo(int n, int panelWidth, int panelHeight) {
        this->numNodos = n;
        matrizAdyacencia = Matriz(n, vector<int>(n, 0));

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

    void generarMatrizAleatoria() {
        srand((unsigned)time(0));
        int probabilidad = (rand() % 26) + 10;

        for (int i = 0; i < numNodos; i++) {
            for (int j = i + 1; j < numNodos; j++) {
                // Usa la probabilidad dinámica calculada arriba
                if (rand() % 100 < probabilidad) {
                    agregarArista(i, j);
                }
            }
        }
    }

    void agregarArista(int origen, int destino) {
        if (origen >= 0 && origen < numNodos && destino >= 0 && destino < numNodos) {
            matrizAdyacencia[origen][destino] = 1;
            matrizAdyacencia[destino][origen] = 1;
            aristas.push_back(new Arista(origen, destino));
        }
    }

    void calcularComponentesConexas() {
        Matriz caminos = construirMatrizCaminos(matrizAdyacencia);
        vector<int> orden = obtenerOrdenFilas(caminos);
        Matriz ordenada = reordenarMatriz(caminos, orden);
        componentesFinales = obtenerBloques(ordenada, orden);
    }

    void dibujar(Graphics^ graphics, int etapa) {
        // Uso de cli::array corregido para evitar conflictos con std::array
        cli::array<Color>^ paleta = gcnew cli::array<Color>{
            Color::Red, Color::Green, Color::DarkOrange, Color::Purple,
                Color::DeepPink, Color::Cyan, Color::Brown, Color::Teal, Color::Gold
        };

        if (etapa == 3 && !componentesFinales.empty()) {
            for (size_t i = 0; i < componentesFinales.size(); i++) {
                Color col = paleta[i % paleta->Length];
                for (int nodoIndice : componentesFinales[i]) {
                    nodosVis[nodoIndice]->setColor(col.R, col.G, col.B);
                }
            }
        }
        else {
            for (Circulo* c : nodosVis) c->setColor(0, 0, 255);
        }

        Pen^ penArista = gcnew Pen(Color::Black, 2);
        for (Arista* a : aristas) {
            Circulo* c1 = nodosVis[a->origen];
            Circulo* c2 = nodosVis[a->destino];
            int centro1X = c1->getX() + (c1->getAncho() / 2);
            int centro1Y = c1->getY() + (c1->getAlto() / 2);
            int centro2X = c2->getX() + (c2->getAncho() / 2);
            int centro2Y = c2->getY() + (c2->getAlto() / 2);
            graphics->DrawLine(penArista, centro1X, centro1Y, centro2X, centro2Y);
        }
        delete penArista;

        for (Circulo* c : nodosVis) c->dibujar(graphics);
    }
};