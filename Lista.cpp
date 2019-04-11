//
// Created by dantroll on 12/03/19.
//
/**
 * @authors Daniel Acuña Mora, Josue Mata
 */
#include "Lista.h"

/**
 * @brief Constructor de la clase Lista.
 */

Lista::Lista() {
    size = 1;
    head = NULL;
    tail = NULL;
}
void Lista::addLetra(std::string dato) {
    Nodo *temp = new Nodo;
    temp->letra = dato;
    temp->fil = 0;
    temp->col = 0;
    temp->next = NULL;

    if (!head) { //
        head = temp;
        return;
    } else { // find last and link the new node
        Nodo *last = head;
        while (last->next) last = last->next;
        last->next = temp;
        temp->fil = 0;
        temp->col = 0;
    }
    size++;
}


/**
 * @brief Funcion que agrega un nodo al final de la lista, recibe un numero entero que será el valor que se almacene
 * en el Nodo.
 * @param valor
 */
void Lista::addLetra(std::string dato,int colum,int fila) {
    Nodo *temp = new Nodo;
    temp->letra = dato;
    temp->fil = fila;
    temp->col = colum;
    temp->next = NULL;

    if (!head) { //
        head = temp;
        return;
    } else { // find last and link the new node
        Nodo *last = head;
        while (last->next) last = last->next;
        last->next = temp;
        temp->fil = fila;
        temp->col = colum;
    }
    size++;
}
Nodo *Lista::retornar(int i) const {
    Nodo *temp;
    temp = head;
    int cont =0;
    while (cont!=i) {
        temp = temp->next;
        cont++;
    }
    return temp;
}
/**
 * @brief Simple implementacion de una funcion que muestra los valores de cada nodo en la lista.
 */
void Lista::vernodos() {
    Nodo *temp;
    temp = head;
    while (temp != NULL) {
         std::cout <<temp->letra <<"("<<temp->col<<","<<temp->fil<<")"<< std::endl;
        temp = temp->next;
    }
}
void Lista::clear(){
    Nodo *temp;
    temp = head;
    while (temp != NULL) {
        free (temp);
        temp = temp->next;
}
    head = NULL;
    size =1;
    delete temp;
}
/**
 * @brief Funcion que elimina el primer nodo de una lista.
 */


/**
 * @brief Funcion que elimina el ultimo nodo de una lista.
 */


Nodo *Lista::getHead() const {
    return head;
}

void Lista::setHead(Nodo *head) {
    Lista::head = head;
}
