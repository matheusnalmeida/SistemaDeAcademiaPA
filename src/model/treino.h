#ifndef TREINO_H
#define TREINO_H
#include <string>

class Treino
{
public:
    Treino();
    Treino(int quantidadeR, std::string nomeTreino);
    int getRepeticao();

    std::string getNomeTreino();
private:
    int qtdRepeticao;
    std::string nomeTreino;
};

#endif // TREINO_H
