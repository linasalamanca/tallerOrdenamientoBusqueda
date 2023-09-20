#include <queue>
#include <iostream>

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>::NodoBinario() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>::NodoBinario(T& val){
    this->dato = val;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>::NodoBinario(T& val, NodoBinario<T> *izq, NodoBinario<T> *der) {
    this->dato = val;
    this->hijoIzq = izq;
    this->hijoDer = der;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>::~NodoBinario() {
    if (this->hijoIzq != NULL) {
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }
    if (this->hijoDer != NULL) {
        delete this->hijoDer;
        this->hijoDer = NULL;
    }
}

// ------------------------------------------------------------------------
template< class T >
bool NodoBinario<T>::esHoja() {
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

// ------------------------------------------------------------------------
template< class T >
T& NodoBinario<T>::obtenerDato() {
    return this->dato;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

// ------------------------------------------------------------------------
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    return this->hijoDer;
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::fijarDato(T& val) {
    this->dato = val;
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq) {
    this->hijoIzq = izq;
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der) {
    this->hijoDer = der;
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::preOrden() {
    std::cout << this->dato << "\t";
    if (this->hijoIzq != NULL)
        this->hijoIzq->preOrden();
    if (this->hijoDer != NULL)
        this->hijoDer->preOrden();
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::inOrden() {
    if (this->hijoIzq != NULL)
        this->hijoIzq->inOrden();
    std::cout << this->dato << "\t";
    if (this->hijoDer != NULL)
        this->hijoDer->inOrden();
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::inOrdenLista(std::list<T>& lista) {
    if (this->hijoIzq != NULL)
        this->hijoIzq->inOrdenLista(lista);
    lista.push_back(this->dato);
    if (this->hijoDer != NULL)
        this->hijoDer->inOrdenLista(lista);
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::posOrden() {
    if (this->hijoIzq != NULL)
        this->hijoIzq->posOrden();
    if (this->hijoDer != NULL)
        this->hijoDer->posOrden();
    std::cout << this->dato << "\t";
}

// ------------------------------------------------------------------------
template< class T >
void NodoBinario<T>::nivelOrden() {
    std::queue< NodoBinario<T>* > q;
    NodoBinario<T> *t = this;
    while (t != NULL) {
        std::cout << t->dato << "\t";
        if (t->hijoIzq != NULL)
            q.push(t->hijoIzq);
        if (t->hijoDer != NULL)
            q.push(t->hijoDer);
        if (!q.empty()) {
            t = q.front();
            q.pop();
        } else
            t = NULL;
    }
}

// ------------------------------------------------------------------------
template< class T >
bool NodoBinario<T>::buscar(T& val) {
    NodoBinario<T> *p = this;
    bool encontrado = false;
    while (p != NULL && !encontrado) {
        if (val < p->dato)
            p = p->hijoIzq;
        else if (val > p->dato)
            p = p->hijoDer;
        else
            encontrado = true;
    }
    return encontrado;
}

// ------------------------------------------------------------------------
template< class T >
bool NodoBinario<T>::insertar(T& val, NodoBinario<T> **nraiz) {
    NodoBinario<T> *p = this;
    NodoBinario<T> *pp = this;
    bool insertado = false;
    bool duplicado = false;
    while (p != NULL) {
        pp = p;
        if (val < p->dato)
            p = p->hijoIzq;
        else if (val > p->dato)
            p = p->hijoDer;
        else {
            duplicado = true;
            break;
        }
    }
    if (!duplicado) {
        NodoBinario<T> *n = new NodoBinario<T>(val);
        if (n != NULL) {
            if (val < pp->dato)
                pp->fijarHijoIzq(n);
            else
                pp->fijarHijoDer(n);
        }
        insertado = true;
    }

    return insertado;
}

// ------------------------------------------------------------------------
template< class T >
bool NodoBinario<T>::eliminar(T& val, NodoBinario<T> **nraiz) {
    NodoBinario<T> *p = this;
    NodoBinario<T> *pp = this;
    bool eliminado = false;
    while (p != NULL && p->dato != val){
        pp = p;
        if (val < p->dato)
            p = p->hijoIzq;
        else if (val > p->dato)
            p = p->hijoDer;
    }
    if (p != NULL) {
        if (p->hijoIzq != NULL && p->hijoDer != NULL) {
            NodoBinario<T> *s = p->hijoIzq;
            NodoBinario<T> *ps = p;
            while (s->hijoDer != NULL) {
                ps = s;
                s = s->hijoDer;
            }
            p->dato = s->dato;
            if (ps == p)
                ps->hijoIzq = s->hijoIzq;
            else
                ps->hijoDer = s->hijoIzq;
        } else {
            NodoBinario<T> *c = NULL;
            if (p->hijoIzq != NULL)
                c = p->hijoIzq;
            else if (p->hijoDer != NULL)
                c = p->hijoDer;
            if (p == this) {
                this->dato = c->dato;
                this->hijoIzq = c->hijoIzq;
                this->hijoDer = c->hijoDer;
                delete c;
                c = NULL;
            } else {
                if (p == pp->hijoIzq)
                    pp->hijoIzq = c;
                else if (p == pp->hijoDer)
                    pp->hijoDer = c;
            }
        }

        eliminado = true;
    }

    return eliminado;
}

// ------------------------------------------------------------------------
template< class T >
T& NodoBinario<T>::minimo() {
    NodoBinario<T> *p = this;
    while (p->hijoIzq != NULL) {
        p = p->hijoIzq;
    }
    return p->dato;
}

// ------------------------------------------------------------------------
template< class T >
T& NodoBinario<T>::maximo() {
    NodoBinario<T> *p = this;
    while (p->hijoDer != NULL) {
        p = p->hijoDer;
    }
    return p->dato;
}

// ------------------------------------------------------------------------
template< class T >
int NodoBinario<T>::tamano() {
    int vtam = 0;
    if (this->hijoIzq != NULL)
        vtam += this->hijoIzq->tamano();
    if (this->hijoDer != NULL)
        vtam += this->hijoDer->tamano();
    return (vtam+1);
}

// eof - NodoBinario.hxx


