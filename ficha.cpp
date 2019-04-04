#include "ficha.h"

Ficha::Ficha(int fil, int col, char letra) : Col(col), Fil(fil),Letra(letra), Contorno(QPen(Qt::black)){}


int Ficha::getCol() const {
    return Col;
}

void Ficha::setCol(int col) {
    Col = col;
}

int Ficha::getFil() const {
    return Fil;
}

void Ficha::setFil(int fil) {
    Fil = fil;
}

char Ficha::getLetra() const {
    return Letra;
}

void Ficha::setLetra(char letra) {
    Col = letra;
}
void Ficha::setContorno(QPen contorno){
    Contorno=contorno;
}
QPen Ficha::getContorno(){
    return Contorno;
}
