#include "treino.h"

Treino::Treino()
{
   this->exercicios = new std::map<QString, int>();
}

std::map<QString, int>* Treino::getMap(){
   return this->exercicios;
}


void Treino::adicionarExercicio(QString nome_exercicio, int repeticao){
   this->exercicios->insert(std::pair<QString, int>(nome_exercicio,repeticao));
}
