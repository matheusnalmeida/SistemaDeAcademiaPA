#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login_Screen;
}

class Login_Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Login_Screen(QWidget *parent = nullptr);
    ~Login_Screen();

private slots:
    void on_login_button_clicked();
    void on_cadastrar_button_clicked();

private:
    Ui::Login_Screen *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // LOGIN_H
