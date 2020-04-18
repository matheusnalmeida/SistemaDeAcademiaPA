#include "sistemadeacademia.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SistemaDeAcademia w;
    w.show();
    return a.exec();
}
