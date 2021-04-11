// Ta datoteka vsebuje vse glavne komponente programa Geometer:
//
// Nastavitve: vse nastavitve v obliki nizov in funkcije za manipulacijo z njimi
// Parser: pretvorba txt datotek v izvrsljivo kodo
// Podatki: pretvorjene nastavitve, BMP tabela
// Grafika: funkcija za risanje trikotnika v 3D
// Eksekutor: funkcije za izvajanje izvrsljive kode (risanje trikotnikov v BMP tabelo)
// ShraniBMP: funkcija za shranjevanje BMP v datoteko
// Pozeni: izvede vse funkcije (od branja vhodne datoteke, parsanja, risanja do shranjevanja BMP)

#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "Nastavitve.h"

// Inicializirane so privzete nastavitve (ce "Save Settings" checkbox ni izbrano).
namespace Nastavitve {

	// Direktoriji in datoteke
	namespace Dir {
		std::string VhodnaDat = "";
		std::string IzhodnaDat = "";
		std::string MakroDir = "";
	}

	// Polozaj kamere
	namespace Kamera {
		std::string X = "-100", Y = "-100", Z = "50";
		std::string Theta = "0", Phi = "0", Psi = "0";
		bool Orientiraj = true;
	}

	// Vir svetlobe
	namespace Svetloba {
		std::string Theta = "0", Phi = "0";
	}

	// Podatki o bitni sliki
	namespace BMP {
		std::string Sirina = "1000", Visina = "600";
		std::string Razmerje = "100";
		std::string R = "0", G = "0", B = "0";
	}

	// "Save settings" checkbox
	bool Shrani = false;

	// Konstante, ki definirajo preverjalne funkcije
	const double Max_Koordinata = 10000;
	const double Max_Kot = 6.3;
	const int Max_BMP_Dim = 20000;
	const double Min_Ratio = 0.0000001;
	const double Max_Ratio = 10000000;

	bool VeljavenInt(std::string s) {
		if (s != "" && s[0] == '-') s = s.substr(1);
		if (s == "") return false;
		std::string cifre = "0123456789";
		for (std::size_t i = 0; i < s.length(); i++)
			if (cifre.find(s[i]) == std::string::npos) return false;
		return true;
	}

	bool VeljavenDouble(std::string s) {
		if (s.find('.') == std::string::npos) return VeljavenInt(s);
		std::string s1 = s.substr(0, s.find('.'));
		std::string s2 = s.substr(s.find('.') + 1);
		if (!VeljavenInt(s1)) return false;
		if (s2 == "") return true;
		return VeljavenInt(s2) && s2[0] != '-';
	}

	bool VeljavnaKoordinata(std::string s) {
		if (!VeljavenDouble(s)) return false;
		double x = atof(s.c_str());
		return x <= Max_Koordinata && x >= -Max_Koordinata;
	}

	bool VeljavenKot(std::string s) {
		if (!VeljavenDouble(s)) return false;
		double x = atof(s.c_str());
		return x <= Max_Kot && x >= -Max_Kot;
	}

	bool VeljavenRGB(std::string s) {
		if (!VeljavenDouble(s)) return false;
		double x = atof(s.c_str());
		return x >= 0 && x <= 1;
	}

	bool VeljavnaDimBMP(std::string s) {
		if (!VeljavenInt(s)) return false;
		int x = atoi(s.c_str());
		return x >= 0 && x <= Max_BMP_Dim;
	}

	bool VeljavenRatio(std::string s) {
		if (!VeljavenDouble(s)) return false;
		double x = atof(s.c_str());
		return x >= Min_Ratio && x <= Max_Ratio;
	}

	// Vrstni red v ini datoteki:
	// dir_vh, dir_izh, dir_makro, x, y, z, theta, phi, psi, orient,
	// svetloba_theta, svetloba_phi,
	// sir, vis, ratio, r, g, b
	// Naslednji podatki vsebujejo ustrezne nize v ini datoteki
	constexpr char* Ini_Nizi[23] = {
		"[Dir]",
		"Input = ",
		"Output = ",
		"Macro = ",
		"[Camera]",
		"X = ",
		"Y = ",
		"Z = ",
		"Theta = ",
		"Phi = ",
		"Psi = ",
		"Orient = ",
		"[Light Source]",
		"Theta = ",
		"Phi = ",
		"[BMP]",
		"Width = ",
		"Height = ",
		"Ratio = ",
		"[BMP Background]",
		"Red = ",
		"Green = ",
		"Blue = "
	};

	// Shrani nastavitve v datoteko
	bool ShraniDat(std::string ime) {
		std::ofstream dat(ime);
		if (!dat.is_open()) return false;
		dat << Ini_Nizi[0] << "\n";
		dat << Ini_Nizi[1] << Nastavitve::Dir::VhodnaDat << "\n";
		dat << Ini_Nizi[2] << Nastavitve::Dir::IzhodnaDat << "\n";
		dat << Ini_Nizi[3] << Nastavitve::Dir::MakroDir << "\n";
		dat << Ini_Nizi[4] << "\n";
		dat << Ini_Nizi[5] << Nastavitve::Kamera::X << "\n";
		dat << Ini_Nizi[6] << Nastavitve::Kamera::Y << "\n";
		dat << Ini_Nizi[7] << Nastavitve::Kamera::Z << "\n";
		dat << Ini_Nizi[8] << Nastavitve::Kamera::Theta << "\n";
		dat << Ini_Nizi[9] << Nastavitve::Kamera::Phi << "\n";
		dat << Ini_Nizi[10] << Nastavitve::Kamera::Psi << "\n";
		dat << Ini_Nizi[11] << ((Nastavitve::Kamera::Orientiraj) ? "true" : "false") << "\n";
		dat << Ini_Nizi[12] << "\n";
		dat << Ini_Nizi[13] << Nastavitve::Svetloba::Theta << "\n";
		dat << Ini_Nizi[14] << Nastavitve::Svetloba::Phi << "\n";
		dat << Ini_Nizi[15] << "\n";
		dat << Ini_Nizi[16] << Nastavitve::BMP::Sirina << "\n";
		dat << Ini_Nizi[17] << Nastavitve::BMP::Visina << "\n";
		dat << Ini_Nizi[18] << Nastavitve::BMP::Razmerje << "\n";
		dat << Ini_Nizi[19] << "\n";
		dat << Ini_Nizi[20] << Nastavitve::BMP::R << "\n";
		dat << Ini_Nizi[21] << Nastavitve::BMP::G << "\n";
		dat << Ini_Nizi[22] << Nastavitve::BMP::B << "\n";
		dat.close();
		return true;
	}

	// Preberi nastavitve iz datoteke
	bool BeriDat(std::string ime) {
		std::ifstream dat(ime);
		if (!dat.is_open()) return false;
		std::string vrstice[23];
		for (int i = 0; i < 23; i++)
			if (!getline(dat, vrstice[i])) {
				dat.close();
				return false;
			}
		std::string niz;
		if (getline(dat, niz)) {
			dat.close();
			return false;
		}
		dat.close();
		for (int i = 0; i < 23; i++)
			if (vrstice[i].length() < strlen(Ini_Nizi[i])) return false;
		if (vrstice[0] != Ini_Nizi[0]) return false;
		if (vrstice[4] != Ini_Nizi[4]) return false;
		if (vrstice[12] != Ini_Nizi[12]) return false;
		if (vrstice[15] != Ini_Nizi[15]) return false;
		if (vrstice[19] != Ini_Nizi[19]) return false;
		for (int i = 0; i < 23; i++)
			if (vrstice[i].substr(0, strlen(Ini_Nizi[i])) != Ini_Nizi[i]) return false;
		std::string input, output, makro;
		std::string x, y, z, th, ph, ps, or , lth, lph, sir, vis, r, g, b, ratio;
		input = vrstice[1].substr(strlen(Ini_Nizi[1]));
		output = vrstice[2].substr(strlen(Ini_Nizi[2]));
		makro = vrstice[3].substr(strlen(Ini_Nizi[3]));
		x = vrstice[5].substr(strlen(Ini_Nizi[5]));
		y = vrstice[6].substr(strlen(Ini_Nizi[6]));
		z = vrstice[7].substr(strlen(Ini_Nizi[7]));
		th = vrstice[8].substr(strlen(Ini_Nizi[8]));
		ph = vrstice[9].substr(strlen(Ini_Nizi[9]));
		ps = vrstice[10].substr(strlen(Ini_Nizi[10]));
		or = vrstice[11].substr(strlen(Ini_Nizi[11]));
		lth = vrstice[13].substr(strlen(Ini_Nizi[13]));
		lph = vrstice[14].substr(strlen(Ini_Nizi[14]));
		sir = vrstice[16].substr(strlen(Ini_Nizi[16]));
		vis = vrstice[17].substr(strlen(Ini_Nizi[17]));
		ratio = vrstice[18].substr(strlen(Ini_Nizi[18]));
		r = vrstice[20].substr(strlen(Ini_Nizi[20]));
		g = vrstice[21].substr(strlen(Ini_Nizi[21]));
		b = vrstice[22].substr(strlen(Ini_Nizi[22]));
		if (!VeljavnaKoordinata(x)) return false;
		if (!VeljavnaKoordinata(y)) return false;
		if (!VeljavnaKoordinata(z)) return false;
		if (!VeljavenKot(th)) return false;
		if (!VeljavenKot(ph)) return false;
		if (!VeljavenKot(ps)) return false;
		if (or != "true" && or != "false") return false;
		if (!VeljavenKot(lth)) return false;
		if (!VeljavenKot(lph)) return false;
		if (!VeljavnaDimBMP(sir)) return false;
		if (!VeljavnaDimBMP(vis)) return false;
		if (!VeljavenRatio(ratio)) return false;
		if (!VeljavenRGB(r)) return false;
		if (!VeljavenRGB(g)) return false;
		if (!VeljavenRGB(b)) return false;
		Dir::VhodnaDat = input;
		Dir::IzhodnaDat = output;
		Dir::MakroDir = makro;
		Kamera::X = x;
		Kamera::Y = y;
		Kamera::Z = z;
		Kamera::Theta = th;
		Kamera::Phi = ph;
		Kamera::Psi = ps;
		Kamera::Orientiraj = (or == "true");
		Svetloba::Theta = lth;
		Svetloba::Phi = lph;
		BMP::Sirina = sir;
		BMP::Visina = vis;
		BMP::Razmerje = ratio;
		BMP::R = r;
		BMP::G = g;
		BMP::B = b;
		Shrani = true;
		return true;
	}
}

namespace Parser {
	typedef std::string Niz;
	typedef std::vector<Niz> Nizi;

	// Ukazi v makrih in vhodni datoteki.
	// Se jih lahko preimenuje, ne more se jih pa dodajati brez posega v kodo.
	namespace Ukazi {
		const Nizi Kontrolni = { "args", "label", "goto", "if" };
		const Nizi Funkcije = { "exp", "log", "sin", "cos", "tan", "arcsin", "arccos", "arctan", "round" };
		const Nizi Primitivi = { "triangle" };
		const Nizi Relacije = { "==", "!=", "<=", ">=", "<", ">" };

		// Operatorji so razporejeni po prioriteti, prvi so tudi unarni,
		// in sicer prek definicije operator(a) = 0 operator a.
		const Nizi Operatorji = { "+-", "*/", "^" }; 

		const Nizi Prireditveni = { "=" };
	}

	// Funkcija vrne niz brez presledkov in tabulatorjev na levi in desni.
	Niz Oklesti(Niz niz) {
		Niz presTab = " \t";
		while (niz != "" && presTab.find(niz[0]) != Niz::npos)
			niz = niz.substr(1);
		while (niz != "" && presTab.find(niz[niz.length() - 1]) != Niz::npos)
			niz = niz.substr(0, niz.length() - 1);
		return niz;
	}

	// Vrne seznam oklestenih nizov, ki so bili loceni z vejicami
	Nizi Seznam(Niz niz) {
		Nizi seznam;
		niz = Oklesti(niz);
		if (niz == "") return seznam;
		while (niz.find(',') != Niz::npos) {
			seznam.push_back(Oklesti(niz.substr(0, niz.find(','))));
			niz = niz.substr(niz.find(',') + 1);
		}
		seznam.push_back(Oklesti(niz));
		return seznam;
	}

	// Ali je niz veljavno ime spremenljivke?
	bool VeljavnaSpr(Niz ime) {
		if (ime == "") return false;
		Niz veljavni = "0123456789_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (char znak : ime)
			if (veljavni.find(znak) == Niz::npos) return false;
		Niz cifre = "0123456789";
		if (cifre.find(ime[0]) != Niz::npos) return false;
		if (std::find(Ukazi::Funkcije.begin(), Ukazi::Funkcije.end(), ime) != Ukazi::Funkcije.end()) return false;
		if (std::find(Ukazi::Kontrolni.begin(), Ukazi::Kontrolni.end(), ime) != Ukazi::Kontrolni.end()) return false;
		if (std::find(Ukazi::Primitivi.begin(), Ukazi::Primitivi.end(), ime) != Ukazi::Primitivi.end()) return false;
		return true;
	}

	// Ali je niz veljavna nenegativna konstanta?
	bool VeljavnaKonst(Niz konst, double& vrednost) {
		if (konst == "" || konst == ".") return false;
		Niz cifre = "0123456789";
		bool pika = false;
		for (char znak : konst) {
			if (znak == '.') {
				if (pika) return false;
				pika = true;
			}
			else if (cifre.find(znak) == Niz::npos) return false;
		}
		vrednost = atof(konst.c_str());
		return true;
	}

	// Poisce zadnji znak v nizu niz,
	// ki je zunaj vseh oklepajev in ki se nahaja v nizu znaki.
	// Vrne lokacijo zadnjega zunanjega znaka in garantira,
	// da so oklepaji za tem znakom pravilno postavljeni.
	// Ce znaki niso pravilno postavljeni ali ce znak ne obstaja,
	// vrne npos.
	std::size_t PoisciZunanjiZnak(Niz niz, Niz znaki) {
		int stopnja_oklepajev = 0;
		for (int i = (int)niz.length() - 1; i >= 0; i--)
			if (niz[i] == ')') stopnja_oklepajev++;
			else if (niz[i] == '(') {
				if (stopnja_oklepajev == 0) return Niz::npos;
				stopnja_oklepajev--;
			}
			else if (stopnja_oklepajev == 0 && znaki.find(niz[i]) != Niz::npos)
				return (std::size_t)i;
		return Niz::npos;
	}

	// Ali se niz zacne z danim podnizom?
	bool SeZacne(Niz niz, Niz podniz) {
		return niz.length() >= podniz.length() && niz.substr(0, podniz.length()) == podniz;
	}

	typedef std::vector<int> Inti;
	typedef std::vector<std::size_t> Lokacije;

	// Ali je neoklesteni niz (ki pa nima komentarjev) veljaven izraz?
	// Ce je, ga nalima na konec kode in posodobi spremenljivke.
	bool VeljavenIzraz(Niz izraz, Nizi& spremenljivke, Inti& koda) {
		izraz = Oklesti(izraz);
		if (izraz == "") return false;
		if (Ukazi::Operatorji.at(0).find(izraz[0]) != Niz::npos) izraz = "0" + izraz;
		std::size_t pozicija = Niz::npos;

		// Ali je binarna operacija?
		for (std::size_t i = 0; i < Ukazi::Operatorji.size(); i++) {
			Niz operatorji = Ukazi::Operatorji.at(i);
			pozicija = PoisciZunanjiZnak(izraz, operatorji);
			if (pozicija != Niz::npos) {
				Niz izraz1 = izraz.substr(0, pozicija);
				Niz izraz2 = izraz.substr(pozicija + 1);
				int j = operatorji.find(izraz[pozicija]);
				koda.push_back((int)i * 10 + j);
				if (!VeljavenIzraz(izraz1, spremenljivke, koda)) return false;
				if (!VeljavenIzraz(izraz2, spremenljivke, koda)) return false;
				return true;
			}
		}
		for (std::size_t i = 0; i < Ukazi::Funkcije.size(); i++)
			if (SeZacne(izraz, Ukazi::Funkcije.at(i) + "(")) {
				koda.push_back((int)i + 100);
				izraz = izraz.substr(Ukazi::Funkcije.at(i).length());
				return VeljavenIzraz(izraz, spremenljivke, koda);
			}
		if (izraz[0] == '(' && izraz[izraz.length() - 1] == ')')
			return VeljavenIzraz(izraz.substr(1, izraz.length() - 2), spremenljivke, koda);
		if (VeljavnaSpr(izraz)) {
			koda.push_back(200);
			int i;
			Nizi::iterator pozicija = std::find(spremenljivke.begin(), spremenljivke.end(), izraz);
			if (pozicija == spremenljivke.end()) {
				i = (int)spremenljivke.size();
				spremenljivke.push_back(izraz);
			}
			else
				i = (int)std::distance(spremenljivke.begin(), pozicija);
			koda.push_back(i);
			return true;
		}
		double vrednost; // 8 bytov
		if (!VeljavnaKonst(izraz, vrednost))
			return false;
		koda.push_back(201);
		int* kazalec_int = (int*)&vrednost;
		koda.push_back(*kazalec_int);
		koda.push_back(*(kazalec_int + 1));
		return true;
	}

	// Ali je neoklesceni niz (ki nima komentarjev) veljavna neenakost?
	// Ce je, jo nalima na konec kode in posodobi spremenljivke.
	bool VeljavnaNeenakost(Niz neenakost, Nizi& spremenljivke, Inti& koda) {
		for (std::size_t i = 0; i < Ukazi::Relacije.size(); i++) {
			std::size_t pozicija = neenakost.find(Ukazi::Relacije.at(i));
			if (pozicija != Niz::npos) {
				koda.push_back(i);
				Niz izraz1 = neenakost.substr(0, pozicija);
				Niz izraz2 = neenakost.substr(pozicija + Ukazi::Relacije.at(i).length());
				if (!VeljavenIzraz(izraz1, spremenljivke, koda)) return false;
				if (!VeljavenIzraz(izraz2, spremenljivke, koda)) return false;
				return true;
			}
		}
		return false;
	}

	// Shrani vrstice datoteke v seznam nizov. Ne brise presledkov in komentarjev.
	bool PreberiDatoteko(Niz ime_datoteke, Nizi& vrstice) {
		std::ifstream dat(ime_datoteke);
		if (!dat.is_open()) return false;
		vrstice.clear();
		std::string s;
		while (getline(dat, s)) vrstice.push_back(s);
		dat.close();
		return true;
	}

	// KODE NAPAK:
	// 1 argumenti niso v 1. vrstici
	// 2 nic argumentov
	// 3 neveljavno ime argumenta
	// 4 podvojen argument
	// 11 neveljavno ime labela
	// 12 podvojen label
	// 13 labela ni bilo mogoce najti (v stavku goto)
	// 21 neveljavna neenakost v if stavku
	// 22 za if stavkom ni nobenega stavka, pa bi moral biti
	// 31 neveljavno ime spremenljivke v prireditvenem stavku
	// 32 neveljaven izraz v prireditvenem stavku
	// 41 napacno postavljeni oklepaji pri klicu trikotnika
	// 42 napacno stevilo argumentov pri klicu trikotnika
	// 43 neveljavni argumenti pri klicu trikotnika
	// 51 napacno postavljeni oklepaji pri klicu makra
	// 52 neveljavno ime makra
	// 54 neveljavni argumenti pri klicu makra

	// Klic makra (ali vhodne datoteke).
	struct Klic {

		// ime klicanega makra (ali prazen niz, ce klicemo vhodno datoteko)
		Niz Ime;

		// ime klicatelja ("", ce klice vhodna datoteka ali
		// ce je klicani ze sam vhodna datoteka)
		Niz Klicatelj;

		// stevilo argumentov, s katerim klicemo (vhodno datoteko npr.
		// klicemo z 0 argumenti
		int SteviloArgumentov;

		// originalna vrstica v klicatelju, kjer se nahaja klic
		int OriginalnaVrstica;

		// mesto klica v kodi
		std::size_t LokacijaKlica;
	};

	typedef std::vector<Klic> Klici;

	// Prevede (nepociscene) vrstice ene datoteke v kodo. Lastnik je ime
	// makra, ki ga prevajamo (oz. "", ce prevajamo vhodno datoteko),
	// vrstice so input, klici se posodobijo, st_argumentov se shrani
	// (koliko argumentov makro (oz. vh. dat.) dejansko ima), koda
	// se shrani. V primeru napake se vrne originalna vrstica, kjer
	// je prislo do napake, in koda napake (0, ce je vse OK).
	// Za napake glej KODE NAPAK.
	int ParsajVrstice(Niz lastnik, const Nizi& vrstice, Klici& klici, int& st_argumentov, Inti& koda, int& VrsticaNapake) {
		Lokacije vrstice_lokacije; //lokacije prevedenih vrstic
		Nizi spremenljivke; // imena vseh spremenljivk
		Nizi labeli; // imena vseh labelov
		Lokacije labeli_lokacije; // lokacije labelov v kodi
		Nizi gotoji; // imena gotojev
		Lokacije gotoji_lokacije; // lokacije gotojev (na znak za goto)
		Inti gotoji_originalne_vrstice; // lokacije gotojev v originalnih vrsticah
		Lokacije ifi_vrstice; // vrstice vseh if stavkov v prevedeni kodi
		Inti ifi_originalne_vrstice; // lokacije ifov v originalnih vrsticah
		st_argumentov = 0;
		for (std::size_t i = 0; i < vrstice.size(); i++) {
			VrsticaNapake = (int)i;
			Niz vrstica = vrstice.at(i);
			if (vrstica.find("//") != Niz::npos)
				vrstica = vrstica.substr(0, vrstica.find("//"));
			vrstica = Oklesti(vrstica);
			for (std::size_t i = 0; i < Ukazi::Kontrolni.size(); i++)
				if (SeZacne(vrstica, Ukazi::Kontrolni.at(i) + " ") ||
					SeZacne(vrstica, Ukazi::Kontrolni.at(i) + "\t")) {
					Niz parametri = vrstica.substr(Ukazi::Kontrolni.at(i).length());
					if (i == 0) { // args
						if (!vrstice_lokacije.empty() || !labeli_lokacije.empty() || !spremenljivke.empty()) return 1; // argumenti niso v 1. vrstici
						Nizi argumenti = Seznam(parametri);
						if (argumenti.empty()) return 2; // imeti 0 argumentov ni dovoljeno
						st_argumentov = argumenti.size();
						for (Niz argument : argumenti) {
							if (!VeljavnaSpr(argument)) return 3; // neveljavno ime argumenta
							if (std::find(spremenljivke.begin(), spremenljivke.end(), argument) != spremenljivke.end()) return 4; // podvojen argument
							spremenljivke.push_back(argument);
						}
					}
					else if (i == 1) { // label
						Niz ime = Oklesti(parametri);
						if (!VeljavnaSpr(ime)) return 11; // neveljavno ime labela
						if (std::find(labeli.begin(), labeli.end(), ime) != labeli.end())
							return 12; // podvojen label
						labeli.push_back(ime);
						labeli_lokacije.push_back(koda.size());
					}
					else if (i == 2) { // goto
						Niz ime = Oklesti(parametri);
						if (!VeljavnaSpr(ime)) return 11; // neveljavno ime labela
						gotoji.push_back(ime);
						gotoji_lokacije.push_back(koda.size());
						gotoji_originalne_vrstice.push_back(VrsticaNapake);
						vrstice_lokacije.push_back(koda.size());
						koda.push_back(0);
						koda.push_back(0);
					}
					else { // if
						ifi_vrstice.push_back(vrstice_lokacije.size());
						ifi_originalne_vrstice.push_back(VrsticaNapake);
						vrstice_lokacije.push_back(koda.size());
						koda.push_back(1);
						koda.push_back(0);
						if (!VeljavnaNeenakost(parametri, spremenljivke, koda)) return 21; // neveljavna enakost
					}
					vrstica = "";
					break;
				}
			if (vrstica == "") continue;
			std::size_t pozicija = vrstica.find(Ukazi::Prireditveni.at(0));
			if (pozicija != Niz::npos) {
				vrstice_lokacije.push_back(koda.size());
				Niz ime = Oklesti(vrstica.substr(0, pozicija));
				Niz izraz = vrstica.substr(pozicija + 1);
				koda.push_back(2);
				if (!VeljavnaSpr(ime)) return 31; // neveljavno ime spremenljivke
				int i;
				Nizi::iterator spr_pozicija = std::find(spremenljivke.begin(), spremenljivke.end(), ime);
				if (spr_pozicija == spremenljivke.end()) {
					i = (int)spremenljivke.size();
					spremenljivke.push_back(ime);
				}
				else
					i = (int)std::distance(spremenljivke.begin(), spr_pozicija);
				koda.push_back(i);
				if (!VeljavenIzraz(izraz, spremenljivke, koda)) return 32; // neveljaven izraz v prireditvenem stavku
				continue;
			}
			if (SeZacne(vrstica, Ukazi::Primitivi.at(0) + "(")) {
				if (vrstica[vrstica.length() - 1] != ')') return 41; // napacni oklepaji v ukazu za trikotnik
				vrstica = vrstica.substr(Ukazi::Primitivi.at(0).length());
				vrstica = vrstica.substr(1, vrstica.length() - 2);
				Nizi args = Seznam(vrstica);
				if (args.size() != 12) return 42; // napacno stevilo argumentov pri klicu trikotnika
				vrstice_lokacije.push_back(koda.size());
				koda.push_back(3);
				for (int i = 0; i < 12; i++)
					if (!VeljavenIzraz(args.at(i), spremenljivke, koda)) return 43; // neveljavni argumenti
				continue;
			}
			if (vrstica.find("(") == Niz::npos) vrstica += "()";
			if (vrstica[vrstica.length() - 1] != ')') return 51; // napacno postavljeni oklepaji pri klicu makra
			Niz ime = vrstica.substr(0, vrstica.find("("));
			vrstica = vrstica.substr(vrstica.find("(") + 1);
			vrstica = vrstica.substr(0, vrstica.length() - 1);
			Nizi args = Seznam(vrstica);
			if (!VeljavnaSpr(ime)) return 52; // neveljavno ime makra
			Klic klic;
			klic.Ime = ime;
			klic.Klicatelj = lastnik;
			klic.OriginalnaVrstica = VrsticaNapake;
			klic.SteviloArgumentov = args.size();
			klic.LokacijaKlica = koda.size();
			klici.push_back(klic);
			vrstice_lokacije.push_back(koda.size());
			koda.push_back(4);
			koda.push_back(0);
			koda.push_back(args.size());
			for (Niz izraz : args)
				if (!VeljavenIzraz(izraz, spremenljivke, koda)) return 54; // neveljavni argumenti
		}
		for (int i = 0; i < (int)gotoji.size(); i++) {
			VrsticaNapake = gotoji_originalne_vrstice.at(i);
			Nizi::iterator pozicija = std::find(labeli.begin(), labeli.end(), gotoji.at(i));
			if (pozicija == labeli.end()) return 13;
			int j = (int)std::distance(labeli.begin(), pozicija);
			koda.at(gotoji_lokacije.at(i) + 1) = labeli_lokacije.at(j);
		}
		if (!ifi_vrstice.empty() && ifi_vrstice.back() == vrstice_lokacije.size() - 1) {
			VrsticaNapake = ifi_originalne_vrstice.back();
			return 22;
		}
		for (int indeks : ifi_vrstice) {
			std::size_t lokacija;
			if (indeks == vrstice_lokacije.size() - 2)
				lokacija = koda.size();
			else
				lokacija = vrstice_lokacije.at(indeks + 2);
			koda.at(vrstice_lokacije.at(indeks) + 1) = lokacija;
		}
		return 0;
	}

	// Dodatne KODE NAPAK:
	// 100 stevilo argumentov se ne ujema s tistim v datoteki
	// 101 datoteka ne obstaja
	// 102 makro ne obstaja
	// 105 izvorna datoteka z argumenti

	// Sparsa datoteko (ime mora biti brez koncnice txt)
	// in vse podrejene makre.
	// Vrne seznam imen makrov (1. ime je izvornoIme),
	// seznam stevil argumentov in seznam sparsanih kod.
	// Vrne 0, ce je vse OK, in kodo napake sicer.
	int ParsajDatoteko(Nizi& makriImena, Inti& stevilaArgumentov, std::vector<Inti>& kode, int& VrsticaNapake, Niz& DatotekaNapake) {
		Klici klici;
		Klic klic;
		klic.Ime = "";
		klic.SteviloArgumentov = 0;
		klic.Klicatelj = "";
		klic.OriginalnaVrstica = 0;
		klic.LokacijaKlica = 0;
		klici.push_back(klic);
		while (!klici.empty()) {
			Klic klic = klici.back();
			klici.pop_back();
			Nizi::iterator pozicija = std::find(makriImena.begin(), makriImena.end(), klic.Ime);
			if (pozicija != makriImena.end()) {
				int i = (int)std::distance(makriImena.begin(), pozicija);
				if (klic.SteviloArgumentov != stevilaArgumentov.at(i)) {
					VrsticaNapake = klic.OriginalnaVrstica;
					DatotekaNapake = klic.Klicatelj;
					return 100; // stevilo argumentov se ne ujema s tistim v datoteki
				}
				Nizi::iterator pozicijaKlicatelja = std::find(makriImena.begin(), makriImena.end(), klic.Klicatelj);
				int j = (int)std::distance(makriImena.begin(), pozicijaKlicatelja);
				kode.at(j).at(klic.LokacijaKlica + 1) = i;
			}
			else {
				Nizi vrstice;
				std::string ime_datoteke;
				if (klic.Ime == "") ime_datoteke = Nastavitve::Dir::VhodnaDat;
				else ime_datoteke = Nastavitve::Dir::MakroDir + "\\" + klic.Ime + ".txt";
				if (!PreberiDatoteko(ime_datoteke, vrstice)) {
					DatotekaNapake = klic.Klicatelj;
					VrsticaNapake = klic.OriginalnaVrstica;
					if (klic.Ime == "") return 101;
					else return 102;
				}
				int st_argumentov;
				Inti koda;
				int i = ParsajVrstice(klic.Ime, vrstice, klici, st_argumentov, koda, VrsticaNapake);
				if (i != 0) {
					DatotekaNapake = klic.Ime;
					return i;
				}
				if (st_argumentov != klic.SteviloArgumentov) {
					VrsticaNapake = klic.OriginalnaVrstica;
					if (klic.Ime == "") return 105; // izvorna datoteka ima argumente
					DatotekaNapake = klic.Klicatelj;
					return 100;
				}
				if (klic.Ime != "") {
					Nizi::iterator pozicijaKlicatelja = std::find(makriImena.begin(), makriImena.end(), klic.Klicatelj);
					int j = (int)std::distance(makriImena.begin(), pozicijaKlicatelja);
					kode.at(j).at(klic.LokacijaKlica + 1) = makriImena.size();
				}
				makriImena.push_back(klic.Ime);
				stevilaArgumentov.push_back(st_argumentov);
				kode.push_back(koda);
			}
		}
		return 0;
	}
}

namespace Podatki {

	// Velikost BMP v pikslih.
	int Sirina, Visina;

	// Podatki o kameri. Kamera je v originalu orientirana tako,
	// da je postavljena v (0,0,0) in gleda v narascajoco smer y.
	// (Os z gleda gor.) Parametri dolocajo zasuk in rotacijo
	// kamere: (X,Y,Z) je lokacija kamere, theta je rotacija
	// v pozitivni smeri okrog kamerine lastne z-osi, phi
	// je rotacija okrog x-osi in psi okrog y-osi.
	double KameraX, KameraY, KameraZ, KameraTheta, KameraPhi, KameraPsi;

	// Smer svetlobe. Vektor (0,1,0) (originalni vektor kamere)
	// se zavrti za theta (v poz. smeri) okrog z-osi in nato se
	// za psi okrog lastne x-osi vektorja
	double SvetlobaTheta, SvetlobaPhi;

	// barva ozadja
	double OzadjeR, OzadjeG, OzadjeB;

	// razmerje piksli/enoto
	double Faktor;

	struct Piksel {
		double R, G, B;
		double Oddaljenost;
	};

	// slika
	std::vector<Piksel> Tabela;

	// Prebere podatke iz nastavitev in inicializira prazno (crno) sliko.
	void Inicializiraj() {
		Sirina = atoi(Nastavitve::BMP::Sirina.c_str());
		Visina = atoi(Nastavitve::BMP::Visina.c_str());
		KameraX = atof(Nastavitve::Kamera::X.c_str());
		KameraY = atof(Nastavitve::Kamera::Y.c_str());
		KameraZ = atof(Nastavitve::Kamera::Z.c_str());
		if (Nastavitve::Kamera::Orientiraj) {
			if (KameraX == 0)
				KameraTheta = (KameraY > 0) ? atan(1) * 4 : 0;
			else if (KameraX > 0)
				KameraTheta = atan(KameraY / KameraX) + atan(1) * 2;
			else
				KameraTheta = atan(KameraY / KameraX) - atan(1) * 2;
			double r0 = sqrt(KameraX * KameraX + KameraY * KameraY);
			if (r0 == 0)
				KameraPhi = (KameraZ > 0) ? -atan(1) * 2 : atan(1) * 2;
			else
				KameraPhi = -atan(KameraZ / r0);
			KameraPsi = 0;
		}
		else {
			KameraTheta = atof(Nastavitve::Kamera::Theta.c_str());
			KameraPhi = atof(Nastavitve::Kamera::Phi.c_str());
			KameraPsi = atof(Nastavitve::Kamera::Psi.c_str());
		}
		SvetlobaTheta = atof(Nastavitve::Svetloba::Theta.c_str());
		SvetlobaPhi = atof(Nastavitve::Svetloba::Phi.c_str());
		OzadjeR = atof(Nastavitve::BMP::R.c_str());
		OzadjeG = atof(Nastavitve::BMP::G.c_str());
		OzadjeB = atof(Nastavitve::BMP::B.c_str());
		Faktor = atof(Nastavitve::BMP::Razmerje.c_str());
		Tabela.resize(Sirina * Visina);
		for (int i = 0; i < Sirina * Visina; i++) {
			Tabela.at(i).R = OzadjeR;
			Tabela.at(i).G = OzadjeG;
			Tabela.at(i).B = OzadjeB;
			Tabela.at(i).Oddaljenost = -1;
		}
	}
}

namespace Grafika {
	const double Defekt = 0.00000001; // natancnost racunanja

	typedef std::vector<int> Inti;

	// V pravokotni mrezi, katere spodnji levi vogal je v tocki (0,0),
	// zgornji desni pa v tocki (Sirina, Visina),
	// poisce vse piksle (i,j) (vrne spodnje leve vogale),
	// katerih tezisca lezijo znotraj trikotnika.
	// Piksle prikljuci na konec seznamov Iji in Jji.
	void PiksliVTrikotniku(double x1, double y1, double x2, double y2, double x3, double y3, Inti& Iji, Inti& Jji) {
		if (x2 < x1) {
			std::swap(x1, x2);
			std::swap(y1, y2);
		}
		if (x3 < x1) {
			std::swap(x1, x3);
			std::swap(y1, y3);
		}
		if (x3 < x2) {
			std::swap(x2, x3);
			std::swap(y2, y3);
		} // garantiramo x1 <= x2 <= x3
		if (x1 == x3) return; // garantiramo, da ne bo deljenja z 0
		double y4 = y1 + (y3 - y1) / (x3 - x1) * (x2 - x1);
		if (y4 < y2) std::swap(y2, y4);
		if (x1 < Podatki::Sirina - 0.5 && x2 > 0.5) {
			int imin = (x1 < 0.5) ? 0 : (int)(x1 + 0.5);
			int imax = (x2 > Podatki::Sirina - 0.5) ? Podatki::Sirina - 1 : (int)(x2 - 0.5);
			for (int i = imin; i <= imax; i++)
				if (x1 != x2) {
					double ymin = y1 + (y2 - y1) / (x2 - x1) * (i + 0.5 - x1); // presecisce premice x=i+0.5 s spodnjim robom trikotnika
					double ymax = y1 + (y4 - y1) / (x2 - x1) * (i + 0.5 - x1); // presecisce z zgornjim robom
					if (ymin < Podatki::Visina - 0.5 && ymax > 0.5) {
						int jmin = (ymin < 0.5) ? 0 : (int)(ymin + 0.5);
						int jmax = (ymax > Podatki::Visina - 0.5) ? Podatki::Visina - 1 : (int)(ymax - 0.5);
						for (int j = jmin; j <= jmax; j++) {
							Iji.push_back(i);
							Jji.push_back(j);
						}
					}
				}
		}
		if (x2 < Podatki::Sirina - 0.5 && x3 > 0.5) {
			int imin = (x2 < 0.5) ? 0 : (int)(x2 + 0.5);
			int imax = (x3 > Podatki::Sirina - 0.5) ? Podatki::Sirina - 1 : (int)(x3 - 0.5);
			for (int i = imin; i <= imax; i++)
				if (x2 != x3) {
					double ymin = y3 + (y2 - y3) / (x2 - x3) * (i + 0.5 - x3); // presecisce premice x=i+0.5 s spodnjim robom trikotnika
					double ymax = y3 + (y4 - y3) / (x2 - x3) * (i + 0.5 - x3); // presecisce z zgornjim robom
					if (ymin < Podatki::Visina - 0.5 && ymax > 0.5) {
						int jmin = (ymin < 0.5) ? 0 : (int)(ymin + 0.5);
						int jmax = (ymax > Podatki::Visina - 0.5) ? Podatki::Visina - 1 : (int)(ymax - 0.5);
						for (int j = jmin; j <= jmax; j++) {
							Iji.push_back(i);
							Jji.push_back(j);
						}
					}
				}
		}
	}

	// Vrne piksle, vsebovane v konveksnem ravninskem izseku z vrhom (x0,y0) in
	// krakoma skozi (x1,y1) in (x2,y2). Kraka morata biti dolzine, vecje od 0,
	// kot pri vrhu pa mora biti strogo manjsi od pi.
	// Ce je izbrano obrezi, je iz izseka izvzet trikotnik z danimi oglisci.
	// Primer: (0,0),(1,0),(0,1),false je 1. kvadrant, true pa 1. kvadrant brez malega trikotnika.
	void PiksliVIzseku(double x0, double y0, double x1, double y1, double x2, double y2, bool obrezi, Inti& Iji, Inti& Jji) {
		double n1 = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
		double n2 = sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));
		double n = n1 + n2;
		if ((x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0) < 0) { // topokotni izsek
			if (n == 0) return;
			double x3 = (n1 * x2 + n2 * x1) / n;
			double y3 = (n1 * y2 + n2 * y1) / n;
			PiksliVIzseku(x0, y0, x1, y1, x3, y3, obrezi, Iji, Jji);
			PiksliVIzseku(x0, y0, x2, y2, x3, y3, obrezi, Iji, Jji);
			return;
		}
		double krak = 2 * (abs(x0) + abs(y0) + Podatki::Sirina + Podatki::Visina) + n; // risem (prirezan) enakokraki trikotnik s tema krakoma
		if (n1 == 0 || n2 == 0) return;
		double x3 = x0 + (x1 - x0) * krak / n1;
		double y3 = y0 + (y1 - y0) * krak / n1;
		double x4 = x0 + (x2 - x0) * krak / n2;
		double y4 = y0 + (y2 - y0) * krak / n2;
		if (obrezi) {
			PiksliVTrikotniku(x1, y1, x3, y3, x4, y4, Iji, Jji);
			PiksliVTrikotniku(x1, y1, x2, y2, x4, y4, Iji, Jji);
		}
		else
			PiksliVTrikotniku(x0, y0, x3, y3, x4, y4, Iji, Jji);
	}

	// Ravninska rotacija
	void Rotiraj(double& x, double& y, double psi) {
		double xnovi = x * cos(psi) - y * sin(psi);
		double ynovi = y * cos(psi) + x * sin(psi);
		x = xnovi;
		y = ynovi;
	}

	// Inverzni vzporedni premik glede na lokacijo kamere
	void TranslacijaKamera(double& x, double& y, double& z) {
		x -= Podatki::KameraX;
		y -= Podatki::KameraY;
		z -= Podatki::KameraZ;
	}

	// Inverzna rotacija glede na lokacijo kamere
	void RotacijaKamera(double& x, double& y, double& z) {
		Rotiraj(x, y, -Podatki::KameraTheta);
		Rotiraj(y, z, -Podatki::KameraPhi);
		Rotiraj(x, z, -Podatki::KameraPsi);
	}

	// Narise trikotnik v 3D, tako da posodobi podatke (tabelo).
	void NarisiTrikotnik(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double R, double G, double B) {
		TranslacijaKamera(x1, y1, z1);
		TranslacijaKamera(x2, y2, z2);
		TranslacijaKamera(x3, y3, z3);
		RotacijaKamera(x1, y1, z1);
		RotacijaKamera(x2, y2, z2);
		RotacijaKamera(x3, y3, z3);
		if (y1 == 0) y1 = Defekt;
		if (y2 == 0) y2 = Defekt;
		if (y3 == 0) y3 = Defekt; // izognem se deljenju z 0
		if (y2 < y1) {
			std::swap(x1, x2);
			std::swap(y1, y2);
			std::swap(z1, z2);
		}
		if (y3 < y1) {
			std::swap(x1, x3);
			std::swap(y1, y3);
			std::swap(z1, z3);
		}
		if (y3 < y2) {
			std::swap(x2, x3);
			std::swap(y2, y3);
			std::swap(z2, z3);
		} // garantiram y1 <= y2 <= y3
		if (y3 < 0) return; // trikotnik je za kamero
		double x1proj = Podatki::Faktor * x1 / y1 + (double)Podatki::Sirina / 2;
		double y1proj = Podatki::Faktor * z1 / y1 + (double)Podatki::Visina / 2;
		double x2proj = Podatki::Faktor * x2 / y2 + (double)Podatki::Sirina / 2;
		double y2proj = Podatki::Faktor * z2 / y2 + (double)Podatki::Visina / 2;
		double x3proj = Podatki::Faktor * x3 / y3 + (double)Podatki::Sirina / 2;
		double y3proj = Podatki::Faktor * z3 / y3 + (double)Podatki::Visina / 2; // projekcije
		Inti Iji;
		Inti Jji;
		if (y2 < 0) {
			x1proj += 2 * (x3proj - x1proj);
			y1proj += 2 * (y3proj - y1proj);
			x2proj += 2 * (x3proj - x2proj);
			y2proj += 2 * (y3proj - y2proj);
			if ((x1proj == x3proj && y1proj == y3proj) || (x2proj == x3proj && y2proj == y3proj)) return;
			PiksliVIzseku(x3proj, y3proj, x1proj, y1proj, x2proj, y2proj, false, Iji, Jji);
		}
		else if (y1 < 0) {
			if ((x1proj == x3proj && y1proj == y3proj) || (x2proj == x1proj && y2proj == y1proj)) return;
			PiksliVIzseku(x1proj, y1proj, x2proj, y2proj, x3proj, y3proj, true, Iji, Jji);
		}
		else
			PiksliVTrikotniku(x1proj, y1proj, x2proj, y2proj, x3proj, y3proj, Iji, Jji);
		if (Iji.empty()) return;
		double a1 = x1 - x3;
		double a2 = y1 - y3;
		double a3 = z1 - z3;
		double b1 = x2 - x3;
		double b2 = y2 - y3;
		double b3 = z2 - z3;
		double n1 = a2 * b3 - a3 * b2;
		double n2 = -a1 * b3 + a3 * b1;
		double n3 = a1 * b2 - a2 * b1; // normala trikotnika
		double t3n = x3 * n1 + y3 * n2 + z3 * n3;
		if (t3n > 0) {
			n1 = -n1;
			n2 = -n2;
			n3 = -n3; // garantiramo, da normala gleda proti kameri
			t3n = -t3n;
		}
		if (t3n == 0) return;
		double n = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
		if (n == 0) return;
		double sv1 = 0;
		double sv2 = 1;
		double sv3 = 0;
		Rotiraj(sv2, sv3, Podatki::SvetlobaPhi);
		Rotiraj(sv1, sv2, Podatki::SvetlobaTheta);
		RotacijaKamera(sv1, sv2, sv3); // vektor svetlobe
		double nsv = (n1 * sv1 + n2 * sv2 + n3 * sv3) / n;
		double sv_faktor;
		if (nsv >= 1) sv_faktor = 0;
		else if (nsv <= -1) sv_faktor = 1;
		else sv_faktor = acos(nsv) / (atan(1) * 4);
		R *= sv_faktor;
		G *= sv_faktor;
		B *= sv_faktor;
		for (int i = 0; i < (int)Iji.size(); i++) {
			double xproj = (Iji.at(i) + 0.5 - (double)Podatki::Sirina / 2) / Podatki::Faktor;
			double yproj = (Jji.at(i) + 0.5 - (double)Podatki::Visina / 2) / Podatki::Faktor;
			double koef = xproj * n1 + n2 + yproj * n3;
			if (koef == 0) continue;
			double y = t3n / koef;
			double x = xproj * y;
			double z = yproj * y;
			double oddaljenost = sqrt(x * x + y * y + z * z);
			int lokacija = Jji.at(i) * Podatki::Sirina + Iji.at(i);
			double stara_odd = Podatki::Tabela.at(lokacija).Oddaljenost;
			if (stara_odd < 0 || stara_odd > oddaljenost) {
				Podatki::Tabela.at(lokacija).Oddaljenost = oddaljenost;
				Podatki::Tabela.at(lokacija).R = R;
				Podatki::Tabela.at(lokacija).G = G;
				Podatki::Tabela.at(lokacija).B = B;
			}
		}
	}
}

namespace Eksekutor {
	const double Epsilon = 0.0000000001; // natancnost preverjanja enakosti in neenakosti

	Parser::Nizi ImenaMakrov;
	Parser::Inti StevilaArgumentov;
	std::vector<Parser::Inti> KodeMakrov;

	// Postavim se na pozicijo v kodi ustreznega makra, izracunam
	// vrednost glede na spremenljivke (ki jih po potrebi posodobim),
	// posodobim pozicijo in shranim vrednost. Vrnjena je koda napake:
	//
	// 1001 deljenje z 0
	// 1002 potenca z negativno osnovo
	// 1003 negativen argument logaritma
	// 1004 argument od arcsin zunaj [-1,1]
	// 1005 argument od arccos zunaj [-1,1]
	int Izracunaj(int indeksMakra, int& pozicija, std::vector<double>& spremenljivke, double& vrednost) {
		int operacija = KodeMakrov.at(indeksMakra).at(pozicija++);
		if (operacija < 100) {
			double a, b;
			int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, a);
			if (koda != 0) return koda;
			koda = Izracunaj(indeksMakra, pozicija, spremenljivke, b);
			if (koda != 0) return koda;
			if (operacija == 0) vrednost = a + b;
			else if (operacija == 1) vrednost = a - b;
			else if (operacija == 10) vrednost = a * b;
			else if (operacija == 11) {
				if (b == 0) return 1001;
				vrednost = a / b;
			}
			else {
				if (a < 0) return 1002;
				vrednost = exp(log(a) * b);
			}
		}
		else if (operacija < 200) {
			double a;
			int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, a);
			if (koda != 0) return koda;
			if (operacija == 100) vrednost = exp(a);
			else if (operacija == 101) {
				if (a <= 0) return 1003;
				vrednost = log(a);
			}
			else if (operacija == 102) vrednost = sin(a);
			else if (operacija == 103) vrednost = cos(a);
			else if (operacija == 104) vrednost = tan(a);
			else if (operacija == 105) {
				if (a > 1 || a < -1) return 1004;
				vrednost = asin(a);
			}
			else if (operacija == 106) {
				if (a > 1 || a < -1) return 1005;
				vrednost = acos(a);
			}
			else if (operacija == 107) vrednost = atan(a);
			else vrednost = round(a);
		}
		else if (operacija == 200) {
			int indeks = KodeMakrov.at(indeksMakra).at(pozicija++);
			if ((int)spremenljivke.size() <= indeks)
				spremenljivke.resize(indeks + 1);
			vrednost = spremenljivke.at(indeks);
		}
		else {
			double* kazalec_double = (double*)&KodeMakrov.at(indeksMakra).at(pozicija);
			pozicija += 2;
			vrednost = *kazalec_double;
		}
		return 0;
	}

	// Izvede makro v celoti, tako da klice tudi podrejene makre.
	// Ob napaki je v spremenljivki indeksNapake indeks podmakra,
	// v katerem je prislo do napake. Mozna napaka poleg zgoraj nastetih:
	//
	// 1006 neveljavna barva pri klicu trikotnika
	int Izvedi(int indeksMakra, std::vector<double> argumenti, int& indeksNapake) {
		int pozicija = 0;
		std::vector<double> spremenljivke = argumenti;
		indeksNapake = indeksMakra;
		while (pozicija != KodeMakrov.at(indeksMakra).size()) {
			int ukaz = KodeMakrov.at(indeksMakra).at(pozicija++);
			if (ukaz == 0)
				pozicija = KodeMakrov.at(indeksMakra).at(pozicija);
			else if (ukaz == 1) {
				int nova_pozicija = KodeMakrov.at(indeksMakra).at(pozicija++);
				int neenacaj = KodeMakrov.at(indeksMakra).at(pozicija++);
				double izraz1, izraz2;
				int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, izraz1);
				if (koda != 0) return koda;
				koda = Izracunaj(indeksMakra, pozicija, spremenljivke, izraz2);
				if (koda != 0) return koda;
				bool izjava;
				if (neenacaj == 0) izjava = (abs(izraz1 - izraz2) < Epsilon);
				else if (neenacaj == 1) izjava = (abs(izraz1 - izraz2) > Epsilon);
				else if (neenacaj == 2) izjava = (izraz1 < izraz2 + Epsilon);
				else if (neenacaj == 3) izjava = (izraz1 > izraz2 - Epsilon);
				else if (neenacaj == 4) izjava = (izraz1 < izraz2);
				else izjava = (izraz1 > izraz2);
				if (!izjava) pozicija = nova_pozicija;
			}
			else if (ukaz == 2) {
				int index = KodeMakrov.at(indeksMakra).at(pozicija++);
				if (index >= (int)spremenljivke.size())
					spremenljivke.resize(index + 1);
				double izraz;
				int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, izraz);
				if (koda != 0) return koda;
				spremenljivke.at(index) = izraz;
			}
			else if (ukaz == 3) {
				std::vector<double> podatki;
				for (int i = 0; i < 12; i++) {
					double izraz;
					int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, izraz);
					if (koda != 0) return koda;
					podatki.push_back(izraz);
					if (i >= 9 && (izraz > 1 || izraz < 0)) return 1006;
				}
				Grafika::NarisiTrikotnik(podatki.at(0), podatki.at(1), podatki.at(2),
					podatki.at(3), podatki.at(4), podatki.at(5),
					podatki.at(6), podatki.at(7), podatki.at(8),
					podatki.at(9), podatki.at(10), podatki.at(11));
			}
			else {
				int index = KodeMakrov.at(indeksMakra).at(pozicija++);
				int st_arg = KodeMakrov.at(indeksMakra).at(pozicija++);
				std::vector<double> podatki;
				for (int i = 0; i < st_arg; i++) {
					double izraz;
					int koda = Izracunaj(indeksMakra, pozicija, spremenljivke, izraz);
					if (koda != 0) return koda;
					podatki.push_back(izraz);
				}
				int napaka;
				int koda = Izvedi(index, podatki, napaka);
				if (koda != 0) {
					indeksNapake = napaka;
					return koda;
				}
			}
		}
		return 0;
	}
}

bool ShraniBMP() {
	std::fstream datoteka;
	datoteka.open(Nastavitve::Dir::IzhodnaDat, std::ios::out | std::ios::binary);
	if (!datoteka.is_open()) return false;
	char a[54];
	a[0] = 'B';
	a[1] = 'M';
	for (int i = 2; i < 10; i++) a[i] = 0;
	a[10] = 54;
	for (int i = 11; i < 14; i++) a[i] = 0;
	a[14] = 40;
	for (int i = 15; i < 18; i++) a[i] = 0;
	a[18] = Podatki::Sirina % 256;
	a[19] = Podatki::Sirina / 256;
	a[20] = 0;
	a[21] = 0;
	a[22] = Podatki::Visina % 256;
	a[23] = Podatki::Visina / 256;
	a[24] = 0;
	a[25] = 0;
	a[26] = 1;
	a[27] = 0;
	a[28] = 24;
	for (int i = 29; i < 54; i++) a[i] = 0;
	datoteka.write(a, 54);
	char* vrstica = new char[Podatki::Sirina * 3 + 3];
	int kolicina = Podatki::Sirina * 3;
	while (kolicina % 4 != 0) vrstica[kolicina++] = 0;
	for (int j = 0; j < Podatki::Visina; j++) {
		for (int i = 0; i < Podatki::Sirina; i++) {
			int lokacija = i + j * Podatki::Sirina;
			int rint = (int)(round(Podatki::Tabela.at(lokacija).R * 255) + 0.1);
			int gint = (int)(round(Podatki::Tabela.at(lokacija).G * 255) + 0.1);
			int bint = (int)(round(Podatki::Tabela.at(lokacija).B * 255) + 0.1);
			vrstica[3 * i] = bint;
			vrstica[3 * i + 1] = gint;
			vrstica[3 * i + 2] = rint;
		}
		datoteka.write(vrstica, kolicina);
	}
	delete[] vrstica;
	datoteka.close();
	return true;
}

// Izvede celotno proceduro: nastavi podatke, sparsa makre in jih pozene.
// kodaNapake: vrstica napake pri parserju, sicer nima vloge
// imeMakra: ime makra, kjer je prislo do napake pri parserju/eksekutorju
// return: koda napake, t. j. ena od zgoraj nastetih v parserju in eksekutorju ali:
//
// 2000 neveljavno ime vhodne datoteke - imeti mora koncnico txt
// 3000 napaka pri pisanju v izhodno datoteko
int Pozeni(int& vrsticaNapake, std::string& imeMakra) {
	std::string imeVhodne = Nastavitve::Dir::VhodnaDat;
	std::size_t pozicija = imeVhodne.find_last_of('\\');
	if (pozicija != std::string::npos)
		imeVhodne = imeVhodne.substr(pozicija + 1); // rabim samo v primeru napake
	Podatki::Inicializiraj();
	Eksekutor::ImenaMakrov.clear();
	Eksekutor::StevilaArgumentov.clear();
	Eksekutor::KodeMakrov.clear();
	int kodaNapake = Parser::ParsajDatoteko(Eksekutor::ImenaMakrov, Eksekutor::StevilaArgumentov, Eksekutor::KodeMakrov, vrsticaNapake, imeMakra);
	if (kodaNapake != 0) {
		if (imeMakra == "") imeMakra = imeVhodne;
		else imeMakra += ".txt";
		return kodaNapake;
	}
	std::vector<double> args;
	int index;
	kodaNapake = Eksekutor::Izvedi(0, args, index);
	if (kodaNapake != 0) {
		if (index == 0) imeMakra = imeVhodne;
		else imeMakra = Eksekutor::ImenaMakrov.at(index) + ".txt";
		return kodaNapake;
	}
	if (!ShraniBMP()) return 3000;
	return 0;
}