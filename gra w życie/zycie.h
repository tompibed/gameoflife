#pragma once
#include <iostream>
#include "Include\allegro.h"
#include <time.h>
#include <fstream>
#include <string>
//#include <dirent.h>



using namespace std;

class zycie
{public:
	int kolumny ;
	int rozmiar;
	int moja_liczba;
	int* pole ;
	int* poprz;
	int* nast ;
	long int x; 
	int c,d,identyczne,n;
	volatile long int komorki;
	bool jestPoprawny(int i);
	bool jestLewy(int i);
	bool jestPrawy(int i);
	void obliczTure();
	void czysc ();
	char e,str[256];
	void odczytajDane(const char* );
	void zapiszDane(const char*);
	
	/*void natura();
	void kreseczki();
	void statki();
	void pulsacja();
	void zyrafa();
	void galactic();
	void krokodyl();
	void cos_1();
	void zegar();
	void fontanna();
	void gwiazdka();
	void cos_2();
	void wystrzal();
	void engine();
	*/
	void losuj(int);
	void ustalPole();

	int sprawdzLiczbeZywych();
	zycie(void);
	~zycie(void);
	
};
