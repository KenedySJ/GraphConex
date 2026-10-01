#pragma once

// ============================================================
// PROYECTO 1 - COMPONENTES CONEXAS
// Matriz de Adyacencia + Matriz de Caminos
// ============================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Esta linea permite usar "vector<vector<int>>" como "Matriz"
using Matriz = vector<vector<int>>;

// ============================================================
// CONSTRUCCIÓN DE LA MATRIZ DE ADYACENCIA
// ============================================================

// Matriz n x n llena de ceros (grafo sin aristas)
inline Matriz crearMatrizVacia(int n) {
    return Matriz(n, vector<int>(n, 0));
}

// Grafo no dirigido: si a-b existe, se marca [a][b] y [b][a]
inline void agregarArista(Matriz& m, int a, int b) {
    if (a == b) return;          // sin lazos
    m[a][b] = 1;
    m[b][a] = 1;
}

inline Matriz generarMatrizAleatoria(int n) {
    Matriz m = crearMatrizVacia(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (rand() % 100 < 30)
                agregarArista(m, i, j);
    return m;
}

inline void mostrarMatriz(const Matriz& m, const string& titulo);

// ============================================================
// FUNCIONES AUXILIARES (se reutilizan en varios pasos)
// ============================================================

inline int cantidadUnos(const vector<int>& fila) {
    return count(fila.begin(), fila.end(), 1);
}

inline int primeraColumna(const vector<int>& fila) {
    return find(fila.begin(), fila.end(), 1) - fila.begin();
}

inline bool filaLlena(const vector<int>& fila) {
    return cantidadUnos(fila) == (int)fila.size();
}

// ¿El cuadrado [inicio..fin] x [inicio..fin] está lleno de 1s?
inline bool bloqueCompleto(const Matriz& m, int inicio, int fin) {
    for (int f = inicio; f <= fin; f++)
        for (int c = inicio; c <= fin; c++)
            if (m[f][c] != 1) return false;
    return true;
}


// ============================================================
// PASO 1: MATRIZ DE CAMINOS
// ============================================================
inline Matriz construirMatrizCaminos(const Matriz& ady) {
    int n = ady.size();
    // Copiamos la matriz de adyacencia
    Matriz caminos = ady;
    // Todo nodo puede llegar a sí mismo
    for (int i = 0; i < n; i++) {
        if (caminos[i][i] == 0) {
            caminos[i][i] = 1;
        }
    }
    mostrarMatriz(
        caminos,
        "MATRIZ DE CAMINOS (Diagonal de 1's)"
    );
    // k = nodo intermedio
    for (int k = 0; k < n; k++) {
        // i = nodo origen
        for (int i = 0; i < n; i++) {
            // Si i no puede llegar a k,
            // no podemos usar k como intermediario.
            if (caminos[i][k] == 0)
                continue;
            // j = nodo destino
            for (int j = 0; j < n; j++) {
                // Si k puede llegar a j,
                // entonces i también puede llegar a j.
                if (caminos[k][j] == 1 &&
                    caminos[i][j] == 0) {

                    caminos[i][j] = 1;
                    mostrarMatriz(
                        caminos,
                        "PASO 1: MATRIZ DE CAMINOS (cambio)"
                    );
                }
            }
        }
    }

    return caminos;
}
// ============================================================
// PASO 2: ORDEN DE LAS FILAS
// más 1s primero, luego menor primera columna, luego fila igual (mismos alcanzables), luego menor nodo
// ============================================================

inline vector<int> obtenerOrdenFilas(const Matriz& caminos) {
    int n = caminos.size();
    vector<int> orden(n);
    for (int i = 0; i < n; i++) orden[i] = i;

    sort(orden.begin(), orden.end(), [&](int a, int b) { // a y b son indices de filas porque [&] permite acceder a la variable caminos
        int unosA = cantidadUnos(caminos[a]);
        int unosB = cantidadUnos(caminos[b]);
        if (unosA != unosB) return unosA > unosB;

        int colA = primeraColumna(caminos[a]);
        int colB = primeraColumna(caminos[b]);
        if (colA != colB) return colA < colB;

        // Nodos de la misma componente tienen filas idénticas: así quedan juntos
        if (caminos[a] != caminos[b]) return caminos[a] > caminos[b];

        return a < b;
        });
    return orden;
}


// ============================================================
// PASO 3: ORDENAR FILAS Y COLUMNAS
// ============================================================

inline Matriz reordenarMatriz(const Matriz& m, const vector<int>& orden) {
    int n = orden.size();
    Matriz nueva(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nueva[i][j] = m[orden[i]][orden[j]];

    return nueva;
}


// ============================================================
// PASO 4: BLOQUES CUADRADOS Y COMPONENTES
// ============================================================

inline vector<vector<int>> obtenerBloques(const Matriz& ordenada, const vector<int>& orden) {
    int n = ordenada.size();
    vector<vector<int>> bloques;

    int inicio = 0;
    while (inicio < n) {
        int fin = inicio + 1;
        while (fin < n && bloqueCompleto(ordenada, inicio, fin))
            fin++;

        bloques.push_back(vector<int>(orden.begin() + inicio, orden.begin() + fin));
        inicio = fin; // el siguiente cuadrado empieza en (fin, fin), o sea i+n+1
    }
    return bloques;
}


// ============================================================
// IMPRESIÓN (solo para probar en consola)
// ============================================================

inline void mostrarTitulo(const string& titulo) {
    cout << "\n" << string(60, '=') << "\n" << titulo << "\n" << string(60, '=') << "\n";
}

inline void mostrarMatriz(const Matriz& m, const string& titulo) {
    int n = m.size();
    mostrarTitulo(titulo);

    cout << "   ";
    for (int i = 0; i < n; i++) cout << setw(2) << i + 1 << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(2) << i + 1 << "  ";
        for (int j = 0; j < n; j++) cout << m[i][j] << "  ";
        cout << "\n";
    }
}

// Devuelve los nodos en base 1 separados por 'sep': "1, 2, 4"
inline string nodosATexto(const vector<int>& nodos, const string& sep) {
    string texto;
    for (size_t i = 0; i < nodos.size(); i++) {
        if (i > 0) texto += sep;
        texto += to_string(nodos[i] + 1);
    }
    return texto;
}

/*
// ============================================================
// MAIN
// ============================================================

Este es un main de ejemplo para probar el algoritmo completo.
Lo que nos queda por hacer es crear un panel gráfico
para que el usuario pueda ingresar la matriz de adyacencia
y ver los resultados paso a paso.



int main() {

    Matriz matrizAdyacencia = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    };

    mostrarMatriz(matrizAdyacencia, "MATRIZ DE ADYACENCIA");

    // Paso 1
    Matriz caminos = construirMatrizCaminos(matrizAdyacencia);
    mostrarMatriz(caminos, "PASO 1: MATRIZ DE CAMINOS FINAL");

    // Paso 2
    vector<int> orden = obtenerOrdenFilas(caminos);
    mostrarTitulo("PASO 2: ORDEN DE LAS FILAS");
    for (int i = 0; i < (int)caminos.size(); i++)
        cout << "Nodo " << i + 1 << ": " << cantidadUnos(caminos[i]) << " unos | primer 1 en columna "
        << primeraColumna(caminos[i]) + 1 << "\n";
    cout << "\nOrden de las filas: [" << nodosATexto(orden, ", ") << "]\n";

    // Paso 3
    Matriz ordenada = reordenarMatriz(caminos, orden);
    mostrarMatriz(ordenada, "PASO 3: FILAS Y COLUMNAS ORDENADAS");

    // Paso 4
    vector<vector<int>> bloques = obtenerBloques(ordenada, orden);
    mostrarTitulo("PASO 4: BLOQUES CUADRADOS");
    for (size_t i = 0; i < bloques.size(); i++)
        cout << "Bloque " << i + 1 << ": " << nodosATexto(bloques[i], "; ")
        << " (" << bloques[i].size() << "x" << bloques[i].size() << ")\n";

    // Todo bloque cuadrado es una componente (incluidos los de 1x1)
    mostrarTitulo("RESULTADO FINAL");
    cout << "Cantidad de componentes conexas: " << bloques.size() << "\n";
    for (size_t i = 0; i < bloques.size(); i++)
        cout << "Componente " << i + 1 << ": { " << nodosATexto(bloques[i], ", ") << " }\n";

    return 0;
}
*/