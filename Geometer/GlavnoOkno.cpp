#include "GlavnoOkno.h"
#include "Nastavitve.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	Nastavitve::BeriDat("Geometer.ini");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Geometer::GlavnoOkno glokno;
	Application::Run(% glokno);
	if (Nastavitve::Shrani)
		Nastavitve::ShraniDat("Geometer.ini");
}