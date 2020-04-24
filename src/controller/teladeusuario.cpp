#include "teladeusuario.h"
#include "ui_teladeusuario.h"
#include <QMessageBox>
#include <QCloseEvent>

teladeusuario::teladeusuario(QWidget *parent,QWidget *prev_window) :
    QWidget(parent),
    ui(new Ui::teladeusuario)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    //Colcando icones na tela
    QPixmap pix_icon(":/imagem/src/resources/imagem_icon.jpg");
    this->ui->icon_default->setPixmap(pix_icon);
}

void teladeusuario::closeEvent(QCloseEvent *event){
    if (event->spontaneous()) {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Logout",
                                                                  "Deseja finalizar a sessão?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            this->prev_window->show();
            this->hide();
        }else{
            event->ignore();
        }
    } else {
        QWidget::closeEvent(event);
    }
}

teladeusuario::~teladeusuario()
{
    delete ui;
}
