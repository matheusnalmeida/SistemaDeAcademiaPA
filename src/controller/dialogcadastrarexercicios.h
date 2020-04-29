#ifndef DIALOGCADASTRAREXERCICIOS_H
#define DIALOGCADASTRAREXERCICIOS_H

#include <QDialog>

namespace Ui {
class Dialogcadastrarexercicios;
}

class Dialogcadastrarexercicios : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcadastrarexercicios(QWidget *parent = nullptr);
    ~Dialogcadastrarexercicios();

private:
    Ui::Dialogcadastrarexercicios *ui;
};

#endif // DIALOGCADASTRAREXERCICIOS_H
