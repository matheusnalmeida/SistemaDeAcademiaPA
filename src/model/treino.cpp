#include "treino.h"

Treino::Treino(QString nome)
{
    this->nomeDoTreino = nome;
    this->exercicios = new std::map<QString, int>();
}

Treino::~Treino(){
    delete this->exercicios;
}

std::map<QString, int>* Treino::getMap(){
    return this->exercicios;
}

QString Treino::getNome(){
return this->nomeDoTreino;
}

void Treino::adicionarExercicio(QString nome_exercicio, int repeticao){
    this->exercicios->insert(std::pair<QString, int>(nome_exercicio,repeticao));
}
