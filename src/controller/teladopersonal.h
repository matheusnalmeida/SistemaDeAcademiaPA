#ifndef TELADOPERSONAL_H
#define TELADOPERSONAL_H

#include <QWidget>
#include "src/model/pessoa.h"
namespace Ui {
class Teladopersonal;
}

class Teladopersonal : public QWidget
{
    Q_OBJECT

public:
    explicit Teladopersonal(QWidget *parent = nullptr, QWidget *prev_window = nullptr, Pessoa *pessoa = nullptr);
    ~Teladopersonal();

private slots:


private:
    Ui::Teladopersonal *ui;
    QWidget *prev_window;
    Pessoa* usuario;
    void closeEvent(QCloseEvent *event);
    void preencherDados();
};

#endif // TELADOPERSONAL_H
