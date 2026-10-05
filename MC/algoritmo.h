#pragma once
// [CAMBIO GRANDE] Las funciones sueltas pasan a ser la clase Algoritmo, que ejecuta el proceso hasta el paso pedido

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

using Matriz = vector<vector<int>>;

const int MIN_NODOS = 4;
const int MAX_NODOS = 12;

class Algoritmo {
private:
    int n;
    int contador;
    int objetivo;
    Matriz vista;
    Matriz nuevas;
    vector<int> orden;
    vector<int> etiquetas;
    vector<vector<int>> bloques;
    int pivote, origen, compuerta, ventanaInicio, ventanaFin, malFila, malColumna;
    bool resumenFilas;
    wstring titulo;
    wstring mensaje;

    wstring nodoATexto(int nodo) {
        return to_wstring(nodo + 1);
    }

    wstring nodosATexto(const vector<int>& nodos, const wstring& sep) {
        wstring texto;
        for (size_t i = 0; i < nodos.size(); i++) {
            if (i > 0) texto += sep;
            texto += nodoATexto(nodos[i]);
        }
        return texto;
    }

    vector<int> nodosEnRango(int inicio, int fin) {
        return vector<int>(orden.begin() + inicio, orden.begin() + fin);
    }

    void limpiarMarcas() {
        for (vector<int>& fila : nuevas) fill(fila.begin(), fila.end(), 0);
        pivote = origen = ventanaInicio = ventanaFin = malFila = malColumna = -1;
        compuerta = 0;
        resumenFilas = false;
    }

    // Cada paso cuenta uno; si es el pedido se detiene con las marcas intactas, si no las limpia para el siguiente
    bool paso(const wstring& nuevoTitulo, const wstring& texto) {
        titulo = nuevoTitulo;
        mensaje = texto;
        if (contador++ == objetivo) return true;
        limpiarMarcas();
        return false;
    }

    bool bloqueCompleto(const Matriz& m, int inicio, int fin) {
        for (int f = inicio; f <= fin; f++)
            for (int c = inicio; c <= fin; c++)
                if (m[f][c] != 1) {
                    malFila = f;
                    malColumna = c;
                    return false;
                }
        return true;
    }

    bool construirMatrizCaminos() {
        int agregadas = 0;
        for (int i = 0; i < n; i++) {
            if (vista[i][i] == 0) {
                vista[i][i] = 1;
                nuevas[i][i] = 1;
                agregadas++;
            }
        }
        wstring texto = L"Todo nodo puede llegar a sí mismo, así que se pone 1 en la diagonal";
        if (agregadas > 0) texto += L" (" + to_wstring(agregadas) + L" celdas nuevas).";
        else texto += L". La diagonal ya tenía todos sus 1s.";
        if (paso(L"Matriz de caminos (en construcción)", texto)) return true;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                pivote = k;
                origen = i;
                compuerta = (vista[i][k] == 1) ? 1 : 2;
                if (vista[i][k] == 0) {
                    texto = L"El nodo " + nodoATexto(i) + L" no llega a " + nodoATexto(k) + L" (celda (" + nodoATexto(i) + L"," + nodoATexto(k)
                        + L") = 0). Sin ese camino, " + nodoATexto(k) + L" no sirve como intermediario para " + nodoATexto(i) + L": se salta la fila.";
                    if (paso(L"Matriz de caminos (en construcción)", texto)) return true;
                    continue;
                }
                vector<int> alcanzables;
                wstring celdasNuevas;
                for (int j = 0; j < n; j++) {
                    if (vista[k][j] == 1) alcanzables.push_back(j);
                    if (vista[k][j] == 1 && vista[i][j] == 0) {
                        vista[i][j] = 1;
                        nuevas[i][j] = 1;
                        if (!celdasNuevas.empty()) celdasNuevas += L", ";
                        celdasNuevas += L"(" + nodoATexto(i) + L"," + nodoATexto(j) + L")";
                    }
                }
                if (i == k) {
                    texto = L"i = k (nodo " + nodoATexto(k) + L"): es el mismo nodo, no hay nada nuevo que propagar.";
                }
                else {
                    texto = nodoATexto(i) + L" llega a " + nodoATexto(k) + L", y " + nodoATexto(k) + L" llega a {" + nodosATexto(alcanzables, L", ")
                        + L"}. Por transitividad, " + nodoATexto(i) + L" también llega a todos ellos. ";
                    if (celdasNuevas.empty()) texto += L"Pero todo eso ya estaba en la fila " + nodoATexto(i) + L": no cambia nada.";
                    else texto += L"Celdas nuevas: " + celdasNuevas + L".";
                }
                if (paso(L"Matriz de caminos (en construcción)", texto)) return true;
            }
        }
        return paso(L"Matriz de caminos (final)", L"Matriz de caminos final: un 1 en (i,j) indica que existe algún camino, directo o con intermediarios, de i a j. "
            L"Siguiente: ordenar los nodos para agrupar los que se alcanzan entre sí.");
    }

    bool obtenerOrdenFilas() {
        sort(orden.begin(), orden.end(), [&](int a, int b) {
            int unosA = cantidadUnos(vista[a]);
            int unosB = cantidadUnos(vista[b]);
            if (unosA != unosB) return unosA > unosB;

            int colA = primeraColumna(vista[a]);
            int colB = primeraColumna(vista[b]);
            if (colA != colB) return colA < colB;

            // Nodos de la misma componente tienen filas idénticas: así quedan juntos
            if (vista[a] != vista[b]) return vista[a] > vista[b];

            return a < b;
            });
        resumenFilas = true;
        return paso(L"Filas de la matriz de caminos", L"Cada fila se resume con dos datos: cantidad de unos y primera columna con 1. Se ordena por más unos, luego menor primera columna, "
            L"luego fila idéntica (mismos alcanzables) y al final menor nodo. Orden resultante: [" + nodosATexto(orden, L", ") + L"].");
    }

    bool reordenarMatriz() {
        Matriz nueva(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                nueva[i][j] = vista[orden[i]][orden[j]];
        vista = nueva;
        etiquetas = orden;
        return paso(L"Matriz reordenada", L"Se reordenan filas y columnas con ese orden. Los nodos que se alcanzan entre sí quedan formando cuadrados de 1s sobre la diagonal.");
    }

    bool obtenerBloques() {
        int inicio = 0;
        while (inicio < n) {
            int fin = inicio + 1;
            while (fin < n) {
                bool completo = bloqueCompleto(vista, inicio, fin);
                ventanaInicio = inicio;
                ventanaFin = fin;
                int lado = fin - inicio + 1;
                wstring texto = L"¿El cuadrado " + to_wstring(lado) + L"x" + to_wstring(lado) + L" (nodos " + nodosATexto(nodosEnRango(inicio, fin + 1), L", ") + L") está lleno de 1s? ";
                if (completo) texto += L"Sí: el nodo " + nodoATexto(orden[fin]) + L" se une al bloque.";
                else texto += L"No: hay un 0 en la fila " + nodoATexto(orden[malFila]) + L", columna " + nodoATexto(orden[malColumna]) + L". El nodo " + nodoATexto(orden[fin]) + L" no pertenece a este bloque.";
                if (paso(L"Buscando cuadrados de 1s", texto)) return true;
                if (!completo) break;
                fin++;
            }
            bloques.push_back(nodosEnRango(inicio, fin));
            int lado = fin - inicio;
            wstring texto = L"Bloque " + to_wstring(bloques.size()) + L": {" + nodosATexto(bloques.back(), L", ") + L"} (" + to_wstring(lado) + L"x" + to_wstring(lado) + L"). ";
            if (lado == 1) texto += L"Un nodo solo también es una componente. ";
            if (fin < n) texto += L"El siguiente cuadrado empieza en la posición " + to_wstring(fin + 1) + L" (fila y columna " + to_wstring(fin + 1) + L").";
            else texto += L"Ya no quedan nodos.";
            if (paso(L"Buscando cuadrados de 1s", texto)) return true;
            inicio = fin;
        }
        return false;
    }

public:
    Algoritmo() : n(0), contador(0), objetivo(-1), resumenFilas(false) {
        limpiarMarcas();
    }

    int cantidadUnos(const vector<int>& fila) {
        return count(fila.begin(), fila.end(), 1);
    }

    int primeraColumna(const vector<int>& fila) {
        return find(fila.begin(), fila.end(), 1) - fila.begin();
    }

    // [CAMBIO GRANDE] No se guarda historial: para ir a cualquier paso (incluso hacia atrás) se vuelve a ejecutar el algoritmo desde cero hasta ese paso.
    // Con n <= 12 son pocos cientos de operaciones, y así no hay que conservar una copia de la matriz por cada paso.
    void ejecutar(const Matriz& adyacencia, int pasoObjetivo) {
        n = adyacencia.size();
        contador = 0;
        objetivo = pasoObjetivo;
        vista = adyacencia;
        nuevas = Matriz(n, vector<int>(n, 0));
        orden = vector<int>(n);
        iota(orden.begin(), orden.end(), 0);
        etiquetas = orden;
        bloques.clear();
        limpiarMarcas();

        if (paso(L"Matriz de adyacencia", L"Matriz de adyacencia: un 1 en (i,j) significa que hay una arista dirigida de i hacia j. "
            L"Haz clic en una celda para cambiarla (la diagonal no se edita) y mira cómo cambia el grafo. Luego avanza con los botones.")
            || construirMatrizCaminos() || obtenerOrdenFilas() || reordenarMatriz() || obtenerBloques()) return;

        wstring texto = L"Resultado: " + to_wstring(bloques.size()) + (bloques.size() == 1 ? L" componente conexa. " : L" componentes conexas. ");
        for (size_t b = 0; b < bloques.size(); b++) {
            if (b > 0) texto += L"; ";
            texto += to_wstring(b + 1) + L": {" + nodosATexto(bloques[b], L", ") + L"}";
        }
        paso(L"Componentes conexas", texto + L".");
    }

    // Ejecuta sobre una copia para no alterar el paso que se está mostrando
    int contarPasos(const Matriz& adyacencia) {
        Algoritmo recorrido;
        recorrido.ejecutar(adyacencia, -1);
        return recorrido.contador;
    }

    const Matriz& getVista() { return vista; }
    const Matriz& getNuevas() { return nuevas; }
    const vector<int>& getEtiquetas() { return etiquetas; }
    const vector<vector<int>>& getBloques() { return bloques; }
    int getPivote() { return pivote; }
    int getOrigen() { return origen; }
    int getCompuerta() { return compuerta; }
    int getVentanaInicio() { return ventanaInicio; }
    int getVentanaFin() { return ventanaFin; }
    int getMalFila() { return malFila; }
    int getMalColumna() { return malColumna; }
    bool getResumenFilas() { return resumenFilas; }
    wstring getTitulo() { return titulo; }
    wstring getMensaje() { return mensaje; }
};
