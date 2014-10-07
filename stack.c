#include "stack.h"

My_complex pop(Stack** s)
{
	if(*s != NULL)
	{
		Stack tmp = **s;
		free(*s);
		*s = tmp.prev;	
		return tmp.value;
	}
	else
	{
		fprintf(stderr,"Blad: Nieprawidlowe wyrazenie (pusty stos)!\n"); 
		exit(4);
	}
}

My_complex top(Stack** s)
{
	return (*s)->value;
}

Stack* push(Stack** s, My_complex wartosc)
{
	Stack* nowy = (Stack*) malloc(sizeof(Stack));
	nowy->prev = *s;
	nowy->value = wartosc;
	/*nowy->operacja = operacja;*/
	*s = nowy;
	return nowy;
}

int isEmpty(Stack* s)
{
	if(s == NULL)
		return 1;
	else 
		return 0;
}

void init(Stack** s)
{
	*s = NULL;
}
