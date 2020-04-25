#include "login.h"
#include "ui_login.h"
#include "dialogcadastro.h"
#include "teladeusuario.h"
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QMainWindow>

Login_Screen::Login_Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_Screen)
{
    ui->setupUi(this);
    this->banco_de_dados = new BancoDeDados();
    this->cadastrar_dialog = new DialogCadastro(nullptr,this,this->banco_de_dados);
    //Setando mascaras de input
    this->ui->cpf_field->setInputMask( "000\\.000\\.000\\-00" );
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

void Login_Screen::closeEvent(QCloseEvent *event){}

Login_Screen::~Login_Screen()
{
    delete ui;
    delete banco_de_dados;
    delete cadastrar_dialog;
}

void Login_Screen::on_login_button_clicked()
{
    QString cpf_login = this->ui->cpf_field->text();
    QString matricula_login = this->ui->matricula_field->text();
    Pessoa* pessoa_login = this->banco_de_dados->procurar(cpf_login);
    bool matriculaCorreta = matricula_login == pessoa_login->getMatricula();
    if(pessoa_login != nullptr && matriculaCorreta){
            if(pessoa_login->getMatricula().at(pessoa_login->getMatricula().length()-1) == 'a'){
                teladeusuario *tela = new teladeusuario(nullptr,this,pessoa_login);
                tela->show();
                this->hide();
            }else{

            }
    }else{
        QMessageBox::warning(this,"","Nenhum usuário cadastrado com as credenciais informadas!");
    }
}

void Login_Screen::on_cadastrar_button_clicked()
{
    this->close();
    this->cadastrar_dialog->limparCampos();
    this->cadastrar_dialog->exec();
}

void Login_Screen::validaCampos(){
    bool cpfPreenchido = this->ui->cpf_field->text().length() == 14;
    bool matriculaPreenchido = this->ui->matricula_field->text().length() != 0;
    if(cpfPreenchido && matriculaPreenchido){
        this->ui->login_button->setEnabled(true);
        this->ui->login_button->setStyleSheet("background-color: #4CAF50;\
                                                  border: none;\
                                                  color: white;\
                                                  padding: 15px 32px;\
                                                  text-align: center;\
                                                  text-decoration: none;\
                                                  font-size: 16px;\
                                                  margin: 4px 2px;\
                                                  border-radius: 5px;");
    }
    else{
        this->ui->login_button->setEnabled(false);
        this->ui->login_button->setStyleSheet("background-color: #cccccc;\
                                                  border: none;\
                                                  color: white;\
                                                  padding: 15px 32px;\
                                                  text-align: center;\
                                                  text-decoration: none;\
                                                  font-size: 16px;\
                                                  margin: 4px 2px;\
                                                  border-radius: 5px;");
    }
}

void Login_Screen::on_cpf_field_textChanged(const QString &arg1)
{
    this->validaCampos();
}

void Login_Screen::on_matricula_field_textChanged(const QString &arg1)
{
    this->validaCampos();
}
