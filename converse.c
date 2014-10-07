#include "converse.h"

/* funkcja przerabiajaca ciag znaków str w liczbê wynik i liczbê operacja
 * zwraca 0 - jak funkcja wykona sie poprawnie */
int converseToComplex(char* str, My_complex* wynik, int* operacja)
{
	double re, im;
	double suma_czesc;
	double liczbaPrzedPrzecinkiem, liczbaPoPrzecinku;
	double *tmp;
	double dzielnik;
	char znak;
	int ileLiczb;
	int czyI, przecinek;
	
	wynik->re = wynik->im = 0;
	*operacja = 0;

	re=0;
	im=0;
	if(strlen(str)==1)
	/*if(*(str+1)==0) // rownoznaczne z tym wyzej */
	{
		if(str[0]=='+' || str[0]=='-' || str[0]=='*' || str[0]=='/' || str[0]=='^')
		{
			*operacja = str[0];
			/*printf("operacja: '%c'[%d]\n",*operacja,*operacja);*/
			return 0;
		}
		else if(*str=='i' || *str=='I' || *str=='j' || *str=='J')
			im = 1;
		else if(*str>='0' && *str<='9')
			re = *str-'0';
		else
		{
			fprintf(stderr,"Blad: Niewlasciwy operator! Operator '%c'",str[0]);
			exit(1);
		}
	}
	else
	{
		re = im = 0;
		ileLiczb = 0;
		liczbaPrzedPrzecinkiem = liczbaPoPrzecinku = 0;
		dzielnik = 1;
		znak = 0;
		czyI = 0;
		przecinek=0;	/* 0 - to calkowita, 1 - po przecinku */

		for(;;str++)
		{
			/* jesli liczba to zczytuje wszystkie liczby po kolei */
			if(*str>='0' && *str<='9')
			{
				dzielnik = 1;
				if(!przecinek) tmp = &liczbaPrzedPrzecinkiem;
				else tmp = &liczbaPoPrzecinku;
				
				for(; *str != 0 && *str>='0' && *str<='9'; str++, dzielnik*=10)
					*tmp = 10*(*tmp) + *str -'0';
				
				if(przecinek) (*tmp) /= dzielnik;

				ileLiczb++;
				str--;
			}
			/* przecinek sluzy jako flaga do zczytywania liczby przed czy po.
			 * odziela czesc przed i po przecinkiem */
			else if(*str==',' || *str=='.')
			{
				przecinek = 1;
			}
			/* aby odroznic liczbe Re od Im */
			else if(*str=='i' || *str=='I' || *str=='j' || *str=='J')
			{
				++czyI;
				ileLiczb++;
				if(czyI>1)
				{
					fprintf(stderr,"Blad: Bledna reprezentacja liczby (I)!\n");
					exit(2);
				}
			}
			/* wylapywanie funkcji SQRT, SIN, COS, ....  */
			else if((*str >= 'a' && *str <='z') || (*str >= 'A' && *str <='Z'))
			{
				if((strncmp(str,"sqrt",4)==0 || strncmp(str,"SQRT",4)==0) && *(str+4)==0)
				{
					/*printf("Tu SQRT\n");*/
					*operacja = 1;
					return 0;
				}
				else if((strncmp(str,"sin",3)==0 || strncmp(str,"SIN",3)==0) && *(str+3)==0)
				{
					/* printf("Tu SIN\n"); */
					*operacja = 2;
					return 0;
				}
				else if((strncmp(str,"cos",3)==0 || strncmp(str,"COS",3)==0) && *(str+3)==0)
				{
					/*printf("Tu COS\n");*/
					*operacja = 3;
					return 0;
				}
				else if((strncmp(str,"tan",3)==0 || strncmp(str,"TAN",3)==0) && *(str+3)==0)
				{
					/*printf("Tu COS\n");*/
					*operacja = 4;
					return 0;
				}
				else if((strncmp(str,"log",3)==0 || strncmp(str,"LOG",3)==0) && *(str+3)==0)
				{
					/*printf("Tu COS\n");*/
					*operacja = 5;
					return 0;
				}
				else
				{
					fprintf(stderr,"Blad! Niepoprawne wyrazenie!\n");
					exit(6);
				}
			}
			/* sprawdzanie czy liczba nie jest poprzedzona znakiem '+' lub '-' 
			 * */
			else if((*str == '+' || *str == '-') && ileLiczb==0)
			{
				znak = *str;
			}
			/* najwazniejsza czesc, odpowiedzialna za zapisanie liczby do Re lub Im */
			else if(((*str == '+' || *str == '-') && ileLiczb>0) || (*str == 0))
			{
				/* jesli bylo jakies [ijIJ] to zapisujemy liczbe do Im, w przeciwnym wypadku do Re */
				if(czyI) tmp = &im;
				else tmp = &re;
				
				/* laczy w calosc czesc przed i po przecinku */
				suma_czesc = liczbaPrzedPrzecinkiem + liczbaPoPrzecinku;
				/* jesli jest w wyrazeniu (np ..+j-..) samo 'j' to jest to j1 (zakladam ze j==j1) */
				if(suma_czesc==0 && czyI!=0) suma_czesc+=1;
				/* jesli znak byl ujemny to zmiana liczby na przeciwna */
				if(znak == '-') suma_czesc*=-1;		
				/* dodaje do wyniku (Re lub Im) aktualnie policzona liczbe 
				 * dodaje a nie przypisuje ze wzgledu na przypadek 3+j3+3 (to 6+3j), 
				 * nie wyswietlam bledu a przewiduje takie przypadki i sumuje)
				 * */
				*tmp += suma_czesc;
				/* znak oddzielajacy Re i Im w wyrazeniu jest znakiem przypisywanym 
				 * do nastepnej wczytywanej liczby w stringu */
				znak=*str;
				
				
				/* inicjuje zmienne do wczytania nastepnej liczby
				 * (znaki '+''-' s¹ rozgranicznikami liczb w stringu) */
				ileLiczb = 0;
				liczbaPrzedPrzecinkiem = liczbaPoPrzecinku = 0;
				dzielnik = 1;
				czyI = 0;
				przecinek=0;
				
				/* kazdy string z argv ma na koncu znak '\0', jesli taki spotykam to koncze petle */
				if(*str == 0) break;
			}
			else
			{
				fprintf(stderr, "Blad: Bledna reprezentacja liczby!\n"); 
				exit(3);
			}
		}
	}
	/* printf("re: %f, im: %f\n",re,im); */
	wynik->re=re,
	wynik->im=im;

	return 0;
}
