#include "ArbolBinarioOrdenado.h"
#include <iostream>

// ------------------------------------------------------------------------
template< class T >
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado() {
    this->raiz = NULL;
}

// ------------------------------------------------------------------------
template< class T >
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(T& val) {
    this->raiz = new NodoBinarioAVL<T>(val);
}

// ------------------------------------------------------------------------
template< class T >
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::esVacio() {
    return (this->raiz == NULL);
}

// ------------------------------------------------------------------------
template< class T >
T& ArbolBinarioOrdenado<T>::datoRaiz() {
    return (this->raiz)->obtenerDato();
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::fijarRaiz(NodoBinarioAVL<T> *n_raiz) {
    this->raiz = n_raiz;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinarioAVL<T>* ArbolBinarioOrdenado<T>::obtenerRaiz() {
    return this->raiz;
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::preOrden() {
    if (this->raiz != NULL)
        this->raiz->preOrden();
    std::cout << this->obtenerDato()<<" ";
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::inOrden() {
    if (this->raiz != NULL)
        this->raiz->inOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::inOrdenLista(std::list<T>& lista) {
    if (this->raiz != NULL)
        this->raiz->inOrdenLista(lista);
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::posOrden() {
    if (this->raiz != NULL)
        this->raiz->posOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template< class T >
void ArbolBinarioOrdenado<T>::nivelOrden() {
    if (this->raiz != NULL)
        this->raiz->nivelOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::buscar(T& val) {
    bool res;
    if (this->raiz == NULL)
        res = false;
    else
        res = this->raiz->buscar(val);

    return res;
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::insert(T& val) {
    return this->insertar(val);
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::insertar(T& val) {
    bool res;

    if (this->raiz == NULL) {
        this->raiz = new NodoBinarioAVL<T>(val);
        res = true;
    } else {
        NodoBinarioAVL<T> *nraiz = this->raiz;
        res = this->raiz->insertar(val,&nraiz);
        this->raiz = nraiz;
    }

    return res;
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::erase(T& val) {
    return this->eliminar(val);
}

// ------------------------------------------------------------------------
template< class T >
bool ArbolBinarioOrdenado<T>::eliminar(T& val) {
    bool res;

    if (this->raiz == NULL)
        res = false;
    else if (this->raiz->esHoja() && this->raiz->obtenerDato() == val) {
        delete this->raiz;
        this->raiz = NULL;
        res = true;
    } else {
        NodoBinarioAVL<T> *nraiz = this->raiz;
        res = this->raiz->eliminar(val,&nraiz);
        this->raiz = nraiz;
    }

    return res;
}

// ------------------------------------------------------------------------
template< class T >
T& ArbolBinarioOrdenado<T>::minimo() {
    if (this->raiz != NULL)
        return this->raiz->minimo();
}

// ------------------------------------------------------------------------
template< class T >
T& ArbolBinarioOrdenado<T>::maximo() {
    if (this->raiz != NULL)
        return this->raiz->maximo();
}

// ------------------------------------------------------------------------
template< class T >
int ArbolBinarioOrdenado<T>::tamano() {
    int val;
    if (this->raiz == NULL)
        val = 0;
    else
        val = this->raiz->tamano();

    return val;
}

// ------------------------------------------------------------------------
template< class T >
int ArbolBinarioOrdenado<T>::altura() {
    int val;
    if (this->raiz == NULL)
        val = -1;
    else
        val = this->raiz->obtenerAltura();

    return val;
}

// eof - ArbolBinarioOrdenado.hxx