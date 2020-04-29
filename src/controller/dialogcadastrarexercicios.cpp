#include "dialogcadastrarexercicios.h"
#include "ui_dialogcadastrarexercicios.h"

Dialogcadastrarexercicios::Dialogcadastrarexercicios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogcadastrarexercicios)
{
    ui->setupUi(this);
}

Dialogcadastrarexercicios::~Dialogcadastrarexercicios()
{
    delete ui;
}
