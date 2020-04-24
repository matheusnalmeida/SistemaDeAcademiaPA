#ifndef TELADEUSUARIO_H
#define TELADEUSUARIO_H

#include <QWidget>
#include "src/utils/matriculagenerator.h"

namespace Ui {
class teladeusuario;
}

class teladeusuario : public QWidget
{
    Q_OBJECT

public:
    explicit teladeusuario(QWidget *parent = nullptr,QWidget *prev_window = nullptr);
    ~teladeusuario();

private:
    Ui::teladeusuario *ui;
    QWidget *prev_window;
    MatriculaGenerator* matricula_generator;
    void closeEvent(QCloseEvent *event);
};

#endif // TELADEUSUARIO_H
