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
    std::map<QString,QString>* getMap();
    QString getNome();
    void adicionarExercicio(QString nome_exercicio, QString repeticao);
private:
    QString nomeDoTreino;
    std::map<QString, QString> *exercicios;
};

#endif // TREINO_H
