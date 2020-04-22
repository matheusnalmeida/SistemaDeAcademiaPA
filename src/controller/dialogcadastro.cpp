#include "dialogcadastro.h"
#include "ui_dialogcadastro.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QRegularExpression>

DialogCadastro::DialogCadastro(QWidget *parent,QWidget *prev_window) :
    QDialog(parent),
    ui(new Ui::DialogCadastro)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    ui->widget->setGraphicsEffect(effect);
    //Configurando input masks nos camps de cpf cep e telefone
    this->ui->text_cpf->setInputMask( "000\\.000\\.000\\-00" );
    this->ui->text_cep->setInputMask( "00\\.000\\-000" );
    this->ui->phone_text->setInputMask("\\(00\\) 00000\\-0000");
}

DialogCadastro::~DialogCadastro()
{
    delete ui;
}

void DialogCadastro::show_received_data(QNetworkReply* reply){

    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonObject rootObj = document.object();

    if(rootObj.empty())
        qDebug() << "Empty";
    else{
        this->ui->text_UF->setText(rootObj.value("uf").toString());
        this->ui->text_Bairro->setText(rootObj.value("bairro").toString());
        this->ui->text_Cidade->setText(rootObj.value("cidade").toString());
        this->ui->text_Logradouro->setText(rootObj.value("logradouro").toString());
    }
}

void DialogCadastro::on_DialogCadastro_finished(int result)
{
    this->close();
    this->prev_window->show();
}

void DialogCadastro::on_text_cep_textChanged(const QString &arg1)
{
    QRegularExpression re("[.|-]");
    QString text_validated(arg1);
    text_validated = text_validated.replace(re,"");
    if(text_validated.size() == 8){
        QNetworkAccessManager* a = new QNetworkAccessManager();
        QNetworkRequest request("http://cep.la/" + text_validated);
        request.setRawHeader("Accept", "application/json");
        a->get(request);
        connect(a, SIGNAL(finished(QNetworkReply*)),this,SLOT(show_received_data(QNetworkReply*)));
    }else{
        this->ui->text_UF->clear();
        this->ui->text_Bairro->clear();
        this->ui->text_Cidade->clear();
        this->ui->text_Logradouro->clear();
    }
}

