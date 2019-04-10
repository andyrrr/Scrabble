#include "scrabble.h"
#include "tablero.h"

#include <QGridLayout>
#include <QLabel>
Tablero *nativo;
scrabble::scrabble(QWidget *parent)
    :QWidget (parent)
{
    setWindowTitle(tr("Scrabble"));
     nativo = new Tablero(&dibujar,this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nativo,0,0);
    setLayout(layout);
}
scrabble::~scrabble()
{
}
void scrabble::setID(int i){
    this->id =i;
    nativo->setIDJuego(i);
}
