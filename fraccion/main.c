#include <stdio.h>
#include "fraccion.h"

int main()
{
    printf("Prueba del TAD Fraccion\n");

    Fraccion* f1 = crearFraccion(1, 2);
    Fraccion* f2 = crearFraccion(3, 4);

    if (f1 == NULL || f2 == NULL) {
        return 1;
    }

    printf("Fraccion 1: ");
    imprimir(f1);

    printf("Fraccion 2: ");
    imprimir(f2);


    printf("\nSuma de fracciones:\n");

    Fraccion* resultado = sumar(f1, f2);


    if (resultado != NULL) {
        printf("Resultado: ");
        imprimir(resultado);
    }


    destruir(f1);
    destruir(f2);
    destruir(resultado);

    return 0;
}
