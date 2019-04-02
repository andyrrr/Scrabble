#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <QWidget>
#include "dibujar.h"

class scrabble : public QWidget
{
    Q_OBJECT

public:
    scrabble(QWidget *parent = 0);
    ~scrabble();

private:
    Dibujar dibujar;
};

#endif // SCRABBLE_H
