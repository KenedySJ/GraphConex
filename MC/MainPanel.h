#pragma once

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
	private: System::Windows::Forms::Button^ Delete_Node;
	private: System::Windows::Forms::ComboBox^ listaNodosTemporal = nullptr;
	private: System::Windows::Forms::NumericUpDown^ inputNodosTemporal = nullptr;
	private: System::Windows::Forms::Label^ lblLimitesTemporal = nullptr;
	private: System::Windows::Forms::Button^ botonOriginal = nullptr;
	private: bool modoAutomatico = false;

	private: System::Windows::Forms::Button^ Add_Node;

	private: System::Windows::Forms::PictureBox^ pb1_generarGrafo;
	private: System::Windows::Forms::Button^ GraphGeneratorAutomatic_Button_;
	private: System::Windows::Forms::Button^ GraphGeneratorCSV_Button;

	private: System::Windows::Forms::Button^ GraphGeneratorManual_Botton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pb2_4a12;



		   MatrizVisual* miMatriz = nullptr;

	public:
		MainPanel(void)
		{
			InitializeComponent();

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
	private: System::Windows::Forms::Panel^ Graph_Panel; 


	private: System::Windows::Forms::Label^ Testing_Label;
	private: System::Windows::Forms::Timer^ Page_Timer;
	private: System::Windows::Forms::Panel^ Matrix_Panel; 
	private: System::Windows::Forms::Label^ Description_Label;

	private: System::Windows::Forms::OpenFileDialog^ CSV_Dialog;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainPanel::typeid));
			   this->Buttons = (gcnew System::Windows::Forms::GroupBox());
			   this->Delete_Node = (gcnew System::Windows::Forms::Button());
			   this->Add_Node = (gcnew System::Windows::Forms::Button());
			   this->Final = (gcnew System::Windows::Forms::Button());
			   this->Next = (gcnew System::Windows::Forms::Button());
			   this->Start_Pause = (gcnew System::Windows::Forms::Button());
			   this->Previous = (gcnew System::Windows::Forms::Button());
			   this->Beginning = (gcnew System::Windows::Forms::Button());
			   this->Graph_Panel = (gcnew System::Windows::Forms::Panel());
			   this->Testing_Label = (gcnew System::Windows::Forms::Label());
			   this->Page_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pb1Logo = (gcnew System::Windows::Forms::PictureBox());
			   this->Matrix_Panel = (gcnew System::Windows::Forms::Panel());
			   this->Description_Label = (gcnew System::Windows::Forms::Label());
			   this->CSV_Dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->GraphGeneratorAutomatic_Button_ = (gcnew System::Windows::Forms::Button());
			   this->GraphGeneratorManual_Botton = (gcnew System::Windows::Forms::Button());
			   this->GraphGeneratorCSV_Button = (gcnew System::Windows::Forms::Button());
			   this->pb1_generarGrafo = (gcnew System::Windows::Forms::PictureBox());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->pb2_4a12 = (gcnew System::Windows::Forms::PictureBox());
			   this->Buttons->SuspendLayout();
			   this->Graph_Panel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1Logo))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1_generarGrafo))->BeginInit();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2_4a12))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Buttons
			   // 
			   this->Buttons->Controls->Add(this->Delete_Node);
			   this->Buttons->Controls->Add(this->Add_Node);
			   this->Buttons->Controls->Add(this->Final);
			   this->Buttons->Controls->Add(this->Next);
			   this->Buttons->Controls->Add(this->Start_Pause);
			   this->Buttons->Controls->Add(this->Previous);
			   this->Buttons->Controls->Add(this->Beginning);
			   this->Buttons->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Buttons->Location = System::Drawing::Point(173, 370);
			   this->Buttons->Name = L"Buttons";
			   this->Buttons->Size = System::Drawing::Size(418, 136);
			   this->Buttons->TabIndex = 0;
			   this->Buttons->TabStop = false;
			   // 
			   // Delete_Node
			   // 
			   this->Delete_Node->BackColor = System::Drawing::Color::LightCoral;
			   this->Delete_Node->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Delete_Node->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->Delete_Node->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Delete_Node->ForeColor = System::Drawing::Color::Black;
			   this->Delete_Node->Location = System::Drawing::Point(215, 88);
			   this->Delete_Node->Name = L"Delete_Node";
			   this->Delete_Node->Size = System::Drawing::Size(92, 31);
			   this->Delete_Node->TabIndex = 6;
			   this->Delete_Node->Text = L"Eliminar Nodo";
			   this->Delete_Node->UseVisualStyleBackColor = false;
			   this->Delete_Node->Click += gcnew System::EventHandler(this, &MainPanel::Delete_Node_Click);
			   // 
			   // Add_Node
			   // 
			   this->Add_Node->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->Add_Node->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Add_Node->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->Add_Node->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Add_Node->Location = System::Drawing::Point(106, 88);
			   this->Add_Node->Name = L"Add_Node";
			   this->Add_Node->Size = System::Drawing::Size(91, 31);
			   this->Add_Node->TabIndex = 5;
			   this->Add_Node->Text = L"Agregar nodo";
			   this->Add_Node->UseVisualStyleBackColor = false;
			   this->Add_Node->Click += gcnew System::EventHandler(this, &MainPanel::Add_Node_Click);
			   // 
			   // Final
			   // 
			   this->Final->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Final->Location = System::Drawing::Point(331, 41);
			   this->Final->Name = L"Final";
			   this->Final->Size = System::Drawing::Size(54, 23);
			   this->Final->TabIndex = 4;
			   this->Final->Text = L"⏭";
			   this->Final->UseVisualStyleBackColor = true;
			   this->Final->Click += gcnew System::EventHandler(this, &MainPanel::Final_Click);
			   // 
			   // Next
			   // 
			   this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Next->Location = System::Drawing::Point(253, 41);
			   this->Next->Name = L"Next";
			   this->Next->Size = System::Drawing::Size(54, 23);
			   this->Next->TabIndex = 3;
			   this->Next->Text = L"⏩";
			   this->Next->UseVisualStyleBackColor = true;
			   this->Next->Click += gcnew System::EventHandler(this, &MainPanel::Next_Click);
			   // 
			   // Start_Pause
			   // 
			   this->Start_Pause->BackColor = System::Drawing::Color::Silver;
			   this->Start_Pause->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Start_Pause->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->Start_Pause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Start_Pause->Location = System::Drawing::Point(181, 41);
			   this->Start_Pause->Name = L"Start_Pause";
			   this->Start_Pause->Size = System::Drawing::Size(54, 23);
			   this->Start_Pause->TabIndex = 2;
			   this->Start_Pause->Text = L"⏵";
			   this->Start_Pause->UseVisualStyleBackColor = false;
			   this->Start_Pause->Click += gcnew System::EventHandler(this, &MainPanel::Start_Pause_Click);
			   // 
			   // Previous
			   // 
			   this->Previous->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Previous->Enabled = false;
			   this->Previous->Location = System::Drawing::Point(106, 41);
			   this->Previous->Name = L"Previous";
			   this->Previous->Size = System::Drawing::Size(54, 23);
			   this->Previous->TabIndex = 1;
			   this->Previous->Text = L"⏪";
			   this->Previous->UseVisualStyleBackColor = true;
			   this->Previous->Click += gcnew System::EventHandler(this, &MainPanel::Previous_Click);
			   // 
			   // Beginning
			   // 
			   this->Beginning->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Beginning->Location = System::Drawing::Point(22, 41);
			   this->Beginning->Name = L"Beginning";
			   this->Beginning->Size = System::Drawing::Size(54, 23);
			   this->Beginning->TabIndex = 0;
			   this->Beginning->Text = L"⏮";
			   this->Beginning->UseVisualStyleBackColor = true;
			   this->Beginning->Click += gcnew System::EventHandler(this, &MainPanel::Beginning_Click);
			   // 
			   // Graph_Panel
			   // 
			   this->Graph_Panel->BackColor = System::Drawing::Color::White;
			   this->Graph_Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Graph_Panel.BackgroundImage")));
			   this->Graph_Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->Graph_Panel->Controls->Add(this->Testing_Label);
			   this->Graph_Panel->Location = System::Drawing::Point(160, 15);
			   this->Graph_Panel->Name = L"Graph_Panel";
			   this->Graph_Panel->Size = System::Drawing::Size(448, 349);
			   this->Graph_Panel->TabIndex = 1;
			   this->Graph_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Graph_Panel_Paint);
			   // 
			   // Testing_Label
			   // 
			   this->Testing_Label->AutoSize = true;
			   this->Testing_Label->BackColor = System::Drawing::Color::Transparent;
			   this->Testing_Label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Testing_Label->Location = System::Drawing::Point(18, 13);
			   this->Testing_Label->Name = L"Testing_Label";
			   this->Testing_Label->Size = System::Drawing::Size(67, 21);
			   this->Testing_Label->TabIndex = 0;
			   this->Testing_Label->Text = L"Paso 0";
			   // 
			   // Page_Timer
			   // 
			   this->Page_Timer->Interval = 800;
			   this->Page_Timer->Tick += gcnew System::EventHandler(this, &MainPanel::timer1_Tick);
			   // 
			   // pb1Logo
			   // 
			   this->pb1Logo->BackColor = System::Drawing::Color::Transparent;
			   this->pb1Logo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb1Logo.BackgroundImage")));
			   this->pb1Logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pb1Logo->Location = System::Drawing::Point(0, 0);
			   this->pb1Logo->Margin = System::Windows::Forms::Padding(2);
			   this->pb1Logo->Name = L"pb1Logo";
			   this->pb1Logo->Size = System::Drawing::Size(153, 75);
			   this->pb1Logo->TabIndex = 3;
			   this->pb1Logo->TabStop = false;
			   // 
			   // Matrix_Panel
			   // 
			   this->Matrix_Panel->BackColor = System::Drawing::Color::White;
			   this->Matrix_Panel->Location = System::Drawing::Point(613, 34);
			   this->Matrix_Panel->Name = L"Matrix_Panel";
			   this->Matrix_Panel->Size = System::Drawing::Size(281, 317);
			   this->Matrix_Panel->TabIndex = 4;
			   this->Matrix_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Matrix_Panel_Paint);
			   this->Matrix_Panel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPanel::Matrix_Panel_MouseClick);
			   // 
			   // Description_Label
			   // 
			   this->Description_Label->Location = System::Drawing::Point(625, 384);
			   this->Description_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->Description_Label->Name = L"Description_Label";
			   this->Description_Label->Size = System::Drawing::Size(269, 105);
			   this->Description_Label->TabIndex = 5;
			   // 
			   // CSV_Dialog
			   // 
			   this->CSV_Dialog->Filter = L"Archivos CSV (*.csv)|*.csv";
			   this->CSV_Dialog->Title = L"Cargar grafo desde CSV";
			   // 
			   // GraphGeneratorAutomatic_Button_
			   // 
			   this->GraphGeneratorAutomatic_Button_->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GraphGeneratorAutomatic_Button_.BackgroundImage")));
			   this->GraphGeneratorAutomatic_Button_->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->GraphGeneratorAutomatic_Button_->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorAutomatic_Button_->FlatAppearance->BorderSize = 0;
			   this->GraphGeneratorAutomatic_Button_->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->GraphGeneratorAutomatic_Button_->Location = System::Drawing::Point(16, 124);
			   this->GraphGeneratorAutomatic_Button_->Name = L"GraphGeneratorAutomatic_Button_";
			   this->GraphGeneratorAutomatic_Button_->Size = System::Drawing::Size(93, 34);
			   this->GraphGeneratorAutomatic_Button_->TabIndex = 3;
			   this->GraphGeneratorAutomatic_Button_->UseVisualStyleBackColor = true;
			   this->GraphGeneratorAutomatic_Button_->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorAutomatic_Button__Click);
			   // 
			   // GraphGeneratorManual_Botton
			   // 
			   this->GraphGeneratorManual_Botton->BackColor = System::Drawing::Color::Transparent;
			   this->GraphGeneratorManual_Botton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GraphGeneratorManual_Botton.BackgroundImage")));
			   this->GraphGeneratorManual_Botton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->GraphGeneratorManual_Botton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorManual_Botton->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			   this->GraphGeneratorManual_Botton->FlatAppearance->BorderSize = 0;
			   this->GraphGeneratorManual_Botton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->GraphGeneratorManual_Botton->ForeColor = System::Drawing::Color::Transparent;
			   this->GraphGeneratorManual_Botton->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			   this->GraphGeneratorManual_Botton->Location = System::Drawing::Point(16, 174);
			   this->GraphGeneratorManual_Botton->Name = L"GraphGeneratorManual_Botton";
			   this->GraphGeneratorManual_Botton->Size = System::Drawing::Size(93, 34);
			   this->GraphGeneratorManual_Botton->TabIndex = 4;
			   this->GraphGeneratorManual_Botton->UseVisualStyleBackColor = false;
			   this->GraphGeneratorManual_Botton->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorManual_Botton_Click);
			   // 
			   // GraphGeneratorCSV_Button
			   // 
			   this->GraphGeneratorCSV_Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GraphGeneratorCSV_Button.BackgroundImage")));
			   this->GraphGeneratorCSV_Button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->GraphGeneratorCSV_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorCSV_Button->FlatAppearance->BorderSize = 0;
			   this->GraphGeneratorCSV_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->GraphGeneratorCSV_Button->Location = System::Drawing::Point(15, 224);
			   this->GraphGeneratorCSV_Button->Name = L"GraphGeneratorCSV_Button";
			   this->GraphGeneratorCSV_Button->Size = System::Drawing::Size(93, 31);
			   this->GraphGeneratorCSV_Button->TabIndex = 5;
			   this->GraphGeneratorCSV_Button->UseVisualStyleBackColor = true;
			   this->GraphGeneratorCSV_Button->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorCSV_Button_Click);
			   // 
			   // pb1_generarGrafo
			   // 
			   this->pb1_generarGrafo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb1_generarGrafo.BackgroundImage")));
			   this->pb1_generarGrafo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pb1_generarGrafo->Location = System::Drawing::Point(15, 78);
			   this->pb1_generarGrafo->Margin = System::Windows::Forms::Padding(1);
			   this->pb1_generarGrafo->Name = L"pb1_generarGrafo";
			   this->pb1_generarGrafo->Size = System::Drawing::Size(94, 21);
			   this->pb1_generarGrafo->TabIndex = 6;
			   this->pb1_generarGrafo->TabStop = false;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			   this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panel1->Controls->Add(this->pb2_4a12);
			   this->panel1->Controls->Add(this->pb1_generarGrafo);
			   this->panel1->Controls->Add(this->GraphGeneratorAutomatic_Button_);
			   this->panel1->Controls->Add(this->GraphGeneratorCSV_Button);
			   this->panel1->Controls->Add(this->GraphGeneratorManual_Botton);
			   this->panel1->Location = System::Drawing::Point(0, 74);
			   this->panel1->Margin = System::Windows::Forms::Padding(1);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(137, 369);
			   this->panel1->TabIndex = 6;
			   // 
			   // pb2_4a12
			   // 
			   this->pb2_4a12->Location = System::Drawing::Point(0, 0);
			   this->pb2_4a12->Name = L"pb2_4a12";
			   this->pb2_4a12->Size = System::Drawing::Size(100, 50);
			   this->pb2_4a12->TabIndex = 0;
			   this->pb2_4a12->TabStop = false;
			   // 
			   // MainPanel
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::LightGray;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(925, 519);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->Description_Label);
			   this->Controls->Add(this->Matrix_Panel);
			   this->Controls->Add(this->pb1Logo);
			   this->Controls->Add(this->Graph_Panel);
			   this->Controls->Add(this->Buttons);
			   this->Name = L"MainPanel";
			   this->Padding = System::Windows::Forms::Padding(3);
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L" ";
			   this->Load += gcnew System::EventHandler(this, &MainPanel::MainPanel_Load);
			   this->Buttons->ResumeLayout(false);
			   this->Graph_Panel->ResumeLayout(false);
			   this->Graph_Panel->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1Logo))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1_generarGrafo))->EndInit();
			   this->panel1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2_4a12))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: void ActualizarVistaPasoAPaso() {
		miGrafo->ejecutarPaso(page);
		Algoritmo& algoritmo = miGrafo->getAlgoritmo();

		this->Previous->Enabled = (page > 0);
		this->Next->Enabled = (page < max_pages);
		Testing_Label->Text = String::Format(L"Paso {0} de {1}", page + 1, max_pages + 1);
		Description_Label->Text = String::Format(L"{0}\r\n\r\n{1}", gcnew String(algoritmo.getTitulo().c_str()), gcnew String(algoritmo.getMensaje().c_str()));

		PintarPanel();
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

	private: void PintarPanel() {
		Graph_Panel->Invalidate();
		Matrix_Panel->Invalidate();
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

	private: System::Void Matrix_Panel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int fila, columna;
		if (miGrafo == nullptr || page != 0) return;
		if (miMatriz->celdaEn(e->X, e->Y, miGrafo->getNumNodos(), fila, columna)) {
			miGrafo->alternarArista(fila, columna);
			ReiniciarSimulacion();
		}
	}

private: System::Void GraphGeneratorManual_Botton_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarInputNodos(GraphGeneratorManual_Botton, false);
}

private: System::Void GraphGeneratorAutomatic_Button__Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarInputNodos(GraphGeneratorAutomatic_Button_, true);
}

	private: System::Void GraphGeneratorCSV_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (CSV_Dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;

		try {
			LectorCSV lector;
			Matriz matriz = lector.leer(CSV_Dialog->FileName);
			int n = matriz.size();
			NuevoGrafo(n);
			miGrafo->cargarMatriz(matriz);
			ReiniciarSimulacion();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error al leer el CSV", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void Add_Node_Click(System::Object^ sender, System::EventArgs^ e) {
		if (miGrafo != nullptr && miGrafo->getNumNodos() < MAX_NODOS) {
			miGrafo->agregarNodo();
			ReiniciarSimulacion();
			PintarPanel();
		}
		else {
			MessageBox::Show("La cantidad de nodos ha alcanzado el máximo permitido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

private: System::Void Delete_Node_Click(System::Object^ sender, System::EventArgs^ e) {
	if (miGrafo == nullptr) {
		MessageBox::Show("Primero debe generar un grafo.", "Aviso");
		return;
	}
	if (miGrafo->getNumNodos() <= MIN_NODOS) {
		MessageBox::Show("La cantidad de nodos es insuficiente.", "Aviso",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (listaNodosTemporal != nullptr) {
		CancelarComboBox();
		return;
	}
	listaNodosTemporal = gcnew ComboBox();
	listaNodosTemporal->DropDownStyle = ComboBoxStyle::DropDownList;
	listaNodosTemporal->Location = Delete_Node->Location;
	listaNodosTemporal->Size = Delete_Node->Size;
	for (int i = 1; i <= miGrafo->getNumNodos(); i++) {
		listaNodosTemporal->Items->Add(i.ToString());
	}
	listaNodosTemporal->SelectedIndex = -1;
	Delete_Node->Visible = false;
	Buttons->Controls->Add(listaNodosTemporal);
	listaNodosTemporal->BringToFront();
	listaNodosTemporal->SelectionChangeCommitted +=
		gcnew System::EventHandler(this, &MainPanel::EliminarNodoSeleccionado);
	listaNodosTemporal->DroppedDown = true;

	listaNodosTemporal->SelectionChangeCommitted +=
		gcnew System::EventHandler(this, &MainPanel::EliminarNodoSeleccionado);
	listaNodosTemporal->DropDownClosed +=
		gcnew System::EventHandler(this, &MainPanel::ComboCerrado);   // <-- NUEVO
	listaNodosTemporal->DroppedDown = true;
}
private: System::Void ComboCerrado(System::Object^ sender, System::EventArgs^ e) {
	this->BeginInvoke(gcnew MethodInvoker(this, &MainPanel::CancelarComboBox));
}


private: System::Void EliminarNodoSeleccionado(System::Object^ sender, System::EventArgs^ e) {
	if (listaNodosTemporal == nullptr ||
		listaNodosTemporal->SelectedItem == nullptr) {
		return;
	}
	int nodo = Convert::ToInt32(listaNodosTemporal->SelectedItem);
	CancelarComboBox();
	miGrafo->eliminarNodo(nodo - 1);
	ReiniciarSimulacion();
	PintarPanel();
}
private: void CancelarComboBox() {
	if (listaNodosTemporal == nullptr) return;
	listaNodosTemporal->SelectionChangeCommitted -=
		gcnew System::EventHandler(this, &MainPanel::EliminarNodoSeleccionado);
	listaNodosTemporal->DropDownClosed -=
		gcnew System::EventHandler(this, &MainPanel::ComboCerrado);  
	Buttons->Controls->Remove(listaNodosTemporal);
	delete listaNodosTemporal;
	listaNodosTemporal = nullptr;
	Delete_Node->Text = L"Eliminar_Nodo";
	Delete_Node->Visible = true;
	Delete_Node->BringToFront();
}
private: void MostrarInputNodos(Button^ boton, bool automatico) {
	if (inputNodosTemporal != nullptr) CancelarInputNodos();

	modoAutomatico = automatico;
	botonOriginal = boton;

	lblLimitesTemporal = gcnew Label();
	lblLimitesTemporal->Text = String::Format(L"Nodos ({0}-{1}):", MIN_NODOS, MAX_NODOS);
	lblLimitesTemporal->ForeColor = Color::White;
	lblLimitesTemporal->BackColor = Color::Transparent;
	lblLimitesTemporal->Font = gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, FontStyle::Bold);
	lblLimitesTemporal->AutoSize = false;
	lblLimitesTemporal->TextAlign = ContentAlignment::MiddleCenter;
	lblLimitesTemporal->Size = System::Drawing::Size(boton->Width, 16);
	lblLimitesTemporal->Location = System::Drawing::Point(boton->Left, boton->Top - 17);

	inputNodosTemporal = gcnew NumericUpDown();
	inputNodosTemporal->Minimum = Decimal(MIN_NODOS);
	inputNodosTemporal->Maximum = Decimal(MAX_NODOS);
	inputNodosTemporal->Value = Decimal(MIN_NODOS);
	inputNodosTemporal->TextAlign = HorizontalAlignment::Center;
	inputNodosTemporal->Font = gcnew System::Drawing::Font(L"Comic Sans MS", 11.0F, FontStyle::Bold);
	inputNodosTemporal->Location = boton->Location;
	inputNodosTemporal->Width = boton->Width;

	boton->Visible = false;
	panel1->Controls->Add(lblLimitesTemporal);
	panel1->Controls->Add(inputNodosTemporal);
	lblLimitesTemporal->BringToFront();
	inputNodosTemporal->BringToFront();

	inputNodosTemporal->KeyDown +=
		gcnew System::Windows::Forms::KeyEventHandler(this, &MainPanel::InputNodos_KeyDown);
	inputNodosTemporal->Leave +=
		gcnew System::EventHandler(this, &MainPanel::InputNodos_Leave);

	inputNodosTemporal->Focus();
	inputNodosTemporal->Select(0, inputNodosTemporal->Text->Length);
}

private: System::Void InputNodos_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		e->SuppressKeyPress = true;
		ConfirmarInputNodos();
	}
	else if (e->KeyCode == Keys::Escape) {
		e->SuppressKeyPress = true;
		CancelarInputNodos();
	}
}

private: System::Void InputNodos_Leave(System::Object^ sender, System::EventArgs^ e) {
	this->BeginInvoke(gcnew MethodInvoker(this, &MainPanel::CancelarSiPerdioFoco));
}

private: void CancelarSiPerdioFoco() {
	if (inputNodosTemporal != nullptr && !inputNodosTemporal->Focused) {
		CancelarInputNodos();
	}
}

private: void ConfirmarInputNodos() {
	if (inputNodosTemporal == nullptr) return;

	int n;
	if (!Int32::TryParse(inputNodosTemporal->Text, n)) {
		n = Decimal::ToInt32(inputNodosTemporal->Value);
	}
	if (n < MIN_NODOS) n = MIN_NODOS;
	if (n > MAX_NODOS) n = MAX_NODOS;

	bool automatico = modoAutomatico;
	CancelarInputNodos();

	NuevoGrafo(n);
	if (automatico) {
		miGrafo->generarMatrizAleatoria();
	}
	ReiniciarSimulacion();
}

private: void CancelarInputNodos() {
	if (inputNodosTemporal == nullptr) return;

	inputNodosTemporal->KeyDown -=
		gcnew System::Windows::Forms::KeyEventHandler(this, &MainPanel::InputNodos_KeyDown);
	inputNodosTemporal->Leave -=
		gcnew System::EventHandler(this, &MainPanel::InputNodos_Leave);

	panel1->Controls->Remove(inputNodosTemporal);
	panel1->Controls->Remove(lblLimitesTemporal);
	delete inputNodosTemporal;
	delete lblLimitesTemporal;
	inputNodosTemporal = nullptr;
	lblLimitesTemporal = nullptr;

	if (botonOriginal != nullptr) {
		botonOriginal->Visible = true;
		botonOriginal = nullptr;
	}
}
private: System::Void MainPanel_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void NodoAEliminar_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}