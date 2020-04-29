#include "src/controller/login.h"
#include "src/controller/dialogcadastro.h"
#include "src/utils/matriculagenerator.h"
#include <QDebug>
#include <QApplication>
#include <map>
#include <string>
#include <iostream>
#include "src/controller/dialogmostrarusuarios.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_Screen(w);
    w.show();
    return a.exec();
}
