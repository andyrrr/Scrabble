#ifndef DIBUJAR_H
#define DIBUJAR_H


#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Dibujar
{
public:
    Dibujar();
    void paint(QPainter *painter, int x, int y, QBrush relleno);
    void paint2(QPainter *painter, int x, int y, char letra, QBrush relleno);

private:
    QPen contorno;
    QPen textPen;
    QFont textFont;
};

#endif // DIBUJAR_H
