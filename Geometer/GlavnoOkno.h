#pragma once

#include "Nastavitve.h"
#include "NastavitveOkno.h"
#include <msclr\marshal_cppstd.h>
#include <sys/stat.h>
#include <string>

namespace Geometer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GlavnoOkno
	/// </summary>
	public ref class GlavnoOkno : public System::Windows::Forms::Form
	{
	public:
		GlavnoOkno(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			textBox1->Text = msclr::interop::marshal_as<System::String^>(Nastavitve::Dir::VhodnaDat);
			std::string niz = Nastavitve::Dir::IzhodnaDat;
			if (niz.find("\\") == std::string::npos) {
				textBox3->Text = "";
				textBox4->Text = msclr::interop::marshal_as<System::String^>(niz);
			}
			else {
				int i = (int)niz.find_last_of("\\");
				textBox3->Text = msclr::interop::marshal_as<System::String^>(niz.substr(0, i));
				textBox4->Text = msclr::interop::marshal_as<System::String^>(niz.substr(i + 1));
			}
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GlavnoOkno()
		{
			Nastavitve::Dir::VhodnaDat = msclr::interop::marshal_as<std::string>(textBox1->Text);
			if (textBox3->Text == "")
				Nastavitve::Dir::IzhodnaDat = msclr::interop::marshal_as<std::string>(textBox4->Text);
			else
				Nastavitve::Dir::IzhodnaDat = msclr::interop::marshal_as<std::string>(textBox3->Text + "\\" + textBox4->Text);
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	protected:

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog2 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Text Files|*.txt|All Files|*.*";
			this->openFileDialog1->Title = L"Select Input File";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(309, 119);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Input File";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(204, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GlavnoOkno::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(294, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"File Name:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(12, 146);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(309, 155);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Output File";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(9, 105);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(294, 20);
			this->textBox4->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"File Name:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(204, 66);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Browse";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GlavnoOkno::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(9, 40);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(294, 20);
			this->textBox3->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Directory:";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(12, 307);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(99, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Settings";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GlavnoOkno::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(117, 307);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(99, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Begin";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GlavnoOkno::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(222, 307);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(99, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Exit";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &GlavnoOkno::button6_Click);
			// 
			// GlavnoOkno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(335, 341);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GlavnoOkno";
			this->Text = L"Geometer";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		textBox1->Text = openFileDialog1->FileName;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (folderBrowserDialog2->ShowDialog() == Windows::Forms::DialogResult::OK)
		textBox3->Text = folderBrowserDialog2->SelectedPath;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Nastavitve::Dir::VhodnaDat = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (textBox3->Text == "")
		Nastavitve::Dir::IzhodnaDat = msclr::interop::marshal_as<std::string>(textBox4->Text);
	else
		Nastavitve::Dir::IzhodnaDat = msclr::interop::marshal_as<std::string>(textBox3->Text + "\\" + textBox4->Text);
	struct stat podatki;
	if (stat(Nastavitve::Dir::IzhodnaDat.c_str(), &podatki) == 0) {
		if (MessageBox::Show(
			"The output file already exists. Overwrite?",
			"Geometer",
			MessageBoxButtons::OKCancel,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Cancel)
			return;
	}
	int vrsticaNapake;
	std::string makroNapake;
	int kodaNapake = Pozeni(vrsticaNapake, makroNapake);
	System::String^ makroStr = msclr::interop::marshal_as<System::String^>(makroNapake);
	if (kodaNapake == 0)
		MessageBox::Show("Complete.", "Geometer", MessageBoxButtons::OK, MessageBoxIcon::Information);
	else if (kodaNapake == 3000)
		MessageBox::Show(
			"Could not write the output file.",
			"Geometer",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else if (kodaNapake == 2000)
		MessageBox::Show(
			"Illegal input file name. The file extension must be txt.",
			"Geometer",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	else if (kodaNapake >= 1000) {
		std::vector<std::string> odgovori = {
			"Divison by zero",
			"Negative power base",
			"Negative argument of logarithm",
			"Argument of function arcsin out of range [-1, 1]",
			"Argument of function arccos out of range [-1, 1]",
			"Color parameter of triangle out of range [0, 1]" };
		MessageBox::Show("Execution error no. " +
			kodaNapake.ToString() + ": " + msclr::interop::marshal_as<System::String^>(odgovori.at(kodaNapake - 1001)) +
			".\nFile name: " + msclr::interop::marshal_as<System::String^>(makroNapake),
			"Geometer",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
	
	else {
		std::vector<std::string> odgovori = {
			"List of arguments not in the first line of the file",
			"Missing arguments",
			"Illegal argument name",
			"Repeated argument",
			"Illegal label name",
			"Repeated label",
			"Label missing",
			"Illegal expression in if statement",
			"Command expected after if statement",
			"Illegal variable name",
			"Illegal expression",
			"Unbalanced parentheses",
			"Triangle command not having correct number of arguments",
			"Illegal expression in triangle command",
			"Unbalanced parentheses",
			"Illegal macro name",
			"Illegal arguments in macro command",
			"Incorrect number of arguments",
			"Missing input file",
			"Missing macro",
			"Input file must not have arguments" };
		std::string sporocilo;
		if (kodaNapake < 10) sporocilo = odgovori.at(kodaNapake - 1);
		else if (kodaNapake < 20) sporocilo = odgovori.at(kodaNapake - 7);
		else if (kodaNapake < 30) sporocilo = odgovori.at(kodaNapake - 14);
		else if (kodaNapake < 40) sporocilo = odgovori.at(kodaNapake - 22);
		else if (kodaNapake < 50) sporocilo = odgovori.at(kodaNapake - 30);
		else if (kodaNapake < 53) sporocilo = odgovori.at(kodaNapake - 37);
		else if (kodaNapake == 54) sporocilo = odgovori.at(16);
		else if (kodaNapake < 103) sporocilo = odgovori.at(kodaNapake - 83);
		else sporocilo = odgovori.at(20);
		if (kodaNapake == 101) makroStr = msclr::interop::marshal_as<System::String^>(Nastavitve::Dir::VhodnaDat);
		System::String^ obvestilo = "Parsing error no. " +
			kodaNapake.ToString() + ": " +
			msclr::interop::marshal_as<System::String^>(sporocilo) + ".\n" +
			"File: " + makroStr;
		vrsticaNapake++;
		if (kodaNapake != 101) obvestilo += "\nLine: " + vrsticaNapake.ToString();
		MessageBox::Show(obvestilo, "Geometer",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Geometer::NastavitveOkno nastOkno;
	nastOkno.ShowDialog();
}
};
}
