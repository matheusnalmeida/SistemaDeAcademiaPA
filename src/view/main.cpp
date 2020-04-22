#include "src/controller/login.h"
#include "src/controller/teladecadastro.h"

#include <QApplication>

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    Login_Screen w;

    w.show();
    return a.exec();
}
