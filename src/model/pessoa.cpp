#include "pessoa.h"

Pessoa::Pessoa(){}

Pessoa::Pessoa(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero)
{
    this->nome = nome;
    this->cpf = cpf;
    this->telefone = telefone;
    this->email = email;
    this->endereco = endereco;
    this->matricula = matricula;
    this->genero = genero;
    this->treinos = new std::map<QString,Treino*>();
}

Pessoa::~Pessoa(){
    delete this->endereco;
    std::map<QString, Treino*>::iterator itr;
    for (itr = this->treinos->begin(); itr != this->treinos->end(); ++itr) {
        delete itr->second;
    }
    delete this->treinos;
}

//Cadastro e remoção
void Pessoa::cadastrarTreino(QString nomeDoTreino){
    Treino* novoTreino = new Treino(nomeDoTreino);
    this->treinos->insert(std::pair<QString, Treino*>(nomeDoTreino,novoTreino));
}

void Pessoa::removerTreino(QString nomeDoTreino){
    this->treinos->erase(nomeDoTreino);
}

//Getters
QString Pessoa::getNome(){
    return this->nome;
}

QString Pessoa::getCpf(){
    return this->cpf;
}

QString Pessoa::getTelefone(){
    return this->telefone;
}

QString Pessoa::getEmail(){
    return this->email;
}

Endereco* Pessoa::getEndereco(){
    return this->endereco;
}

QString Pessoa::getMatricula(){
    return this->matricula;
}

QChar Pessoa::getGenero(){
    return this->genero;
}

std::map<QString,Treino*>* Pessoa::getTreinos(){
    return this->treinos;
}
