#include "listaficha.h"

NodoFicha::NodoFicha(Ficha *dato):Dato(dato), Sig(nullptr){

}
void NodoFicha::setDato(Ficha *dato) {
    Dato=dato;
}
void NodoFicha::setSig(NodoFicha *sig) {
    Sig=sig;
}
Ficha *NodoFicha::getDato() const{
    return Dato;
}
NodoFicha *NodoFicha::getSig() const{
    return Sig;
}
NodoFicha::~NodoFicha() {

}

ListaFicha::ListaFicha() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaFicha::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaFicha::agregar(Ficha *dato) {
    NodoFicha *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoFicha(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoFicha(dato);
        this->getFin()->setSig(actual);
        this->setFin(actual);
    }
}


NodoFicha *ListaFicha::retornar(int i) {
    int lugar=0;
    NodoFicha *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaFicha::toString() {
    string ListaFinal="[";
    if (estaVacia()){
        return "";
    } else {
        NodoFicha *actual = this->getInicio();
        while(actual->getSig()!= nullptr){
            string dire = "("+to_string(actual->getDato()->getY())+" "+ to_string(actual->getDato()->getX())+")";
            ListaFinal= dire+", ";
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaFicha::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoFicha *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaFicha::limpiar() {
//    NodoFicha actual= this->getInicio();
//    while (actual.getSig()!= nullptr) {
//        delete (this->getInicio());
//        this->setInicio(actual.getSig());
//        actual = this->getInicio();
//    }
//    delete (actual);
    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoFicha *ListaFicha::getInicio() {
    return Inicio;
}


void ListaFicha::setInicio(NodoFicha *inicio) {
    Inicio = inicio;
}


NodoFicha *ListaFicha::getFin(){
    return Fin;
}


void ListaFicha::setFin(NodoFicha *fin) {
    Fin = fin;
}

ListaFicha::~ListaFicha() {

}
