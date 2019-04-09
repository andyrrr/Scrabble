#include "ficha.h"

using namespace std;

Ficha::Ficha(int y, int x, string letra) : X(x), Y(y),Letra(letra), Contorno(QPen(Qt::black)){}


int Ficha::getX() const {
    return X;
}

void Ficha::setX(int x) {
    X = x;
}

int Ficha::getY() const {
    return Y;
}

void Ficha::setY(int y) {
    Y = y;
}
int Ficha::getColM() const {
    return ColM;
}

void Ficha::setColM(int colM) {
    ColM = colM;
}

int Ficha::getFilM() const {
    return FilM;
}

void Ficha::setFilM(int filM) {
    FilM = filM;
}

string Ficha::getLetra() const {
    return Letra;
}

void Ficha::setLetra(string le) {
    Letra = le;
}
void Ficha::setContorno(QPen contorno){
    Contorno=contorno;
}
QPen Ficha::getContorno(){
    return Contorno;
}
