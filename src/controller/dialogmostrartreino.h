#ifndef DIALOGMOSTRARTREINO_H
#define DIALOGMOSTRARTREINO_H

#include <QDialog>
#include "src/model/treino.h"
#include <map>

namespace Ui {
class dialogmostrartreino;
}

class dialogmostrartreino : public QDialog
{
    Q_OBJECT

public:
    explicit dialogmostrartreino(QWidget *parent = nullptr,
                                 QWidget *prev_window = nullptr);
    ~dialogmostrartreino();

private slots:
    void on_dialogmostrartreino_finished(int result);

private:
    Ui::dialogmostrartreino *ui;
    QWidget *prev_window;

};

#endif // DIALOGMOSTRARTREINO_H
