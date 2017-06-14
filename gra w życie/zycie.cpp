#include "zycie.h"
		
zycie::zycie(void)
{
	kolumny=32;
	rozmiar=1024; 
	pole = new int[rozmiar];
	nast = new int[rozmiar];
	poprz =new int[rozmiar];
	czysc();
	komorki=0;
	d=0;
	identyczne=0;
	moja_liczba = 0;

	
	
}

bool zycie::jestPoprawny(int i)
{
        return ((i > 0) && (i < rozmiar));// sprawdzamy czy indeks jest poprawny i nie wykracza poza okreslony przez nas rozmiar tab,jezeli jest poprawny zwroci wartosc TRUE
}

bool zycie::jestLewy(int i)
{
        return ((i% kolumny) == 0);// sprawdzamy czy jest lewy, jesli jest lewy to wynikiem dzialania numer_indeksu modulo ilosc_kolumn zawsze jest 0, zwroci wartosc 1 (TRUE/PRAWDA)
}

bool zycie::jestPrawy(int i)

{
        return ((i% kolumny) == kolumny-1);// sprawdzamy czy jest prawy
}

void zycie::obliczTure() 
{	identyczne=0;
	

    for(int i = 0; i< rozmiar; i++)
    {
		if(pole[i] && jestPoprawny(i-kolumny-1) && !jestLewy(i))//jesli pole pod wskazanym indeksem zyje(pali sie), pole wiersz nizej po skosie w lewno istnieje(nie wykracza poza rozmiar tabeli) i nie jest ono krawedzia
            nast[i-kolumny-1]++;
		if(pole[i] && jestPoprawny(i-kolumny))//pole pod spodem nie wykracza poza zakres
            nast[i-kolumny]++;
		if(pole[i] && jestPoprawny(i-kolumny+1) && !jestPrawy(i))
            nast[i-kolumny+1]++;

		if(pole[i] && jestPoprawny(i-1) && !jestLewy(i))
            nast[i-1]++;
		if(pole[i] && jestPoprawny(i+1) && !jestPrawy(i))
            nast[i+1]++;

		if(pole[i] && jestPoprawny(i+kolumny-1) && !jestLewy(i))
            nast[i+kolumny-1]++;
		if(pole[i] && jestPoprawny(i+kolumny))
            nast[i+kolumny]++;
		if(pole[i] && jestPoprawny(i+kolumny+1) && !jestPrawy(i))
            nast[i+kolumny+1]++;
		poprz[i]=pole[i];
		
    }
    for(int i = 0; i<rozmiar; i++)
    {
        if(nast[i] == 3)
            pole[i] = 1;
        else if(nast[i] == 2 && pole[i] == 1)
           ;
        else
            pole[i] = 0;
        nast[i] = 0;
		
		
		
		
    }
	for(int i=0;i<rozmiar;i++)if(((poprz[i]==0)&&(pole[i]==0))||((poprz[i]==1)&&(pole[i]==1)))identyczne++;//ile ewoluowalo
	
		
	
}

void zycie::czysc()
{	
	
	for( int i=0; i<rozmiar; i++)
	{	pole[i]=0;
		
		nast[i]=0;
	}
}

void zycie::losuj(int ile)
{

int komorek=(rozmiar/10)*ile;//ilosc komorek ktora ma stac sie zywa
int* tab = new int[rozmiar]; //dynamiczna alokacja pamieci, do przechowywanie indeksow pol, ktore maja stac sie zywe
				 
                // Inicjuje generator liczb pseudolosowych 
				srand( (unsigned)time( NULL ) ); 
                               // Wyœwietla iles losowych liczb 
                               // z przedzialu 0...limit 
					for( c = 0; c < komorek;c++ ) 
						{ 
							  do 
								  { 
									 do 
										 { 
											x=(rozmiar*rand())/0x7fff ;//oblicznie indeksu kolejnej
										 } 
	
					while(x<0||x>rozmiar); 
						for(d=0; d<c; d++) 
						 if(tab[d]==x) 
							 break; 
					 } 
					 while(tab[d]==x&&c); 
					  tab[c]=x; //nie-umiesc wartosc w pomocniczej tab
					 pole[x]=1;
			
			
				}
					delete [] tab;
					
			}






void zycie::zapiszDane(const char* s) 


	
	{
		std::ofstream plik(s,ios::out);
 

		
 for( int i=0; i<rozmiar; i++)
		{
  
if(pole[i]==1) plik<<i<<endl; 
		}

plik.close(); 
 
			 
	}



void zycie::odczytajDane(const char* str)
{
	ifstream config;
	config.open(str);

	if(!config)
	{
		rest(200);
			allegro_message("plik o podanej nazwie nie istnieje");
	}
	else
	{
	while(config.good())
	{
		e=config.get();
		if(config.good())
		{
			if(e == 0x0a)
			{
				pole[moja_liczba]=1;
				moja_liczba=0;
				continue;
			}

			moja_liczba = (e > 0x29 && e < 0x3A) ? moja_liczba*10+e-0x30 : moja_liczba;
		}	
	}
config.close();
}
}



/*void zycie::natura()
{	
	czysc();
	pole[(3kolumny+25)]=1;
	pole[(4kolumny+26)]=1;
	pole[(4kolumny+24)]=1;
	pole[(5kolumny+26)]=1;
	pole[(5kolumny+23)]=1;
	pole[(6kolumny+25)]=1;
	pole[(6kolumny+24)]=1;
	pole[(5kolumny+8)]=1;
	pole[(6kolumny+7)]=1;
	pole[(6kolumny+9)]=1;
	pole[(7kolumny+7)]=1;
	pole[(7kolumny+9)]=1;
	pole[(8kolumny+8)]=1;
	pole[(12kolumny+15)]=1;
	pole[(13kolumny+14)]=1;
	pole[(13kolumny+16)]=1;
	pole[(14kolumny+15)]=1;
	pole[(13kolumny+5)]=1;
	pole[(13kolumny+6)]=1;
	pole[(14kolumny+5)]=1;
	pole[(14kolumny+6)]=1;
	pole[(16kolumny+27)]=1;
	pole[(16kolumny+26)]=1;
	pole[(17kolumny+28)]=1;
	pole[(17kolumny+26)]=1;
	pole[(18kolumny+28)]=1;
	pole[(18kolumny+27)]=1;
	pole[(22kolumny+6)]=1;
	pole[(22kolumny+7)]=1;
	pole[(23kolumny+5)]=1;
	pole[(23kolumny+8)]=1;
	pole[(24kolumny+5)]=1;
	pole[(24kolumny+8)]=1;
	pole[(25kolumny+6)]=1;
	pole[(25kolumny+7)]=1;
	pole[(23kolumny+19)]=1;
	pole[(23kolumny+20)]=1;
	pole[(24kolumny+18)]=1;
	pole[(24kolumny+20)]=1;
	pole[(25kolumny+19)]=1;





	if(kolumny<30)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 30 X 30 !");
	czysc();
	}

}
void zycie::kreseczki()
{
	czysc();
	//kreska 3
	pole[(2*kolumny+3)]=1;
	pole[(2*kolumny+4)]=1;
	pole[(2*kolumny+5)]=1;
	//kreska 4
	pole[(6*kolumny+8)]=1;
	pole[(6*kolumny+9)]=1;
	pole[(6*kolumny+10)]=1;
	pole[(6*kolumny+11)]=1;
	//kreska 5
	pole[(12*kolumny+12)]=1;
	pole[(12*kolumny+13)]=1;
	pole[(12*kolumny+14)]=1;
	pole[(12*kolumny+15)]=1;
	pole[(12*kolumny+16)]=1;
	//kreska 7
	pole[(22*kolumny+19)]=1;
	pole[(22*kolumny+20)]=1;
	pole[(22*kolumny+21)]=1;
	pole[(22*kolumny+22)]=1;
	pole[(22*kolumny+23)]=1;
	pole[(22*kolumny+24)]=1;
	pole[(22*kolumny+25)]=1;

	if(kolumny<30)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 30 X 30 !");
	czysc();
	}

}

void zycie::statki()
{
	czysc();
	//statek duzy
	pole[kolumny-3]=1;
	pole[kolumny-4]=1;
	pole[2*kolumny-1]=1;
	pole[2*kolumny-6]=1;
	pole[3*kolumny-7]=1;
	pole[4*kolumny-1]=1;
	pole[4*kolumny-7]=1;
	pole[5*kolumny-2]=1;
	pole[5*kolumny-3]=1;
	pole[5*kolumny-4]=1;
	pole[5*kolumny-5]=1;
	pole[5*kolumny-6]=1;
	pole[5*kolumny-7]=1;
	//statek sredni
	pole[10*kolumny-3]=1;
	pole[11*kolumny-1]=1;
	pole[11*kolumny-5]=1;
	pole[12*kolumny-6]=1;
	pole[13*kolumny-1]=1;
	pole[13*kolumny-6]=1;
	pole[14*kolumny-2]=1;
	pole[14*kolumny-3]=1;
	pole[14*kolumny-4]=1;
	pole[14*kolumny-5]=1;
	pole[14*kolumny-6]=1;
	//statek maly->glider
	pole[19*kolumny-1]=1;
	pole[19*kolumny-4]=1;
	pole[20*kolumny-5]=1;
	pole[21*kolumny-1]=1;
	pole[21*kolumny-5]=1;
	pole[22*kolumny-2]=1;
	pole[22*kolumny-3]=1;
	pole[22*kolumny-4]=1;
	pole[22*kolumny-5]=1;

if(kolumny<24)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 24 X 24 !");
	czysc();
	}

}

void zycie::pulsacja()
{
	czysc();
	pole[(kolumny/2)*kolumny+(kolumny/2)-1]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+2]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-3]=1;

if(kolumny<16)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 16 X 16 !");
	czysc();
	}

}

void zycie::zyrafa()
{
	czysc();
	pole[(kolumny-1)*kolumny+1]=1;
	pole[(kolumny-1)*kolumny+3]=1;
	pole[(kolumny-1)*kolumny+4]=1;
	pole[(kolumny-2)*kolumny+1]=1;
	pole[(kolumny-2)*kolumny+2]=1;
	pole[(kolumny-2)*kolumny+3]=1;
	pole[(kolumny-2)*kolumny+4]=1;
	pole[(kolumny-3)*kolumny+1]=1;
	pole[(kolumny-3)*kolumny+2]=1;
	pole[(kolumny-3)*kolumny+3]=1;
	pole[(kolumny-3)*kolumny+4]=1;
	pole[(kolumny-3)*kolumny+5]=1;
	pole[(kolumny-4)*kolumny+6]=1;
	pole[(kolumny-5)*kolumny+7]=1;
	pole[(kolumny-6)*kolumny+8]=1;
	pole[(kolumny-7)*kolumny+9]=1;
	pole[(kolumny-8)*kolumny+10]=1;
	pole[(kolumny-9)*kolumny+11]=1;
	pole[(kolumny-10)*kolumny+12]=1;
	pole[(kolumny-11)*kolumny+13]=1;
	pole[(kolumny-12)*kolumny+14]=1;
	pole[(kolumny-13)*kolumny+15]=1;
	pole[(kolumny-14)*kolumny+16]=1;
	pole[(kolumny-15)*kolumny+17]=1;
	pole[(kolumny-16)*kolumny+18]=1;
	pole[(kolumny-17)*kolumny+19]=1;
	pole[(kolumny-18)*kolumny+20]=1;
	pole[(kolumny-19)*kolumny+21]=1;
	pole[(kolumny-20)*kolumny+22]=1;
	pole[(kolumny-21)*kolumny+23]=1;
	pole[(kolumny-22)*kolumny+24]=1;
	pole[(kolumny-23)*kolumny+25]=1;
	pole[(kolumny-23)*kolumny+27]=1;
	pole[(kolumny-24)*kolumny+26]=1;
	pole[(kolumny-24)*kolumny+27]=1;
	
if(kolumny<30)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 30 X 30 !");
	czysc();
	}
}
void zycie::galactic()
{
	czysc();
	pole[(kolumny/2)*kolumny+(kolumny/2)+2]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+3]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)+3]=1;

		if(kolumny<15)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 15 X 15 !");
	czysc();
	}
}

void zycie::krokodyl()
{
	czysc();
	pole[(kolumny/2)*kolumny+(kolumny/2)-4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-5]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-6]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+3]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+5]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+4]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+4]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-4]=1;

		if(kolumny<16)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 16 X 16 !");
	czysc();
	}
}
void zycie::fontanna()
{
	czysc();
	
	pole[(kolumny/2)*kolumny+(kolumny/2)-1]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-2]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-3]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+1]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+2]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)+3]=1;
	
	if(kolumny<10)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 10 X 10 !");
	czysc();
	}
}
void zycie::cos_2()
{
	czysc();
	
	pole[(kolumny/2)*kolumny+(kolumny/2)]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+2]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+5]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-1]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+4]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+5]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)+1]=1;
	
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+5)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+5)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-6]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-3]=1;
	
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-6]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-5)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-5)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-6)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-6)*kolumny+(kolumny/2)+1]=1;

if(kolumny<12)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 12 X 12 !");
	czysc();
	}

}

void zycie::gwiazdka()
{
	czysc();
	
	pole[(kolumny/2)*kolumny+(kolumny/2)+4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)+5]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-4]=1;
	pole[(kolumny/2)*kolumny+(kolumny/2)-5]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)+4]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)+3]=1;
	
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)-3)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)-4)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)-5)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+5)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+4)*kolumny+(kolumny/2)+1]=1;

	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+1]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+2]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-1]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-2]=1;
	pole[((kolumny/2)+3)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+2)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-4]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)-3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+3]=1;
	pole[((kolumny/2)+1)*kolumny+(kolumny/2)+4]=1;

if(kolumny<15)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 15 X 15 !");
	czysc();
	}

}
void zycie::cos_1()
{
	czysc();
	
	pole[(kolumny/2)*kolumny-7]=1;
	pole[(kolumny/2)*kolumny-10]=1;
	pole[((kolumny/2)-1)*kolumny-1]=1;
	pole[((kolumny/2)-1)*kolumny-2]=1;
	pole[((kolumny/2)-1)*kolumny-3]=1;
	pole[((kolumny/2)-1)*kolumny-4]=1;
	
	pole[((kolumny/2)-1)*kolumny-7]=1;
	pole[((kolumny/2)-1)*kolumny-9]=1;
	pole[((kolumny/2)-2)*kolumny-5]=1;
	pole[((kolumny/2)-2)*kolumny-8]=1;
	pole[((kolumny/2)-3)*kolumny-1]=1;
	pole[((kolumny/2)-3)*kolumny-5]=1;
	
	pole[((kolumny/2)-4)*kolumny-1]=1;
	pole[((kolumny/2)-5)*kolumny-3]=1;
	pole[((kolumny/2)-5)*kolumny-4]=1;
	pole[((kolumny/2)-6)*kolumny-1]=1;
	pole[((kolumny/2)-6)*kolumny-3]=1;
	pole[((kolumny/2)-7)*kolumny-2]=1;
	
	pole[((kolumny/2)+1)*kolumny-1]=1;
	pole[((kolumny/2)+1)*kolumny-2]=1;
	pole[((kolumny/2)+1)*kolumny-3]=1;
	pole[((kolumny/2)+1)*kolumny-4]=1;
	
	pole[((kolumny/2)+1)*kolumny-7]=1;
	pole[((kolumny/2)+1)*kolumny-9]=1;
	pole[((kolumny/2)+2)*kolumny-5]=1;
	pole[((kolumny/2)+2)*kolumny-8]=1;
	pole[((kolumny/2)+3)*kolumny-1]=1;
	pole[((kolumny/2)+3)*kolumny-5]=1;
	
	pole[((kolumny/2)+4)*kolumny-1]=1;
	pole[((kolumny/2)+5)*kolumny-3]=1;
	pole[((kolumny/2)+5)*kolumny-4]=1;
	pole[((kolumny/2)+6)*kolumny-1]=1;
	pole[((kolumny/2)+6)*kolumny-3]=1;
	pole[((kolumny/2)+7)*kolumny-2]=1;
	
if(kolumny<16)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 16 X 16 !");
	czysc();
	}


}

void zycie::zegar()
{
	czysc();
	
	pole[kolumny*kolumny-8]=1;
	pole[kolumny*kolumny-9]=1;
	pole[(kolumny-1)*kolumny-7]=1;
	pole[(kolumny-2)*kolumny-7]=1;
	pole[(kolumny-2)*kolumny-9]=1;
	pole[(kolumny-2)*kolumny-10]=1;
	pole[(kolumny-3)*kolumny-8]=1;
	pole[(kolumny-4)*kolumny-6]=1;
	pole[(kolumny-4)*kolumny-8]=1;
	pole[(kolumny-4)*kolumny-9]=1;
	pole[(kolumny-5)*kolumny-6]=1;
	pole[(kolumny-5)*kolumny-8]=1;
	pole[(kolumny-6)*kolumny-1]=1;
	
	pole[(kolumny-7)*kolumny-2]=1;
	pole[(kolumny-7)*kolumny-4]=1;
	pole[(kolumny-7)*kolumny-6]=1;
	pole[(kolumny-7)*kolumny-7]=1;
	pole[(kolumny-7)*kolumny-8]=1;
	pole[(kolumny-8)*kolumny-1]=1;
	pole[(kolumny-8)*kolumny-2]=1;
	pole[(kolumny-8)*kolumny-7]=1;
	pole[(kolumny-8)*kolumny-8]=1;
	pole[(kolumny-8)*kolumny-9]=1;
	pole[(kolumny-9)*kolumny-2]=1;

	pole[(kolumny-9)*kolumny-3]=1;
	pole[(kolumny-9)*kolumny-4]=1;
	pole[(kolumny-9)*kolumny-11]=1;
	pole[(kolumny-9)*kolumny-12]=1;
	pole[(kolumny-9)*kolumny-14]=1;
	pole[(kolumny-10)*kolumny-9]=1;
	pole[(kolumny-10)*kolumny-14]=1;
	pole[(kolumny-11)*kolumny-11]=1;
	pole[(kolumny-11)*kolumny-13]=1;
	pole[(kolumny-11)*kolumny-14]=1;
	pole[(kolumny-12)*kolumny-11]=1;
	pole[(kolumny-13)*kolumny-11]=1;
	pole[(kolumny-13)*kolumny-9]=1;
	pole[(kolumny-14)*kolumny-11]=1;
	pole[(kolumny-14)*kolumny-10]=1;

if(kolumny<15)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 15 X 15 !");
	czysc();
	}

}
void zycie::wystrzal()
{
	czysc();
	pole[5*kolumny+26]=1;
	pole[6*kolumny+26]=1;
	pole[6*kolumny+31]=1;
	pole[6*kolumny+25]=1;
	pole[6*kolumny+24]=1;
	pole[6*kolumny+23]=1;
	pole[7*kolumny+31]=1;
	pole[7*kolumny+25]=1;
	pole[7*kolumny+24]=1;
	pole[7*kolumny+23]=1;
	pole[7*kolumny+22]=1;
	pole[7*kolumny+14]=1;
	pole[8*kolumny+13]=1;
	pole[8*kolumny+15]=1;
	pole[8*kolumny+22]=1;
	pole[8*kolumny+25]=1;
	pole[8*kolumny+35]=1;
	pole[8*kolumny+36]=1;
	pole[9*kolumny+12]=1;
	pole[9*kolumny+16]=1;
	pole[9*kolumny+17]=1;
	pole[9*kolumny+22]=1;
	pole[9*kolumny+23]=1;
	pole[9*kolumny+24]=1;
	pole[9*kolumny+25]=1;
	pole[9*kolumny+35]=1;
	pole[9*kolumny+36]=1;
	pole[10*kolumny+1]=1;
	pole[10*kolumny+2]=1;
	pole[10*kolumny+12]=1;
	pole[10*kolumny+16]=1;
	pole[10*kolumny+17]=1;
	pole[10*kolumny+23]=1;
	pole[10*kolumny+24]=1;
	pole[10*kolumny+25]=1;
	pole[10*kolumny+26]=1;
	pole[11*kolumny+1]=1;
	pole[11*kolumny+2]=1;
	pole[11*kolumny+12]=1;
	pole[11*kolumny+16]=1;
	pole[11*kolumny+17]=1;
	pole[11*kolumny+26]=1;
	pole[12*kolumny+13]=1;
	pole[12*kolumny+15]=1;
	pole[13*kolumny+14]=1;

	if(kolumny<40)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 40 X 40 !");
	czysc();
	}

}
void zycie::engine()
{
	czysc();
	pole[(kolumny/2)*kolumny+8]=1;
	pole[(kolumny/2)*kolumny+9]=1;
	pole[(kolumny/2)*kolumny+10]=1;
	pole[((kolumny/2)-1)*kolumny+8]=1;
	pole[((kolumny/2)-1)*kolumny+9]=1;
	pole[((kolumny/2)-1)*kolumny+12]=1;
	pole[((kolumny/2)-1)*kolumny+15]=1;
	pole[((kolumny/2)-2)*kolumny+16]=1;
	pole[((kolumny/2)-3)*kolumny+16]=1;
	pole[((kolumny/2)-3)*kolumny+12]=1;
	pole[((kolumny/2)-4)*kolumny+13]=1;
	pole[((kolumny/2)-4)*kolumny+14]=1;
	pole[((kolumny/2)-4)*kolumny+15]=1;
	pole[((kolumny/2)-4)*kolumny+16]=1;
	pole[((kolumny/2)+1)*kolumny+8]=1;
	pole[((kolumny/2)+1)*kolumny+9]=1;
	pole[((kolumny/2)+1)*kolumny+12]=1;
	pole[((kolumny/2)+1)*kolumny+15]=1;
	pole[((kolumny/2)+2)*kolumny+16]=1;
	pole[((kolumny/2)+3)*kolumny+16]=1;
	pole[((kolumny/2)+3)*kolumny+12]=1;
	pole[((kolumny/2)+4)*kolumny+13]=1;
	pole[((kolumny/2)+4)*kolumny+14]=1;
	pole[((kolumny/2)+4)*kolumny+15]=1;
	pole[((kolumny/2)+4)*kolumny+16]=1;

if(kolumny<40)
	{
	allegro_message("Optymalny rozmiar dla tej konfiguracji to min 40 X 40 !");
	czysc();
	}

}*/
int zycie::sprawdzLiczbeZywych()
{
	for(int i=0; i<rozmiar;i++)
		if(pole[i]==1)komorki++;
return komorki;

}
//alokacja pamieci dla poszczegolnych tab w zaleznosci od rozmiaru
void zycie::ustalPole()
{	
	delete [] pole;
	delete [] nast;
	delete [] poprz;

	pole = new int[rozmiar];
	nast = new int[rozmiar];
	poprz =new int[rozmiar];

}

zycie::~zycie(void)
{
	delete [] pole;
	delete [] nast;
	delete [] poprz;
	
}

