#ifndef PESSOA_H
#define PESSOA_H

#include <QString>
#include "endereco.h"

class Pessoa
{
public:
    Pessoa();
    Pessoa(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero);
    ~Pessoa();
    //Getters
    QString getNome();
    QString getCpf();
    QString getTelefone();
    QString getEmail();
    Endereco* getEndereco();
    QString getMatricula();
    QChar getGenero();

private:
    //Atributos
    QString nome;
    QString cpf;
    QString telefone;
    QString email;
    Endereco* endereco;
    QString matricula;
    QChar genero;

};

#endif // PESSOA_H
