#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <stdlib.h>
#include <math.h>
#include <complex.h>
/* 
 * #include <complex>
 */ 
/*#pragma STDC CX_LIMITED_RANGE on
 */

typedef struct _My_complex
{
	double re;
	double im;
} My_complex;

My_complex dodaj(My_complex a, My_complex b);
My_complex odejmij(My_complex a, My_complex b);
My_complex mnoz(My_complex a, My_complex b);
My_complex dziel(My_complex a, My_complex b);
My_complex potega(My_complex a, My_complex b);
My_complex m_sqrt(My_complex a);
My_complex m_sin(My_complex a);
My_complex m_cos(My_complex a);
My_complex m_tan(My_complex a);
My_complex m_log(My_complex a);

 
#endif
