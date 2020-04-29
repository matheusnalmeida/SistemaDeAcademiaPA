#ifndef PESSOA_H
#define PESSOA_H

#include <QString>
#include "endereco.h"
#include "treino.h"
#include <map>

class Pessoa
{
public:
    Pessoa();
    Pessoa(QString nome,QString cpf,QString telefone,QString email,Endereco* endereco,QString matricula,QChar genero);
    ~Pessoa();
    void cadastrarTreino(QString nomeDoTreino);
    void removerTreino(QString nomeDoTreino);
    //Getters
    QString getNome();
    QString getCpf();
    QString getTelefone();
    QString getEmail();
    Endereco* getEndereco();
    QString getMatricula();
    QChar getGenero();
    std::map<QString,Treino*>* getTreinos();

private:
    //Atributos
    QString nome;
    QString cpf;
    QString telefone;
    QString email;
    Endereco* endereco;
    QString matricula;
    QChar genero;
    std::map<QString,Treino*>* treinos;
};

#endif // PESSOA_H
