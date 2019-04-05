//
// Created by dantroll on 29/03/19.
//

#include "Nodo.h"

void Nodo::setLetra(std::string dato) {
    letra = dato;
}
void Nodo::setNext(Nodo *next){
    this->next = next;
}
