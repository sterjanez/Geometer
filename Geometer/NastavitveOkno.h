#pragma once
#include "Nastavitve.h"
#include <msclr\marshal_cppstd.h>

namespace Geometer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NastavitveOkno
	/// </summary>
	public ref class NastavitveOkno : public System::Windows::Forms::Form
	{
	public:
		NastavitveOkno(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			posX->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::X);
			posY->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::Y);
			posZ->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::Z);
			posTheta->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::Theta);
			posPhi->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::Phi);
			posPsi->Text = msclr::interop::marshal_as<String^>(Nastavitve::Kamera::Psi);
			orientBox->Checked = Nastavitve::Kamera::Orientiraj;
			lightTheta->Text = msclr::interop::marshal_as<String^>(Nastavitve::Svetloba::Theta);
			lightPhi->Text = msclr::interop::marshal_as<String^>(Nastavitve::Svetloba::Phi);
			macroBox->Text = msclr::interop::marshal_as<String^>(Nastavitve::Dir::MakroDir);
			widthBox->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::Sirina);
			heightBox->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::Visina);
			textBoxRatio->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::Razmerje);
			textBoxR->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::R);
			textBoxG->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::G);
			textBoxB->Text = msclr::interop::marshal_as<String^>(Nastavitve::BMP::B);
			checkBox1->Checked = Nastavitve::Shrani;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NastavitveOkno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ lightPhi;
	protected:

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ lightTheta;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ posPhi;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ posTheta;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ posZ;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ posY;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ posX;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ macroBox;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBoxB;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ textBoxG;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBoxR;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ heightBox;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ widthBox;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBoxRatio;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ OKknof;
	private: System::Windows::Forms::Button^ Cancelknof;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ orientBox;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ posPsi;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->orientBox = (gcnew System::Windows::Forms::CheckBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->posPsi = (gcnew System::Windows::Forms::TextBox());
			this->lightPhi = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lightTheta = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->posPhi = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->posTheta = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->posZ = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->posY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->posX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->macroBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxRatio = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBoxG = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->heightBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->widthBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->OKknof = (gcnew System::Windows::Forms::Button());
			this->Cancelknof = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->orientBox);
			this->groupBox1->Controls->Add(this->label20);
			this->groupBox1->Controls->Add(this->posPsi);
			this->groupBox1->Controls->Add(this->lightPhi);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->lightTheta);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->posPhi);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->posTheta);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->posZ);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->posY);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->posX);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(235, 337);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Camera and Light Settings";
			// 
			// orientBox
			// 
			this->orientBox->AutoSize = true;
			this->orientBox->Location = System::Drawing::Point(122, 228);
			this->orientBox->Name = L"orientBox";
			this->orientBox->Size = System::Drawing::Size(99, 17);
			this->orientBox->TabIndex = 14;
			this->orientBox->Text = L"Orient to (0,0,0)";
			this->orientBox->UseVisualStyleBackColor = true;
			this->orientBox->CheckedChanged += gcnew System::EventHandler(this, &NastavitveOkno::orientBox_CheckedChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(16, 204);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(30, 13);
			this->label20->TabIndex = 12;
			this->label20->Text = L"Psi =";
			// 
			// posPsi
			// 
			this->posPsi->Location = System::Drawing::Point(60, 201);
			this->posPsi->Name = L"posPsi";
			this->posPsi->Size = System::Drawing::Size(161, 20);
			this->posPsi->TabIndex = 13;
			// 
			// lightPhi
			// 
			this->lightPhi->Location = System::Drawing::Point(60, 302);
			this->lightPhi->Name = L"lightPhi";
			this->lightPhi->Size = System::Drawing::Size(161, 20);
			this->lightPhi->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(16, 305);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Phi =";
			// 
			// lightTheta
			// 
			this->lightTheta->Location = System::Drawing::Point(60, 276);
			this->lightTheta->Name = L"lightTheta";
			this->lightTheta->Size = System::Drawing::Size(161, 20);
			this->lightTheta->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(16, 279);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Theta =";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(16, 255);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(78, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Light Direction:";
			// 
			// posPhi
			// 
			this->posPhi->Location = System::Drawing::Point(60, 175);
			this->posPhi->Name = L"posPhi";
			this->posPhi->Size = System::Drawing::Size(161, 20);
			this->posPhi->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 178);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Phi =";
			// 
			// posTheta
			// 
			this->posTheta->Location = System::Drawing::Point(60, 149);
			this->posTheta->Name = L"posTheta";
			this->posTheta->Size = System::Drawing::Size(161, 20);
			this->posTheta->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Theta =";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Orientation:";
			// 
			// posZ
			// 
			this->posZ->Location = System::Drawing::Point(60, 96);
			this->posZ->Name = L"posZ";
			this->posZ->Size = System::Drawing::Size(161, 20);
			this->posZ->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Z =";
			// 
			// posY
			// 
			this->posY->Location = System::Drawing::Point(60, 70);
			this->posY->Name = L"posY";
			this->posY->Size = System::Drawing::Size(161, 20);
			this->posY->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y =";
			// 
			// posX
			// 
			this->posX->Location = System::Drawing::Point(60, 44);
			this->posX->Name = L"posX";
			this->posX->Size = System::Drawing::Size(161, 20);
			this->posX->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"X =";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Position:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->macroBox);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Location = System::Drawing::Point(261, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(235, 101);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Macro Directory";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(127, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NastavitveOkno::button1_Click);
			// 
			// macroBox
			// 
			this->macroBox->Location = System::Drawing::Point(20, 44);
			this->macroBox->Name = L"macroBox";
			this->macroBox->Size = System::Drawing::Size(201, 20);
			this->macroBox->TabIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(17, 25);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(52, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Directory:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBox1);
			this->groupBox3->Controls->Add(this->textBoxRatio);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->textBoxB);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->textBoxG);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->textBoxR);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->heightBox);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->widthBox);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Location = System::Drawing::Point(261, 119);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(235, 230);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"BMP";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(129, 198);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(92, 17);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->Text = L"Save Settings";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBoxRatio
			// 
			this->textBoxRatio->Location = System::Drawing::Point(108, 121);
			this->textBoxRatio->Name = L"textBoxRatio";
			this->textBoxRatio->Size = System::Drawing::Size(113, 20);
			this->textBoxRatio->TabIndex = 13;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(17, 124);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(90, 13);
			this->label19->TabIndex = 12;
			this->label19->Text = L"Pixel/Unit Ratio =";
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(170, 93);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(51, 20);
			this->textBoxB->TabIndex = 11;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(129, 96);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(31, 13);
			this->label18->TabIndex = 10;
			this->label18->Text = L"Blue:";
			// 
			// textBoxG
			// 
			this->textBoxG->Location = System::Drawing::Point(170, 67);
			this->textBoxG->Name = L"textBoxG";
			this->textBoxG->Size = System::Drawing::Size(51, 20);
			this->textBoxG->TabIndex = 9;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(129, 70);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(39, 13);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Green:";
			// 
			// textBoxR
			// 
			this->textBoxR->Location = System::Drawing::Point(170, 41);
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->Size = System::Drawing::Size(51, 20);
			this->textBoxR->TabIndex = 7;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(129, 44);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(30, 13);
			this->label16->TabIndex = 6;
			this->label16->Text = L"Red:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(124, 21);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(95, 13);
			this->label15->TabIndex = 5;
			this->label15->Text = L"Background Color:";
			// 
			// heightBox
			// 
			this->heightBox->Location = System::Drawing::Point(65, 67);
			this->heightBox->Name = L"heightBox";
			this->heightBox->Size = System::Drawing::Size(56, 20);
			this->heightBox->TabIndex = 4;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(17, 70);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(47, 13);
			this->label14->TabIndex = 3;
			this->label14->Text = L"Height =";
			// 
			// widthBox
			// 
			this->widthBox->Location = System::Drawing::Point(65, 41);
			this->widthBox->Name = L"widthBox";
			this->widthBox->Size = System::Drawing::Size(56, 20);
			this->widthBox->TabIndex = 2;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(17, 44);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(44, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Width =";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 21);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(65, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Size (pixels):";
			// 
			// OKknof
			// 
			this->OKknof->Location = System::Drawing::Point(278, 355);
			this->OKknof->Name = L"OKknof";
			this->OKknof->Size = System::Drawing::Size(106, 23);
			this->OKknof->TabIndex = 3;
			this->OKknof->Text = L"OK";
			this->OKknof->UseVisualStyleBackColor = true;
			this->OKknof->Click += gcnew System::EventHandler(this, &NastavitveOkno::OKknof_Click);
			// 
			// Cancelknof
			// 
			this->Cancelknof->Location = System::Drawing::Point(390, 355);
			this->Cancelknof->Name = L"Cancelknof";
			this->Cancelknof->Size = System::Drawing::Size(106, 23);
			this->Cancelknof->TabIndex = 4;
			this->Cancelknof->Text = L"Cancel";
			this->Cancelknof->UseVisualStyleBackColor = true;
			this->Cancelknof->Click += gcnew System::EventHandler(this, &NastavitveOkno::Cancelknof_Click);
			// 
			// NastavitveOkno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 391);
			this->Controls->Add(this->Cancelknof);
			this->Controls->Add(this->OKknof);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"NastavitveOkno";
			this->Text = L"Settings";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (folderBrowserDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			macroBox->Text = folderBrowserDialog1->SelectedPath;
	}
private: System::Void Cancelknof_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void OKknof_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string x, y, z, th, ph, ps, lth, lph, makro;
	std::string sir, vis, ratio, r, g, b;
	x = msclr::interop::marshal_as<std::string>(posX->Text);
	y = msclr::interop::marshal_as<std::string>(posY->Text);
	z = msclr::interop::marshal_as<std::string>(posZ->Text);
	th = msclr::interop::marshal_as<std::string>(posTheta->Text);
	ph = msclr::interop::marshal_as<std::string>(posPhi->Text);
	ps = msclr::interop::marshal_as<std::string>(posPsi->Text);
	lth = msclr::interop::marshal_as<std::string>(lightTheta->Text);
	lph = msclr::interop::marshal_as<std::string>(lightPhi->Text);
	makro = msclr::interop::marshal_as<std::string>(macroBox->Text);
	sir = msclr::interop::marshal_as<std::string>(widthBox->Text);
	vis = msclr::interop::marshal_as<std::string>(heightBox->Text);
	ratio = msclr::interop::marshal_as<std::string>(textBoxRatio->Text);
	r = msclr::interop::marshal_as<std::string>(textBoxR->Text);
	g = msclr::interop::marshal_as<std::string>(textBoxG->Text);
	b = msclr::interop::marshal_as<std::string>(textBoxB->Text);
	int koda = 0;
	if (!Nastavitve::VeljavnaKoordinata(x)) koda = 1;
	else if (!Nastavitve::VeljavnaKoordinata(y)) koda = 2;
	else if (!Nastavitve::VeljavnaKoordinata(z)) koda = 3;
	else if (!Nastavitve::VeljavenKot(th)) koda = 4;
	else if (!Nastavitve::VeljavenKot(ph)) koda = 5;
	else if (!Nastavitve::VeljavenKot(ps)) koda = 6;
	else if (!Nastavitve::VeljavenKot(lth)) koda = 7;
	else if (!Nastavitve::VeljavenKot(lph)) koda = 8;
	else if (!Nastavitve::VeljavnaDimBMP(sir)) koda = 9;
	else if (!Nastavitve::VeljavnaDimBMP(vis)) koda = 10;
	else if (!Nastavitve::VeljavenRatio(ratio)) koda = 11;
	else if (!Nastavitve::VeljavenRGB(r)) koda = 12;
	else if (!Nastavitve::VeljavenRGB(g)) koda = 13;
	else if (!Nastavitve::VeljavenRGB(b)) koda = 14;
	if (koda != 0) {
		std::string s = "Illegal input parameter: ";
		if (koda == 1) s += "X";
		else if (koda == 2) s += "Y";
		else if (koda == 3) s += "Z";
		else if (koda == 4) s += "Theta";
		else if (koda == 5) s += "Phi";
		else if (koda == 6) s += "Psi";
		else if (koda == 7) s += "Theta (light)";
		else if (koda == 8) s += "Phi (light)";
		else if (koda == 9) s += "BMP Width";
		else if (koda == 10) s += "BMP Height";
		else if (koda == 11) s += "Ratio";
		else if (koda == 12) s += "Red";
		else if (koda == 13) s += "Green";
		else if (koda == 14) s += "Blue";
		s += ". Input must be ";
		if (koda <= 3) {
			std::string kon = msclr::interop::marshal_as<std::string>(Nastavitve::Max_Koordinata.ToString());
			s += "a floating point number between -";
			s += kon + " and " + kon + ".";
		}
		else if (koda <= 8) {
			std::string kon = msclr::interop::marshal_as<std::string>(Nastavitve::Max_Kot.ToString());
			s += "a floating point number between -";
			s += kon + " and " + kon + ".";
		}
		else if (koda <= 10) {
			std::string kon = msclr::interop::marshal_as<std::string>(Nastavitve::Max_BMP_Dim.ToString());
			s += "a whole number between 0 and " + kon + ".";
		}
		else if (koda == 11) {
			std::string kon1 = msclr::interop::marshal_as<std::string>(Nastavitve::Min_Ratio.ToString());
			std::string kon2 = msclr::interop::marshal_as<std::string>(Nastavitve::Max_Ratio.ToString());
			s += "a floating point number between ";
			s += kon1 + " and " + kon2 + ".";
		}
		else
			s += "a floating point number between 0 and 1.";
		MessageBox::Show(msclr::interop::marshal_as<String^>(s), "Illegal input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	Nastavitve::Kamera::X = x;
	Nastavitve::Kamera::Y = y;
	Nastavitve::Kamera::Z = z;
	Nastavitve::Kamera::Theta = th;
	Nastavitve::Kamera::Phi = ph;
	Nastavitve::Kamera::Psi = ps;
	Nastavitve::Kamera::Orientiraj = orientBox->Checked;
	Nastavitve::Svetloba::Theta = lth;
	Nastavitve::Svetloba::Phi = lph;
	Nastavitve::Dir::MakroDir = msclr::interop::marshal_as<std::string>(macroBox->Text);
	Nastavitve::BMP::Sirina = sir;
	Nastavitve::BMP::Visina = vis;
	Nastavitve::BMP::Razmerje = ratio;
	Nastavitve::BMP::R = r;
	Nastavitve::BMP::G = g;
	Nastavitve::BMP::B = b;
	Nastavitve::Shrani = checkBox1->Checked;
	Close();
}
private: System::Void orientBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	posTheta->Enabled = !orientBox->Checked;
	posPhi->Enabled = !orientBox->Checked;
	posPsi->Enabled = !orientBox->Checked;
}
};
}



