#pragma once
#include "Grafo.h"
#include "algoritmo.h" 
#include "MatrizForm.h" // NUEVO: Incluimos el nuevo formulario de la tabla interactiva
#include <iostream>

namespace MC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainPanel : public System::Windows::Forms::Form
	{
	private:
		int page = 0;
		int max_pages = 3;
		Grafo* miGrafo = nullptr;

	public:
		MainPanel(void)
		{
			InitializeComponent();
			Testing_Label->Text = "Ingrese nodos y genere el grafo";
		}

	protected:
		~MainPanel()
		{
			if (components)
			{
				delete components;
			}
			if (miGrafo != nullptr) {
				delete miGrafo;
				miGrafo = nullptr;
			}
		}

	private: System::Windows::Forms::GroupBox^ Buttons;
	private: System::Windows::Forms::Button^ Final;
	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Start_Pause;
	private: System::Windows::Forms::Button^ Previous;
	private: System::Windows::Forms::Button^ Beginning;
	private: System::Windows::Forms::Panel^ Graph_Panel; // Aquí se verán los grafos visuales
	private: System::Windows::Forms::GroupBox^ Inputs_Panel;
	private: System::Windows::Forms::TextBox^ NumberofNodes_TextBox;
	private: System::Windows::Forms::Label^ NumberofNodes_Label;
	private: System::Windows::Forms::Label^ GrafoGenerator_Label;
	private: System::Windows::Forms::Button^ GraphGeneratorManual_Botton;
	private: System::Windows::Forms::Button^ GraphGeneratorAutomatic_Button_;
	private: System::Windows::Forms::Label^ Testing_Label;
	private: System::Windows::Forms::Timer^ Page_Timer;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->Buttons = (gcnew System::Windows::Forms::GroupBox());
			   this->Final = (gcnew System::Windows::Forms::Button());
			   this->Next = (gcnew System::Windows::Forms::Button());
			   this->Start_Pause = (gcnew System::Windows::Forms::Button());
			   this->Previous = (gcnew System::Windows::Forms::Button());
			   this->Beginning = (gcnew System::Windows::Forms::Button());
			   this->Graph_Panel = (gcnew System::Windows::Forms::Panel());
			   this->Testing_Label = (gcnew System::Windows::Forms::Label());
			   this->Inputs_Panel = (gcnew System::Windows::Forms::GroupBox());
			   this->GraphGeneratorManual_Botton = (gcnew System::Windows::Forms::Button());
			   this->GraphGeneratorAutomatic_Button_ = (gcnew System::Windows::Forms::Button());
			   this->GrafoGenerator_Label = (gcnew System::Windows::Forms::Label());
			   this->NumberofNodes_TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->NumberofNodes_Label = (gcnew System::Windows::Forms::Label());
			   this->Page_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->Buttons->SuspendLayout();
			   this->Graph_Panel->SuspendLayout();
			   this->Inputs_Panel->SuspendLayout();
			   this->SuspendLayout();

			   // [Controles de botones de reproducción omitidos por brevedad, son idénticos]
			   this->Buttons->Controls->Add(this->Final);
			   this->Buttons->Controls->Add(this->Next);
			   this->Buttons->Controls->Add(this->Start_Pause);
			   this->Buttons->Controls->Add(this->Previous);
			   this->Buttons->Controls->Add(this->Beginning);
			   this->Buttons->Location = System::Drawing::Point(212, 390);
			   this->Buttons->Name = L"Buttons";
			   this->Buttons->Size = System::Drawing::Size(415, 100);
			   this->Buttons->TabIndex = 0;
			   this->Buttons->TabStop = false;

			   this->Final->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Final->Location = System::Drawing::Point(333, 41);
			   this->Final->Name = L"Final";
			   this->Final->Size = System::Drawing::Size(54, 23);
			   this->Final->TabIndex = 4;
			   this->Final->Text = L"⏭";
			   this->Final->UseVisualStyleBackColor = true;
			   this->Final->Click += gcnew System::EventHandler(this, &MainPanel::Final_Click);

			   this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Next->Location = System::Drawing::Point(253, 42);
			   this->Next->Name = L"Next";
			   this->Next->Size = System::Drawing::Size(54, 23);
			   this->Next->TabIndex = 3;
			   this->Next->Text = L"⏩";
			   this->Next->UseVisualStyleBackColor = true;
			   this->Next->Click += gcnew System::EventHandler(this, &MainPanel::Next_Click);

			   this->Start_Pause->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Start_Pause->Location = System::Drawing::Point(178, 41);
			   this->Start_Pause->Name = L"Start_Pause";
			   this->Start_Pause->Size = System::Drawing::Size(54, 25);
			   this->Start_Pause->TabIndex = 2;
			   this->Start_Pause->Text = L"⏵";
			   this->Start_Pause->UseVisualStyleBackColor = true;
			   this->Start_Pause->Click += gcnew System::EventHandler(this, &MainPanel::Start_Pause_Click);

			   this->Previous->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Previous->Location = System::Drawing::Point(106, 43);
			   this->Previous->Name = L"Previous";
			   this->Previous->Size = System::Drawing::Size(54, 23);
			   this->Previous->TabIndex = 1;
			   this->Previous->Text = L"⏪";
			   this->Previous->UseVisualStyleBackColor = true;
			   this->Previous->Enabled = false;
			   this->Previous->Click += gcnew System::EventHandler(this, &MainPanel::Previous_Click);

			   this->Beginning->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Beginning->Location = System::Drawing::Point(28, 43);
			   this->Beginning->Name = L"Beginning";
			   this->Beginning->Size = System::Drawing::Size(54, 23);
			   this->Beginning->TabIndex = 0;
			   this->Beginning->Text = L"⏮";
			   this->Beginning->UseVisualStyleBackColor = true;
			   this->Beginning->Click += gcnew System::EventHandler(this, &MainPanel::Beginning_Click);

			   // Graph_Panel - Solo alojará el dibujo de los grafos
			   this->Graph_Panel->BackColor = System::Drawing::Color::White;
			   this->Graph_Panel->Controls->Add(this->Testing_Label);
			   this->Graph_Panel->Location = System::Drawing::Point(212, 65);
			   this->Graph_Panel->Name = L"Graph_Panel";
			   this->Graph_Panel->Size = System::Drawing::Size(415, 277);
			   this->Graph_Panel->TabIndex = 1;
			   this->Graph_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Graph_Panel_Paint);

			   // Testing_Label
			   this->Testing_Label->AutoSize = true;
			   this->Testing_Label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Testing_Label->Location = System::Drawing::Point(10, 10);
			   this->Testing_Label->Name = L"Testing_Label";
			   this->Testing_Label->Size = System::Drawing::Size(56, 52);
			   this->Testing_Label->TabIndex = 0;
			   this->Testing_Label->Text = L"Paso 0";

			   // Inputs_Panel
			   this->Inputs_Panel->Controls->Add(this->GraphGeneratorManual_Botton);
			   this->Inputs_Panel->Controls->Add(this->GraphGeneratorAutomatic_Button_);
			   this->Inputs_Panel->Controls->Add(this->GrafoGenerator_Label);
			   this->Inputs_Panel->Controls->Add(this->NumberofNodes_TextBox);
			   this->Inputs_Panel->Controls->Add(this->NumberofNodes_Label);
			   this->Inputs_Panel->Location = System::Drawing::Point(12, 65);
			   this->Inputs_Panel->Name = L"Inputs_Panel";
			   this->Inputs_Panel->Size = System::Drawing::Size(147, 442);
			   this->Inputs_Panel->TabIndex = 2;
			   this->Inputs_Panel->TabStop = false;

			   // GraphGeneratorManual_Botton
			   this->GraphGeneratorManual_Botton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorManual_Botton->Location = System::Drawing::Point(17, 295);
			   this->GraphGeneratorManual_Botton->Name = L"GraphGeneratorManual_Botton";
			   this->GraphGeneratorManual_Botton->Size = System::Drawing::Size(97, 27);
			   this->GraphGeneratorManual_Botton->TabIndex = 4;
			   this->GraphGeneratorManual_Botton->Text = L"Manual";
			   this->GraphGeneratorManual_Botton->UseVisualStyleBackColor = true;
			   // NUEVO: Vincular el evento click para abrir la ventana de matriz interactiva
			   this->GraphGeneratorManual_Botton->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorManual_Botton_Click);

			   // GraphGeneratorAutomatic_Button_
			   this->GraphGeneratorAutomatic_Button_->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorAutomatic_Button_->Location = System::Drawing::Point(17, 342);
			   this->GraphGeneratorAutomatic_Button_->Name = L"GraphGeneratorAutomatic_Button_";
			   this->GraphGeneratorAutomatic_Button_->Size = System::Drawing::Size(97, 27);
			   this->GraphGeneratorAutomatic_Button_->TabIndex = 3;
			   this->GraphGeneratorAutomatic_Button_->Text = L"Automatica";
			   this->GraphGeneratorAutomatic_Button_->UseVisualStyleBackColor = true;
			   this->GraphGeneratorAutomatic_Button_->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorAutomatic_Button__Click);

			   // GrafoGenerator_Label
			   this->GrafoGenerator_Label->Location = System::Drawing::Point(17, 252);
			   this->GrafoGenerator_Label->Name = L"GrafoGenerator_Label";
			   this->GrafoGenerator_Label->Size = System::Drawing::Size(100, 25);
			   this->GrafoGenerator_Label->TabIndex = 2;
			   this->GrafoGenerator_Label->Text = L"Generar Grafo:";

			   // NumberofNodes_TextBox
			   this->NumberofNodes_TextBox->Location = System::Drawing::Point(17, 67);
			   this->NumberofNodes_TextBox->Name = L"NumberofNodes_TextBox";
			   this->NumberofNodes_TextBox->Size = System::Drawing::Size(100, 20);
			   this->NumberofNodes_TextBox->TabIndex = 1;

			   // NumberofNodes_Label
			   this->NumberofNodes_Label->Location = System::Drawing::Point(17, 39);
			   this->NumberofNodes_Label->Name = L"NumberofNodes_Label";
			   this->NumberofNodes_Label->Size = System::Drawing::Size(100, 37);
			   this->NumberofNodes_Label->TabIndex = 0;
			   this->NumberofNodes_Label->Text = L"Cantidad de Nodos (4-12):";

			   // Page_Timer
			   this->Page_Timer->Interval = 1500;
			   this->Page_Timer->Tick += gcnew System::EventHandler(this, &MainPanel::timer1_Tick);

			   // MainPanel
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(679, 519);
			   this->Controls->Add(this->Inputs_Panel);
			   this->Controls->Add(this->Graph_Panel);
			   this->Controls->Add(this->Buttons);
			   this->Name = L"MainPanel";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Proyecto Componentes Conexas";
			   this->Buttons->ResumeLayout(false);
			   this->Graph_Panel->ResumeLayout(false);
			   this->Graph_Panel->PerformLayout();
			   this->Inputs_Panel->ResumeLayout(false);
			   this->Inputs_Panel->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: void ActualizarVistaPasoAPaso() {
		this->Previous->Enabled = (page > 0);
		this->Next->Enabled = (page < max_pages);

		if (page == 0) {
			Testing_Label->Text = "Paso 0: Grafo Inicial (Matriz de Adyacencia)";
		}
		else if (page == 1) {
			Testing_Label->Text = "Paso 1: Construyendo Matriz de Caminos";
		}
		else if (page == 2) {
			Testing_Label->Text = "Paso 2: Reordenando Filas y Columnas";
		}
		else if (page == 3) {
			Testing_Label->Text = "Paso 3: Componentes Conexas Encontradas";
		}

		Graph_Panel->Invalidate();
	}

	private: System::Void Start_Pause_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo == nullptr) return;

		if (Page_Timer->Enabled == false) {
			Page_Timer->Start();
			this->Start_Pause->Text = L"\u23F8";
		}
		else {
			Page_Timer->Stop();
			this->Start_Pause->Text = L"\u23F5";
		}
	}

	private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo != nullptr && page < max_pages) {
			page++;
			ActualizarVistaPasoAPaso();
		}
	}

	private: System::Void Previous_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo != nullptr && page > 0) {
			page--;
			ActualizarVistaPasoAPaso();
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (page < max_pages) {
			page++;
			ActualizarVistaPasoAPaso();
		}
		else {
			Page_Timer->Stop();
			this->Start_Pause->Text = L"\u23F5";
		}
	}

	private: System::Void Beginning_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo != nullptr) {
			page = 0;
			ActualizarVistaPasoAPaso();
		}
	}

	private: System::Void Final_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo != nullptr) {
			page = max_pages;
			ActualizarVistaPasoAPaso();
		}
	}

	private: System::Void Graph_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (miGrafo != nullptr) {
			miGrafo->dibujar(e->Graphics, page);
		}
	}

		   // NUEVO EVENTO: Al hacer clic en el botón "Manual"
	private: System::Void GraphGeneratorManual_Botton_Click(System::Object^ sender, System::EventArgs^ e) {
		int n;
		if (Int32::TryParse(NumberofNodes_TextBox->Text, n) && n >= 4 && n <= 12) {
			// Crear la nueva ventana de MatrizForm
			MatrizForm^ ventanaMatriz = gcnew MatrizForm(n);

			// Suscribir a este formulario para recibir la matriz cuando el usuario termine
			ventanaMatriz->OnMatrizConfirmada += gcnew MatrizConfirmadaEventHandler(this, &MainPanel::RecibirMatrizManual);

			// Mostrar la ventana como un diálogo modal (bloquea la ventana principal hasta que termine)
			ventanaMatriz->ShowDialog();
		}
		else {
			MessageBox::Show("Por favor, ingrese un número entero válido entre 4 y 12.",
				"Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   // NUEVO MÉTODO: Se llama cuando el usuario presiona "Confirmar" en la ventana MatrizForm
	private: void RecibirMatrizManual(std::vector<std::vector<int>> matrizAdy) {
		int n = matrizAdy.size();

		if (miGrafo != nullptr) { delete miGrafo; }

		// 1. Se crea la base visual del panel
		miGrafo = new Grafo(n, Graph_Panel->Width, Graph_Panel->Height);

		// 2. Transferimos la información creada manualmente al Grafo visual
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (matrizAdy[i][j] == 1) {
					// Gracias a la lógica espejo en MatrizForm, sabemos que si [i][j] es 1, [j][i] también lo es
					miGrafo->agregarArista(i, j);
				}
			}
		}

		// 3. Calculamos la parte visual en Grafo.h
		miGrafo->calcularComponentesConexas();

		// 4. Imprimimos el proceso matemático paso a paso en la consola
		std::cout << "\n============================================================\n";
		std::cout << "INICIO DE GENERACION MANUAL - COMPONENTES CONEXAS";
		std::cout << "\n============================================================\n";
		mostrarMatriz(matrizAdy, "MATRIZ DE ADYACENCIA INICIAL");

		Matriz caminos = construirMatrizCaminos(matrizAdy);
		mostrarMatriz(caminos, "PASO 1: MATRIZ DE CAMINOS FINAL");

		std::vector<int> orden = obtenerOrdenFilas(caminos);
		mostrarTitulo("PASO 2: ORDEN DE LAS FILAS");
		for (int i = 0; i < (int)caminos.size(); i++) {
			std::cout << "Nodo " << i + 1 << ": " << cantidadUnos(caminos[i])
				<< " unos | primer 1 en columna "
				<< primeraColumna(caminos[i]) + 1 << "\n";
		}
		std::cout << "\nOrden de las filas: [" << nodosATexto(orden, ", ") << "]\n";

		Matriz ordenada = reordenarMatriz(caminos, orden);
		mostrarMatriz(ordenada, "PASO 3: FILAS Y COLUMNAS ORDENADAS");

		std::vector<std::vector<int>> bloques = obtenerBloques(ordenada, orden);
		mostrarTitulo("PASO 4: BLOQUES CUADRADOS");
		for (size_t i = 0; i < bloques.size(); i++) {
			std::cout << "Bloque " << i + 1 << ": " << nodosATexto(bloques[i], "; ")
				<< " (" << bloques[i].size() << "x" << bloques[i].size() << ")\n";
		}

		mostrarTitulo("RESULTADO FINAL");
		std::cout << "Cantidad de componentes conexas: " << bloques.size() << "\n";
		for (size_t i = 0; i < bloques.size(); i++) {
			std::cout << "Componente " << i + 1 << ": { " << nodosATexto(bloques[i], ", ") << " }\n";
		}
		std::cout << "\n*** REVISE EL PANEL GRAFICO PARA VER LA ANIMACION ***\n\n";

		// Reiniciamos UI y temporizador
		page = 0;
		Page_Timer->Stop();
		this->Start_Pause->Text = L"\u23F5";
		ActualizarVistaPasoAPaso();
	}

	private: System::Void GraphGeneratorAutomatic_Button__Click(System::Object^ sender, System::EventArgs^ e) {
		int n;
		if (Int32::TryParse(NumberofNodes_TextBox->Text, n) && n >= 4 && n <= 12) {
			if (miGrafo != nullptr) { delete miGrafo; }

			miGrafo = new Grafo(n, Graph_Panel->Width, Graph_Panel->Height);

			// Generamos la matriz automáticamente
			Matriz matrizAdy = generarMatrizAleatoria(n);

			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (matrizAdy[i][j] == 1) {
						miGrafo->agregarArista(i, j);
					}
				}
			}

			miGrafo->calcularComponentesConexas();

			std::cout << "\n============================================================\n";
			std::cout << "INICIO DE GENERACION AUTOMATICA - COMPONENTES CONEXAS";
			std::cout << "\n============================================================\n";
			mostrarMatriz(matrizAdy, "MATRIZ DE ADYACENCIA INICIAL");

			Matriz caminos = construirMatrizCaminos(matrizAdy);
			mostrarMatriz(caminos, "PASO 1: MATRIZ DE CAMINOS FINAL");

			std::vector<int> orden = obtenerOrdenFilas(caminos);
			mostrarTitulo("PASO 2: ORDEN DE LAS FILAS");
			for (int i = 0; i < (int)caminos.size(); i++) {
				std::cout << "Nodo " << i + 1 << ": " << cantidadUnos(caminos[i])
					<< " unos | primer 1 en columna "
					<< primeraColumna(caminos[i]) + 1 << "\n";
			}
			std::cout << "\nOrden de las filas: [" << nodosATexto(orden, ", ") << "]\n";

			Matriz ordenada = reordenarMatriz(caminos, orden);
			mostrarMatriz(ordenada, "PASO 3: FILAS Y COLUMNAS ORDENADAS");

			std::vector<std::vector<int>> bloques = obtenerBloques(ordenada, orden);
			mostrarTitulo("PASO 4: BLOQUES CUADRADOS");
			for (size_t i = 0; i < bloques.size(); i++) {
				std::cout << "Bloque " << i + 1 << ": " << nodosATexto(bloques[i], "; ")
					<< " (" << bloques[i].size() << "x" << bloques[i].size() << ")\n";
			}

			mostrarTitulo("RESULTADO FINAL");
			std::cout << "Cantidad de componentes conexas: " << bloques.size() << "\n";
			for (size_t i = 0; i < bloques.size(); i++) {
				std::cout << "Componente " << i + 1 << ": { " << nodosATexto(bloques[i], ", ") << " }\n";
			}
			std::cout << "\n*** REVISE EL PANEL GRAFICO PARA VER LA ANIMACION ***\n\n";

			page = 0;
			Page_Timer->Stop();
			this->Start_Pause->Text = L"\u23F5";
			ActualizarVistaPasoAPaso();
		}
		else {
			MessageBox::Show("Por favor, ingrese un número entero válido entre 4 y 12.",
				"Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	};
}