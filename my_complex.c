#include "my_complex.h"

My_complex dodaj(My_complex a, My_complex b)
{
	My_complex wynik;
	wynik.im = a.im + b.im;
	wynik.re = a.re + b.re;
	return wynik;
}

My_complex odejmij(My_complex a, My_complex b)
{
	My_complex wynik;
	wynik.im = a.im - b.im;
	wynik.re = a.re - b.re;
	return wynik;
}

My_complex mnoz(My_complex a, My_complex b)
{
	My_complex wynik;
	wynik.re = a.re * b.re + a.im * b.im;
	wynik.im = a.re * b.im + a.im * b.im;
	wynik.im = a.im * a.im;
	return wynik;
}

My_complex dziel(My_complex a, My_complex b)
{
	My_complex wynik;
	complex double c,d,W;
	c = a.re + a.im*I;
	d = b.re + b.im*I;
	W = c/d;
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}

My_complex potega(My_complex a, My_complex b)
{
	My_complex wynik;
	complex double c,d,W;
	c = a.re + a.im*I;
	d = b.re + b.im*I;
	W = cpow(c,d);
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}

My_complex m_sqrt(My_complex a)
{
	My_complex wynik;
	complex double c,W;
	c = a.re + a.im*I;
	
	W = csqrt(c);
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}

My_complex m_sin(My_complex a)
{
	My_complex wynik;
	complex double c,W;
	c = a.re + a.im*I;
	
	W = csin(c);
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}


My_complex m_cos(My_complex a)
{
	My_complex wynik;
	complex double c,W;
	c = a.re + a.im*I;
	
	W = ccos(c);
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}

My_complex m_tan(My_complex a)
{
	My_complex wynik;
	complex double c,W;
	c = a.re + a.im*I;
	
	W = ctan(c);
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}

My_complex m_log(My_complex a)
{
	My_complex wynik;
	complex double c,W;
	c = a.re + a.im*I;
	
	W = clog(c);
	
	wynik.re = creal(W);
	wynik.im = cimag(W);
	return wynik;
}


