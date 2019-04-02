#include "scrabble.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scrabble w;
    w.resize(1000,600);
    w.show();



    return a.exec();
}
