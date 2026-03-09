#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

struct Fraccion
{
    int num;
    int den;
};

int mcd(int a, int b)
{
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b) {
        a %= b;
        int t = a;
        a = b;
        b = t;
    }
    return a;
}

Fraccion* crearFraccion(int num, int den)
{
    if (den == 0) {
        printf("Error: El denominador no puede ser 0.\n");
        return NULL;
    }

    Fraccion* f = (Fraccion*)malloc(sizeof(Fraccion));
    if (f == NULL) return NULL;

    f->num = num;
    f->den = den;

    simplificar(f);

    return f;
}

void simplificar(Fraccion* f)
{
    if (f == NULL) return;

    int comun = mcd(f->num, f->den);
    f->num /= comun;
    f->den /= comun;

    if (f->den < 0) {
        f->num = -f->num;
        f->den = -f->den;
    }
}

Fraccion* sumar(Fraccion* a, Fraccion* b)
{
    if (a == NULL || b == NULL) return NULL;

    int nuevoNum = (a->num * b->den) + (b->num * a->den);
    int nuevoDen = a->den * b->den;

    return crearFraccion(nuevoNum, nuevoDen);
}

void imprimir(Fraccion* f)
{
    if (f == NULL) return;
    printf("%d/%d\n", f->num, f->den);
}

void destruir(Fraccion* f)
{
    if (f != NULL) {
        free(f);
    }
}
