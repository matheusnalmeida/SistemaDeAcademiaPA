#ifndef DIALOGCADASTRARTREINO_H
#define DIALOGCADASTRARTREINO_H

#include <QDialog>
#include <map>
#include "src/model/treino.h"
#include "QListWidgetItem"

namespace Ui {
class DialogCadastrarTreino;
}

class DialogCadastrarTreino : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCadastrarTreino(QWidget *parent = nullptr,
                                   QWidget* prev_window = nullptr,
                                   std::map<QString,Treino*>* bancoDeTreinos = nullptr);
    ~DialogCadastrarTreino();

private slots:
    void on_DialogCadastrarTreino_finished(int result);

    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_edit_button_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::DialogCadastrarTreino *ui;
    std::map<QString,Treino*>* bancoDeTreinos;
    QWidget* prev_window;
    void carregarTreinos();
};

#endif // DIALOGCADASTRARTREINO_H
