#ifndef LISTAFICHA_H
#define LISTAFICHA_H
#include "ficha.h"
#include <string>

using namespace std;
class NodoFicha{
public:
    NodoFicha(Ficha *Dato);

     void setDato(Ficha *);
     void setSig(NodoFicha *);
     Ficha *getDato() const;
     NodoFicha  *getSig() const;
     ~NodoFicha();
private:
    Ficha *Dato;
    NodoFicha *Sig;
};
class ListaFicha {
public:
    ListaFicha();
    bool estaVacia();
    void agregar(Ficha *);
    NodoFicha *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaFicha();
    NodoFicha *getInicio();
    void setInicio(NodoFicha *inicio);
    NodoFicha *getFin();
    void setFin(NodoFicha *fin);
    NodoFicha *Inicio;
    NodoFicha *Fin;
};

#endif // LISTAFICHA_H
