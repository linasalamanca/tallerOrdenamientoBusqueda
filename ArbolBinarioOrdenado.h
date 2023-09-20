#ifndef __ARBOLBIN__H__
#define __ARBOLBIN__H__

#include <iostream>
#include "NodoBinarioAVL.h"
#include <list>
#include <utility>

template< class T >
class ArbolBinarioOrdenado {
protected:
    NodoBinarioAVL<T> *raiz;
public:
    //constructores
    ArbolBinarioOrdenado();
    ArbolBinarioOrdenado(T& val);
    //destructor
    ~ArbolBinarioOrdenado();
    //manipuladores del arbol
    bool esVacio();
    T& datoRaiz();
    void fijarRaiz(NodoBinarioAVL<T> *n_raiz);
    NodoBinarioAVL<T>* obtenerRaiz();
    //operaciones del arbol
    void preOrden();
    void inOrden();
    void inOrdenLista(std::list<T>& lista);
    void posOrden();
    void nivelOrden();
    bool buscar(T& val);
    bool insert(T& val);
    bool insertar(T& val);
    bool erase(T& val);
    bool eliminar(T& val);
};

#include "ArbolBinarioOrdenado.hxx"

#endif // __ARBOLBIN__H__