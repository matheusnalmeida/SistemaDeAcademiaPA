#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H
#include <map>
#include <QRegularExpression>
#include "pessoa.h";

class BancoDeDados
{
public:
    BancoDeDados();
    ~BancoDeDados();
    void armazenar(QString cpf, Pessoa *pessoa);
    void removerChave(QString cpf);
    Pessoa procurar(QString cpf);

private:
    std::map<QString , Pessoa* > *banco;
    bool contem(QString cpf);
};

#endif // BANCODEDADOS_H
