#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 25

int main(void) {
	int n;
	char buffer[MAX_STRING], *p;
	double sum = 0;

	n = 0;
	while(fgets(buffer, MAX_STRING, stdin) != NULL) {
		n++;

		sum += strtod(buffer, &p);

		if(*p != '\n') {
			fprintf(stderr, "ERR: \"%s\" no es un valor valido.\n", buffer);
			return EXIT_FAILURE;
		}
	}

	if(! n) {
		fprintf(stderr, "ERR: No se ingresaron numeros\n");
		return EXIT_FAILURE;
	}

	printf("%f\n", sum / n);

	return EXIT_SUCCESS;
}
