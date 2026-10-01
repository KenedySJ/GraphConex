#pragma once
#include <vector>

namespace MC {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    // Delegado para enviar la matriz terminada de vuelta al panel principal
    public delegate void MatrizConfirmadaEventHandler(std::vector<std::vector<int>> matrizGenerada);

    public ref class MatrizForm : public System::Windows::Forms::Form
    {
    public:
        event MatrizConfirmadaEventHandler^ OnMatrizConfirmada;

    private:
        int numNodos;
        System::Windows::Forms::DataGridView^ gridMatriz;
        System::Windows::Forms::Button^ btnConfirmar;
        System::Windows::Forms::Label^ lblInstrucciones;

    public:
        MatrizForm(int n)
        {
            numNodos = n;
            InitializeComponent();
            ConfigurarGrid();
        }

    protected:
        ~MatrizForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->gridMatriz = (gcnew System::Windows::Forms::DataGridView());
               this->btnConfirmar = (gcnew System::Windows::Forms::Button());
               this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMatriz))->BeginInit();
               this->SuspendLayout();

               // lblInstrucciones
               this->lblInstrucciones->AutoSize = true;
               this->lblInstrucciones->Location = System::Drawing::Point(12, 9);
               this->lblInstrucciones->Name = L"lblInstrucciones";
               this->lblInstrucciones->Size = System::Drawing::Size(250, 13);
               this->lblInstrucciones->TabIndex = 2;
               this->lblInstrucciones->Text = L"Haga clic en las celdas para conectar nodos (0 -> 1)";

               // gridMatriz
               this->gridMatriz->AllowUserToAddRows = false;
               this->gridMatriz->AllowUserToDeleteRows = false;
               this->gridMatriz->AllowUserToResizeColumns = false;
               this->gridMatriz->AllowUserToResizeRows = false;
               this->gridMatriz->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->gridMatriz->Location = System::Drawing::Point(12, 35);
               this->gridMatriz->Name = L"gridMatriz";
               this->gridMatriz->ReadOnly = true; // Se edita por clic, no escribiendo
               this->gridMatriz->RowHeadersWidth = 50;
               this->gridMatriz->Size = System::Drawing::Size(400, 300);
               this->gridMatriz->TabIndex = 0;
               this->gridMatriz->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MatrizForm::gridMatriz_CellClick);

               // btnConfirmar
               this->btnConfirmar->Location = System::Drawing::Point(12, 350);
               this->btnConfirmar->Name = L"btnConfirmar";
               this->btnConfirmar->Size = System::Drawing::Size(120, 30);
               this->btnConfirmar->TabIndex = 1;
               this->btnConfirmar->Text = L"Confirmar y Dibujar";
               this->btnConfirmar->UseVisualStyleBackColor = true;
               this->btnConfirmar->Click += gcnew System::EventHandler(this, &MatrizForm::btnConfirmar_Click);

               // MatrizForm
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(430, 400);
               this->Controls->Add(this->lblInstrucciones);
               this->Controls->Add(this->btnConfirmar);
               this->Controls->Add(this->gridMatriz);
               this->Name = L"MatrizForm";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
               this->Text = L"Constructor de Matriz de Adyacencia";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMatriz))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion

    private: void ConfigurarGrid() {
        // Crear columnas
        for (int i = 0; i < numNodos; i++) {
            gridMatriz->Columns->Add("Col" + i, (i + 1).ToString());
            gridMatriz->Columns[i]->Width = 30;
            gridMatriz->Columns[i]->SortMode = DataGridViewColumnSortMode::NotSortable;
        }

        // Crear filas y llenarlas de 0s
        for (int i = 0; i < numNodos; i++) {
            gridMatriz->Rows->Add();
            gridMatriz->Rows[i]->HeaderCell->Value = (i + 1).ToString();
            for (int j = 0; j < numNodos; j++) {
                gridMatriz->Rows[i]->Cells[j]->Value = "0";
                gridMatriz->Rows[i]->Cells[j]->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
                if (i == j) {
                    gridMatriz->Rows[i]->Cells[j]->Style->BackColor = Color::LightGray; // Diagonal inhabilitada
                }
            }
        }
    }

           // Evento al hacer clic en una celda
    private: System::Void gridMatriz_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        int fila = e->RowIndex;
        int col = e->ColumnIndex;

        // Ignorar clics fuera de las celdas o en la diagonal
        if (fila < 0 || col < 0 || fila == col) return;

        String^ valorActual = gridMatriz->Rows[fila]->Cells[col]->Value->ToString();

        // Alternar entre "0" y "1"
        String^ nuevoValor = (valorActual == "0") ? "1" : "0";

        // *** AQUÍ ESTÁ LA LÓGICA ESPEJO (BIDIRECCIONAL) ***
        gridMatriz->Rows[fila]->Cells[col]->Value = nuevoValor;
        gridMatriz->Rows[col]->Cells[fila]->Value = nuevoValor; // Conecta viceversa al mismo tiempo
    }

    private: System::Void btnConfirmar_Click(System::Object^ sender, System::EventArgs^ e) {
        // Extraer los datos del DataGridView a un vector std de C++
        std::vector<std::vector<int>> matrizGenerada(numNodos, std::vector<int>(numNodos, 0));

        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                matrizGenerada[i][j] = Convert::ToInt32(gridMatriz->Rows[i]->Cells[j]->Value);
            }
        }

        // Disparar evento para enviar la matriz a MainPanel
        OnMatrizConfirmada(matrizGenerada);
        this->Close(); // Cerrar esta ventana de matriz
    }
    };
}