#pragma once
#include"zycie.h"


class interfejs
{
public:

	BITMAP *bufor;
	BITMAP *bufor2;
	BITMAP *bufor3;
	BITMAP *tlo ;
	BITMAP *mmenu;
	SAMPLE *dzwiek;
	
	int u;
	bool m_dzwiek;
	bool kratki;
	zycie z;
	volatile long int kroki;
	int i,xp,xk,yp,yk,px,py,yy,xx;
	int szer,jaki;
	void inicjuj();
	void obslugaPola();
	void rysujPlansze();
	void buforuj();
	void zakoncz();
	void rozmiar(int);
	void ustawienia();
	void rysujLinie();
	void begin();
	void start();
	void czysc();
	void krok();
	void instalujDzwiek();
	void informacje();
	void zapisz();
	void odczyt();
	void wczytaj();
	string wyraz;
	int caret;
    bool insert;
	int newkey;
	char ASCII;
	char scancode;
	void wyswietl();


string nazwa;



	interfejs(void);
	~interfejs(void);
};
