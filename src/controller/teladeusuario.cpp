#include "teladeusuario.h"
#include "ui_teladeusuario.h"

teladeusuario::teladeusuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teladeusuario)
{
    ui->setupUi(this);
    QPixmap pix_icon(":/imagem/src/resources/imagem_icon.jpg");
    this->ui->icon_default->setPixmap(pix_icon);
}

teladeusuario::~teladeusuario()
{
    delete ui;
}
