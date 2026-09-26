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
using namespace std;

// Esta linea permite usar "vector<vector<int>>" como "Matriz"
using Matriz = vector<vector<int>>;

void mostrarMatriz(const Matriz& m, const string& titulo);

// ============================================================
// FUNCIONES AUXILIARES (se reutilizan en varios pasos)
// ============================================================

int cantidadUnos(const vector<int>& fila) {
    return count(fila.begin(), fila.end(), 1);
}

int primeraColumna(const vector<int>& fila) {
    return find(fila.begin(), fila.end(), 1) - fila.begin();
}

bool filaLlena(const vector<int>& fila) {
    return cantidadUnos(fila) == (int)fila.size();
}

// ¿El cuadrado [inicio..fin] x [inicio..fin] está lleno de 1s?
bool bloqueCompleto(const Matriz& m, int inicio, int fin) {
    for (int f = inicio; f <= fin; f++)
        for (int c = inicio; c <= fin; c++)
            if (m[f][c] != 1) return false;
    return true;
}


// ============================================================
// PASO 1: MATRIZ DE CAMINOS
// ============================================================
Matriz construirMatrizCaminos(const Matriz& ady) {
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
// más 1s primero, luego menor primera columna, luego menor nodo
// ============================================================

vector<int> obtenerOrdenFilas(const Matriz& caminos) {
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

        return a < b;
        });
    return orden;
}


// ============================================================
// PASO 3: ORDENAR FILAS Y COLUMNAS
// ============================================================

Matriz reordenarMatriz(const Matriz& m, const vector<int>& orden) {
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

vector<vector<int>> obtenerBloques(const Matriz& ordenada, const vector<int>& orden) {
    int n = ordenada.size();
    vector<vector<int>> bloques;

    int inicio = 0;
    while (inicio < n) {
        int fin = inicio + 1;
        while (fin < n && bloqueCompleto(ordenada, inicio, fin))
            fin++;

        bloques.push_back(vector<int>(orden.begin() + inicio, orden.begin() + fin));
        inicio = fin;
    }
    return bloques;
}

// Bloques de tamaño >= 2 son componentes; de tamaño 1 son nodos aislados
void clasificarBloques(const vector<vector<int>>& bloques,
    vector<vector<int>>& componentes,
    vector<int>& aislados) {
    for (const auto& bloque : bloques) {
        if (bloque.size() == 1) aislados.push_back(bloque[0]);
        else componentes.push_back(bloque);
    }
}


// ============================================================
// IMPRESIÓN (solo para probar en consola)
// TOMA EN CUENTA QUE ESTOS PASOS NO SON NECESARIOS PARA EL ALGORITMO EN SÍ
// SOLO SIRVEN PARA VER EL PROCESO PASO A PASO EN CONSOLA
// LO QUE TENEMOS QUE HACER ES USAR LA LÓGICA DE ESTAS FUNCIONES PARA MOSTRAR EL PROCESO EN EL FORMULARIO   
// ============================================================

void mostrarTitulo(const string& titulo) {
    cout << "\n" << string(60, '=') << "\n" << titulo << "\n" << string(60, '=') << "\n";
}

void mostrarMatriz(const Matriz& m, const string& titulo) {
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
string nodosATexto(const vector<int>& nodos, const string& sep) {
    string texto;
    for (size_t i = 0; i < nodos.size(); i++) {
        if (i > 0) texto += sep;
        texto += to_string(nodos[i] + 1);
    }
    return texto;
}

// ============================================================
// MAIN
// ============================================================
/*
 
 NOTA IMPORTANTE:
 Este es un prototipo hecho en consola, para probar el algoritmo paso a paso.
 toma la logica de como usa la función mostrarMatriz() para mostrar los pasos del algoritmo.
 también la uso para 

int main() {

    Matriz matrizAdyacencia = {
    {1, 1, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0},
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

    vector<vector<int>> componentes;
    vector<int> aislados;
    clasificarBloques(bloques, componentes, aislados);

    mostrarTitulo("RESULTADO FINAL");
    cout << "Cantidad de componentes conexas: " << componentes.size() << "\n";
    for (size_t i = 0; i < componentes.size(); i++)
        cout << "Componente " << i + 1 << ": { " << nodosATexto(componentes[i], ", ") << " }\n";

    if (!aislados.empty())
        cout << "\nNodos aislados (bloques 1x1, no contabilizados): [" << nodosATexto(aislados, ", ") << "]\n";

    return 0;
}
*/