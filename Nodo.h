//
// Created by dantroll on 29/03/19.
//

#ifndef PROYECTO1_NODO_H
#define PROYECTO1_NODO_H


#include <iostream>

class Nodo {
public:
    int fil=5;
    int col=5;
    std::string letra;
    Nodo *next;





    int getDato() const;
    void setLetra(std::string letra);

    Nodo *getNext() const;
    void setNext(Nodo *next);

};


#endif //PROYECTO1_NODO_H
