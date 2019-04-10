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
    void setIDJuego(int id);
    int getIDJuego();
    Tablero(Dibujar *dibujar, QWidget *parent);
    void generarPiezas();
    void generarAdyacentes(int col, int fila);
    void generarFichas();
    bool direccion(Pieza* mov);
    void mousePressEvent(QMouseEvent *event) override;
    void asignarFicha(int piezaCol, int piezaFil, int fichaCol, int fichaFil);
    bool verificarDireccion(int piezaCol, int piezaFila);
    void inicializar();
    void actualizar();
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void handleEnviar();
    void handleEliminar();
    void handlePasar();
    void handleSalir();

private:
    Dibujar *dibujar;
    QBrush fondo;
    QBrush relleno;
    QPushButton *enviar;
    QPushButton *eliminar;
    QPushButton *pasar;
    QPushButton *salir;
    Pieza *Matriz[15][15] {};
    Pieza *MatrizBack[15][15] {};
    ListaPieza adyacentes;
    ListaPieza adyacentes2;
    ListaPieza adyacentesBack;
    ListaPieza adyacentes2Back;
    Ficha *listaFichas[4][4] {};
    Ficha *listaFichasBack[4][4] {};
    Ficha *fichaSelec=nullptr;
    Pieza *piezaSelec=nullptr;

    int ponerPCol=-1;
    int ponerPFil=-1;
    int ponerFCol=-1;
    int ponerFFil=-1;

    int piezaActCol=-1;
    int piezaActFila=-1;
    int tam=15;
    int dire=0;
    int contfila=10;
    int contCol=-1;
    string palabraFormada;

    int JugadorID;
    int JuegoID;

};

#endif // TABLERO_H
