#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

#include <iostream>
#include <list>
#include <utility>

template< class T >
class NodoBinario {
protected:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;
public:
    //constructores
    NodoBinario();
    NodoBinario(T& val);
    NodoBinario(T& val, NodoBinario<T> *izq, NodoBinario<T> *der);
    //destructor
    ~NodoBinario();
    //manipuladores del nodo
    bool esHoja();
    T& obtenerDato();
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarDato(T& val);
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    //operaciones del arbol
    void preOrden();
    void inOrden();
    void inOrdenLista(std::list<T>& lista);
    void posOrden();
    void nivelOrden();
    bool buscar(T& val);
    bool insertar(T& val, NodoBinario<T> **nraiz);
    bool eliminar(T& val, NodoBinario<T> **nraiz);
    T& minimo();
    T& maximo();
    int tamano();

};

#include "NodoBinario.hxx"

#endif // __NODOBINARIO__H__

// eof - NodoBinario.h
