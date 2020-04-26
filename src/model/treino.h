#ifndef TREINO_H
#define TREINO_H
#include <string>
#include <map>
#include <QRegularExpression>
class Treino
{
public:
    Treino();
    std::map<QString,int>* getMap();
    void adicionarExercicio(QString nome_exercicio, int repeticao);
private:
    std::map<QString, int> *exercicios;
};

#endif // TREINO_H
