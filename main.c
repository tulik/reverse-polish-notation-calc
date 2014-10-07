#include <stdio.h>
#include "my_complex.h"
#include "stack.h"
#include "converse.h"
#include <string.h>

void oblicz(Stack** stos, char** argv, int pocz, int kon);

void helpik()
{
	printf("calc - kalkulator liczący w odwrotnej notacji polskiej i notacji polskiej\n");
	printf("Autorzy; Grzegorz Rynkowski i Tomasz Urbanik\n");
	printf("\n");	
	printf("Kalkulator obsluguje polska notacje (np) i odwrotnie polska notacje (ONP).\n");
	printf("calc wywolany z prametrem:\n");
	printf("   -h  -  wyswietla pomoc\n");
	printf("   -p  -  tryb NP\n");
	printf("   -o  -  tryb ONP\n");
	printf("Wywolany bez parametru okreslajacego tryb pracuje w trybie ONP,\n");
	printf("Lista dostepny operacji: +,-,*,/,^,sin,cos,tan,sqrt,log\n");
	printf("\nDziekujemy za skorzystanie z naszego produktu :-)\n\n");




}

int main(int argc, char *argv[])
{
	My_complex cos;
	Stack* stos = (Stack*) malloc(sizeof(Stack));
	init(&stos);
	
	if(argc == 1) helpik();
	else if(strncmp(argv[1],"-p\0",3)==0) 
		oblicz(&stos,argv,argc-1,2);
	else if(strncmp(argv[1],"-o\0",3)==0)
		oblicz(&stos,argv,2,argc);
	else if(strncmp(argv[1],"-h\0",3)==0 || argc==1)
		helpik();	
	else 
		oblicz(&stos,argv,1,argc);
	
	while(!isEmpty(stos))
	{
		/*if(stos->operacja) printf("[%c]>%d<\n\n",stos->operacja,stos->operacja);
		*/ 
			printf("%f %fj\n",stos->value.re,stos->value.im);
		cos = pop(&stos);
	}

	return 0;
}

/*///////////////////////////////////////////////////////*/

void oblicz(Stack** stos, char** argv, int pocz, int kon)
{
	My_complex cos, liczba1, liczba2;
	int operacja;
	int i,c;

	c=pocz<kon?1:-1;
	for(i=pocz; pocz<kon?i<kon:i>=kon; i+=c)
	{
		converseToComplex(argv[i], &cos, &operacja);/* ew. tu tez exit jesli !=0 */
		/*if(cos.operacja<0) // to znaczy ze blad wystapil w converseToComplex() 
			return 1;
		else */
		if(operacja==0) /* to znaczy ze w cos mamy liczbe */
		{
			push(stos,cos); 
			/*printf(">>%f %f<<\n",stos->value.re,stos->value.im);*/
		}
		/* to znaczy ze w cos jest znak */
		else if(operacja > 0) 
		{
			switch(operacja)
			{
				case '+':
					liczba2 = pop(stos);
					liczba1 = pop(stos);
					push(stos,dodaj(liczba1,liczba2));
					break;
				case '-':
					liczba2 = pop(stos);
					liczba1 = pop(stos);
					push(stos,odejmij(liczba1,liczba2));
					break;
				case '*':
					liczba2 = pop(stos);
					liczba1 = pop(stos);
					push(stos,mnoz(liczba1,liczba2));
					break;
				case '/':
					liczba2 = pop(stos);
					liczba1 = pop(stos);
					push(stos,dziel(liczba1,liczba2));
					break;
				case '^':
					liczba2 = pop(stos);
					liczba1 = pop(stos);
					push(stos,potega(liczba1,liczba2));
					break;
				case 1:
					liczba1 = pop(stos);
					push(stos,m_sqrt(liczba1));
					break;
				case 2:
					liczba1 = pop(stos);	
					push(stos,m_sin(liczba1));
					break;
				case 3:
					liczba1 = pop(stos);	
					push(stos,m_cos(liczba1));
					break;
				case 4:
					liczba1 = pop(stos);	
					push(stos,m_tan(liczba1));
					break;
				case 5:
					liczba1 = pop(stos);	
					push(stos,m_log(liczba1));
					break;
				
				default:
					fprintf(stderr,"Blad: Zly operator!\n");
					exit(5);
			}
		}	
	}
}
