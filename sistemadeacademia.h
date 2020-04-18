#ifndef SISTEMADEACADEMIA_H
#define SISTEMADEACADEMIA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SistemaDeAcademia; }
QT_END_NAMESPACE

class SistemaDeAcademia : public QMainWindow
{
    Q_OBJECT

public:
    SistemaDeAcademia(QWidget *parent = nullptr);
    ~SistemaDeAcademia();

private:
    Ui::SistemaDeAcademia *ui;
};
#endif // SISTEMADEACADEMIA_H
