nclude <complex.h> 

_Complex double a, b, c, d; 
void p() {
	d = b/c; 
	{
		#pragma STDC CX_LIMITED_RANGE ON 
		a = b / c; 
	}
}
