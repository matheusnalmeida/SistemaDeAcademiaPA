#include "usuario.h"

Usuario::Usuario()
{
   this->treinos = new std::map<QString,Treino*>();
}
Usuario::~Usuario(){
   delete this->treinos;
}

Usuario::Usuario(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero) : Pessoa( nome, cpf, telefone, email, endereco, matricula, genero) {
    this->treinos = new std::map<QString,Treino*>();
}



std::map<QString,Treino*>* Usuario::getTreinos(){
    return this->treinos;
}
