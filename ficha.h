#ifndef FICHA_H
#define FICHA_H


class Ficha{
public:
    Ficha(int, int,char);
    int getCol() const;
    void setCol(int col);
    int getFil() const;
    void setFil(int fil);
    char getLetra() const;
    void setLetra(char);

private:
    int Col;
    int Fil;
    char Letra;
};

#endif // FICHA_H
