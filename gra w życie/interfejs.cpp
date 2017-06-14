#include "interfejs.h"

//gra w zycie
interfejs::interfejs(void)
{	tlo=NULL;
	bufor=NULL;
	bufor2=NULL;
	bufor3=NULL;
	mmenu=NULL;
	dzwiek=NULL;
	kroki=0;
	px=35;
	py=75;
	jaki=0;
	szer=15;
	u=0;
	m_dzwiek=1;
	kratki=1;
	caret = 0;
	
	
	
	
}
void interfejs::inicjuj()
{	
	
	allegro_init();  
	set_window_title("Gra w zycie");
    set_color_depth(32); 
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0); 


	install_mouse(); 
	show_mouse(screen); 
	install_keyboard();

  
	unscare_mouse();

	
	
	bufor = create_bitmap(1024,600); 
		if (!bufor) 
			{ 
				set_gfx_mode(GFX_TEXT,0,0,0,0); 
				allegro_message("Nie mogê utworzyæ bufora !"); 
				allegro_exit(); 
				
			} 
	bufor2 = create_bitmap(1024,600); 
		if (!bufor2) 
			{ 
				set_gfx_mode(GFX_TEXT,0,0,0,0); 
				allegro_message("Nie mogê utworzyæ bufora 2 !"); 
				allegro_exit(); 
				 
			} 
	bufor3 = create_bitmap(1024,600); 
		if (!bufor3)
			{ 
				set_gfx_mode(GFX_TEXT,0,0,0,0); 
				allegro_message("Nie mogê utworzyæ bufora 3 !"); 
				allegro_exit(); 
				
			} 
	tlo = load_bmp("tlo.bmp",default_palette); 
		if (!tlo) 
			{ 
				set_gfx_mode(GFX_TEXT,0,0,0,0); 
				allegro_message("Nie mogê za³adowaæ obrazka tla !"); 
				allegro_exit(); 
				 
			} 
	mmenu = load_bmp("mmenu.bmp",default_palette);
		if (!mmenu) 
			{ 
				set_gfx_mode(GFX_TEXT,0,0,0,0); 
				allegro_message("Nie mogê za³adowaæ obrazka mmenu !"); 
				allegro_exit(); 
				 
			} 
	blit( tlo, screen, 0,0, 0,0, tlo->w, tlo->h);

	blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
			
			rysujLinie();
				z.sprawdzLiczbeZywych();
				textprintf_ex(bufor3,font,520,500,makecol(254,1,1),-1,"Liczba cykli= %d",  kroki); 
				textprintf_ex(bufor3,font,520,510,makecol(254,1,1),-1,"Liczba zywych komorek= %d" ,z.komorki);
			buforuj();
			
			instalujDzwiek();


}
void interfejs::instalujDzwiek()
{
install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,""); 
set_volume(255,255);

dzwiek = load_sample("Burly_Brawl_001.wav"); 
if (!dzwiek) 
{ 
  set_gfx_mode(GFX_TEXT,0,0,0,0); 
  allegro_message("Nie moge zaladowac dzwieku !"); }


}

void interfejs::buforuj()
{
	
	blit( bufor3, bufor2, 0,0, 0,0, bufor3->w,bufor3->h);

	blit( bufor2, bufor, 0,0, 0,0, bufor2->w,bufor2->h);
	 
	blit( bufor, screen, 0,0, 0,0, bufor->w, bufor->h); 
	
	
}

void interfejs::rysujLinie()
{

	if(kratki==1)
	{for(i=0;i<(480/szer);i++)
			{hline(bufor3, 35, py+i*szer, 515, makecol(0,0,0));		//linie pionowe//bitmapa, X, Y1, Y2, numer koloru
			vline(bufor3, px+i*szer, 75, 555, makecol(0,0,0));		//linie pozioma//bitmapa, X1, Y, X2, numer koloru
			}
	}	
			
}
void interfejs::rysujPlansze()
{
				//blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				
				z.sprawdzLiczbeZywych();
				textprintf_ex(bufor3,font,520,500,makecol(254,1,1),-1,"Liczba cykli= %d" , kroki);
				textprintf_ex(bufor3,font,520,510,makecol(254,1,1),-1,"Liczba zywych komorek= %d" ,z.komorki);
				z.komorki=0;
				for( i=0; i< z.rozmiar; i++)
					if (z.pole[i]==1)
						{
							xp=(i%z.kolumny)*szer + px+1;// obliczamy wspó³rzêdne
							xk=xp+szer-2;// kwadracika
							yp=(i/z.kolumny)*szer + py+1;// który ma
							yk=yp+szer-2;//sie zapalic
					
					rectfill(bufor3, xp, yp, xk, yk, makecol(254,254,1)); // rysujemy kwadracik
							
				}
				
	rysujLinie();

}



void interfejs::obslugaPola()
{
if ((mouse_x > 35)&&(mouse_x < 515)&&(mouse_y > 75)&& (mouse_y < 555))// jeœli najechaliœmy na plansze
			{
				if(mouse_b==1)// i kliknelismy LPM to
				{ i= ((mouse_x - px)/szer)+((mouse_y - py)/szer)*z.kolumny;// obliczamy index w tabeli obliczen
				  z.pole[i]=1;// ustawiamy wartosc 1 w polu o indexie i
				}
				else if(mouse_b==2)// i kliknelismy PPM to
				{ i= ((mouse_x - px)/szer)+((mouse_y - py)/szer)*z.kolumny;// obliczamy index w tabeli obliczen
				  z.pole[i]=0;// ustawiamy wartosc 0 w polu o indexie i
				}
			}


}

void interfejs::start()
{	if(m_dzwiek==1)play_sample(dzwiek, 255,127,1000,1); 
	while(!((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >140)&&(mouse_y<180)&&(mouse_b==1)&&(u==0)))//dopóki nie wciœniemy stop
	{	
		
		
		blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
		z.obliczTure();
		obslugaPola();
		rysujPlansze();
		kroki++;
		buforuj();
		rest(100);
	
			if((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >517)&&(mouse_y<558)&&(mouse_b==1)&&(u==0))zakoncz();
			if ( (mouse_x > 798)&&(mouse_x < 978) && (mouse_y > 275) &&(mouse_y < 315) && (mouse_b==1)&&(u==0))//jeœli wciœniemy czyœæ
			{	
				stop_sample(dzwiek);
				rest(200);
				allegro_message("Nie mozna uzyc tego przycisku podczas trwania symulacji ");
				if(m_dzwiek==1)play_sample(dzwiek, 255,127,1000,1);
			}
		if ((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >343)&&(mouse_y<383)&&(mouse_b==1)&&(u==0)) 
			{	
				stop_sample(dzwiek);
				rest(200);
				allegro_message("Nie mozna uzyc tego przycisku podczas trwania symulacji  ");
				if(m_dzwiek==1)play_sample(dzwiek, 255,127,1000,1);
			}// jeœli wciœniemy ustawienia
		if ((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >207)&&(mouse_y<247)&&(mouse_b==1)&&(u==0))
		{	
				stop_sample(dzwiek);
				rest(200);
				allegro_message("Nie mozna uzyc tego przycisku podczas trwania symulacji  ");
				if(m_dzwiek==1)play_sample(dzwiek, 255,127,1000,1);
			}//krok
	
		if(z.identyczne==z.rozmiar)
		{	stop_sample(dzwiek);
			rest(200);
			allegro_message("Zycie juz nie ewulouje - zakonczenie symulacji");
			rysujPlansze();
			buforuj();
			
			break;
		
		}
	}
	stop_sample(dzwiek);
	kroki=0;
	begin();
}
void interfejs::krok()
{
		
		
		blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
		z.obliczTure();
		rysujPlansze();
		kroki++;
		buforuj();
		while(mouse_b==1);

}
void interfejs::czysc()
{
	z.czysc();
	blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
	kroki=0;
	begin();
	while(mouse_b==1);
	
	

}

void interfejs::ustawienia()
{	u=1;
	blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
informacje();
	buforuj();
		

	while(!((mouse_x > 570)&&(mouse_x<750)&&(mouse_y >545)&&(mouse_y<585)&&(mouse_b==1)&&(u==1)))//dopóki nie wciœniemy wstecz
	{		 
			if ((mouse_x > 525)&&(mouse_x<575)&&(mouse_y >65)&&(mouse_y<105)&&(mouse_b==1)&&(u==1))//rozmieœæ 10% losowo
			{	z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(1);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
				
			}
			if ((mouse_x > 580)&&(mouse_x<630)&&(mouse_y >65)&&(mouse_y<105)&&(mouse_b==1)&&(u==1))
			{
				z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(2);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
			}
			if ((mouse_x > 635)&&(mouse_x<685)&&(mouse_y >65)&&(mouse_y<105)&&(mouse_b==1)&&(u==1))
			{	z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(3);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
			while(mouse_b==1);}
			if ((mouse_x > 690)&&(mouse_x<740)&&(mouse_y >65)&&(mouse_y<105)&&(mouse_b==1)&&(u==1))
			{	z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(4);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
			while(mouse_b==1);}
			if ((mouse_x > 745)&&(mouse_x<795)&&(mouse_y >65)&&(mouse_y<105)&&(mouse_b==1)&&(u==1))
			{z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(5);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
			while(mouse_b==1);}
			if ((mouse_x > 555)&&(mouse_x<605)&&(mouse_y >110)&&(mouse_y<150)&&(mouse_b==1)&&(u==1))
			{z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(6);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
				}
			if ((mouse_x > 610)&&(mouse_x<660)&&(mouse_y >110)&&(mouse_y<150)&&(mouse_b==1)&&(u==1))
			{	z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(7);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
				}
			if ((mouse_x > 665)&&(mouse_x<715)&&(mouse_y >110)&&(mouse_y<150)&&(mouse_b==1)&&(u==1))
			{	z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(8);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
			while(mouse_b==1);}
			if ((mouse_x > 720)&&(mouse_x<770)&&(mouse_y >110)&&(mouse_y<150)&&(mouse_b==1)&&(u==1))
			{z.czysc();
				blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
				z.losuj(9);
				rysujPlansze();
				
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
					while(mouse_b==1);
				}
			if ((mouse_x > 582)&&(mouse_x<631)&&(mouse_y >221)&&(mouse_y<259)&&(mouse_b==1)&&(u==1))//zwieksz skale
			{	
				jaki=jaki+1;
				if(jaki>6)jaki=6;
				rozmiar(jaki);
				z.czysc();
				blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
				rysujPlansze();
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				
				
		while(mouse_b==1);
				
				
			}
			if ((mouse_x > 630)&&(mouse_x<670)&&(mouse_y >221)&&(mouse_y<259)&&(mouse_b==1)&&(u==1))//zmniejsz skale
			{
				jaki=jaki-1;
				if(jaki<-8)jaki=-8;
				rozmiar(jaki);
				z.czysc();
				blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
				rysujPlansze();
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
			

				while(mouse_b==1);
				
			
			}
			if ((mouse_x > 680)&&(mouse_x<720)&&(mouse_y >221)&&(mouse_y<259)&&(mouse_b==1)&&(u==1))
			{	
				kratki=!kratki;
				blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
				rysujPlansze();
				blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
			
			}
	if ((mouse_x > 545)&&(mouse_x<635)&&(mouse_y >305)&&(mouse_y<328)&&(mouse_b==1)&&(u==1))
	{	m_dzwiek=1;
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
	}
	if ((mouse_x > 647)&&(mouse_x<740)&&(mouse_y >305)&&(mouse_y<328)&&(mouse_b==1)&&(u==1))
	{
		m_dzwiek=0;
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
				informacje();
				buforuj();
				while(mouse_b==1);
	}
	/*
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >392)&&(mouse_y<405)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.natura();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	}
	
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >409)&&(mouse_y<422)&&(mouse_b==1)&&(u==1))
	{	z.czysc();
		z.kreseczki();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	}
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >426)&&(mouse_y<439)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.statki();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	
	
	}
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >444)&&(mouse_y<457)&&(mouse_b==1)&&(u==1))
	{	z.czysc();
		z.pulsacja();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	
	
	}
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >463)&&(mouse_y<476)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.zyrafa();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	
	
	}
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >480)&&(mouse_y<493)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.galactic();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	
	}
	if ((mouse_x > 539)&&(mouse_x<551)&&(mouse_y >499)&&(mouse_y<512)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.krokodyl();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);
	
	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >392)&&(mouse_y<405)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.fontanna();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);

	
	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >409)&&(mouse_y<422)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.cos_2();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);

	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >425)&&(mouse_y<438)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.gwiazdka();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);

	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >444)&&(mouse_y<457)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.zegar();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);

	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >462)&&(mouse_y<475)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.cos_1();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();
		while(mouse_b==1);

	
	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >480)&&(mouse_y<493)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.wystrzal();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();	
		while(mouse_b==1);

	}
	if ((mouse_x > 675)&&(mouse_x<687)&&(mouse_y >499)&&(mouse_y<512)&&(mouse_b==1)&&(u==1))
	{
		z.czysc();
		z.engine();
		blit(tlo,bufor3,0,0,0,0,tlo->w,tlo->h);
		rysujPlansze();
		blit(mmenu,bufor3,0,0,520,0,mmenu->w,mmenu->h);
		informacje();
		buforuj();	
		while(mouse_b==1);

	
	}
	*/									
}	
	while(mouse_b==1);
	
	u=0;
	begin();
}
void interfejs::begin()
{
	while(!((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >517)&&(mouse_y<558)&&(mouse_b==1)&&(u==0)))//dopóki nie wciœniemy zakoñcz
	{
		obslugaPola();
		blit( tlo, bufor3, 0,0, 0,0, tlo->w, tlo->h);
		rysujPlansze();
		buforuj();
		if ( (mouse_x > 798)&&(mouse_x < 978) && (mouse_y > 73) &&(mouse_y < 114)&&(mouse_b==1)&&(u==0))start();//jeœli wciœniemy start
		if ((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >207)&&(mouse_y<247)&&(mouse_b==1)&&(u==0))krok();//krok
		if ( (mouse_x > 798)&&(mouse_x < 978) && (mouse_y > 275) &&(mouse_y < 315) && (mouse_b==1)&&(u==0))czysc();//jeœli wciœniemy czyœæ
		if ((mouse_x > 798)&&(mouse_x<978)&&(mouse_y >343)&&(mouse_y<383)&&(mouse_b==1)&&(u==0)) ustawienia();// jeœli wciœniemy ustawienia
		if ((mouse_x > 580)&&(mouse_x<732)&&(mouse_y >169)&&(mouse_y<238)&&(mouse_b==1)&&(u==0)) odczyt();
		if ((mouse_x > 580)&&(mouse_x<732)&&(mouse_y >276)&&(mouse_y<345)&&(mouse_b==1)&&(u==0)) zapisz();
	
	}

}
void interfejs::wyswietl()
{
	int n=0,c=0;
	char p;




ifstream plik;
    plik.open("pom.pom");

    if(!plik)
            {
        rest(200);
            allegro_message("blad danych");
            }
    else
    {
   while(plik.good())
    {
		
        
      p=plik.get();
			n+=10;
       
		if(p=='.')
		{
			for(int i=0;i<5;i++)
				p=plik.get();
			n=0;
			c+=10;
		}
		
		if(p!=0x0a)
	
	
	textprintf_ex(screen,font,535+n,350+c,makecol(0,0,0),-1,"%c",p);	
}
	

plik.close();
    }
	
}

void interfejs::wczytaj()

{
	
		

    wyraz.clear();
    string::iterator iter = wyraz.begin();
    int caret = 0;
    bool insert = true;

    do
    {
       
        while( keypressed() )
        {
            int newkey = readkey();
            char ASCII = newkey & 0xff;
            char scancode = newkey >> 8;
            if( ASCII >= 32 && ASCII <= 126 )
            {
                if( insert || iter == wyraz.end() )
                     iter = wyraz.insert( iter, ASCII );
                else
                     wyraz.replace( caret, 1, 1, ASCII );
               
                caret++;
                iter++;
            } else
            switch( scancode )
            {
            case KEY_BACKSPACE:
                if( iter != wyraz.begin() )
                {
                    caret--;
                    iter--;
                    iter = wyraz.erase( iter );
					buforuj();
                }
                break;
               
            }
        }
         textout_ex( screen, font, wyraz.c_str(), 580, 260, makecol( 0, 0, 0 ), - 1 );
    } while( !key[ KEY_ENTER ] );

   wyraz+=".life";

}
void interfejs::zapisz()
{		
		
		wczytaj();	
		z.zapiszDane(wyraz.c_str());
		buforuj();
		while(mouse_b==1);
		

}

void interfejs::odczyt()
{		
	
		
		z.czysc();
		wyswietl(); 
		wczytaj();
		z.odczytajDane(wyraz.c_str());
		//buforuj();
		while(mouse_b==1);
	
}

void interfejs::rozmiar(int jaki)
{		if(jaki==-8) 
	{	
		szer=60;
		z.kolumny=8;
		z.rozmiar=8*8;
		z.ustalPole();
	}
	
		if(jaki==-7) 
	{	
		szer=48;
		z.kolumny=10;
		z.rozmiar=10*10;
		z.ustalPole();
	}
	if(jaki==-6) 
	{	
		szer=40;
		z.kolumny=12;
		z.rozmiar=12*12;
		z.ustalPole();
	}
	if(jaki==-5) 
	{	szer=32;
		z.kolumny=15;
		z.rozmiar=15*15;
		z.ustalPole();
	}
	if(jaki==-4) 
	{szer=30;
		z.kolumny=16;
		z.rozmiar=16*16;
		z.ustalPole();
	}
	if(jaki==-3) 
	{szer=24;
		z.kolumny=20;
		z.rozmiar=20*20;
		z.ustalPole();
	}
	if(jaki==-2) 
	{szer=20;
		z.kolumny=24;
		z.rozmiar=24*24;
		z.ustalPole();
	}
	if(jaki==-1) 
	{szer=16;
		z.kolumny=30;
		z.rozmiar=30*30;
		z.ustalPole();
	}
	if(jaki==0) 
	{szer=15;
		z.kolumny=32;
		z.rozmiar=32*32;
		z.ustalPole();
	}
	if(jaki==1) 
	{szer=12;
		z.kolumny=40;
		z.rozmiar=40*40;
		z.ustalPole();
	
	}
	if(jaki==2) 
	{	szer=10;
		z.kolumny=48;
		z.rozmiar=48*48;
		z.ustalPole();

	}
	if(jaki==3) 
	{szer=8;
		z.kolumny=60;
		z.rozmiar=60*60;
		z.ustalPole();

	}
	if(jaki==4) 
	{szer=6;
		z.kolumny=80;
		z.rozmiar=80*80;
		z.ustalPole();
	
	}
	if(jaki==5) 
	{	szer=5;
		z.kolumny=96;
		z.rozmiar=96*96;
		z.ustalPole();
	
	}
	if(jaki==6) 
	{	
		szer=4;
		z.kolumny=120;
		z.rozmiar=120*120;
		z.ustalPole();
	
	}
}


void interfejs::zakoncz()
{					if(m_dzwiek==1)
					{
						stop_sample(dzwiek);
					rest(200);}
					allegro_message("Aby zakonczyc kliknij OK!");
					destroy_bitmap(tlo); // zwalniamy pamiêæ zajêt¹ przez tlo
					destroy_bitmap(bufor); // to samo dla bufora
					destroy_bitmap(bufor2);
					destroy_bitmap(bufor3);
					destroy_bitmap(mmenu);
					destroy_sample(dzwiek);

						 
					allegro_exit(); // funkcja wy³¹cza bibliotekê allegro*/
					exit(0);


}
void interfejs::informacje()
{
				textprintf_ex(bufor3,font,605,193,makecol(0,0,0),-1," %d ", z.kolumny); 
				textprintf_ex(bufor3,font,647,193,makecol(0,0,0),-1," %d ", z.kolumny);
				if(m_dzwiek==0)textprintf_ex(bufor3,font,655,344,makecol(0,0,0),-1," wylaczony"); 
				if(m_dzwiek==1)textprintf_ex(bufor3,font,655,344,makecol(0,0,0),-1," wlaczony" ); 
				
				
}



interfejs::~interfejs(void)
{
}
