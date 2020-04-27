#include "bancodedados.h"

BancoDeDados::BancoDeDados()
{
     this->bancoCPF = new std::map<QString, Pessoa*>();
     this->bancoMatricula = new std::map<QString, Pessoa*>();
}

BancoDeDados::~BancoDeDados(){
    std::map<QString, Pessoa*>::iterator itr;
    for (itr = this->bancoCPF->begin(); itr != this->bancoCPF->end(); ++itr) {
            delete itr->second;
    }
    for (itr = this->bancoMatricula->begin(); itr != this->bancoMatricula->end(); ++itr) {
            delete itr->second;
    }
    delete  this->bancoCPF;
    delete this->bancoMatricula;
}

int BancoDeDados::tamanhoMapMatricula(){
    return this->bancoMatricula->size();
}

void BancoDeDados::armazenar(Pessoa *pessoa){
     this->bancoCPF->insert(std::pair<QString, Pessoa*>(pessoa->getCpf(),pessoa));
     this->bancoMatricula->insert(std::pair<QString, Pessoa*>(pessoa->getMatricula(),pessoa));
}


bool BancoDeDados::contemCPF(QString cpf){
    std::map<QString, Pessoa*>::iterator it;
    it = this->bancoCPF->find(cpf);
    if (it == this->bancoCPF->end()){
        return false;
    }else{
        return true;
    }
}

Pessoa* BancoDeDados::procurarCPF(QString cpf){
     std::map<QString, Pessoa*>::iterator it;
     it = this->bancoCPF->find(cpf);
     if (it == this->bancoCPF->end()){
         return nullptr;
     }else{
         Pessoa *pessoa = it->second;
         return pessoa;
     }
}

void BancoDeDados::removerChaveCPF(QString cpf){
     if(this->contemCPF(cpf) == true){
          this->bancoCPF->erase(cpf);
     }
}


std::map<QString , Pessoa*>* BancoDeDados:: getBancoMatricula(){
          return this->bancoMatricula;
}

