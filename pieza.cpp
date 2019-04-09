#include "pieza.h"
#include <string>
using namespace std;
    Pieza::Pieza(int y, int x) : X(x), Y(y),Free(true){
        Fletra = nullptr;
    }

    int Pieza::getX() const {
        return X;
    }

    void Pieza::setX(int x) {
        X = x;
    }
    bool Pieza::getFree() const {
        return Free;
    }

    void Pieza::setFree(bool estado) {
        Free = estado;
    }
    Ficha *Pieza::getFletra() const {
        return Fletra;
    }

    void Pieza::setFletra(Ficha *fletra) {
        Fletra=fletra;
        if(fletra!=nullptr){
            Fletra->setX(X);
            Fletra->setY(Y);
            this->setFree(false);
        }
    }

    int Pieza::getY() const {
        return Y;
    }

    void Pieza::setY(int y) {
        Y = y;
    }
    string Pieza::toString(){
        string final;
        final = "("+to_string(getX())+","+to_string(getY())+")";
        return final;
    }
