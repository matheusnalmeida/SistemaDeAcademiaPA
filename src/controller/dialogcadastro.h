#ifndef DIALOGCADASTRO_H
#define DIALOGCADASTRO_H

#include <QDialog>
#include <QtNetwork>
#include "src/utils/matriculagenerator.h"
#include "src/model/bancodedados.h"

namespace Ui {
class DialogCadastro;
}

class DialogCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCadastro(QWidget *parent = nullptr,QWidget *prev_window = nullptr,BancoDeDados* banco_de_dados = nullptr);
    ~DialogCadastro();

private slots:
    void on_DialogCadastro_finished(int result);
    void show_received_data(QNetworkReply* reply);
    void on_text_cep_textChanged(const QString &arg1);
    void on_text_name_textChanged(const QString &arg1);
    void on_text_cpf_textChanged(const QString &arg1);
    void on_text_email_textChanged(const QString &arg1);
    void on_phone_text_textChanged(const QString &arg1);
    void on_cadastrar_Button_clicked();
    void on_cancelar_Button_clicked();
    void on_radioButton_Homem_clicked();
    void on_radioButton_Mulher_clicked();
    void on_radioButton_Aluno_clicked();
    void on_radioButton_Personal_clicked();

private:
    Ui::DialogCadastro *ui;
    QWidget *prev_window;
    BancoDeDados* banco_de_dados;
    MatriculaGenerator* matricula_generator;
    void validaTodosOsCampos();
};

#endif // DIALOGCADASTRO_H
