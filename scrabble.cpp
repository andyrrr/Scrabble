#include "scrabble.h"
#include "tablero.h"

#include <QGridLayout>
#include <QLabel>

scrabble::scrabble(QWidget *parent)
    :QWidget (parent)
{
    setWindowTitle(tr("Scrabble"));
    Tablero *nativo = new Tablero(&dibujar,this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nativo,0,0);
    setLayout(layout);
}
scrabble::~scrabble()
{
}
