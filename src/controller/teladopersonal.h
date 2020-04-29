#ifndef TELADOPERSONAL_H
#define TELADOPERSONAL_H

#include <QWidget>
#include "src/model/pessoa.h"
#include "src/model/bancodedados.h";
namespace Ui {
class Teladopersonal;
}

class Teladopersonal : public QWidget
{
    Q_OBJECT

public:
    explicit Teladopersonal(QWidget *parent = nullptr, QWidget *prev_window = nullptr, Pessoa *pessoa = nullptr, BancoDeDados *banco = nullptr);
    ~Teladopersonal();

private slots:
    void on_cadastro_botao_clicked();

private:
    Ui::Teladopersonal *ui;
    QWidget *prev_window;
    Pessoa* usuario;
    BancoDeDados* banco;
    void closeEvent(QCloseEvent *event);
    void preencherDados();
};

#endif // TELADOPERSONAL_H
