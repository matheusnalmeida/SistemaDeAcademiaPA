#include "dialogmostrarusuarios.h"
#include "ui_dialogmostrarusuarios.h"
#include <map>
#include "QListWidgetItem"
#include "QMessageBox"
#include "QCloseEvent"
#include "src/model/usuario.h"
DialogMostrarUsuarios::DialogMostrarUsuarios(QWidget *parent, QWidget *prev_window, BancoDeDados *banco) :
    QDialog(parent),
    ui(new Ui::DialogMostrarUsuarios)
{
    ui->setupUi(this);
    this->prev_window = prev_window;
    this->banco = banco;
    std::map<QString , Pessoa*>* bancoMatricula = banco->getAlunosMatricula();
    std::map<QString, Pessoa*>::iterator itr;
    for (itr = bancoMatricula->begin(); itr != bancoMatricula->end(); ++itr) {
        QListWidgetItem * item = new QListWidgetItem(itr->first);
        item->setTextAlignment(Qt::AlignHCenter);
        QFont serifFont("Consolas", 20, QFont::Bold);
        item->setFont(serifFont);
        this->ui->listaWidgte->addItem(item);
    }
}

void DialogMostrarUsuarios::on_DialogMostrarUsuarios_finished(int result)
{
        this->prev_window->show();
        this->close();
}

DialogMostrarUsuarios::~DialogMostrarUsuarios()
{
    delete ui;
}

void DialogMostrarUsuarios::on_listaWidgte_itemClicked(QListWidgetItem *item)
{
    QString matricula_escolhida = item->text();
    Usuario *usuario = (Usuario*) this->banco->procurarMatricula(matricula_escolhida);
    std::map<QString,Treino*>* treinos_atual = usuario->getTreinos();
    DialogCadastrarTreino* tela_de_treinos = new DialogCadastrarTreino(nullptr,this,treinos_atual);
    tela_de_treinos->exec();
}


