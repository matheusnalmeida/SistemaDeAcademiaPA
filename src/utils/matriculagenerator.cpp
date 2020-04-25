#include "matriculagenerator.h"
#include <ctime>
#include <QDebug>
MatriculaGenerator::MatriculaGenerator(){}

void MatriculaGenerator::GenerateMatricula(QString cpf,QChar tipo){
    this->validaCpf(cpf);
    std::time_t t = std::time(0);
    std::tm now = {};
    ::localtime_s(&now,&t);
    int ano = now.tm_year + 1900;
    this->matricula = QString::number(ano) + QString::number(incremental++) + tipo;
}

QString MatriculaGenerator::getMatricula(){
    return this->matricula;
}

void MatriculaGenerator::validaCpf(QString cpf){
    int arr_verificador_digito1[9];
    int arr_verificador_digito2[10];
    int cont_digito_1 = 0;
    int cont_digito_2 = 0;
    int decimo = 0;
    int decimoPrimeiro = 0;
    //Inicializando vetor de verificadores do digito 1
    for(int i = 10;i >= 2;i--){
        arr_verificador_digito1[cont_digito_1++] = i;
    }
    //Inicializando vetor de verificadores do digito 2
    for(int i = 11;i >= 2;i--){
        arr_verificador_digito2[cont_digito_2++] = i;
    }
    //Iterando sobre os digitos do cpf e para verificacao do primeiro digito
    cont_digito_1 = 0;
    cont_digito_2 = 0;
    int result_digito1 = 0;
    for(int i = 0;i < cpf.length()-3;i++){
        if(cpf.at(i) != '.'){
            result_digito1 += arr_verificador_digito1[cont_digito_1++] * cpf.at(i).digitValue();
        }
    }
    if((result_digito1 % 11) == 0 || (result_digito1 % 11) == 1){
        decimo = 0;
    }else if((2 <= (result_digito1 % 11)) && ((result_digito1 % 11) <= 10)){
        decimo = 11 - (result_digito1 % 11);
    }
    //Iterando sobre os digitos do cpf e para verificacao do segundo digito
    int result_digito2 = 0;
    for(int i = 0;i < cpf.length()-1;i++){
        if(i == cpf.length()-2){
            result_digito2 += arr_verificador_digito2[cont_digito_2++] * decimo;
            break;
        }
        if(cpf.at(i) != '.' && cpf.at(i) != "-"){
            result_digito2 += arr_verificador_digito2[cont_digito_2++] * cpf.at(i).digitValue();
        }
    }
    if((result_digito2 % 11) == 0 || (result_digito2 % 11) == 1){
        decimoPrimeiro = 0;
    }else if((2 <= (result_digito2 % 11)) && ((result_digito2 % 11) <= 10)){
        decimoPrimeiro = 11 - (result_digito2 % 11);
    }

    if(decimo != cpf.at(12).digitValue() || decimoPrimeiro != cpf.at(13).digitValue()){
        throw CpfInvalidoException("Cpf Inválido!");
    }
}
