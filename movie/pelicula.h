#ifndef __PELICULA_H__
#define __PELICULA_H__

#define MAX_DIRECTORES 10

typedef struct Pelicula Pelicula;

Pelicula* crearPelicula(const char* titulo, int año, const char* genero);

void imprimir(Pelicula* p);

void cambiarGenero(Pelicula* p, const char* nuevoGenero);

void agregarDirector(Pelicula* p, const char* director);

void destruir(Pelicula* p);

#endif
