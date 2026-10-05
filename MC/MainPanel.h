#pragma once
// [CAMBIO GRANDE] La matriz ahora vive en este formulario: se eliminan MatrizForm.h y la salida por consola
#include "Grafo.h"
#include "MatrizVisual.h"
#include "LectorCSV.h"

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
	private: System::Windows::Forms::PictureBox^ pb1Logo;

		   Grafo* miGrafo = nullptr;
		   MatrizVisual* miMatriz = nullptr;

	public:
		MainPanel(void)
		{
			InitializeComponent();
			pb1Logo->Image = Image::FromFile("graphconex.jpg");
			pb1Logo->SizeMode = PictureBoxSizeMode::StretchImage;
			Testing_Label->Text = "Ingrese nodos y genere el grafo";
			miMatriz = new MatrizVisual();
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
			delete miMatriz;
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
	private: System::Windows::Forms::Panel^ Matrix_Panel; // [CAMBIO GRANDE] Matriz al costado del grafo
	private: System::Windows::Forms::Label^ Description_Label;
	private: System::Windows::Forms::Button^ GraphGeneratorCSV_Button;
	private: System::Windows::Forms::OpenFileDialog^ CSV_Dialog;
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
			   this->pb1Logo = (gcnew System::Windows::Forms::PictureBox());
			   this->Matrix_Panel = (gcnew System::Windows::Forms::Panel());
			   this->Description_Label = (gcnew System::Windows::Forms::Label());
			   this->GraphGeneratorCSV_Button = (gcnew System::Windows::Forms::Button());
			   this->CSV_Dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->Buttons->SuspendLayout();
			   this->Graph_Panel->SuspendLayout();
			   this->Inputs_Panel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1Logo))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Buttons
			   // 
			   this->Buttons->Controls->Add(this->Final);
			   this->Buttons->Controls->Add(this->Next);
			   this->Buttons->Controls->Add(this->Start_Pause);
			   this->Buttons->Controls->Add(this->Previous);
			   this->Buttons->Controls->Add(this->Beginning);
			   this->Buttons->Location = System::Drawing::Point(326, 570);
			   this->Buttons->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Buttons->Name = L"Buttons";
			   this->Buttons->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Buttons->Size = System::Drawing::Size(627, 154);
			   this->Buttons->TabIndex = 0;
			   this->Buttons->TabStop = false;
			   // 
			   // Final
			   // 
			   this->Final->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Final->Location = System::Drawing::Point(500, 63);
			   this->Final->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Final->Name = L"Final";
			   this->Final->Size = System::Drawing::Size(81, 35);
			   this->Final->TabIndex = 4;
			   this->Final->Text = L"⏭";
			   this->Final->UseVisualStyleBackColor = true;
			   this->Final->Click += gcnew System::EventHandler(this, &MainPanel::Final_Click);
			   // 
			   // Next
			   // 
			   this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Next->Location = System::Drawing::Point(380, 65);
			   this->Next->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Next->Name = L"Next";
			   this->Next->Size = System::Drawing::Size(81, 35);
			   this->Next->TabIndex = 3;
			   this->Next->Text = L"⏩";
			   this->Next->UseVisualStyleBackColor = true;
			   this->Next->Click += gcnew System::EventHandler(this, &MainPanel::Next_Click);
			   // 
			   // Start_Pause
			   // 
			   this->Start_Pause->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Start_Pause->Location = System::Drawing::Point(267, 63);
			   this->Start_Pause->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Start_Pause->Name = L"Start_Pause";
			   this->Start_Pause->Size = System::Drawing::Size(81, 38);
			   this->Start_Pause->TabIndex = 2;
			   this->Start_Pause->Text = L"⏵";
			   this->Start_Pause->UseVisualStyleBackColor = true;
			   this->Start_Pause->Click += gcnew System::EventHandler(this, &MainPanel::Start_Pause_Click);
			   // 
			   // Previous
			   // 
			   this->Previous->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Previous->Enabled = false;
			   this->Previous->Location = System::Drawing::Point(159, 66);
			   this->Previous->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Previous->Name = L"Previous";
			   this->Previous->Size = System::Drawing::Size(81, 35);
			   this->Previous->TabIndex = 1;
			   this->Previous->Text = L"⏪";
			   this->Previous->UseVisualStyleBackColor = true;
			   this->Previous->Click += gcnew System::EventHandler(this, &MainPanel::Previous_Click);
			   // 
			   // Beginning
			   // 
			   this->Beginning->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Beginning->Location = System::Drawing::Point(42, 66);
			   this->Beginning->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Beginning->Name = L"Beginning";
			   this->Beginning->Size = System::Drawing::Size(81, 35);
			   this->Beginning->TabIndex = 0;
			   this->Beginning->Text = L"⏮";
			   this->Beginning->UseVisualStyleBackColor = true;
			   this->Beginning->Click += gcnew System::EventHandler(this, &MainPanel::Beginning_Click);
			   // 
			   // Graph_Panel
			   // 
			   this->Graph_Panel->BackColor = System::Drawing::Color::White;
			   this->Graph_Panel->Controls->Add(this->Testing_Label);
			   this->Graph_Panel->Location = System::Drawing::Point(305, 52);
			   this->Graph_Panel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Graph_Panel->Name = L"Graph_Panel";
			   this->Graph_Panel->Size = System::Drawing::Size(677, 487);
			   this->Graph_Panel->TabIndex = 1;
			   this->Graph_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Graph_Panel_Paint);
			   // 
			   // Testing_Label
			   // 
			   this->Testing_Label->AutoSize = true;
			   this->Testing_Label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Testing_Label->Location = System::Drawing::Point(15, 15);
			   this->Testing_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Testing_Label->Name = L"Testing_Label";
			   this->Testing_Label->Size = System::Drawing::Size(96, 31);
			   this->Testing_Label->TabIndex = 0;
			   this->Testing_Label->Text = L"Paso 0";
			   // 
			   // Inputs_Panel
			   // 
			   this->Inputs_Panel->Controls->Add(this->GraphGeneratorCSV_Button);
			   this->Inputs_Panel->Controls->Add(this->GraphGeneratorManual_Botton);
			   this->Inputs_Panel->Controls->Add(this->GraphGeneratorAutomatic_Button_);
			   this->Inputs_Panel->Controls->Add(this->GrafoGenerator_Label);
			   this->Inputs_Panel->Controls->Add(this->NumberofNodes_TextBox);
			   this->Inputs_Panel->Controls->Add(this->NumberofNodes_Label);
			   this->Inputs_Panel->Location = System::Drawing::Point(18, 115);
			   this->Inputs_Panel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Inputs_Panel->Name = L"Inputs_Panel";
			   this->Inputs_Panel->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Inputs_Panel->Size = System::Drawing::Size(255, 665);
			   this->Inputs_Panel->TabIndex = 2;
			   this->Inputs_Panel->TabStop = false;
			   // 
			   // GraphGeneratorManual_Botton
			   // 
			   this->GraphGeneratorManual_Botton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorManual_Botton->Location = System::Drawing::Point(8, 201);
			   this->GraphGeneratorManual_Botton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->GraphGeneratorManual_Botton->Name = L"GraphGeneratorManual_Botton";
			   this->GraphGeneratorManual_Botton->Size = System::Drawing::Size(104, 42);
			   this->GraphGeneratorManual_Botton->TabIndex = 4;
			   this->GraphGeneratorManual_Botton->Text = L"Manual";
			   this->GraphGeneratorManual_Botton->UseVisualStyleBackColor = true;
			   this->GraphGeneratorManual_Botton->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorManual_Botton_Click);
			   // 
			   // GraphGeneratorAutomatic_Button_
			   // 
			   this->GraphGeneratorAutomatic_Button_->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorAutomatic_Button_->Location = System::Drawing::Point(120, 201);
			   this->GraphGeneratorAutomatic_Button_->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->GraphGeneratorAutomatic_Button_->Name = L"GraphGeneratorAutomatic_Button_";
			   this->GraphGeneratorAutomatic_Button_->Size = System::Drawing::Size(104, 42);
			   this->GraphGeneratorAutomatic_Button_->TabIndex = 3;
			   this->GraphGeneratorAutomatic_Button_->Text = L"Auto";
			   this->GraphGeneratorAutomatic_Button_->UseVisualStyleBackColor = true;
			   this->GraphGeneratorAutomatic_Button_->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorAutomatic_Button__Click);
			   // 
			   // GrafoGenerator_Label
			   // 
			   this->GrafoGenerator_Label->Location = System::Drawing::Point(22, 158);
			   this->GrafoGenerator_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->GrafoGenerator_Label->Name = L"GrafoGenerator_Label";
			   this->GrafoGenerator_Label->Size = System::Drawing::Size(150, 38);
			   this->GrafoGenerator_Label->TabIndex = 2;
			   this->GrafoGenerator_Label->Text = L"Generar Grafo:";
			   // 
			   // NumberofNodes_TextBox
			   // 
			   this->NumberofNodes_TextBox->Location = System::Drawing::Point(26, 97);
			   this->NumberofNodes_TextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->NumberofNodes_TextBox->Name = L"NumberofNodes_TextBox";
			   this->NumberofNodes_TextBox->Size = System::Drawing::Size(148, 26);
			   this->NumberofNodes_TextBox->TabIndex = 1;
			   // 
			   // NumberofNodes_Label
			   // 
			   this->NumberofNodes_Label->Location = System::Drawing::Point(26, 53);
			   this->NumberofNodes_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->NumberofNodes_Label->Name = L"NumberofNodes_Label";
			   this->NumberofNodes_Label->Size = System::Drawing::Size(150, 57);
			   this->NumberofNodes_Label->TabIndex = 0;
			   this->NumberofNodes_Label->Text = L"Cantidad de Nodos (4-12):";
			   // 
			   // GraphGeneratorCSV_Button
			   // 
			   this->GraphGeneratorCSV_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorCSV_Button->Location = System::Drawing::Point(8, 251);
			   this->GraphGeneratorCSV_Button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->GraphGeneratorCSV_Button->Name = L"GraphGeneratorCSV_Button";
			   this->GraphGeneratorCSV_Button->Size = System::Drawing::Size(216, 42);
			   this->GraphGeneratorCSV_Button->TabIndex = 5;
			   this->GraphGeneratorCSV_Button->Text = L"Cargar CSV";
			   this->GraphGeneratorCSV_Button->UseVisualStyleBackColor = true;
			   this->GraphGeneratorCSV_Button->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorCSV_Button_Click);
			   // 
			   // Matrix_Panel
			   // 
			   this->Matrix_Panel->BackColor = System::Drawing::Color::White;
			   this->Matrix_Panel->Location = System::Drawing::Point(1010, 52);
			   this->Matrix_Panel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Matrix_Panel->Name = L"Matrix_Panel";
			   this->Matrix_Panel->Size = System::Drawing::Size(440, 487);
			   this->Matrix_Panel->TabIndex = 4;
			   this->Matrix_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Matrix_Panel_Paint);
			   this->Matrix_Panel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPanel::Matrix_Panel_MouseClick);
			   // 
			   // Description_Label
			   // 
			   this->Description_Label->Location = System::Drawing::Point(1010, 570);
			   this->Description_Label->Name = L"Description_Label";
			   this->Description_Label->Size = System::Drawing::Size(440, 154);
			   this->Description_Label->TabIndex = 5;
			   // 
			   // CSV_Dialog
			   // 
			   this->CSV_Dialog->Filter = L"Archivos CSV (*.csv)|*.csv";
			   this->CSV_Dialog->Title = L"Cargar grafo desde CSV";
			   // 
			   // Page_Timer
			   // 
			   this->Page_Timer->Interval = 800;
			   this->Page_Timer->Tick += gcnew System::EventHandler(this, &MainPanel::timer1_Tick);
			   // 
			   // pb1Logo
			   // 
			   this->pb1Logo->BackColor = System::Drawing::Color::Transparent;
			   this->pb1Logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pb1Logo->Location = System::Drawing::Point(12, 14);
			   this->pb1Logo->Name = L"pb1Logo";
			   this->pb1Logo->Size = System::Drawing::Size(261, 119);
			   this->pb1Logo->TabIndex = 3;
			   this->pb1Logo->TabStop = false;
			   // 
			   // MainPanel
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::LightGray;
			   this->ClientSize = System::Drawing::Size(1478, 798);
			   this->Controls->Add(this->Description_Label);
			   this->Controls->Add(this->Matrix_Panel);
			   this->Controls->Add(this->pb1Logo);
			   this->Controls->Add(this->Inputs_Panel);
			   this->Controls->Add(this->Graph_Panel);
			   this->Controls->Add(this->Buttons);
			   this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
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

	// [CAMBIO GRANDE] Cada paso se ejecuta al momento: el grafo solo cambia al llegar al ultimo paso
	private: void ActualizarVistaPasoAPaso() {
		miGrafo->ejecutarPaso(page);
		Algoritmo& algoritmo = miGrafo->getAlgoritmo();

		this->Previous->Enabled = (page > 0);
		this->Next->Enabled = (page < max_pages);
		Testing_Label->Text = String::Format(L"Paso {0} de {1}", page + 1, max_pages + 1);
		Description_Label->Text = String::Format(L"{0}\r\n\r\n{1}", gcnew String(algoritmo.getTitulo().c_str()), gcnew String(algoritmo.getMensaje().c_str()));

		Graph_Panel->Invalidate();
		Matrix_Panel->Invalidate();
	}

	private: void ReiniciarSimulacion() {
		page = 0;
		max_pages = miGrafo->totalPasos() - 1;
		Page_Timer->Stop();
		this->Start_Pause->Text = L"\u23F5";
		ActualizarVistaPasoAPaso();
	}

	private: void NuevoGrafo(int n) {
		if (miGrafo != nullptr) { delete miGrafo; }
		miGrafo = new Grafo(n, Graph_Panel->Width, Graph_Panel->Height);
	}

	private: int LeerCantidadNodos() {
		int n;
		if (Int32::TryParse(NumberofNodes_TextBox->Text, n) && n >= MIN_NODOS && n <= MAX_NODOS) {
			return n;
		}
		MessageBox::Show("Por favor, ingrese un número entero válido entre 4 y 12.",
			"Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return 0;
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
			miGrafo->dibujar(e->Graphics, page == max_pages);
		}
	}

	private: System::Void Matrix_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (miGrafo != nullptr) {
			miMatriz->dibujar(e->Graphics, miGrafo, Matrix_Panel->Width);
		}
	}

	// Solo se edita en el paso 0: despues la matriz es el resultado del algoritmo
	private: System::Void Matrix_Panel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int fila, columna;
		if (miGrafo == nullptr || page != 0) return;
		if (miMatriz->celdaEn(e->X, e->Y, miGrafo->getNumNodos(), fila, columna)) {
			miGrafo->alternarArista(fila, columna);
			ReiniciarSimulacion();
		}
	}

	private: System::Void GraphGeneratorManual_Botton_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = LeerCantidadNodos();
		if (n == 0) return;

		NuevoGrafo(n);
		ReiniciarSimulacion();
	}

	private: System::Void GraphGeneratorAutomatic_Button__Click(System::Object^ sender, System::EventArgs^ e) {
		int n = LeerCantidadNodos();
		if (n == 0) return;

		NuevoGrafo(n);
		miGrafo->generarMatrizAleatoria();
		ReiniciarSimulacion();
	}

	private: System::Void GraphGeneratorCSV_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (CSV_Dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;

		try {
			LectorCSV lector;
			Matriz matriz = lector.leer(CSV_Dialog->FileName);
			int n = matriz.size();
			NumberofNodes_TextBox->Text = n.ToString();
			NuevoGrafo(n);
			miGrafo->cargarMatriz(matriz);
			ReiniciarSimulacion();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error al leer el CSV", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};
}