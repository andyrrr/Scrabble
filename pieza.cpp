#include "pieza.h"

    Pieza::Pieza(int fil, int col) : Col(col), Fil(fil),Free(true){
        Fletra = nullptr;
    }

    int Pieza::getCol() const {
        return Col;
    }

    void Pieza::setCol(int col) {
        Col = col;
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
        Fletra = fletra;
        Fletra->setCol(Col);
        Fletra->setFil(Fil);
        this->setFree(false);
    }

    int Pieza::getFil() const {
        return Fil;
    }

    void Pieza::setFil(int fil) {
        Fil = fil;
    }

