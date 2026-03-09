#include <stdio.h>
#include "nodo.h"

int main()
{
    printf("Prueba del TAD Nodo\n");

    Nodo* n = crearNodo(10);

    if (n != NULL) {
        printf("El valor inicial del nodo es: %d\n", obtenerValor(n));
    }

    asignarValor(n, 25);

    printf("El nuevo valor del nodo es: %d\n", obtenerValor(n));

    destruirNodo(n);
    
    n = NULL;

    (n == NULL) ? printf("El nodo es nulo\n")  : printf("El nodo no es nulo\n");

    return 0;
}
