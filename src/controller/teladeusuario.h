#ifndef TELADEUSUARIO_H
#define TELADEUSUARIO_H

#include <QWidget>
#include "src/model/pessoa.h"
#include "src/model/usuario.h"
namespace Ui {
class teladeusuario;
}

class teladeusuario : public QWidget
{
    Q_OBJECT

public:
    explicit teladeusuario(QWidget *parent = nullptr,QWidget *prev_window = nullptr,Pessoa* usuario = nullptr);
    ~teladeusuario();

private:
    Ui::teladeusuario *ui;
    QWidget *prev_window;
    Usuario* usuario;
    void closeEvent(QCloseEvent *event);
    void preencherDados();
};

#endif // TELADEUSUARIO_H
