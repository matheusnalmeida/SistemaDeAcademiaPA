#include "src/controller/login.h"
#include "src/controller/dialogcadastro.h"
#include "src/utils/matriculagenerator.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_Screen(w);
    w.show();
    return a.exec();
}
