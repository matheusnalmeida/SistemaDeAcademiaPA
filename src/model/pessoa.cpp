#include "pessoa.h"

Pessoa::Pessoa(){}

Pessoa::Pessoa(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco)
{
    this->nome = nome;
    this->cpf = cpf;
    this->telefone = telefone;
    this->email = email;
    this->endereco = endereco;

}

Pessoa::~Pessoa(){
    delete this->endereco;
}

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
