#include "analizador_lexico.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Analizador_lexico w;
    w.show();
    return a.exec();
}
