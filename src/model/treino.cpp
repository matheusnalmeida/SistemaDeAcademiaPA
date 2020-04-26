#include "treino.h"

Treino::Treino()
{

}
Treino::Treino(int quantidadeR, std::string nomeTreino){
     this->qtdRepeticao = quantidadeR;
     this->nomeTreino = nomeTreino;
}
int Treino::getRepeticao(){
    return this->qtdRepeticao;
}

std::string Treino::getNomeTreino(){
    return this->nomeTreino;
}
