#pragma once
#include "Circulo.h"
#include "algoritmo.h"
#include "Arista.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace System::Drawing;
using Matriz = std::vector<std::vector<int>>;

class Grafo {
private:
    int n;
    Matriz matrizAdyacencia;
    std::vector<Circulo*> nodos;
    std::vector<Arista*> aristas;

    // --- Pega aquí tus funciones auxiliares privadas ---
    int cantidadUnos(const std::vector<int>& fila) { return std::count(fila.begin(), fila.end(), 1); }
    int primeraColumna(const std::vector<int>& fila) { return std::find(fila.begin(), fila.end(), 1) - fila.begin(); }
    bool bloqueCompleto(const Matriz& m, int inicio, int fin) { /* tu codigo */ return true; }
    // ...

public:
    // (Mantén tus constructores y métodos de dibujo visual previos)

    // --- NUEVO MÉTODO INTEGRADOR ---
    void calcularComponentesConexas() {
        // 1. Ejecutas tus pasos matemáticos (el código que ya hiciste)
        Matriz caminos = construirMatrizCaminos(matrizAdyacencia);
        std::vector<int> orden = obtenerOrdenFilas(caminos);
        Matriz ordenada = reordenarMatriz(caminos, orden);
        std::vector<std::vector<int>> bloques = obtenerBloques(ordenada, orden);

        // 2. Traducción Visual (Requisito de la rúbrica)
        // Arreglo de colores para pintar cada componente de un color distinto
        Color paleta[6] = { Color::Red, Color::Green, Color::Blue, Color::Orange, Color::Purple, Color::Teal };

        for (size_t i = 0; i < bloques.size(); i++) {
            // Selecciona un color de la paleta (evitando desbordamientos)
            Color colorComponente = paleta[i % 6];

            // Recorre los nodos (ej: 0, 1, 4) de este bloque específico
            for (int idNodo : bloques[i]) {
                // Actualiza el color del objeto Circulo correspondiente
                // Se asume que modificas tu clase Circulo para aceptar Color de .NET
                nodos[idNodo]->setColorNET(colorComponente);
            }
        }
    }
};