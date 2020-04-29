#ifndef TREINO_H
#define TREINO_H
#include <QString>
#include <map>
#include <QRegularExpression>
class Treino
{
public:
    Treino(QString nome);
    ~Treino();
    std::map<QString,int>* getMap();
    QString getNome();
    void adicionarExercicio(QString nome_exercicio, int repeticao);
private:
    QString nomeDoTreino;
    std::map<QString, int> *exercicios;
};

#endif // TREINO_H
