#include "usuario.h"

Usuario::Usuario()
{
   this->treinos = new std::vector<Treino>();
}
Usuario::~Usuario(){
   delete this->treinos;
}

Usuario::Usuario(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero) : Pessoa( nome, cpf, telefone, email, endereco, matricula, genero) {}

void Usuario::adicionarTreino(Treino treino){
    this->treinos->push_back(treino);
}

