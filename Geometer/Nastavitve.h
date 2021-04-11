// Ta header vsebuje konstante in metode za parametre nastavitev.
// Nastavitve najvec uporablja okno "Settings", uporablja pa
// jih tudi glavno okno (tako header kot cpp) in glavna enota.
// Nastavitve so v tej datoteki shranjene v obliki nizov,
// datoteka vsebuje se funkcije za preverjanje veljavnosti nizov
// in funkciji za shranjevanje in odpranje ini datoteke.
// Definicije vsega tega se nahajajo v datoteki GlavnaEnota.cpp.

#pragma once
#include <string>
#include <fstream>

namespace Nastavitve {

	// Direktoriji in datoteke
	namespace Dir {
		extern std::string VhodnaDat, IzhodnaDat, MakroDir;
	}

	// Polozaj kamere
	namespace Kamera {
		extern std::string X, Y, Z, Theta, Phi, Psi;
		extern bool Orientiraj;
	}

	// Vir svetlobe
	namespace Svetloba {
		extern std::string Theta, Phi;
	}

	// Podatki o bitni sliki
	namespace BMP {
		extern std::string Sirina, Visina, Razmerje, R, G, B;
	}

	// "Save settings" checkbox
	extern bool Shrani;

	// Konstante, ki definirajo preverjalne funkcije
	extern const double Max_Koordinata;
	extern const double Max_Kot;
	extern const int Max_BMP_Dim;
	extern const double Min_Ratio;
	extern const double Max_Ratio;

	bool VeljavnaKoordinata(std::string);
	bool VeljavenKot(std::string);
	bool VeljavenRGB(std::string);
	bool VeljavnaDimBMP(std::string);
	bool VeljavenRatio(std::string);
	bool ShraniDat(std::string);
	bool BeriDat(std::string);
}

// Funkcija, definirana v glavni enoti, ki izvede celotno proceduro.
int Pozeni(int&, std::string&);