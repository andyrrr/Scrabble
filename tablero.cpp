#include "tablero.h"
#include "dibujar.h"
#include "listaPieza.h"

#include <QPainter>
#include <QPushButton>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include<time.h>

Tablero::Tablero(Dibujar *dibujar,QWidget *parent):QWidget(parent),dibujar(dibujar)
{
    setFixedSize(1000,600);
    fondo= QBrush(QColor(64,32,64));
    ListaPieza piezas;
    generarPiezas();
    generarFichas();
}


bool Tablero::direccion2(Pieza *mov){
    cout<<"entra"<<endl;
    for (int p=0;p<adyacentes2.tamano();p++){
        if(adyacentes2.retornar(p)->getDato()==mov){
            for (int fila=0;fila<tam;fila++){
                for (int col=0; col<tam; col++){
                    if (Matriz[col][fila]==mov){
                        if(piezaActFila+1==fila){
                            dire=1;
                        } else if (piezaActFila-1==fila) {
                            dire=2;
                        } else if(piezaActCol+1==col){
                            dire=3;
                        } else if(piezaActCol+1==col){
                            dire=4;
                        }
                        cout<<"dire: "<<dire<<endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}




void Tablero::generarAdyacentes(int col, int fila){
    cout<<"llega ga2"<<endl;
    adyacentes2=adyacentes;
    adyacentes.limpiar();
    int i=fila+1;
    if(-1<i && i<tam && col<tam && fila<tam && (dire==1 || dire==0)){
        if(Matriz[col][i]->getFree()){
            cout<<Matriz[col][i]->toString()<<endl;
            adyacentes.agregar(Matriz[col][i]);
        }
    }
    i=fila-1;
    if(-1<i && i<tam && col<tam && fila<tam && (dire==2 || dire==0)){
        if(Matriz[col][i]->getFree()){
            adyacentes.agregar(Matriz[col][i]);
            cout<<Matriz[col][i]->toString()<<endl;
        }
    }
    i=col+1;
    if(-1<i && i<tam && col<tam && fila<tam && (dire==3 || dire==0)){
        if(Matriz[i][fila]->getFree()){
            adyacentes.agregar(Matriz[i][fila]);
            cout<<Matriz[i][fila]->toString()<<endl;
        }
    }
    i=col-1;
    if(-1<i && i<tam && col<tam && fila<tam && (dire==3 || dire==0)){
        if(Matriz[i][fila]->getFree()){
            adyacentes.agregar(Matriz[i][fila]);
            cout<<Matriz[i][fila]->toString()<<endl;
        }
    }
}

void Tablero::generarPiezas(){
    for (int fila=0; fila<tam;fila++){
        for (int col=0; col<tam;col++){
            Pieza *p= new Pieza(col*50,fila*50);
            Matriz[col][fila]=p;
        }
    }

}


void Tablero::generarFichas(){
    srand(time(NULL));
    char letras[26]={'A','B','C','D','E','F','G',
                    'H','I','J','K','L','M','N',
                    'O','P','Q','R','S','T','U',
                     'V','W','X','Y','Z'};
    for (int fila=0; fila<4;fila++){
        for (int col=0; col<3;col++){
            char letra=letras[rand()%26];
            Ficha *p= new Ficha(col*80+700,fila*80+100,letra);
            listaFichas[col][fila]=p;
        }
    }
}



void Tablero::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    for (int fila=0; fila<tam;fila++){
        for (int col=0; col<tam;col++){
            int x=Matriz[col][fila]->getFil();
            int y=Matriz[col][fila]->getCol();
            dibujar->paint(&painter,x,y,fondo);

        }
    }

    for (int fila=0; fila<4;fila++){
        for (int col=0; col<3;col++){
            int x=listaFichas[col][fila]->getFil();
            int y=listaFichas[col][fila]->getCol();
            char letra= listaFichas[col][fila]->getLetra();
            dibujar->paint2(&painter,x,y,letra,QBrush(Qt::yellow));
        }
    }

    for (int q=0; q<adyacentes.tamano();q++){
        //cout<<"el nodo"<<endl;

        int x=adyacentes.retornar(q)->getDato()->getFil();
        int y=adyacentes.retornar(q)->getDato()->getCol();
        dibujar->paint(&painter,x,y,QBrush(Qt::green));
    }

    painter.end();


    enviar = new QPushButton("Enviar",this);
    enviar->setGeometry(QRect(QPoint(700,20),QSize(210,40)));
    enviar->setVisible(true);
    connect(enviar,SIGNAL(released()),this,SLOT(handleButton()));

    eliminar = new QPushButton("Eliminar",this);
    eliminar->setGeometry(QRect(QPoint(700,425),QSize(210,40)));
    eliminar->setVisible(true);
    connect(eliminar,SIGNAL(released()),this,SLOT(handleButton2()));

    pasar = new QPushButton("Pasar",this);
    pasar->setGeometry(QRect(QPoint(700,475),QSize(210,40)));
    pasar->setVisible(true);
    connect(pasar,SIGNAL(released()),this,SLOT(handleButton3()));

    salir = new QPushButton("Salir",this);
    salir->setGeometry(QRect(QPoint(700,525),QSize(210,40)));
    salir->setVisible(true);
    connect(salir,SIGNAL(released()),this,SLOT(handleButton4()));
}

void Tablero::mousePressEvent(QMouseEvent *event){
    for (int fila=0;fila<4;fila++){
        for (int col = 0; col < 3; col++) {
            int fichaX=listaFichas[col][fila]->getFil();
            int fichaY=listaFichas[col][fila]->getCol();
            if(event->x()<fichaX+50 && event->x()>fichaX && event->y()<fichaY+50 && event->y()>fichaY){
                cout<<fichaX<<" "<<fichaY<<endl;
                fichaSelec=listaFichas[col][fila];
                ponerFCol=col;
                ponerFFil=fila;
                //ponerF=q;
                cout<<"ficha seleccionada "<<"("<<col<<","<<fila<<")"<<endl;
            }
        }
    }

    for (int fila=0;fila<tam;fila++){
        for (int col = 0; col < tam; col++) {
            int piezaX=Matriz[col][fila]->getFil();
            int piezaY=Matriz[col][fila]->getCol();
            if(event->x()<piezaX+50 && event->x()>piezaX && event->y()<piezaY+50 && event->y()>piezaY){
                cout<<piezaX<<" "<<piezaY<<endl;
                piezaSelec=Matriz[col][fila];
                ponerPCol=col;
                ponerPFil=fila;
                cout<<"pieza seleccionada "<<"("<<col<<","<<fila<<")"<<endl;
            }
        }
    }


    cout<<"ESTO SE ENVIA"<<ponerPCol<<ponerPFil<<endl;
    cout<<"ESTO SE ENVIA"<<ponerFCol<<ponerFFil<<endl;
    if (fichaSelec!=nullptr && piezaSelec!=nullptr){
        if (dire==0 && piezaActCol!=-1 && piezaActFila!=-1){
            adyacentes2=adyacentes;
            direccion2(piezaSelec);
            asignarFicha(ponerPCol,ponerPFil,ponerFCol,ponerFFil);
        } else {
            asignarFicha(ponerPCol,ponerPFil,ponerFCol,ponerFFil);
        }

    }

}
void Tablero::asignarFicha(int piezaCol, int piezaFila, int fichaCol, int fichaFila){
    if (piezaActCol==-1 && piezaActFila==-1){
        piezaActCol=piezaCol;
        piezaActFila=piezaFila;
        adyacentes.limpiar();
        Matriz[piezaCol][piezaFila]->setFletra(listaFichas[fichaCol][fichaFila]);
        generarAdyacentes(piezaCol,piezaFila);
    } else if (verificarDireccion(piezaCol,piezaFila)){
        cout<<"pasa veri"<<endl;
        piezaActCol=piezaCol;
        piezaActFila=piezaFila;
        adyacentes.limpiar();
        cout<<"pieza"<<piezaCol<<piezaFila<<endl;
        cout<<"ficha"<<fichaCol<<fichaFila<<endl;
        Matriz[piezaCol][piezaFila]->setFletra(listaFichas[fichaCol][fichaFila]);
        cout<<"se añande fletra"<<endl;
        generarAdyacentes(piezaCol,piezaFila);
    }
    ponerFCol=-1;
    ponerFFil=-1;
    ponerPCol=-1;
    ponerPFil=-1;
    fichaSelec=nullptr;
    piezaSelec=nullptr;
    repaint();
}
bool Tablero::verificarDireccion(int piezaCol, int piezaFila){
    cout<<"veri"<<endl;
    if (dire==1 && piezaActFila + 1 == piezaFila){
        return true;
    } else if (dire==2 && piezaActFila - 1 == piezaFila){
        return true;
    } else if (dire==3 && piezaActCol + 1 == piezaCol){
        return true;
    } else if (dire==4 && piezaActCol - 1 == piezaCol){
        return true;
    }
    return false;
}

void Tablero::handleButton()
{
    contCol++;
    cout<<contCol<<","<<contfila<<endl;
    if (contCol==12){
        contCol=0;
        contfila++;
    }
    generarAdyacentes(contCol,contfila);
    repaint();
}
void Tablero::handleButton2()
{

}
void Tablero::handleButton3()
{

}
void Tablero::handleButton4()
{

    repaint();
}
