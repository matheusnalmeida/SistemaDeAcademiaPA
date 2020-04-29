#ifndef USUARIO_H
#define USUARIO_H
#include "pessoa.h"
#include <vector>
#include "treino.h"
class Usuario:public Pessoa
{
public:
    Usuario();
    Usuario(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero);
     std::map<QString,Treino*>* getTreinos();
    ~Usuario();
private:
    std::map<QString,Treino*>* treinos;
};

#endif // USUARIO_H
