#include "bancodedados.h"

BancoDeDados::BancoDeDados()
{
     this->banco = new std::map<QString, Pessoa*>();
}

BancoDeDados::~BancoDeDados(){
    std::map<QString, Pessoa*>::iterator itr;
    for (itr = this->banco->begin(); itr != this->banco->end(); ++itr) {
            delete itr->second;
    }
    delete  this->banco;
}

void BancoDeDados::armazenar(QString cpf, Pessoa *pessoa){
     this->banco->insert(std::pair<QString, Pessoa*>(cpf,pessoa));
}


bool BancoDeDados::contem(QString cpf){
    std::map<QString, Pessoa*>::iterator it;
    it = this->banco->find(cpf);
    if (it == this->banco->end()){
        return false;
    }else{
        return true;
    }
}

Pessoa* BancoDeDados::procurar(QString cpf){
     std::map<QString, Pessoa*>::iterator it;
     it = this->banco->find(cpf);
     if (it == this->banco->end()){
         return nullptr;
     }else{
         Pessoa *pessoa = it->second;
         return pessoa;
     }
}

void BancoDeDados::removerChave(QString cpf){
     if(this->contem(cpf) == true){
          this->banco->erase(cpf);
     }
}


