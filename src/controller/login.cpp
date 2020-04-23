#include "login.h"
#include "ui_login.h"
#include "dialogcadastro.h"
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QMainWindow>
#include "teladeusuario.h"

Login_Screen::Login_Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_Screen)
{
    ui->setupUi(this);
    //Imagem do label principal ta tela de login
    QPixmap pix_main_login(":/imagem/src/resources/icone_academia.png");
    this->ui->label_main_login->setPixmap(pix_main_login);
    //Imagem do label de login
    QPixmap pix_user(":/imagem/src/resources/username_icon.png");
    this->ui->label_user_icon->setPixmap(pix_user);
    //Imagem do label de senha
    QPixmap pix_password(":/imagem/src/resources/password_icon.png");
    this->ui->label_password_icon->setPixmap(pix_password);
}

void Login_Screen::closeEvent(QCloseEvent *event){
    if (event->spontaneous()) {
        QMessageBox::about(this,"My Title","Hello");
        // do event->ignore();
        // or QWidget::closeEvent(event);
    } else {
        QWidget::closeEvent(event);
    }
}

Login_Screen::~Login_Screen()
{
    delete ui;
}

void Login_Screen::on_login_button_clicked()
{
    teladeusuario *tela = new teladeusuario();
    tela->show();
    this->hide();
}

void Login_Screen::on_cadastrar_button_clicked()
{
    this->close();
    DialogCadastro cadastro_dialog(nullptr,this);
    cadastro_dialog.exec();
}
