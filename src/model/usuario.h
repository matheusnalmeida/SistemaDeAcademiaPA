#ifndef USUARIO_H
#define USUARIO_H
#include "pessoa.h"
#include <vector>
#include "treino.h"
class Usuario:private Pessoa
{
public:
    Usuario();
    Usuario(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero);
    void adicionarTreino(Treino treino);

    ~Usuario();
private:
    std::vector<Treino> *treinos;
};

#endif // USUARIO_H
