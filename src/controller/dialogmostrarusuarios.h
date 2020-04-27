#ifndef DIALOGMOSTRARUSUARIOS_H
#define DIALOGMOSTRARUSUARIOS_H
#include "src/model/bancodedados.h";
#include <QDialog>

namespace Ui {
class DialogMostrarUsuarios;
}

class DialogMostrarUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMostrarUsuarios(QWidget *parent = nullptr, QWidget *prev_window = nullptr, BancoDeDados *banco = nullptr);
    ~DialogMostrarUsuarios();

private:
    QWidget *prev_window;
    BancoDeDados* banco;
    void closeEvent(QCloseEvent *event);
    Ui::DialogMostrarUsuarios *ui;
};

#endif // DIALOGMOSTRARUSUARIOS_H
