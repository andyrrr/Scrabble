#include "ingresar.h"
#include "scrabble.h"
#include "ui_ingresar.h"

Ingresar::Ingresar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingresar)
{
    ui->setupUi(this);
}

Ingresar::~Ingresar()
{
    delete ui;
}

void Ingresar::on_pushButton_clicked()
{
    scrabble *sc = new scrabble ();
    sc->show();
    this->hide();
}
