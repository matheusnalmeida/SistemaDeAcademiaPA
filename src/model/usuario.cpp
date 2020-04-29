#include "usuario.h"

Usuario::Usuario()
{
   this->treinos = new std::map<QString,Treino*>();
}
Usuario::~Usuario(){
   delete this->treinos;
}

Usuario::Usuario(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero) : Pessoa( nome, cpf, telefone, email, endereco, matricula, genero) {}

//Cadastro e remoção
void Usuario::cadastrarTreino(QString nomeDoTreino){
    Treino* novoTreino = new Treino(nomeDoTreino);
    this->treinos->insert(std::pair<QString, Treino*>(nomeDoTreino,novoTreino));
}

void Usuario::removerTreino(QString nomeDoTreino){
    this->treinos->erase(nomeDoTreino);
}

std::map<QString,Treino*>* Usuario::getTreinos(){
    return this->treinos;
}
