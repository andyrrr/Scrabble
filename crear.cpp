#include "crear.h"
#include "scrabble.h"
#include "ui_crear.h"
#include "tablero.h"
int JuegoID;
Crear::Crear(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crear)
{
    ui->setupUi(this);
    crear_rnd();


}
void Crear::crear_rnd(){
    srand (time(NULL));
   int id = rand() %(999999-100000)+100000+1;
   ui->label_2->setNum(id);
   this->JuegoID=id;

}
Crear::~Crear()
{
    delete ui;
}

void Crear::on_pushButton_clicked()
{
    scrabble *sc = new scrabble ();
    sc->setID(JuegoID);
    sc->show();
    this->hide();

}
