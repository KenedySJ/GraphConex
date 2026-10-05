#pragma once
// [ARCHIVO NUEVO] Modulo que lee un grafo guardado en un .csv: una fila por nodo de origen, un 0/1 por cada nodo de destino

#include "algoritmo.h"

using namespace System;
using namespace std;

class LectorCSV {
public:
    Matriz leer(String^ ruta) {
        cli::array<String^>^ lineas = System::IO::File::ReadAllLines(ruta);
        cli::array<wchar_t>^ separadores = gcnew cli::array<wchar_t>{ L',', L';' };
        Matriz matriz;

        for (int f = 0; f < lineas->Length; f++) {
            if (lineas[f]->Trim()->Length == 0) continue;

            // RemoveEmptyEntries tolera una coma o punto y coma al final de la fila
            cli::array<String^>^ celdas = lineas[f]->Trim()->Split(separadores, StringSplitOptions::RemoveEmptyEntries);
            vector<int> fila;
            for (int c = 0; c < celdas->Length; c++) {
                int valor;
                if (!Int32::TryParse(celdas[c]->Trim(), valor) || (valor != 0 && valor != 1))
                    throw gcnew FormatException(String::Format(L"Línea {0}: el valor '{1}' no es válido, solo se permiten 0 y 1.", f + 1, celdas[c]));
                fila.push_back(valor);
            }
            matriz.push_back(fila);
        }

        int n = matriz.size();
        if (n < MIN_NODOS || n > MAX_NODOS)
            throw gcnew FormatException(String::Format(L"El archivo tiene {0} filas con datos y se necesitan entre {1} y {2}.", n, MIN_NODOS, MAX_NODOS));
        for (int i = 0; i < n; i++)
            if ((int)matriz[i].size() != n)
                throw gcnew FormatException(String::Format(L"La matriz debe ser cuadrada: la fila {0} tiene {1} columnas y se esperaban {2}.", i + 1, (int)matriz[i].size(), n));

        return matriz;
    }
};
