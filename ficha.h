#ifndef FICHA_H
#define FICHA_H

#include <QPen>



class Ficha{
public:
    Ficha(int col, int fila, std::string letra);
    int getCol() const;
    void setCol(int col);
    int getFil() const;
    void setFil(int fil);
    std::string getLetra() const;
    void setLetra(std::string letra);
    void setContorno(QPen contorno);
    QPen getContorno();

private:
    int Col;
    int Fil;
    std::string Letra;
    QPen Contorno;
};

#endif // FICHA_H
