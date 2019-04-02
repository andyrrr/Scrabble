#include "dibujar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Dibujar::Dibujar()
{
    contorno = QPen(Qt::black);
    contorno.setWidth(2);
    textFont.setPixelSize(50);
}

void Dibujar::paint(QPainter *painter,int x, int y,QBrush relleno)
{
    painter->setPen(contorno);
    painter->setBrush(relleno);
    painter->drawRect(x,y,50,50);
}
void Dibujar::paint2(QPainter *painter,int x, int y, char letra, QBrush relleno)
{
    painter->setPen(contorno);
    painter->setBrush(relleno);
    painter->drawRect(x,y,50,50);
    painter->drawText(QRect(x,y,50,50),Qt::AlignCenter,QString(letra));
}
