#ifndef DIALOGCADASTRAREXERCICIOS_H
#define DIALOGCADASTRAREXERCICIOS_H
#include <map>
#include "src/model/treino.h"
#include <QDialog>

namespace Ui {
class Dialogcadastrarexercicios;
}

class Dialogcadastrarexercicios : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcadastrarexercicios(QWidget *parent = nullptr, QWidget *prev = nullptr,std::map<QString, Treino*>* bancoDeTreinos = nullptr );
    ~Dialogcadastrarexercicios();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogcadastrarexercicios *ui;
    std::map<QString, Treino*>* bancoDeTreinos;
    QWidget *prev;
};

#endif // DIALOGCADASTRAREXERCICIOS_H
