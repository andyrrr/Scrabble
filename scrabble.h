#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <QWidget>
#include "dibujar.h"
#include "tablero.h"

class scrabble : public QWidget
{
    Q_OBJECT

public:
    void setID(int i);
    scrabble(QWidget *parent = 0);
    ~scrabble();

private:
    int id;
    Dibujar dibujar;
};

#endif // SCRABBLE_H
