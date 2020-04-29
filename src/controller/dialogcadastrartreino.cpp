#include "dialogcadastrartreino.h"
#include "ui_dialogcadastrartreino.h"

DialogCadastrarTreino::DialogCadastrarTreino(QWidget *parent,QWidget *prev_window,std::map<QString,Treino*>* bancoDeTreinos) :
    QDialog(parent),
    ui(new Ui::DialogCadastrarTreino)
{
    ui->setupUi(this);
    //this->prev_window = prev_window;
    //this->bancoDeTreinos = bancoDeTreinos;
    //this->carregarTreinos();
    //Carregando icones nos botoes
    QPixmap pixmap_add(":/imagem/src/resources/add_icon.png");
    QIcon ButtonIconAdd(pixmap_add);
    this->ui->add_button->setIcon(ButtonIconAdd);

    QPixmap pixmap_delete(":/imagem/src/resources/delete_icon.png");
    QIcon ButtonIconDelete(pixmap_delete);
    this->ui->delete_button->setIcon(ButtonIconDelete);

    QPixmap pixmap_edit(":/imagem/src/resources/edit_icon.png");
    QIcon ButtonIconEdit(pixmap_edit);
    this->ui->edit_button->setIcon(ButtonIconEdit);
}

void DialogCadastrarTreino::carregarTreinos(){
    std::map<QString, Treino*>::iterator itr;
    for (itr = this->bancoDeTreinos->begin(); itr != this->bancoDeTreinos->end(); ++itr) {
        QListWidgetItem * item = new QListWidgetItem(itr->first);
        item->setTextAlignment(Qt::AlignHCenter);
        QFont serifFont("Consolas", 20, QFont::Bold);
        item->setFont(serifFont);
        this->ui->listWidget->addItem(item);
    }
}

DialogCadastrarTreino::~DialogCadastrarTreino()
{
    delete ui;
}

void DialogCadastrarTreino::on_DialogCadastrarTreino_finished(int result)
{
    //this->close();
    //this->prev_window->show();
}

void DialogCadastrarTreino::on_add_button_clicked()
{

}

void DialogCadastrarTreino::on_delete_button_clicked()
{
    QListWidgetItem* item_atual = this->ui->listWidget->currentItem();
    this->bancoDeTreinos->erase(item_atual->text());
    delete item_atual;
    this->ui->listWidget->selectionModel()->reset();
    this->ui->delete_button->setEnabled(false);
    this->ui->edit_button->setEnabled(false);
}

void DialogCadastrarTreino::on_edit_button_clicked()
{

}

void DialogCadastrarTreino::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->ui->delete_button->setEnabled(true);
    this->ui->edit_button->setEnabled(true);
}
