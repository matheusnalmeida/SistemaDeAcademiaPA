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
    //Metodos usando cpf como chave
    void removerChaveCPF(QString cpf);
    Pessoa* procurarCPF(QString cpf);
    //Metodos usando matricula como chave
    void removerChaveMatricula(QString matricula);
    Pessoa* procurarMatricula(QString matricula);
    //Getters
    std::map<QString,Pessoa*>* getAlunosMatricula();
    std::map<QString,Pessoa*>* getTreinadoresMatricula();
    std::map<QString,Pessoa*>* getAlunosCPF();
    std::map<QString,Pessoa*>* getTreinadoresCPF();

private:
    std::map<QString , Pessoa*> *bancoCPF;
    std::map<QString , Pessoa*> *bancoMatricula;
    std::map<QString,  Pessoa*>* alunosCadastradosMatricula;
    std::map<QString,Pessoa*>* professoresCadastradosMatricula;
    std::map<QString,Pessoa*>* alunosCadastradosCPF;
    std::map<QString,Pessoa*>* professoresCadastradosCPF;
    bool contemCPF(QString cpf);
    bool contemMatricula(QString matricula);
    void removerUsuario(Pessoa* pessoa);

};

#endif // BANCODEDADOS_H
