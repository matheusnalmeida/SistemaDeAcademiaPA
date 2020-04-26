#include "personal.h"

Personal::Personal()
{

}

Personal::Personal(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero) : Pessoa( nome, cpf, telefone, email, endereco, matricula, genero) {}
