#include "dialogcadastrarexercicios.h"
#include "ui_dialogcadastrarexercicios.h"
#include "QMessageBox"
#include "QDebug"
Dialogcadastrarexercicios::Dialogcadastrarexercicios(QWidget *parent , DialogCadastrarTreino *prev , std::map<QString, Treino*>* bancoDeTreinos) :
    QDialog(parent),
    ui(new Ui::Dialogcadastrarexercicios)
{
    ui->setupUi(this);
    this->bancoDeTreinos = bancoDeTreinos;
    this->prev = prev;
    this->ui->texto_rep_1->setInputMask( "00" );
    this->ui->texto_serie_1->setInputMask( "00" );
    this->ui->texto_rep_2->setInputMask( "00" );
    this->ui->texto_serie_2->setInputMask( "00" );
    this->ui->texto_rep_3->setInputMask( "00" );
    this->ui->texto_serie_3->setInputMask( "00" );
    this->ui->texto_rep_4->setInputMask( "00" );
    this->ui->texto_serie_4->setInputMask( "00" );
    this->ui->texto_rep_5->setInputMask( "00" );
    this->ui->texto_serie_5->setInputMask( "00" );
    this->ui->texto_rep_6->setInputMask( "00" );
    this->ui->texto_serie_6->setInputMask( "00" );
}

Dialogcadastrarexercicios::~Dialogcadastrarexercicios()
{
    delete ui;

}

void Dialogcadastrarexercicios::on_pushButton_clicked()
{

    QString nome_treino = this->ui->texto_do_nome_do_treino->text();
    QString repeticao_1 = (this->ui->texto_rep_1->text());
    QString repeticao_2 = (this->ui->texto_rep_2->text());
    QString repeticao_3 = (this->ui->texto_rep_3->text());
    QString repeticao_4 = (this->ui->texto_rep_4->text());
    QString repeticao_5 = (this->ui->texto_rep_5->text());
    QString repeticao_6 = (this->ui->texto_rep_6->text());
    QString nome_exercicio_1 = this->ui->texto_exercicio_1->text();
    QString nome_exercicio_2 = this->ui->texto_exercicio_2->text();
    QString nome_exercicio_3 = this->ui->texto_exercicio_3->text();
    QString nome_exercicio_4 = this->ui->texto_exercicio_4->text();
    QString nome_exercicio_5 = this->ui->texto_exercicio_5->text();
    QString nome_exercicio_6 = this->ui->texto_exercicio_6->text();
    QString numero_serie_1 = this->ui->texto_serie_1->text();
    QString numero_serie_2 = this->ui->texto_serie_2->text();
    QString numero_serie_3 = this->ui->texto_serie_3->text();
    QString numero_serie_4 = this->ui->texto_serie_4->text();
    QString numero_serie_5 = this->ui->texto_serie_5->text();
    QString numero_serie_6 = this->ui->texto_serie_6->text();
    Treino *treino = new Treino(nome_treino);

    if(repeticao_1.size() > 0 && numero_serie_1.size() > 0 && nome_exercicio_1.size() > 0){
            QString rep_1 = numero_serie_1 + "x" + repeticao_1;
            treino->adicionarExercicio(nome_exercicio_1, rep_1);
    }
    if(repeticao_2.size() > 0 && numero_serie_2.size() > 0 && nome_exercicio_2.size() > 0){
            QString rep_2 = numero_serie_2 + "x" + repeticao_2;
            treino->adicionarExercicio(nome_exercicio_2, rep_2);
    }
    if(repeticao_3.size() > 0 && numero_serie_3.size() > 0 && nome_exercicio_3.size() > 0){
            QString rep_3 = numero_serie_3 + "x" + repeticao_3;
            treino->adicionarExercicio(nome_exercicio_3, rep_3);
    }
    if(repeticao_4.size() > 0 && numero_serie_4.size() > 0 && nome_exercicio_4.size() > 0){
             QString rep_4 = numero_serie_4 + "x" + repeticao_4;
             treino->adicionarExercicio(nome_exercicio_4, rep_4);
    }
    if(repeticao_5.size() > 0 && numero_serie_5.size() > 0 && nome_exercicio_5.size() > 0){
            QString rep_5 = numero_serie_5 + "x" + repeticao_5;
            treino->adicionarExercicio(nome_exercicio_5, rep_5);
    }
    if(repeticao_6.size() > 0 && numero_serie_6.size() > 0 && nome_exercicio_6.size() > 0){
            QString rep_6 = numero_serie_6 + "x" + repeticao_6;
            treino->adicionarExercicio(nome_exercicio_6, rep_6);
    }

    this->bancoDeTreinos->insert(std::pair<QString, Treino*>(treino->getNome(),treino));

    QMessageBox::information(this,"","Treino cadastrado com sucesso");
    this->prev->carregarTreinos();
    this->close();
}
