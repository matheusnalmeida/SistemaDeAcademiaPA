#ifndef ENDERECO_H
#define ENDERECO_H

#include <QString>

class Endereco
{
public:
    Endereco(QString uf,QString cidade,QString bairro,QString logradouro);
    ~Endereco();
private:
    //Atributos
    QString uf;
    QString cidade;
    QString bairro;
    QString logradouro;
    //Getters
    QString getUf();
    QString getCidade();
    QString getBairro();
    QString getLogradouro();
};

#endif // ENDERECO_H
