#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>

Login_Screen::Login_Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_Screen)
{
    ui->setupUi(this);
    //Imagem de fundo
    QPixmap bkgnd("src/resources/login_background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //Imagem do label principal ta tela de login
    QPixmap pix_main_login("src/resources/icone_academia.png");
    this->ui->label_main_login->setPixmap(pix_main_login);
    //Imagem do label de login
    QPixmap pix_user("src/resources/username_icon.png");
    this->ui->label_user_icon->setPixmap(pix_user);
    //Imagem do label de senha
    QPixmap pix_password("src/resources/password_icon.png");
    this->ui->label_password_icon->setPixmap(pix_password);
}

Login_Screen::~Login_Screen()
{
    delete ui;
}

void Login_Screen::on_login_button_clicked()
{
    QMessageBox::about(this,"My Title","Hello");
}
