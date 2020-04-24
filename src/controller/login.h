#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "dialogcadastro.h"

namespace Ui {
class Login_Screen;
}

class Login_Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Login_Screen(QWidget *parent = nullptr);
    ~Login_Screen();

private slots:
    void on_login_button_clicked();
    void on_cadastrar_button_clicked();

private:
    //Atributos
    Ui::Login_Screen *ui;
    DialogCadastro* tela_de_cadastro;
    //Metodos
    void closeEvent(QCloseEvent *event);
};

#endif // LOGIN_H
