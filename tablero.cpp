#include "tablero.h"
#include "dibujar.h"
#include "listaPieza.h"

#include <QPainter>
#include <QPushButton>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include<time.h>
#include "Lista.h"
#include "funcionescliente.h"

using namespace std;
Lista *ls = new Lista();
FuncionesCliente *fnC = new FuncionesCliente();


Tablero::Tablero(Dibujar *dibujar,QWidget *parent):QWidget(parent),dibujar(dibujar)
{
    setFixedSize(1000,600);
    fondo= QBrush(QColor(64,32,64));
    ListaPieza piezas;
    generarPiezas();
    generarFichas();
    palabraFormada="";
}


bool Tablero::direccion(Pieza *mov){
    cout<<"entra"<<endl;
    for (int p=0;p<adyacentes2.tamano();p++){
        if(adyacentes2.retornar(p)->getDato()==mov){
            cout<<"esta en adyacentes"<<endl;
            for (int fila=0;fila<tam;fila++){
                for (int col=0; col<tam; col++){
                    if (Matriz[col][fila]==mov){
                        int cont=0;
                        while (Matriz[col][piezaActFila+cont]->getFree()==false && cont<tam){
                            cont++;
                        }
                        if(piezaActFila+cont==fila && piezaActCol==col){
                            cout<<"fila Act"<<piezaActFila+cont<<"fila mov"<<fila<<endl;
                            dire=1;
                            return true;
                        }

                        cont=0;
                        while (Matriz[col][piezaActFila-cont]->getFree()==false && cont<tam){
                            cont++;
                        }

                        if(piezaActFila-cont==fila && piezaActCol==col){
                            dire=2;
                            return true;
                        }

                        cont=0;
                        while (Matriz[piezaActCol+cont][fila]->getFree()==false && cont<tam){
                            cont++;
                        }

                        if(piezaActCol+cont==col && piezaActFila==fila){
                            dire=3;
                            return true;
                        }

                        cont=0;
                        while (Matriz[piezaActCol-cont][fila]->getFree()==false && cont<tam){
                            cont++;
                        }

                        if(piezaActCol-cont==col && piezaActFila==fila){
                            dire=4;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}




void Tablero::generarAdyacentes(int col, int fila){
    cout<<"llega ga2"<<endl;
    cout<<"dire"<<dire<<endl;
    adyacentes2=adyacentes;
    adyacentes.limpiar();
    int i=0;
    while(Matriz[col][fila+i]->getFree()==false){
        i++;
    }
    if(fila+i<tam && col<tam && fila<tam && (dire==1 || dire==0)){
        cout<<Matriz[col][fila+i]->toString()<<endl;
        adyacentes.agregar(Matriz[col][fila+i]);
    }
    i=0;
    while(Matriz[col][fila-i]->getFree()==false){
        i++;
        if (fila-i==-1){
            break;
        }
    }

    if(-1<fila-i && col<tam && fila<tam && (dire==2 || dire==0)){
        cout<<Matriz[col][fila-i]->toString()<<endl;
        adyacentes.agregar(Matriz[col][fila-i]);
    }

    i=0;
    while(Matriz[col+i][fila]->getFree()==false){
        i++;
    }
    if(col+1<tam && col<tam && fila<tam && (dire==3 || dire==0)){
        cout<<Matriz[col+i][fila]->toString()<<endl;
        adyacentes.agregar(Matriz[col+i][fila]);
    }

    i=0;
    while(Matriz[col-i][fila]->getFree()==false){
        i++;
        if (col-i==-1){
            break;
        }
    }

    if(-1<col-i && col<tam && fila<tam && (dire==4 || dire==0)){
        cout<<Matriz[col-i][fila]->toString()<<endl;
        adyacentes.agregar(Matriz[col-i][fila]);
    }


}


void Tablero::generarPiezas(){
    for (int fila=0; fila<tam;fila++){
        for (int col=0; col<tam;col++){
            Pieza *p= new Pieza(col*40,fila*40);
            Matriz[col][fila]=p;
            Pieza *p2= new Pieza(col*40,fila*40);
            MatrizBack[col][fila]=p2;
        }
    }

}


void Tablero::generarFichas(){
    srand(time(NULL));
    char *letras[]={"A","B","C","D","E","F","G",
                    "H","I","J","K","L","M","N",
                    "O","P","Q","R","S","T","U",
                     "V","W","X","Y","Z"};
    for (int fila=0; fila<4;fila++){
        for (int col=0; col<4;col++){
            char *letra=letras[rand()%26];
            std::string s(letra);
            Ficha *p= new Ficha(col*60+700,fila*80+100,s);
            listaFichas[col][fila]=p;
            Ficha *p2= new Ficha(col*60+700,fila*80+100,s);
            listaFichasBack[col][fila]=p2;
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
        for (int col=0; col<4;col++){
            int x=listaFichas[col][fila]->getFil();
            int y=listaFichas[col][fila]->getCol();
            std::string letra= listaFichas[col][fila]->getLetra();
            QPen contorno= listaFichas[col][fila]->getContorno();
            dibujar->paint2(&painter,x,y,letra,contorno);
        }
    }

    for (int q=0; q<adyacentes.tamano();q++){

        int x=adyacentes.retornar(q)->getDato()->getFil();
        int y=adyacentes.retornar(q)->getDato()->getCol();
        dibujar->paint(&painter,x,y,QBrush(Qt::green));
    }

    painter.end();


    enviar = new QPushButton("Enviar",this);
    enviar->setGeometry(QRect(QPoint(700,20),QSize(220,40)));
    enviar->setVisible(true);
    connect(enviar,SIGNAL(released()),this,SLOT(handleEnviar()));

    eliminar = new QPushButton("Eliminar",this);
    eliminar->setGeometry(QRect(QPoint(700,425),QSize(220,40)));
    eliminar->setVisible(true);
    connect(eliminar,SIGNAL(released()),this,SLOT(handleEliminar()));

    pasar = new QPushButton("Pasar",this);
    pasar->setGeometry(QRect(QPoint(700,475),QSize(220,40)));
    pasar->setVisible(true);
    connect(pasar,SIGNAL(released()),this,SLOT(handlePasar()));

    salir = new QPushButton("Salir",this);
    salir->setGeometry(QRect(QPoint(700,525),QSize(220,40)));
    salir->setVisible(true);
    connect(salir,SIGNAL(released()),this,SLOT(handleSalir()));
}

void Tablero::mousePressEvent(QMouseEvent *event){
    for (int fila=0;fila<4;fila++){
        for (int col = 0; col < 4; col++) {
            int fichaX=listaFichas[col][fila]->getFil();
            int fichaY=listaFichas[col][fila]->getCol();
            if(event->x()<fichaX+40 && event->x()>fichaX && event->y()<fichaY+40 && event->y()>fichaY){
                if (fichaSelec!=nullptr){
                    fichaSelec->setContorno(QPen(Qt::black));
                }
                fichaSelec=listaFichas[col][fila];
                fichaSelec->setContorno(QPen(Qt::red));
                ponerFCol=col;
                ponerFFil=fila;
                cout<<"ficha seleccionada "<<"("<<col<<","<<fila<<")"<<endl;
                repaint();
            }
        }
    }

    for (int fila=0;fila<tam;fila++){
        for (int col = 0; col < tam; col++) {
            int piezaX=Matriz[col][fila]->getFil();
            int piezaY=Matriz[col][fila]->getCol();
            if(event->x()<piezaX+40 && event->x()>piezaX && event->y()<piezaY+40 && event->y()>piezaY && fichaSelec!=nullptr){
                cout<<piezaX<<" "<<piezaY<<endl;
                piezaSelec=Matriz[col][fila];
                ponerPCol=col;
                ponerPFil=fila;
                cout<<"pieza seleccionada "<<"("<<col<<","<<fila<<")"<<endl;
            }
        }
    }

    if (fichaSelec!=nullptr && piezaSelec!=nullptr){
        if (dire==0 && piezaActCol!=-1 && piezaActFila!=-1){
            adyacentes2=adyacentes;
            if(direccion(piezaSelec)){
                asignarFicha(ponerPCol,ponerPFil,ponerFCol,ponerFFil);
            }
        } else if (fichaSelec->getCol()!=piezaSelec->getCol() && fichaSelec->getFil()!=piezaSelec->getFil()){
            asignarFicha(ponerPCol,ponerPFil,ponerFCol,ponerFFil);
        }

    }

}
void Tablero::asignarFicha(int piezaCol, int piezaFila, int fichaCol, int fichaFila){
    fichaSelec->setContorno(QPen(Qt::black));
    /**
      ls->addLetra(letra,piezaFila,piezaCol); lo que hace es agregar la letra en mi lista, obteniendoi los
      valores de las posiciones, y aqui es donde me està dando el error.
      La primer letra, y por ende los primeros valores de Columna y Fila al parecer no tienen ningun dato
      entonces cuando se imprime el json, la primer letra no posee la posicion como las demàs.s
      */
    cout<<"pieza actual"<<piezaActCol<<piezaActFila<<endl;
    if ((piezaActCol==-1 && piezaActFila==-1) || verificarDireccion(piezaCol,piezaFila)){
        piezaActCol=piezaCol;
        piezaActFila=piezaFila;
        adyacentes.limpiar();
        int cont=0;
        //cout<<"direccion PPP"<<dire<<endl;
        Matriz[piezaCol][piezaFila]->setFletra(listaFichas[fichaCol][fichaFila]);
        generarAdyacentes(piezaCol,piezaFila);
        if(dire==1 || dire==0){
            //cout<<(Matriz[piezaActCol][piezaActFila+cont]->getFree()==false)<<endl;
            //cout<<(1==1)<<endl;
            while (cont<tam && Matriz[piezaActCol][piezaActFila+cont]->getFree()==false){
                int columna = piezaActCol;
                int fila = piezaActFila+cont;
                std::string letra = Matriz[piezaActCol][piezaActFila+cont]->getFletra()->getLetra();
                palabraFormada=palabraFormada+letra;
                cont++;
                ls->addLetra(letra,piezaFila,piezaCol);
                //cout<<"letraagregada"<<endl;
            }
        }
        if(dire==2 || dire==0){
            //cout<<(Matriz[piezaActCol][piezaActFila+cont]->getFree()==false)<<endl;
            //cout<<(1==1)<<endl;
            while (-1<piezaActFila-cont && Matriz[piezaActCol][piezaActFila-cont]->getFree()==false){
                int columna = piezaActCol;
                int fila = piezaActFila-cont;
                std::string letra = Matriz[piezaActCol][piezaActFila-cont]->getFletra()->getLetra();
                palabraFormada=palabraFormada+ letra;
                cont++;
                ls->addLetra(letra,piezaFila,piezaCol);
                //cout<<"letraagregada"<<endl;
            }
        }
        if(dire==3 || dire==0){
            //cout<<(Matriz[piezaActCol][piezaActFila+cont]->getFree()==false)<<endl;
            //cout<<(1==1)<<endl;

            while (cont<tam && Matriz[piezaActCol+cont][piezaActFila]->getFree()==false){
                int columna = piezaActCol+cont;
                int fila = piezaActFila;
                std::string letra = Matriz[piezaActCol+cont][piezaActFila]->getFletra()->getLetra();
                palabraFormada=palabraFormada+letra;
                cont++;
                ls->addLetra(letra,piezaFila,piezaCol);
                //cout<<"letraagregada"<<endl;
            }
        }

        if(dire==4 || dire==0){
            //cout<<(Matriz[piezaActCol][piezaActFila+cont]->getFree()==false)<<endl;
            //cout<<(1==1)<<endl;
            while (-1<piezaActCol-cont && Matriz[piezaActCol-cont][piezaActFila]->getFree()==false){
                int columna = piezaActCol-cont;
                int fila = piezaActFila;
                std::string letra = Matriz[piezaActCol-cont][piezaActFila]->getFletra()->getLetra();
                palabraFormada=palabraFormada+letra;
                cont++;
                ls->addLetra(letra,piezaFila,piezaCol);

                //cout<<"letraagregada"<<endl;
            }
        }

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
    for (int q=0; q<adyacentes.tamano();q++){
        if (Matriz[piezaCol][piezaFila]==adyacentes.retornar(q)->getDato()){
            return true;
        }
    }
    return  false;

}

void Tablero::handleEnviar()
{
    /*contCol++;
    cout<<contCol<<","<<contfila<<endl;
    if (contCol==15){
        contCol=0;
        contfila++;
    }
    generarAdyacentes(contCol,contfila);
    repaint();*/
    cout<<"entra"<<endl;
    /**
     * @brief jsonGen
     * Aqui lo que hace es hacer un archivo Json a partir de la funcion en "funcionescliente",
     * el jsonGen.dump() imprime el Json en consola.
     */
    json jsonGen = fnC->generarJson(*ls);
    cout << jsonGen.dump(2)<<endl;
    cout<<palabraFormada<<endl;
    for (int fila=0;fila<tam;fila++){
        for (int col=0;col<tam;col++){
            int filaB=Matriz[col][fila]->getFil();
            int colB=Matriz[col][fila]->getCol();
            MatrizBack[col][fila]->setFil(filaB);
            MatrizBack[col][fila]->setCol(colB);
            MatrizBack[col][fila]->setFletra(Matriz[col][fila]->getFletra());
            Matriz[col][fila]->setFree(MatrizBack[col][fila]->getFree());

        }
    }
    cout<<"respalda matriz"<<endl;

    for (int fila=0;fila<4;fila++){
        for (int col=0;col<4;col++){
            int filaB=listaFichas[col][fila]->getFil();
            int colB=listaFichas[col][fila]->getCol();
            listaFichasBack[col][fila]->setFil(filaB);
            listaFichasBack[col][fila]->setCol(colB);

        }
    }
    cout<<"respalda fichas"<<endl;
    adyacentes.limpiar();
    adyacentes2.limpiar();

    inicializar();
    ls->clear();

}

void Tablero::inicializar(){
    ponerPCol=-1;
    ponerPFil=-1;
    ponerFCol=-1;
    ponerFFil=-1;

    piezaActCol=-1;
    piezaActFila=-1;

    dire=0;

    fichaSelec=nullptr;
    piezaSelec=nullptr;

    palabraFormada="";

    repaint();
}
void Tablero::handleEliminar()
{
    for (int fila=0;fila<tam;fila++){
        for (int col=0;col<tam;col++){
            int filaB=MatrizBack[col][fila]->getFil();
            int colB=MatrizBack[col][fila]->getCol();
            Matriz[col][fila]->setFil(filaB);
            Matriz[col][fila]->setCol(colB);
            Matriz[col][fila]->setFletra(MatrizBack[col][fila]->getFletra());
            Matriz[col][fila]->setFree(MatrizBack[col][fila]->getFree());

        }
    }

    for (int fila=0;fila<4;fila++){
        for (int col=0;col<4;col++){
            int filaB=listaFichasBack[col][fila]->getFil();
            int colB=listaFichasBack[col][fila]->getCol();
            listaFichas[col][fila]->setFil(filaB);
            listaFichas[col][fila]->setCol(colB);
        }
    }
    adyacentes.limpiar();
    inicializar();


}
void Tablero::handlePasar()
{

}
void Tablero::handleSalir()
{
    exit(true);
}
