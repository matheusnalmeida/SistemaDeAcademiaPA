#include "dialogmostrarusuarios.h"
#include "ui_dialogmostrarusuarios.h"
#include <map>
#include "QListWidgetItem"
#include "QMessageBox"
#include "QCloseEvent"
DialogMostrarUsuarios::DialogMostrarUsuarios(QWidget *parent, QWidget *prev_window, BancoDeDados *banco) :
    QDialog(parent),
    ui(new Ui::DialogMostrarUsuarios)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->banco = banco;
    std::map<QString , Pessoa*>* bancoMatricula = banco->getBancoMatricula();
    std::map<QString, Pessoa*>::iterator itr;
    for (itr = bancoMatricula->begin(); itr != bancoMatricula->end(); ++itr) {


        if(itr->second->getMatricula().at(itr->second->getMatricula().length()-1) == 'a'){

            QListWidgetItem * item = new QListWidgetItem(itr->first);
            item->setTextAlignment(Qt::AlignHCenter);
            QFont serifFont("Consolas", 20, QFont::Bold);
            item->setFont(serifFont);
            this->ui->listaWidgte->addItem(item);


    }
    }

}

void DialogMostrarUsuarios::closeEvent(QCloseEvent *event){
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

DialogMostrarUsuarios::~DialogMostrarUsuarios()
{

    delete ui;
}
