#include "mainwindow.h"
#include "crear.h"
#include "ingresar.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Crear *cr = new Crear();
    cr->show();
    this->hide();

}

void MainWindow::on_pushButton_2_clicked()
{
    Ingresar *ing = new Ingresar();
    ing->show();
    this->hide();

}
