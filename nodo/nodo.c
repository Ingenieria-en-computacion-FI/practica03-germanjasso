#include "nodo.h"
#include <stdlib.h>
#include <stdio.h>

Nodo *crearNodo (int valor){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    n->valor =valor;
    return n;
}
int obtenerValor (const Nodo *n){
    return n->valor;
}
void asignarValor(Nodo *n, int v){
    if(!n) return;
    n->valor= v;
}
void destruirNodo(Nodo *n){
    if(!n) return;
    free (n);
}
