#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SistemaDeAcademia.h"

class SistemaDeAcademia : public QMainWindow
{
	Q_OBJECT

public:
	SistemaDeAcademia(QWidget *parent = Q_NULLPTR);

private:
	Ui::SistemaDeAcademiaClass ui;
};
