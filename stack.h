#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "my_complex.h"

typedef struct _Stack Stack;
struct _Stack 
{
	My_complex value;
	struct _Stack* prev;
};

My_complex top(Stack** s);
My_complex pop(Stack** stos);
Stack* push(Stack** s, My_complex wartosc);
int isEmpty(Stack* stos);
void init(Stack** stos);



#endif
