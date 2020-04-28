#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *finalPtr;
	printf( "Convirtiendo la cadena \"%s\" en un numero: %e\n", "12.345678e-2",       strtod("12.345678e-2", &finalPtr) );
	printf( "Convirtiendo la cadena \"%s\" en un numero: %e\n", "-12.345678e+2",      strtod("-12.345678e+2", &finalPtr) );
	printf( "Convirtiendo la cadena \"%s\" en un numero: %e\n", "1.2345678",          strtod("1.2345678", &finalPtr) );
	if(!strcmp(finalPtr,"")){
		printf( "linea termina en (%s)\n", finalPtr);
	}
	printf( "Convirtiendo la cadena \"%s\" en un numero: %.2f\n", "hdsg", strtod("hdsg", &finalPtr));
	printf( "(%s) linea termina en\n", finalPtr);
	printf( "Convirtiendo la cadena \"%s\" en un numero: %.2f\n", "125.689", strtod("125.689", &finalPtr));
	printf( "(%s) linea termina en\n", finalPtr);
	printf( "Convirtiendo la cadena \"%s\" en un numero: %e\n", "1.2345678E-22",      strtod("1.2345678E-22", &finalPtr) );
	printf( "Convirtiendo la cadena \"%s\" en un numero: %e\n", "12345.678901234E14", strtod("12345.678901234E14", &finalPtr) );
	printf( "Convirtiendo la cadena \"%s\" en un numero: %.2f\n", "123.5hdsg", strtod("123gfd", &finalPtr));
	printf( "(%s) linea termina en\n", finalPtr);
	return 0;
}
