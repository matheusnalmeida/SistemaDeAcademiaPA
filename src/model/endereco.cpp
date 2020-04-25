#include "endereco.h"

Endereco::Endereco(QString uf,QString cidade,QString bairro,QString logradouro)
{
    this->uf = uf;
    this->cidade = cidade;
    this->bairro = bairro;
    this->logradouro = logradouro;
}

Endereco::~Endereco(){}

QString Endereco::getUf(){
    return this->uf;
}

QString Endereco::getCidade(){
    return this->cidade;
}

QString Endereco::getBairro(){
    return this->bairro;
}

QString Endereco::getLogradouro(){
    return this->logradouro;
}
