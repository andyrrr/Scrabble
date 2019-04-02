#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPushButton>
#include <QMouseEvent>
#include "listaPieza.h"
#include "listaficha.h"
class Dibujar;

class Tablero : public QWidget
{
    Q_OBJECT

public:
    Tablero(Dibujar *dibujar, QWidget *parent);
    void generarPiezas();
    void generarAdyacentes(int);
    void generarFichas();
    bool direccion(Pieza*,int);
    void mousePressEvent(QMouseEvent *event) override;
    void asignarFicha(int pieza,int ficha);
    bool verificarDireccion(int);
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void handleButton();
    void handleButton2();
    void handleButton3();
    void handleButton4();

private:
    Dibujar *dibujar;
    QBrush fondo;
    QBrush relleno;
    QPushButton *enviar;
    QPushButton *eliminar;
    QPushButton *pasar;
    QPushButton *salir;
    ListaPieza piezas;
    ListaPieza adyacentes;
    ListaPieza adyacentes2;
    ListaFicha fichas;
    Ficha *fichaSelec;
    Pieza *piezaSelec;
    int ponerP=-1;
    int ponerF=-1;
    int piezaAct=-1;
    int cont=-1;
    int tam=12;
    int dire=0;
};

#endif // TABLERO_H
