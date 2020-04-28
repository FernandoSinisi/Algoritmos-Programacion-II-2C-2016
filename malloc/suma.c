#include <stdio.h>


void no_incrementar(int b){ // copia el contenido de la variable
    b += 1; // suma uno a la variable local 'b'
}

void incrementar(int *b){ // recibe un puntero
    *b += 1; // accede al contenido del punto y lo modifica
}

int main(void){
    int a = 1;
    a++; // Incremento 'a' (ahora vale 2)
    printf("A vale: %d\n", a); // 2
    
    // Con & consigo la direccion de memoria de mi variable
    incrementar(&a); // Incremento 'a' (ahora vale 3)
    incrementar(a); // NO INCREMENTO 'a' (sigue valiendo 2)
    
    printf("Ahora vale: %d\n", a); // 3
    return 0;
}
