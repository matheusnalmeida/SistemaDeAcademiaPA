#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H
#include <map>
#include <QRegularExpression>
#include "src/model/pessoa.h"

class BancoDeDados
{
public:
    BancoDeDados();
    ~BancoDeDados();
    void armazenar(Pessoa *pessoa);
    void removerChaveCPF(QString cpf);
    int tamanhoMapMatricula();
    Pessoa* procurarCPF(QString cpf);
    std::map<QString , Pessoa*> *getBancoMatricula();
private:
    std::map<QString , Pessoa*> *bancoCPF;
    std::map<QString , Pessoa*> *bancoMatricula;
    bool contemCPF(QString cpf);
};

#endif // BANCODEDADOS_H
