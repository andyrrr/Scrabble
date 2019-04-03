#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPushButton>
#include <QMouseEvent>
#include "listaPieza.h"
#include "listaficha.h"
#include "iostream"
#include "stdio.h"
#include "string"

class Dibujar;

class Tablero : public QWidget
{
    Q_OBJECT

public:
    Tablero(Dibujar *dibujar, QWidget *parent);
    void generarPiezas();
    void generarAdyacentes(int col, int fila);
    void generarFichas();
    bool direccion2(Pieza* mov);
    void mousePressEvent(QMouseEvent *event) override;
    void asignarFicha(int piezaCol, int piezaFil, int fichaCol, int fichaFil);
    bool verificarDireccion(int piezaCol, int piezaFila);
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
    Pieza *Matriz[12][12] {};
    ListaPieza adyacentes;
    ListaPieza adyacentes2;
    Pieza *adyacentess[4] {};
    Pieza *adyacentes22[4] {};
    Ficha *listaFichas[3][4] {};
    Ficha *fichaSelec=nullptr;
    Pieza *piezaSelec=nullptr;

    int ponerPCol=-1;
    int ponerPFil=-1;
    int ponerFCol=-1;
    int ponerFFil=-1;

    int piezaActCol=-1;
    int piezaActFila=-1;
    int tam=12;
    int dire=0;
    int contfila=10;
    int contCol=-1;
};

#endif // TABLERO_H
