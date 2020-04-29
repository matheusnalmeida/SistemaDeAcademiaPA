#include "treino.h"

Treino::Treino(QString nome)
{
    this->nomeDoTreino = nome;
    this->exercicios = new std::map<QString, QString>();
}

Treino::~Treino(){
    delete this->exercicios;
}

std::map<QString, QString>* Treino::getMap(){
    return this->exercicios;
}

QString Treino::getNome(){
return this->nomeDoTreino;
}

void Treino::adicionarExercicio(QString nome_exercicio, QString repeticao){
    this->exercicios->insert(std::pair<QString, QString>(nome_exercicio,repeticao));
}
