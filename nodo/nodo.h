#ifndef __NODO_H__
#define __NODO_H__

struct nodo {
    int valor;

};
typedef struct nodo Nodo;

Nodo *crearNodo (int valor);
int obtenerValor (const Nodo*);
void asignarValor(Nodo*, int);
void destruirNodo(Nodo *);

#endif
