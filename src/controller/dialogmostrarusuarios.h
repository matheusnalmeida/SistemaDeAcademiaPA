#ifndef DIALOGMOSTRARUSUARIOS_H
#define DIALOGMOSTRARUSUARIOS_H
#include "src/model/bancodedados.h";
#include <QDialog>
#include <QListWidgetItem>
#include "src/model/treino.h"
#include "dialogcadastrartreino.h"

namespace Ui {
class DialogMostrarUsuarios;
}

class DialogMostrarUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMostrarUsuarios(QWidget *parent = nullptr, QWidget *prev_window = nullptr, BancoDeDados *banco = nullptr);
    ~DialogMostrarUsuarios();

private slots:
    void on_listaWidgte_itemClicked(QListWidgetItem *item);

    void on_DialogMostrarUsuarios_finished(int result);

private:
    QWidget *prev_window;
    BancoDeDados* banco;
    Ui::DialogMostrarUsuarios *ui;
};

#endif // DIALOGMOSTRARUSUARIOS_H
