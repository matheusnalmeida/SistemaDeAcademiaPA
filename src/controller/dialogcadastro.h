#ifndef DIALOGCADASTRO_H
#define DIALOGCADASTRO_H

#include <QDialog>
#include <QtNetwork>
#include "src/utils/matriculagenerator.h"

namespace Ui {
class DialogCadastro;
}

class DialogCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCadastro(QWidget *parent = nullptr,QWidget *prev_window = nullptr);
    ~DialogCadastro();

private slots:
    void on_DialogCadastro_finished(int result);
    void show_received_data(QNetworkReply* reply);
    void on_text_cep_textChanged(const QString &arg1);

private:
    Ui::DialogCadastro *ui;
    QWidget *prev_window;
    MatriculaGenerator* matricula_generator;
};

#endif // DIALOGCADASTRO_H
