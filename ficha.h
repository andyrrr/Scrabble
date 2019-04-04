#ifndef FICHA_H
#define FICHA_H

#include <QPen>



class Ficha{
public:
    Ficha(int col, int fila, char letra);
    int getCol() const;
    void setCol(int col);
    int getFil() const;
    void setFil(int fil);
    char getLetra() const;
    void setLetra(char letra);
    void setContorno(QPen contorno);
    QPen getContorno();

private:
    int Col;
    int Fil;
    char Letra;
    QPen Contorno;
};

#endif // FICHA_H
