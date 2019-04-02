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
bool Tablero::direccion(Pieza *mov, int num){
    cout<<"entra"<<endl;
    for (int p=0;p<adyacentes2.tamano();p++){
        if(adyacentes2.retornar(p)->getDato()==mov){
            cout<<"está en adyacentes"<<endl;
            for (int q=0;q<piezas.tamano();q++){
                if (piezas.retornar(q)->getDato()==mov){
                    cout<<"esté en piezas"<<q<<endl;
                    if(num+tam==q){
                        dire=1;
                    } else if (num-tam==q) {
                        dire=2;
                    } else if(num+1==q){
                        dire=3;
                    } else if(num-1==q){
                        dire=4;
                    } else if(num+1+tam==q){
                        dire=5;
                    } else if(num-1-tam==q){
                        dire=6;
                    } else if(num+tam-1==q){
                        dire=7;
                    } else if(num-tam+1==q){
                        dire=8;
                    }
                    cout<<"dire: "<<dire<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}



void Tablero::generarAdyacentes(int x){
    adyacentes2=adyacentes;
    adyacentes.limpiar();
    int i=x+tam;
    if(-1<i && i<tam*tam && piezas.retornar(i)->getDato()->getFree()){
        if(dire==1 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x-tam;
    if(-1<i && i<tam*tam && piezas.retornar(i)->getDato()->getFree()){
        if(dire==2 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x+1;
    if(-1<i && i<tam*tam && (x+1)%tam!=0 && piezas.retornar(i)->getDato()->getFree()){
        if(dire==3 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x-1;
    if(-1<i && i<tam*tam && x%tam!=0 && piezas.retornar(i)->getDato()->getFree()){
        if(dire==4 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x+tam+1;
    if(-1<i && x+1+tam<tam*tam && (x+1)%tam && piezas.retornar(i)->getDato()->getFree()){
        if(dire==5 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x-1-tam;
    if(-1<i && i<tam*tam && x%tam!=0 && piezas.retornar(i)->getDato()->getFree()){
        if(dire==6 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x+tam-1;
    if(-1<i && i<tam*tam && x!=0 && x%tam!=0 && piezas.retornar(i)->getDato()->getFree()){
        if(dire==7 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }
    i=x-tam+1;
    if(-1<i && i<tam*tam && (x+1)%tam && piezas.retornar(i)->getDato()->getFree()){
        if(dire==8 || dire==0){
            adyacentes.agregar(piezas.retornar(i)->getDato());
        }
    }

}
void Tablero::generarPiezas(){
    for (int i=0; i<tam;i++){
        for (int j=0; j<tam;j++){
            Pieza *p= new Pieza(j*50,i*50);
            piezas.agregar(p);
        }
    }
}

void Tablero::generarFichas(){
    srand(time(NULL));
    char letras[26]={'A','B','C','D','E','F','G',
                    'H','I','J','K','L','M','N',
                    'O','P','Q','R','S','T','U',
                     'V','W','X','Y','Z'};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char letra=letras[rand()%26];
            Ficha *p= new Ficha(j*80+700,i*80+100,letra);
            fichas.agregar(p);
        }
    }
    char letra=letras[rand()%26];
    Ficha *p=new Ficha(1*80+700,3*80+100,letra);
    fichas.agregar(p);
}

void Tablero::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    for (int q=0; q<piezas.tamano();q++){
        //cout<<"el nodo"<<endl;

        int x=piezas.retornar(q)->getDato()->getFil();
        int y=piezas.retornar(q)->getDato()->getCol();
        dibujar->paint(&painter,x,y,fondo);
    }

    for (int q=0; q<fichas.tamano();q++){
        //cout<<"el nodo"<<endl;

        int x=fichas.retornar(q)->getDato()->getFil();
        int y=fichas.retornar(q)->getDato()->getCol();
        char letra = fichas.retornar(q)->getDato()->getLetra();
        dibujar->paint2(&painter,x,y,letra,QBrush(Qt::yellow));
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
    for (int q=0;q<fichas.tamano();q++){
        int fichaX=fichas.retornar(q)->getDato()->getFil();
        int fichaY=fichas.retornar(q)->getDato()->getCol();
        if(event->x()<fichaX+50 && event->x()>fichaX && event->y()<fichaY+50 && event->y()>fichaY){
            cout<<fichaX<<" "<<fichaY<<endl;
            fichaSelec=fichas.retornar(q)->getDato();
            ponerF=q;
            cout<<"ficha seleccionada "<<q<<endl;
        }
    }
    for (int q=0;q<piezas.tamano();q++){
        int piezaX=piezas.retornar(q)->getDato()->getFil();
        int piezaY=piezas.retornar(q)->getDato()->getCol();
        if(event->x()<piezaX+50 && event->x()>piezaX && event->y()<piezaY+50 && event->y()>piezaY){
            cout<<piezaX<<" "<<piezaY<<endl;
            piezaSelec=piezas.retornar(q)->getDato();
            ponerP=q;
            cout<<"pieza seleccionada "<<q<<endl;
        }
    }
    cout<<"estas"<<ponerF<<ponerP<<endl;
    if (ponerF!=-1 && ponerP!=-1){
        cout<<"estas2"<<dire<<piezaAct<<endl;
        if (dire==0 &&piezaAct!=-1){
            adyacentes2=adyacentes;
            direccion(piezaSelec,piezaAct);
            asignarFicha(ponerP,ponerF);
        } else {
            asignarFicha(ponerP,ponerF);
        }

    }
    cout<<event->x()<<endl;
    cout<<event->y()<<endl;

}

void Tablero::asignarFicha(int pieza, int ficha){
    if (piezaAct==-1){
        piezaAct=pieza;
        adyacentes.limpiar();
        piezas.retornar(pieza)->getDato()->setFletra(fichas.retornar(ficha)->getDato());
        generarAdyacentes(pieza);
    } else if (verificarDireccion(pieza)){
        piezaAct=pieza;
        adyacentes.limpiar();
        piezas.retornar(pieza)->getDato()->setFletra(fichas.retornar(ficha)->getDato());
        generarAdyacentes(pieza);
    }

    ponerF=-1;
    ponerP=-1;
    repaint();
}

bool Tablero::verificarDireccion(int pieza){
    if (dire==1 && piezaAct + tam == pieza){
        return true;
    } else if (dire==2 && piezaAct - tam == pieza){
        return true;
    } else if (dire==3 && piezaAct + 1 == pieza){
        return true;
    } else if (dire==4 && piezaAct - 1 == pieza){
        return true;
    } else if (dire==5 && piezaAct + tam +1== pieza){
        return true;
    } else if (dire==6 && piezaAct - tam -1== pieza){
        return true;
    } else if (dire==7 && piezaAct + tam -1== pieza){
        return true;
    } else if (dire==8 && piezaAct - tam +1== pieza){
        return true;
    }
    return false;
}

void Tablero::handleButton()
{
    adyacentes.limpiar();
    cont++;
    cout<<cont<<endl;
    if (cont<piezas.tamano()){
        generarAdyacentes(cont);
    }
    repaint();
}
void Tablero::handleButton2()
{
    asignarFicha(7,0);
}
void Tablero::handleButton3()
{
    adyacentes2=adyacentes;
    if(direccion(piezas.retornar(7+tam)->getDato(),7)){
        asignarFicha(7+tam,1);
    }
}
void Tablero::handleButton4()
{
    piezas.retornar(7+tam+tam+1+1)->getDato()->setFletra(fichas.retornar(5)->getDato());
    generarAdyacentes(7+tam+tam+1+1);
    repaint();
}
