#include "dialogmostrartreino.h"
#include "ui_dialogmostrartreino.h"
#include <QDebug>
dialogmostrartreino::dialogmostrartreino(QWidget *parent, QWidget *prev_window,Treino* treino_atual) :
    QDialog(parent),
    ui(new Ui::dialogmostrartreino)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->treino_atual = treino_atual;
    //quantas colunas tem que ter
    ui->tableTreinos->setColumnCount(2);
    //tamanho das colunas
    ui->tableTreinos->setColumnWidth(0,350);
    ui->tableTreinos->setColumnWidth(1,350);
    //Colocando nome no cabecao da table
    QStringList cabecalho = {"SeriesxRepetições", "Exercício"};
    ui->tableTreinos->setHorizontalHeaderLabels(cabecalho);
    //o campo nao ser editado
    ui->tableTreinos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //linha inteira selecionada
    ui->tableTreinos->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ocultar os numeros da esquerda
    ui->tableTreinos->verticalHeader()->setVisible(false);
    this->carregarTreinos();
}

void dialogmostrartreino::carregarTreinos(){
    for(std::pair<QString,QString> exercicio : *this->treino_atual->getMap()){
        this->ui->tableTreinos->insertRow(this->ui->tableTreinos->rowCount());
        this->ui->tableTreinos->setItem(this->ui->tableTreinos->rowCount()-1,0,new QTableWidgetItem(exercicio.second));
        this->ui->tableTreinos->setItem(this->ui->tableTreinos->rowCount()-1,1,new QTableWidgetItem(exercicio.first));
    }
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
