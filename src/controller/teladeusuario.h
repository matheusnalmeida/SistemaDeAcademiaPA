#ifndef TELADEUSUARIO_H
#define TELADEUSUARIO_H

#include <QWidget>

namespace Ui {
class teladeusuario;
}

class teladeusuario : public QWidget
{
    Q_OBJECT

public:
    explicit teladeusuario(QWidget *parent = nullptr);
    ~teladeusuario();

private:
    Ui::teladeusuario *ui;
};

#endif // TELADEUSUARIO_H
