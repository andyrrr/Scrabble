#include "crear.h"
#include "scrabble.h"
#include "ui_crear.h"

Crear::Crear(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crear)
{
    ui->setupUi(this);
    crear_rnd();

}
void Crear::crear_rnd(){
    srand (time(NULL));
   int id = rand() %9999+1;
   ui->label_2->setNum(id);

}
Crear::~Crear()
{
    delete ui;
}

void Crear::on_pushButton_clicked()
{
    scrabble *sc = new scrabble ();
    sc->show();
    this->hide();
}
