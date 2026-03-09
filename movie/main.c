#include <stdio.h>
#include "pelicula.h"

int main()
{
    printf("Prueba del TAD Pelicula\n");

    Pelicula* p = crearPelicula("Oppenheimer", 2023, "Drama");

    agregarDirector(p, "Christopher Nolan");
    agregarDirector(p, "Emma Thomas");

    imprimir(p);

    printf("\nCambiar genero\n");

    cambiarGenero(p, "Biografico/Historico");

    imprimir(p);

    destruir(p);
    p = NULL; 

    return 0;
}
