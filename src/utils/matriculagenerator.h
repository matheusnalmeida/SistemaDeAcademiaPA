#ifndef MATRICULAGENERATOR_H
#define MATRICULAGENERATOR_H

#include <QString>
#include "cpfinvalidoexception.h"

class MatriculaGenerator
{
public:
    MatriculaGenerator();
    void GenerateMatricula(QString cpf,QChar tipo);
    QString getMatricula();
private:
    int incremental = 1;
    QString matricula;
    void validaCpf(QString cpf);
};

#endif // MATRICULAGENERATOR_H
