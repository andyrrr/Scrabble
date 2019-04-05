#include "dibujar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Dibujar::Dibujar()
{
    contornoPieza.setColor(Qt::black);
    contornoPieza.setWidth(2);
    textFont.setPixelSize(40);
}

void Dibujar::paint(QPainter *painter,int x, int y,QBrush relleno)
{
    painter->setPen(contornoPieza);
    painter->setBrush(relleno);
    painter->drawRect(x,y,40,40);
}
void Dibujar::paint2(QPainter *painter,int x, int y, std::string letra, QPen cont)
{
    const char* l = letra.c_str();
    contornoFicha = cont;
    contornoFicha.setWidth(2);
    painter->setPen(contornoFicha);
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawRect(x,y,40,40);
    painter->drawText(QRect(x,y,40,40),Qt::AlignCenter,QString(l));
}
