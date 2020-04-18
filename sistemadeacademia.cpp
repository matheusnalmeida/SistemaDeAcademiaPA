#include "sistemadeacademia.h"
#include "ui_sistemadeacademia.h"

SistemaDeAcademia::SistemaDeAcademia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SistemaDeAcademia)
{
    ui->setupUi(this);
}

SistemaDeAcademia::~SistemaDeAcademia()
{
    delete ui;
}

