#ifndef CREAR_H
#define CREAR_H

#include <QDialog>

namespace Ui {
class Crear;
}

class Crear : public QDialog
{
    Q_OBJECT

public:
    void crear_rnd();
    explicit Crear(QWidget *parent = nullptr);
    ~Crear();

private slots:
    void on_pushButton_clicked();

private:
    int JuegoID;
    Ui::Crear *ui;
};

#endif // CREAR_H
