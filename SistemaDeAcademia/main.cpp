#include "SistemaDeAcademia.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SistemaDeAcademia w;
	w.show();
	return a.exec();
}
