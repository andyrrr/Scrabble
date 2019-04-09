#ifndef PIEZA_H
#define PIEZA_H
#include "ficha.h"
#include <QBrush>
#include <string>
using namespace std;

class Pieza {
public:
    Pieza(int x, int y);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    bool getFree() const;
    void setFree(bool);
    Ficha *getFletra() const;
    void setFletra(Ficha * ficha);
    string toString();

private:
    int X;
    int Y;
    Ficha *Fletra;
    bool Free;
    QBrush borde;
};
#endif // PIEZA_H
