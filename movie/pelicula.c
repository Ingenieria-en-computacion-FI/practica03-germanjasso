#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

struct Pelicula
{
    char* titulo;
    int anio;
    char* genero;
    char* directores[MAX_DIRECTORES];
    int numDirectores;
};

char* copiarCadena(const char* texto)
{
    if (texto == NULL) return NULL;
    char* copia = (char*)malloc((strlen(texto) + 1) * sizeof(char));
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

Pelicula* crearPelicula(const char* titulo, int anio, const char* genero)
{
    Pelicula* p = (Pelicula*)malloc(sizeof(Pelicula));
    if (p == NULL) return NULL;

    p->titulo = copiarCadena(titulo);
    p->genero = copiarCadena(genero);
    p->anio = anio;
    p->numDirectores = 0;
    
    for(int i = 0; i < MAX_DIRECTORES; i++) {
        p->directores[i] = NULL;
    }

    return p;
}

void imprimir(Pelicula* p)
{
    if (p == NULL) return;

    printf("Pelicula: %s\n", p->titulo);
    printf("Año:      %d\n", p->anio);
    printf("Genero:   %s\n", p->genero);
    printf("Directores:\n");
    
    if (p->numDirectores == 0) {
        printf("  (Sin directores registrados)\n");
    } else {
        for (int i = 0; i < p->numDirectores; i++) {
            printf("  - %s\n", p->directores[i]);
        }
    }
}

void cambiarGenero(Pelicula* p, const char* nuevoGenero)
{
    if (p == NULL || nuevoGenero == NULL) return;
    free(p->genero);
    p->genero = copiarCadena(nuevoGenero);
}

void agregarDirector(Pelicula* p, const char* director)
{
    if (p == NULL || director == NULL) return;
    if (p->numDirectores < MAX_DIRECTORES) {
        p->directores[p->numDirectores] = copiarCadena(director);
        p->numDirectores++;
    }
}

void destruir(Pelicula* p)
{
    if (p == NULL) return;
    free(p->titulo);
    free(p->genero);
    for (int i = 0; i < p->numDirectores; i++) {
        free(p->directores[i]);
    }
    free(p);
}
