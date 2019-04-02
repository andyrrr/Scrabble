#ifndef LISTAPIEZAS_H
#define LISTAPIEZAS_H
#include "pieza.h"
#include <string>

using namespace std;
class NodoPieza{
public:
    NodoPieza(Pieza *Dato);

     void setDato(Pieza *);
     void setSig(NodoPieza *);
     Pieza *getDato() const;
     NodoPieza  *getSig() const;
     ~NodoPieza();
private:
    Pieza *Dato;
    NodoPieza *Sig;
};
class ListaPieza {
public:
    ListaPieza();
    bool estaVacia();
    void agregar(Pieza *);
    NodoPieza *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    NodoPieza *getInicio();
    void setInicio(NodoPieza *inicio);
    NodoPieza *getFin();
    void setFin(NodoPieza *fin);
    ~ListaPieza();
private:

    NodoPieza *Inicio;
    NodoPieza *Fin;
};


#endif // LISTAPIEZAS_H
