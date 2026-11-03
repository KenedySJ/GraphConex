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

	private: System::Windows::Forms::Button^ Add_Node;
	private: System::Windows::Forms::TextBox^ NodoAEliminar;
	private: System::Windows::Forms::PictureBox^ pb2_4a12;
	private: System::Windows::Forms::PictureBox^ pb1_generarGrafo;
	private: System::Windows::Forms::Button^ GraphGeneratorAutomatic_Button_;
	private: System::Windows::Forms::Button^ GraphGeneratorCSV_Button;
	private: System::Windows::Forms::TextBox^ NumberofNodes_TextBox;
	private: System::Windows::Forms::Button^ GraphGeneratorManual_Botton;
	private: System::Windows::Forms::Panel^ panel1;















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
			   this->NodoAEliminar = (gcnew System::Windows::Forms::TextBox());
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
			   this->NumberofNodes_TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->GraphGeneratorAutomatic_Button_ = (gcnew System::Windows::Forms::Button());
			   this->GraphGeneratorManual_Botton = (gcnew System::Windows::Forms::Button());
			   this->GraphGeneratorCSV_Button = (gcnew System::Windows::Forms::Button());
			   this->pb1_generarGrafo = (gcnew System::Windows::Forms::PictureBox());
			   this->pb2_4a12 = (gcnew System::Windows::Forms::PictureBox());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->Buttons->SuspendLayout();
			   this->Graph_Panel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1Logo))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1_generarGrafo))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2_4a12))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // Buttons
			   // 
			   this->Buttons->Controls->Add(this->NodoAEliminar);
			   this->Buttons->Controls->Add(this->Delete_Node);
			   this->Buttons->Controls->Add(this->Add_Node);
			   this->Buttons->Controls->Add(this->Final);
			   this->Buttons->Controls->Add(this->Next);
			   this->Buttons->Controls->Add(this->Start_Pause);
			   this->Buttons->Controls->Add(this->Previous);
			   this->Buttons->Controls->Add(this->Beginning);
			   this->Buttons->Location = System::Drawing::Point(320, 712);
			   this->Buttons->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Buttons->Name = L"Buttons";
			   this->Buttons->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Buttons->Size = System::Drawing::Size(836, 263);
			   this->Buttons->TabIndex = 0;
			   this->Buttons->TabStop = false;
			   // 
			   // NodoAEliminar
			   // 
			   this->NodoAEliminar->Location = System::Drawing::Point(570, 181);
			   this->NodoAEliminar->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->NodoAEliminar->Name = L"NodoAEliminar";
			   this->NodoAEliminar->Size = System::Drawing::Size(228, 31);
			   this->NodoAEliminar->TabIndex = 7;
			   this->NodoAEliminar->Text = L"Elija el nodo eliminar";
			   // 
			   // Delete_Node
			   // 
			   this->Delete_Node->Location = System::Drawing::Point(356, 169);
			   this->Delete_Node->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Delete_Node->Name = L"Delete_Node";
			   this->Delete_Node->Size = System::Drawing::Size(184, 60);
			   this->Delete_Node->TabIndex = 6;
			   this->Delete_Node->Text = L"Eliminar_Nodo";
			   this->Delete_Node->UseVisualStyleBackColor = true;
			   this->Delete_Node->Click += gcnew System::EventHandler(this, &MainPanel::Delete_Node_Click);
			   // 
			   // Add_Node
			   // 
			   this->Add_Node->Location = System::Drawing::Point(56, 169);
			   this->Add_Node->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Add_Node->Name = L"Add_Node";
			   this->Add_Node->Size = System::Drawing::Size(182, 60);
			   this->Add_Node->TabIndex = 5;
			   this->Add_Node->Text = L"Agregar nodo";
			   this->Add_Node->UseVisualStyleBackColor = true;
			   this->Add_Node->Click += gcnew System::EventHandler(this, &MainPanel::Add_Node_Click);
			   // 
			   // Final
			   // 
			   this->Final->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Final->Location = System::Drawing::Point(666, 79);
			   this->Final->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Final->Name = L"Final";
			   this->Final->Size = System::Drawing::Size(108, 44);
			   this->Final->TabIndex = 4;
			   this->Final->Text = L"⏭";
			   this->Final->UseVisualStyleBackColor = true;
			   this->Final->Click += gcnew System::EventHandler(this, &MainPanel::Final_Click);
			   // 
			   // Next
			   // 
			   this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Next->Location = System::Drawing::Point(506, 81);
			   this->Next->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Next->Name = L"Next";
			   this->Next->Size = System::Drawing::Size(108, 44);
			   this->Next->TabIndex = 3;
			   this->Next->Text = L"⏩";
			   this->Next->UseVisualStyleBackColor = true;
			   this->Next->Click += gcnew System::EventHandler(this, &MainPanel::Next_Click);
			   // 
			   // Start_Pause
			   // 
			   this->Start_Pause->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Start_Pause->Location = System::Drawing::Point(356, 79);
			   this->Start_Pause->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Start_Pause->Name = L"Start_Pause";
			   this->Start_Pause->Size = System::Drawing::Size(108, 48);
			   this->Start_Pause->TabIndex = 2;
			   this->Start_Pause->Text = L"⏵";
			   this->Start_Pause->UseVisualStyleBackColor = true;
			   this->Start_Pause->Click += gcnew System::EventHandler(this, &MainPanel::Start_Pause_Click);
			   // 
			   // Previous
			   // 
			   this->Previous->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Previous->Enabled = false;
			   this->Previous->Location = System::Drawing::Point(212, 83);
			   this->Previous->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Previous->Name = L"Previous";
			   this->Previous->Size = System::Drawing::Size(108, 44);
			   this->Previous->TabIndex = 1;
			   this->Previous->Text = L"⏪";
			   this->Previous->UseVisualStyleBackColor = true;
			   this->Previous->Click += gcnew System::EventHandler(this, &MainPanel::Previous_Click);
			   // 
			   // Beginning
			   // 
			   this->Beginning->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Beginning->Location = System::Drawing::Point(56, 83);
			   this->Beginning->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Beginning->Name = L"Beginning";
			   this->Beginning->Size = System::Drawing::Size(108, 44);
			   this->Beginning->TabIndex = 0;
			   this->Beginning->Text = L"⏮";
			   this->Beginning->UseVisualStyleBackColor = true;
			   this->Beginning->Click += gcnew System::EventHandler(this, &MainPanel::Beginning_Click);
			   // 
			   // Graph_Panel
			   // 
			   this->Graph_Panel->BackColor = System::Drawing::Color::White;
			   this->Graph_Panel->Controls->Add(this->Testing_Label);
			   this->Graph_Panel->Location = System::Drawing::Point(320, 65);
			   this->Graph_Panel->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Graph_Panel->Name = L"Graph_Panel";
			   this->Graph_Panel->Size = System::Drawing::Size(883, 610);
			   this->Graph_Panel->TabIndex = 1;
			   this->Graph_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Graph_Panel_Paint);
			   // 
			   // Testing_Label
			   // 
			   this->Testing_Label->AutoSize = true;
			   this->Testing_Label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Testing_Label->Location = System::Drawing::Point(20, 19);
			   this->Testing_Label->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->Testing_Label->Name = L"Testing_Label";
			   this->Testing_Label->Size = System::Drawing::Size(96, 31);
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
			   this->pb1Logo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pb1Logo->Name = L"pb1Logo";
			   this->pb1Logo->Size = System::Drawing::Size(305, 144);
			   this->pb1Logo->TabIndex = 3;
			   this->pb1Logo->TabStop = false;
			   // 
			   // Matrix_Panel
			   // 
			   this->Matrix_Panel->BackColor = System::Drawing::Color::White;
			   this->Matrix_Panel->Location = System::Drawing::Point(1226, 65);
			   this->Matrix_Panel->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Matrix_Panel->Name = L"Matrix_Panel";
			   this->Matrix_Panel->Size = System::Drawing::Size(563, 610);
			   this->Matrix_Panel->TabIndex = 4;
			   this->Matrix_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainPanel::Matrix_Panel_Paint);
			   this->Matrix_Panel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPanel::Matrix_Panel_MouseClick);
			   // 
			   // Description_Label
			   // 
			   this->Description_Label->Location = System::Drawing::Point(1221, 712);
			   this->Description_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Description_Label->Name = L"Description_Label";
			   this->Description_Label->Size = System::Drawing::Size(538, 203);
			   this->Description_Label->TabIndex = 5;
			   // 
			   // CSV_Dialog
			   // 
			   this->CSV_Dialog->Filter = L"Archivos CSV (*.csv)|*.csv";
			   this->CSV_Dialog->Title = L"Cargar grafo desde CSV";
			   // 
			   // NumberofNodes_TextBox
			   // 
			   this->NumberofNodes_TextBox->Location = System::Drawing::Point(30, 130);
			   this->NumberofNodes_TextBox->Margin = System::Windows::Forms::Padding(6);
			   this->NumberofNodes_TextBox->Name = L"NumberofNodes_TextBox";
			   this->NumberofNodes_TextBox->Size = System::Drawing::Size(204, 31);
			   this->NumberofNodes_TextBox->TabIndex = 1;
			   // 
			   // GraphGeneratorAutomatic_Button_
			   // 
			   this->GraphGeneratorAutomatic_Button_->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GraphGeneratorAutomatic_Button_.BackgroundImage")));
			   this->GraphGeneratorAutomatic_Button_->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->GraphGeneratorAutomatic_Button_->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->GraphGeneratorAutomatic_Button_->FlatAppearance->BorderSize = 0;
			   this->GraphGeneratorAutomatic_Button_->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->GraphGeneratorAutomatic_Button_->Location = System::Drawing::Point(29, 299);
			   this->GraphGeneratorAutomatic_Button_->Margin = System::Windows::Forms::Padding(6);
			   this->GraphGeneratorAutomatic_Button_->Name = L"GraphGeneratorAutomatic_Button_";
			   this->GraphGeneratorAutomatic_Button_->Size = System::Drawing::Size(187, 65);
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
			   this->GraphGeneratorManual_Botton->Location = System::Drawing::Point(29, 376);
			   this->GraphGeneratorManual_Botton->Margin = System::Windows::Forms::Padding(6);
			   this->GraphGeneratorManual_Botton->Name = L"GraphGeneratorManual_Botton";
			   this->GraphGeneratorManual_Botton->Size = System::Drawing::Size(187, 65);
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
			   this->GraphGeneratorCSV_Button->Location = System::Drawing::Point(29, 453);
			   this->GraphGeneratorCSV_Button->Margin = System::Windows::Forms::Padding(6);
			   this->GraphGeneratorCSV_Button->Name = L"GraphGeneratorCSV_Button";
			   this->GraphGeneratorCSV_Button->Size = System::Drawing::Size(187, 59);
			   this->GraphGeneratorCSV_Button->TabIndex = 5;
			   this->GraphGeneratorCSV_Button->UseVisualStyleBackColor = true;
			   this->GraphGeneratorCSV_Button->Click += gcnew System::EventHandler(this, &MainPanel::GraphGeneratorCSV_Button_Click);
			   // 
			   // pb1_generarGrafo
			   // 
			   this->pb1_generarGrafo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb1_generarGrafo.BackgroundImage")));
			   this->pb1_generarGrafo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pb1_generarGrafo->Location = System::Drawing::Point(28, 215);
			   this->pb1_generarGrafo->Name = L"pb1_generarGrafo";
			   this->pb1_generarGrafo->Size = System::Drawing::Size(193, 61);
			   this->pb1_generarGrafo->TabIndex = 6;
			   this->pb1_generarGrafo->TabStop = false;
			   // 
			   // pb2_4a12
			   // 
			   this->pb2_4a12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb2_4a12.BackgroundImage")));
			   this->pb2_4a12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pb2_4a12->Location = System::Drawing::Point(30, 52);
			   this->pb2_4a12->Name = L"pb2_4a12";
			   this->pb2_4a12->Size = System::Drawing::Size(204, 69);
			   this->pb2_4a12->TabIndex = 7;
			   this->pb2_4a12->TabStop = false;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			   this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panel1->Controls->Add(this->pb2_4a12);
			   this->panel1->Controls->Add(this->pb1_generarGrafo);
			   this->panel1->Controls->Add(this->NumberofNodes_TextBox);
			   this->panel1->Controls->Add(this->GraphGeneratorAutomatic_Button_);
			   this->panel1->Controls->Add(this->GraphGeneratorCSV_Button);
			   this->panel1->Controls->Add(this->GraphGeneratorManual_Botton);
			   this->panel1->Location = System::Drawing::Point(0, 143);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(275, 710);
			   this->panel1->TabIndex = 6;
			   // 
			   // MainPanel
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::LightGray;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1850, 998);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->Description_Label);
			   this->Controls->Add(this->Matrix_Panel);
			   this->Controls->Add(this->pb1Logo);
			   this->Controls->Add(this->Graph_Panel);
			   this->Controls->Add(this->Buttons);
			   this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Name = L"MainPanel";
			   this->Padding = System::Windows::Forms::Padding(6);
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L" ";
			   this->Load += gcnew System::EventHandler(this, &MainPanel::MainPanel_Load);
			   this->Buttons->ResumeLayout(false);
			   this->Buttons->PerformLayout();
			   this->Graph_Panel->ResumeLayout(false);
			   this->Graph_Panel->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1Logo))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1_generarGrafo))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2_4a12))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
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
		if (miGrafo != nullptr && miGrafo->getNumNodos() > MIN_NODOS) {
			int nodo;
			if (Int32::TryParse(NodoAEliminar->Text, nodo) && nodo > 0 && nodo <= miGrafo->getNumNodos()) {
				nodo--; // El usuario escribe 1..n; internamente el índice es 0..n-1

				miGrafo->eliminarNodo(nodo);
				// Aquí reinicia los pasos a 0 y redibuja, igual que en tu botón Agregar
				ReiniciarSimulacion();
				PintarPanel();
			}
			else {
				MessageBox::Show("Por favor, ingrese un número entero válido para el nodo a eliminar.", "Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		else {
			MessageBox::Show("La cantidad de nodos es insuficiente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}
private: System::Void MainPanel_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}