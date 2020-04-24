#ifndef DIALOGMOSTRARTREINO_H
#define DIALOGMOSTRARTREINO_H

#include <QDialog>

namespace Ui {
class dialogmostrartreino;
}

class dialogmostrartreino : public QDialog
{
    Q_OBJECT

public:
    explicit dialogmostrartreino(QWidget *parent = nullptr);
    ~dialogmostrartreino();

private:
    Ui::dialogmostrartreino *ui;
};

#endif // DIALOGMOSTRARTREINO_H
