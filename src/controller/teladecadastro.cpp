#include "teladecadastro.h"
#include "ui_teladecadastro.h"
#include <QCloseEvent>
#include <QGraphicsDropShadowEffect>

TelaDeCadastro::TelaDeCadastro(QWidget *parent,QWidget* prev_wind) :
    QWidget(parent),
    ui(new Ui::TelaDeCadastro)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    ui->widget->setGraphicsEffect(effect);
    //Configurando input masks nos camps de cpf e cep
    this->ui->text_cpf->setInputMask( "000\\.000\\.000\\-00" );
    this->ui->text_cep->setInputMask( "00\\.000\\-000" );
    this->prev_wind = prev_wind;
}


void TelaDeCadastro::closeEvent(QCloseEvent *event){
    if (event->spontaneous()) {
        this->prev_wind->show();
        this->hide();
    } else {
        QWidget::closeEvent(event);
    }
}


TelaDeCadastro::~TelaDeCadastro()
{
    delete ui;
}
