#include "dialogmostrartreino.h"
#include "ui_dialogmostrartreino.h"

dialogmostrartreino::dialogmostrartreino(QWidget *parent, QWidget *prev_window) :
    QDialog(parent),
    ui(new Ui::dialogmostrartreino)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    //quantas colunas tem que ter
    ui->treinos->setColumnCount(2);
    //tamanho das colunas
    ui->treinos->setColumnWidth(0,350);
    ui->treinos->setColumnWidth(1,350);
    //Colocando nome no cabecao da table
    QStringList cabecalho = {"Repetições", "Exercício"};
    ui->treinos->setHorizontalHeaderLabels(cabecalho);
    //o campo nao ser editado
    ui->treinos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //linha inteira selecionada
    ui->treinos->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ocultar os numeros da esquerda
    ui->treinos->verticalHeader()->setVisible(false);

}


dialogmostrartreino::~dialogmostrartreino()
{
    delete ui;
}

void dialogmostrartreino::on_dialogmostrartreino_finished(int result)
{
    this->close();
    this->prev_window->show();
}
