#include <complex.h> 

_Complex double cd = 10.10 + 10.10*I; 
int p() { 

#pragma STDC CX_LIMITED_RANGE ON  

	double d = cabs(cd);  
}
