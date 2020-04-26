#ifndef PERSONAL_H
#define PERSONAL_H
#include "pessoa.h"

class Personal:public Pessoa
{
public:
    Personal();
    Personal(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero);
};

#endif // PERSONAL_H
