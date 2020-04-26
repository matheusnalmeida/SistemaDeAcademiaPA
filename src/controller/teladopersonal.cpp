#include "teladopersonal.h"
#include "ui_teladopersonal.h"
#include "QMessageBox"
#include "QCloseEvent"
Teladopersonal::Teladopersonal(QWidget *parent, QWidget *prev_window,Pessoa* usuario) :
    QWidget(parent),
    ui(new Ui::Teladopersonal)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->usuario = usuario;
    this->preencherDados();
    //Colcando icones na tela
    QPixmap pix_icon(":/imagem/src/resources/imagem_icon.jpg");
    this->ui->icon_default->setPixmap(pix_icon);
}

Teladopersonal::~Teladopersonal()
{
    delete ui;
}

void Teladopersonal::closeEvent(QCloseEvent *event){
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

void Teladopersonal::preencherDados(){
    this->ui->texto_nome->setText(this->usuario->getNome());
    this->ui->texto_cpf->setText(this->usuario->getCpf());
    this->ui->texto_telefone->setText(this->usuario->getTelefone());
    this->ui->texto_bairro->setText(this->usuario->getEndereco()->getBairro());
    this->ui->texto_cidade->setText(this->usuario->getEndereco()->getCidade());
    this->ui->texto_email->setText(this->usuario->getEmail());
    this->ui->texto_logradouro->setText(this->usuario->getEndereco()->getLogradouro());
    this->ui->texto_uf->setText(this->usuario->getEndereco()->getUf());
}
