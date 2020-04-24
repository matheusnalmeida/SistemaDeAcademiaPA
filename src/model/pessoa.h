#ifndef PESSOA_H
#define PESSOA_H

#include <QString>
#include "endereco.h"

class Pessoa
{
public:
    Pessoa();
    Pessoa(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco);
    ~Pessoa();
private:
    //Atributos
    QString nome;
    QString cpf;
    QString telefone;
    QString email;
    Endereco* endereco;
    //Getters
    QString getNome();
    QString getCpf();
    QString getTelefone();
    QString getEmail();
    Endereco* getEndereco();
};

#endif // PESSOA_H
