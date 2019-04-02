#ifndef PIEZA_H
#define PIEZA_H
#include "ficha.h"
#include <string>
using namespace std;

class Pieza {
public:
    Pieza(int, int);
    int getCol() const;
    void setCol(int);
    int getFil() const;
    void setFil(int);
    bool getFree() const;
    void setFree(bool);
    Ficha *getFletra() const;
    void setFletra(Ficha *);
    string toString();

private:
    int Col;
    int Fil;
    Ficha *Fletra;
    bool Free;
};
#endif // PIEZA_H
