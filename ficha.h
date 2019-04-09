#ifndef FICHA_H
#define FICHA_H

#include <QPen>

using namespace std;

class Ficha{
public:
    Ficha(int x, int y, string letra);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getColM() const;
    void setColM(int colM);
    int getFilM() const;
    void setFilM(int filM);
    string getLetra() const;
    void setLetra(string letra);
    void setContorno(QPen contorno);
    QPen getContorno();

private:
    int X;
    int Y;
    int ColM;
    int FilM;
    string Letra;
    QPen Contorno;
};

#endif // FICHA_H
