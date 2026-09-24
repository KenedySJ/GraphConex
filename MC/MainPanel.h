#pragma once

namespace MC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MainPanel
	/// </summary>
	public ref class MainPanel : public System::Windows::Forms::Form
	{
	private:
	int page = 0;

	public:
		MainPanel(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MainPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ Buttons;
	private: System::Windows::Forms::Button^ Final;
	protected:

	private: System::Windows::Forms::Button^ Next;
	private: System::Windows::Forms::Button^ Start_Pause;
	private: System::Windows::Forms::Button^ Previous;
	private: System::Windows::Forms::Button^ Beginning;
	private: System::Windows::Forms::Panel^ Graph_Panel;

	private: System::Windows::Forms::GroupBox^ Inputs_Panel;
	private: System::Windows::Forms::TextBox^ NumberofNodes_TextBox;
	private: System::Windows::Forms::Label^ NumberofNodes_Label;
	private: System::Windows::Forms::Label^ GrafoGenerator_Label;
	private: System::Windows::Forms::Button^ GraphGeneratorManual_Botton;
	private: System::Windows::Forms::Button^ GraphGeneratorAutomatic_Button_;
	private: System::Windows::Forms::Label^ Testing_Label;
	private: System::Windows::Forms::Timer^ Page_Timer;

	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
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
			// 
			// Buttons
			// 
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
			// 
			// Final
			// 
			this->Final->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Final->Location = System::Drawing::Point(333, 41);
			this->Final->Name = L"Final";
			this->Final->Size = System::Drawing::Size(54, 23);
			this->Final->TabIndex = 4;
			this->Final->Text = L"⏭";
			this->Final->UseVisualStyleBackColor = true;
			this->Final->Click += gcnew System::EventHandler(this, &MainPanel::button5_Click);
			// 
			// Next
			// 
			this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Next->Location = System::Drawing::Point(253, 42);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(54, 23);
			this->Next->TabIndex = 3;
			this->Next->Text = L"⏩";
			this->Next->UseVisualStyleBackColor = true;
			this->Next->Click += gcnew System::EventHandler(this, &MainPanel::Next_Click);
			// 
			// Start_Pause
			// 
			this->Start_Pause->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Start_Pause->Location = System::Drawing::Point(178, 41);
			this->Start_Pause->Name = L"Start_Pause";
			this->Start_Pause->Size = System::Drawing::Size(54, 25);
			this->Start_Pause->TabIndex = 2;
			this->Start_Pause->Text = L"⏵";
			this->Start_Pause->UseVisualStyleBackColor = true;
			this->Start_Pause->Click += gcnew System::EventHandler(this, &MainPanel::Start_Pause_Click);
			// 
			// Previous
			// 
			this->Previous->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Previous->Location = System::Drawing::Point(106, 43);
			this->Previous->Name = L"Previous";
			this->Previous->Size = System::Drawing::Size(54, 23);
			this->Previous->TabIndex = 1;
			this->Previous->Text = L"⏪";
			this->Previous->UseVisualStyleBackColor = true;
			this->Previous->Enabled = false;
			this->Previous->Click += gcnew System::EventHandler(this, &MainPanel::Previous_Click);
			// 
			// Beginning
			// 
			this->Beginning->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Beginning->Location = System::Drawing::Point(28, 43);
			this->Beginning->Name = L"Beginning";
			this->Beginning->Size = System::Drawing::Size(54, 23);
			this->Beginning->TabIndex = 0;
			this->Beginning->Text = L"⏮";
			this->Beginning->UseVisualStyleBackColor = true;
			this->Beginning->Click += gcnew System::EventHandler(this, &MainPanel::Beginning_Click);
			// 
			// Graph_Panel
			// 
			this->Graph_Panel->Controls->Add(this->Testing_Label);
			this->Graph_Panel->Location = System::Drawing::Point(212, 65);
			this->Graph_Panel->Name = L"Graph_Panel";
			this->Graph_Panel->Size = System::Drawing::Size(415, 277);
			this->Graph_Panel->TabIndex = 1;
			// 
			// Testing_Label
			// 
			this->Testing_Label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Testing_Label->Location = System::Drawing::Point(176, 109);
			this->Testing_Label->Name = L"Testing_Label";
			this->Testing_Label->Size = System::Drawing::Size(56, 52);
			this->Testing_Label->TabIndex = 0;
			this->Testing_Label->Text = L"0";
			this->Testing_Label->Click += gcnew System::EventHandler(this, &MainPanel::Testing_Label_Click);
			// 
			// Inputs_Panel
			// 
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
			this->Inputs_Panel->Enter += gcnew System::EventHandler(this, &MainPanel::Inputs_Panel_Enter);
			// 
			// GraphGeneratorManual_Botton
			// 
			this->GraphGeneratorManual_Botton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GraphGeneratorManual_Botton->Location = System::Drawing::Point(17, 295);
			this->GraphGeneratorManual_Botton->Name = L"GraphGeneratorManual_Botton";
			this->GraphGeneratorManual_Botton->Size = System::Drawing::Size(97, 27);
			this->GraphGeneratorManual_Botton->TabIndex = 4;
			this->GraphGeneratorManual_Botton->Text = L"Manual";
			this->GraphGeneratorManual_Botton->UseVisualStyleBackColor = true;
			// 
			// GraphGeneratorAutomatic_Button_
			// 
			this->GraphGeneratorAutomatic_Button_->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GraphGeneratorAutomatic_Button_->Location = System::Drawing::Point(17, 342);
			this->GraphGeneratorAutomatic_Button_->Name = L"GraphGeneratorAutomatic_Button_";
			this->GraphGeneratorAutomatic_Button_->Size = System::Drawing::Size(97, 27);
			this->GraphGeneratorAutomatic_Button_->TabIndex = 3;
			this->GraphGeneratorAutomatic_Button_->Text = L"Automatica";
			this->GraphGeneratorAutomatic_Button_->UseVisualStyleBackColor = true;
			// 
			// GrafoGenerator_Label
			// 
			this->GrafoGenerator_Label->Location = System::Drawing::Point(17, 252);
			this->GrafoGenerator_Label->Name = L"GrafoGenerator_Label";
			this->GrafoGenerator_Label->Size = System::Drawing::Size(100, 25);
			this->GrafoGenerator_Label->TabIndex = 2;
			this->GrafoGenerator_Label->Text = L"Generar Grafo:";
			// 
			// NumberofNodes_TextBox
			// 
			this->NumberofNodes_TextBox->Location = System::Drawing::Point(17, 67);
			this->NumberofNodes_TextBox->Name = L"NumberofNodes_TextBox";
			this->NumberofNodes_TextBox->Size = System::Drawing::Size(100, 20);
			this->NumberofNodes_TextBox->TabIndex = 1;
			// 
			// NumberofNodes_Label
			// 
			this->NumberofNodes_Label->Location = System::Drawing::Point(17, 39);
			this->NumberofNodes_Label->Name = L"NumberofNodes_Label";
			this->NumberofNodes_Label->Size = System::Drawing::Size(100, 37);
			this->NumberofNodes_Label->TabIndex = 0;
			this->NumberofNodes_Label->Text = L"Cantidad de Nodos:";
			// 
			// Page_Timer
			// 
			this->Page_Timer->Tick += gcnew System::EventHandler(this, &MainPanel::timer1_Tick);
			// 
			// MainPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 519);
			this->Controls->Add(this->Inputs_Panel);
			this->Controls->Add(this->Graph_Panel);
			this->Controls->Add(this->Buttons);
			this->Name = L"MainPanel";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainPanel";
			this->Buttons->ResumeLayout(false);
			this->Graph_Panel->ResumeLayout(false);
			this->Inputs_Panel->ResumeLayout(false);
			this->Inputs_Panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Start_Pause_Click(System::Object^ sender, System::EventArgs^ e) {

	if (Page_Timer->Enabled == false) {
		Page_Timer->Start();
		this->Start_Pause->Text = L"\u23F8";
	}
	else {
		Page_Timer->Stop();
		this->Start_Pause->Text = L"\u23F5";
	}
	if (page == 0) {
		this->Previous->Enabled = false;
	}
	if (page > 0) {
		this->Previous->Enabled = true;
	}
}
private: System::Void Inputs_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e) {
	page++;
	this->Testing_Label->Text = System::Convert::ToString(page);

	this->Graph_Panel->Focus();
	if (page == 0) {
		this->Previous->Enabled = false;
	}
	if (page > 0) {
		this->Previous->Enabled = true;
	}
}
private: System::Void Testing_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Previous_Click(System::Object^ sender, System::EventArgs^ e) {
	page--;
	this->Testing_Label->Text = System::Convert::ToString(page);
	this->Graph_Panel->Focus();
	if (page == 0) {
		this->Previous->Enabled = false;
	}
	if (page > 0) {
		this->Previous->Enabled = true;
	}
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (page>=0 && page < 10) {
		page++;
		this->Testing_Label->Text = System::Convert::ToString(page);
	}
	else {
		// Hola Munde
		// Los quiero mucho
		// Los amo padres, los amoooo
		Page_Timer->Stop();
		this->Start_Pause->Text = L"\u23F5";
	}
}
private: System::Void Beginning_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
