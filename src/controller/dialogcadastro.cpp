#include "dialogcadastro.h"
#include "ui_dialogcadastro.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QRegularExpression>
#include <QRegExpValidator>
#include <QMessageBox>
#include "src/model/usuario.h"
#include "src/model/personal.h"
DialogCadastro::DialogCadastro(QWidget *parent,QWidget *prev_window,BancoDeDados* banco_de_dados) :
    QDialog(parent),
    ui(new Ui::DialogCadastro)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->matricula_generator = new MatriculaGenerator();
    this->banco_de_dados = banco_de_dados;
    //Setando cor do texto dos labels
    this->ui->label_nome->setText(R"**(<span style="color:#20ab7d;">Nome</span><span style="color:red;">*</span>)**");
    this->ui->label_cpf->setText(R"**(<span style="color:#20ab7d;">CPF</span><span style="color:red;">*</span>)**");
    this->ui->label_email->setText(R"**(<span style="color:#20ab7d;">Email</span><span style="color:red;">*</span>)**");
    this->ui->label_telefone->setText(R"**(<span style="color:#20ab7d;">Telefone</span><span style="color:red;">*</span>)**");
    this->ui->label_cep->setText(R"**(<span style="color:#20ab7d;">CEP</span><span style="color:red;">*</span>)**");
    this->ui->label_tipo->setText(R"**(<span style="color:#20ab7d;">Tipo</span><span style="color:red;">*</span>)**");
    this->ui->label_genero->setText(R"**(<span style="color:#20ab7d;">Genero</span><span style="color:red;">*</span>)**");
    //Colocando sombra na janela de dialogo
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    ui->widget->setGraphicsEffect(effect);
    //Configurando input masks nos camps de cpf cep e telefone e validator no campo de email
    QRegExp rx_email ("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)");
    this->ui->text_email->setValidator (new QRegExpValidator (rx_email, this));
    this->ui->text_cpf->setInputMask( "000\\.000\\.000\\-00" );
    this->ui->text_cep->setInputMask( "00\\.000\\-000" );
    this->ui->phone_text->setInputMask("\\(00\\) 00000\\-0000");
}

DialogCadastro::~DialogCadastro()
{
    delete ui;
    delete matricula_generator;
}

void DialogCadastro::show_received_data(QNetworkReply* reply){

    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonObject rootObj = document.object();

    if(rootObj.empty()){
        QMessageBox::warning(this,"Cep Invalido!","O cep informado é invalido!");
        this->ui->text_cep->clear();
    }else{
        this->ui->text_UF->setText(rootObj.value("uf").toString());
        this->ui->text_Bairro->setText(rootObj.value("bairro").toString());
        this->ui->text_Cidade->setText(rootObj.value("cidade").toString());
        this->ui->text_Logradouro->setText(rootObj.value("logradouro").toString());
    }
    this->validaTodosOsCampos();
}

void DialogCadastro::on_DialogCadastro_finished(int result)
{
    this->close();
    this->prev_window->show();
}

void DialogCadastro::validaTodosOsCampos(){
    //Validando nome
    bool campoNomeValido = this->ui->text_name->text().length() != 0;
    if(campoNomeValido){
        this->ui->label_nome->setText(R"**(<span style="color:#20ab7d;">Nome</span>)**");
    }else{
        this->ui->label_nome->setText(R"**(<span style="color:#20ab7d;">Nome</span><span style="color:red;">*</span>)**");
    }
    //Validando cpf
    bool campoCpfValido = this->ui->text_cpf->text().length() == 14;
    if(campoCpfValido){
        this->ui->label_cpf->setText(R"**(<span style="color:#20ab7d;">CPF</span>)**");
    }else{
        this->ui->label_cpf->setText(R"**(<span style="color:#20ab7d;">CPF</span><span style="color:red;">*</span>)**");
    }
    //Validando email
    QString actual_email(this->ui->text_email->text());
    int pos = 0;
    bool campoEmailValido = this->ui->text_email->validator()->validate(actual_email,pos) == QValidator::Acceptable;
    if(campoEmailValido){
        this->ui->label_email->setText(R"**(<span style="color:#20ab7d;">Email</span>)**");
    }else{
        this->ui->label_email->setText(R"**(<span style="color:#20ab7d;">Email</span><span style="color:red;">*</span>)**");
    }
    //Validando telefone
    bool campoTelefoneValido = this->ui->phone_text->text().length() == 15;
    if(campoTelefoneValido){
        this->ui->label_telefone->setText(R"**(<span style="color:#20ab7d;">Telefone</span>)**");
    }else{
        this->ui->label_telefone->setText(R"**(<span style="color:#20ab7d;">Telefone</span><span style="color:red;">*</span>)**");
    }
    //Validando CEP (Caso o campo UF tenha sido preenchido , isso significa que foi informado um numero valido para cep
    bool campoCepValido = this->ui->text_UF->text() != "";
    if(campoCepValido){
        this->ui->label_cep->setText(R"**(<span style="color:#20ab7d;">CEP</span>)**");
    }else{
        this->ui->label_cep->setText(R"**(<span style="color:#20ab7d;">CEP</span><span style="color:red;">*</span>)**");
    }
    //Validando campo de selecao de genero
    bool campoGeneroValido = false;
    for (auto radio_button: this->ui->groupBox_genero->findChildren<QRadioButton*>()){
        if(radio_button->isChecked()){
            campoGeneroValido = true;
            break;
        }
    }
    if(campoGeneroValido){
        this->ui->label_genero->setText(R"**(<span style="color:#20ab7d;">Genero</span>)**");
    }else{
        this->ui->label_genero->setText(R"**(<span style="color:#20ab7d;">Genero</span><span style="color:red;">*</span>)**");
    }
    //Validando campo de selecao de tipo
    bool campoTipoValido = false;
    for (auto radio_button: this->ui->groupBox_Tipo->findChildren<QRadioButton*>()){
        if(radio_button->isChecked()){
            campoTipoValido = true;
            break;
        }
    }
    if(campoTipoValido){
        this->ui->label_tipo->setText(R"**(<span style="color:#20ab7d;">Tipo</span>)**");
    }else{
        this->ui->label_tipo->setText(R"**(<span style="color:#20ab7d;">Tipo</span><span style="color:red;">*</span>)**");
    }
    if(campoNomeValido && campoCpfValido && campoEmailValido && campoTelefoneValido && campoCepValido && campoGeneroValido && campoTipoValido){
        this->ui->cadastrar_Button->setEnabled(true);
        this->ui->cadastrar_Button->setStyleSheet("background-color: #4CAF50;\
                                                  border: none;\
                                                  color: white;\
                                                  padding: 15px 32px;\
                                                  text-align: center;\
                                                  text-decoration: none;\
                                                  font-size: 16px;\
                                                  margin: 4px 2px;\
                                                  border-radius: 5px;");
        this->ui->label_informacao->clear();

    }
    else{
        this->ui->cadastrar_Button->setEnabled(false);
        this->ui->cadastrar_Button->setStyleSheet("background-color: #cccccc;\
                                                  border: none;\
                                                  color: white;\
                                                  padding: 15px 32px;\
                                                  text-align: center;\
                                                  text-decoration: none;\
                                                  font-size: 16px;\
                                                  margin: 4px 2px;\
                                                  border-radius: 5px;");
        this->ui->label_informacao->setText(R"**(<span style="color:#ff0004;">
                                                  * Existem campos com informacoes a serem preenchidas</span>)**");

    }
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
        this->validaTodosOsCampos();
    }
}

void DialogCadastro::limparCampos(){
    for(QLineEdit* text :this->ui->widget->findChildren<QLineEdit*>()){
        text->clear();
    }
    for(QRadioButton* radio_button :this->ui->widget->findChildren<QRadioButton*>()){
        radio_button->setAutoExclusive(false);
        radio_button->setChecked(false);
        radio_button->setAutoExclusive(true);
    }
    this->ui->label_tipo->setText(R"**(<span style="color:#20ab7d;">Tipo</span><span style="color:red;">*</span>)**");
    this->ui->label_genero->setText(R"**(<span style="color:#20ab7d;">Genero</span><span style="color:red;">*</span>)**");
}

void DialogCadastro::on_text_name_textChanged(const QString &arg1)
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_text_cpf_textChanged(const QString &arg1)
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_text_email_textChanged(const QString &arg1)
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_phone_text_textChanged(const QString &arg1)
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_cadastrar_Button_clicked()
{
    QChar tipo_novo_ususario = this->ui->radioButton_Aluno->isChecked() ? 'a' : 'p';
    QString nome_novo_usuario = this->ui->text_name->text();
    QString cpf_novo_usuario = this->ui->text_cpf->text();
    QString email_novo_usuario = this->ui->text_email->text();
    QString telefone_novo_usuario = this->ui->phone_text->text();
    QString cep_novo_usuario = this->ui->text_cep->text();
    QChar genero_novo_usuario = this->ui->radioButton_Mulher->isChecked() ? 'f' : 'm';
    Endereco* endereco_novo_usuario = new Endereco(this->ui->text_UF->text(),
                                                    this->ui->text_Cidade->text(),
                                                    this->ui->text_Bairro->text(),
                                                    this->ui->text_Logradouro->text());
    try {
        this->matricula_generator->GenerateMatricula(cpf_novo_usuario,tipo_novo_ususario);

        if(this->matricula_generator->getMatricula().at(matricula_generator->getMatricula().length()-1) == 'a'){

        if(this->banco_de_dados->procurarCPF(cpf_novo_usuario) == nullptr){
            Usuario* usuario = new Usuario(nome_novo_usuario,
                                             cpf_novo_usuario,
                                             telefone_novo_usuario,
                                             email_novo_usuario,
                                             endereco_novo_usuario,
                                             this->matricula_generator->getMatricula(),
                                             genero_novo_usuario);
            this->banco_de_dados->armazenar(usuario);
            QMessageBox::information(this,"","Usuario cadastrado com sucesso!\nSua matricula é " + this->matricula_generator->getMatricula());
            this->finished(0);
        }else{
            QMessageBox::warning(this,"Cpf Existente!","Ja existe usuario cadastrado com o cpf informado!");
        }
        }else{
            if(this->banco_de_dados->procurarCPF(cpf_novo_usuario) == nullptr){
            Personal* personal = new Personal(nome_novo_usuario,
                                             cpf_novo_usuario,
                                             telefone_novo_usuario,
                                             email_novo_usuario,
                                             endereco_novo_usuario,
                                             this->matricula_generator->getMatricula(),
                                             genero_novo_usuario);
            this->banco_de_dados->armazenar(personal);
            QMessageBox::information(this,"","Usuario cadastrado com sucesso!\nSua matricula é " + this->matricula_generator->getMatricula());
            this->finished(0);
        }else{
                QMessageBox::warning(this,"Cpf Existente!","Ja existe usuario cadastrado com o cpf informado!");
            }
            }
    } catch (CpfInvalidoException& ex) {
        QMessageBox::warning(this,"Cpf Invalido!","O cpf informado nao é um cpf válido!");
    }

}

void DialogCadastro::on_cancelar_Button_clicked()
{
    this->finished(0);
}

void DialogCadastro::on_radioButton_Homem_clicked()
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_radioButton_Mulher_clicked()
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_radioButton_Aluno_clicked()
{
    this->validaTodosOsCampos();
}

void DialogCadastro::on_radioButton_Personal_clicked()
{
    this->validaTodosOsCampos();
}
