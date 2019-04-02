#include "listaPieza.h"

NodoPieza::NodoPieza(Pieza *dato):Dato(dato), Sig(nullptr){

}
void NodoPieza::setDato(Pieza *dato) {
    Dato=dato;
}
void NodoPieza::setSig(NodoPieza *sig) {
    Sig=sig;
}
Pieza *NodoPieza::getDato() const{
    return Dato;
}
NodoPieza *NodoPieza::getSig() const{
    return Sig;
}
NodoPieza::~NodoPieza() {

}

ListaPieza::ListaPieza() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaPieza::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaPieza::agregar(Pieza *dato) {
    NodoPieza *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoPieza(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoPieza(dato);
        this->getFin()->setSig(actual);
        this->setFin(actual);
    }
}


NodoPieza *ListaPieza::retornar(int i) {
    int lugar=0;
    NodoPieza *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaPieza::toString() {
    string ListaFinal="[";
    if (estaVacia()){
        return "";
    } else {
        NodoPieza *actual = this->getInicio();
        while(actual->getSig()!= nullptr){
            string dire = "("+to_string(actual->getDato()->getFil())+" "+ to_string(actual->getDato()->getCol())+")";
            ListaFinal= dire+", ";
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaPieza::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoPieza *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaPieza::limpiar() {
//    NodoPieza actual= this->getInicio();
//    while (actual.getSig()!= nullptr) {
//        delete (this->getInicio());
//        this->setInicio(actual.getSig());
//        actual = this->getInicio();
//    }
//    delete (actual);
    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoPieza *ListaPieza::getInicio() {
    return Inicio;
}


void ListaPieza::setInicio(NodoPieza *inicio) {
    Inicio = inicio;
}


NodoPieza *ListaPieza::getFin(){
    return Fin;
}


void ListaPieza::setFin(NodoPieza *fin) {
    Fin = fin;
}

ListaPieza::~ListaPieza() {

}
