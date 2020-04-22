#ifndef TELADECADASTRO_H
#define TELADECADASTRO_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class TelaDeCadastro;
}

class TelaDeCadastro : public QWidget
{
    Q_OBJECT

public:
    explicit TelaDeCadastro(QWidget *parent = nullptr,QWidget* prev_wind = nullptr);
    ~TelaDeCadastro();

private:
    void closeEvent(QCloseEvent *event);
    Ui::TelaDeCadastro *ui;
    QWidget* prev_wind;
};

#endif // TELADECADASTRO_H
