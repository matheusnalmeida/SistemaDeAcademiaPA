#include "bancodedados.h"

BancoDeDados::BancoDeDados()
{
    this->bancoCPF = new std::map<QString, Pessoa*>();
    this->bancoMatricula = new std::map<QString, Pessoa*>();
    this->alunosCadastradosMatricula = new std::map<QString, Pessoa*>();
    this->professoresCadastradosMatricula = new std::map<QString,Pessoa*>();
    this->alunosCadastradosCPF = new std::map<QString,Pessoa*>();
    this->professoresCadastradosCPF = new std::map<QString,Pessoa*>();
}

BancoDeDados::~BancoDeDados(){
    std::map<QString, Pessoa*>::iterator itr;
    for (itr = this->bancoCPF->begin(); itr != this->bancoCPF->end(); ++itr) {
        delete itr->second;
    }
    delete this->bancoCPF;
    delete this->bancoMatricula;
    delete this->alunosCadastradosMatricula;
    delete this->professoresCadastradosMatricula;
    delete this->alunosCadastradosCPF;
    delete this->professoresCadastradosCPF;
}

void BancoDeDados::armazenar(Pessoa *pessoa){
    this->bancoCPF->insert(std::pair<QString, Pessoa*>(pessoa->getCpf(),pessoa));
    this->bancoMatricula->insert(std::pair<QString, Pessoa*>(pessoa->getMatricula(),pessoa));
    if(pessoa->getMatricula().at(pessoa->getMatricula().length()-1) == 'p'){
        this->professoresCadastradosMatricula->insert(std::pair<QString, Pessoa*>(pessoa->getMatricula(),pessoa));
        this->professoresCadastradosCPF->insert(std::pair<QString, Pessoa*>(pessoa->getCpf(),pessoa));
    }else{
        this->alunosCadastradosMatricula->insert(std::pair<QString, Pessoa*>(pessoa->getMatricula(),pessoa));
        this->alunosCadastradosCPF->insert(std::pair<QString, Pessoa*>(pessoa->getCpf(),pessoa));
    }
}

void BancoDeDados::removerUsuario(Pessoa* pessoa){
    this->bancoCPF->erase(pessoa->getCpf());
    this->bancoMatricula->erase(pessoa->getMatricula());
    this->alunosCadastradosMatricula->erase(pessoa->getMatricula());
    this->alunosCadastradosCPF->erase(pessoa->getCpf());
    this->professoresCadastradosMatricula->erase(pessoa->getMatricula());
    this->professoresCadastradosCPF->erase(pessoa->getCpf());
    delete pessoa;
}

//Metodos de funcionamento com cpf como chave
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
        this->removerUsuario(this->procurarCPF(cpf));
    }
}

//Metodos de funcionamento com matricula como chave

Pessoa* BancoDeDados::procurarMatricula(QString matricula){
    std::map<QString, Pessoa*>::iterator it;
    it = this->bancoMatricula->find(matricula);
    if (it == this->bancoMatricula->end()){
        return nullptr;
    }else{
        Pessoa *pessoa = it->second;
        return pessoa;
    }
}

void BancoDeDados::removerChaveMatricula(QString matricula){
    if(this->contemMatricula(matricula) == true){
        this->removerUsuario(this->procurarMatricula(matricula));
    }
}

bool BancoDeDados::contemMatricula(QString matricula){
    std::map<QString, Pessoa*>::iterator it;
    it = this->bancoMatricula->find(matricula);
    if (it == this->bancoMatricula->end()){
        return false;
    }else{
        return true;
    }
}

//Getters

std::map<QString,Pessoa*>* BancoDeDados::getAlunosMatricula(){
    return this->alunosCadastradosMatricula;
}

std::map<QString,Pessoa*>* BancoDeDados::getTreinadoresMatricula(){
    return this->professoresCadastradosMatricula;
}

std::map<QString,Pessoa*>* BancoDeDados::getAlunosCPF(){
    return this->alunosCadastradosCPF;
}

std::map<QString,Pessoa*>* BancoDeDados::getTreinadoresCPF(){
    return this->professoresCadastradosCPF;
}


