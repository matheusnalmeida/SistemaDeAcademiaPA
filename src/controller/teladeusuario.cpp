#include "teladeusuario.h"
#include "ui_teladeusuario.h"
#include <QMessageBox>
#include <QCloseEvent>
#include "QListWidgetItem"
teladeusuario::teladeusuario(QWidget *parent,QWidget *prev_window,Pessoa* usuario) :
    QWidget(parent),
    ui(new Ui::teladeusuario)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->usuario = (Usuario*) usuario;
    this->preencherDados();
    //Colcando icones na tela
    QPixmap pix_icon(":/imagem/src/resources/imagem_icon.jpg");
    this->ui->icon_default->setPixmap(pix_icon);
}

teladeusuario::~teladeusuario()
{
    delete ui;
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

void teladeusuario::preencherDados(){
    this->ui->texto_nome->setText(this->usuario->getNome());
    this->ui->texto_cpf->setText(this->usuario->getCpf());
    this->ui->texto_telefone->setText(this->usuario->getTelefone());
    this->ui->texto_bairro->setText(this->usuario->getEndereco()->getBairro());
    this->ui->texto_cidade->setText(this->usuario->getEndereco()->getCidade());
    this->ui->texto_email->setText(this->usuario->getEmail());
    this->ui->texto_logradouro->setText(this->usuario->getEndereco()->getLogradouro());
    this->ui->texto_uf->setText(this->usuario->getEndereco()->getUf());
    std::map<QString, Treino*>* treinos = this->usuario->getTreinos();
     std::map<QString, Treino*>::iterator itr;
    if(treinos->size() != 0){
        for (itr = treinos->begin(); itr != treinos->end(); ++itr) {
            QListWidgetItem * item = new QListWidgetItem(itr->first);
            item->setTextAlignment(Qt::AlignHCenter);
            QFont serifFont("Consolas", 20, QFont::Bold);
            item->setFont(serifFont);
            this->ui->listWidget->addItem(item);
        }
    }
}


void teladeusuario::on_listWidget_itemClicked(QListWidgetItem *item)
{
    std::map<QString,Treino*>::iterator it = this->usuario->getTreinos()->find(item->text());
    dialogmostrartreino* tela_do_treino = new dialogmostrartreino(nullptr,this,it->second);
    tela_do_treino->exec();
}
