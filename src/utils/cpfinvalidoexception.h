#ifndef CPFINVALIDOEXCEPTION_H
#define CPFINVALIDOEXCEPTION_H
#include "QException"
#include "QString"

class CpfInvalidoException : public QException
{
public:
    CpfInvalidoException(QString message);
    const char * what () const throw () {
       return this->message.toStdString().c_str();
    }
private:
    QString message;
};

#endif // CPFINVALIDOEXCEPTION_H
