#ifndef ENDERECO_H
#define ENDERECO_H

#include <QString>

class Endereco
{
public:
    Endereco(QString uf,QString cidade,QString bairro,QString logradouro);
    ~Endereco();
    //Getters
    QString getUf();
    QString getCidade();
    QString getBairro();
    QString getLogradouro();
private:
    //Atributos
    QString uf;
    QString cidade;
    QString bairro;
    QString logradouro;

};

#endif // ENDERECO_H
