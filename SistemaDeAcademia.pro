QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/controller/dialogcadastrarexercicios.cpp \
    src/controller/dialogmostrarusuarios.cpp \
    src/controller/dialogcadastrartreino.cpp \
    src/model/personal.cpp \
    src/controller/dialogmostrartreino.cpp \
    src/model/bancodedados.cpp \
    src/controller/dialogcadastro.cpp \
    src/utils/cpfinvalidoexception.cpp \
    src/model/endereco.cpp \
    src/controller/login.cpp \
    src/model/pessoa.cpp \
    src/utils/matriculagenerator.cpp \
    src/view/main.cpp \
    src/controller/teladeusuario.cpp \
    src/model/treino.cpp \
    src/model/usuario.cpp \
    src/controller/teladopersonal.cpp

HEADERS += \
    src/controller/dialogcadastrarexercicios.h \
    src/controller/dialogmostrarusuarios.h \
    src/controller/dialogcadastrartreino.h \
    src/model/personal.h \
    src/controller/dialogmostrartreino.h \
    src/model/bancodedados.h \
    src/controller/dialogcadastro.h \
    src/utils/cpfinvalidoexception.h \
    src/model/endereco.h \
    src/controller/login.h \
    src/model/pessoa.h \
    src/controller/teladeusuario.h \
    src/utils/matriculagenerator.h \
    src/model/treino.h \
    src/model/usuario.h \
    src/controller/teladopersonal.h

FORMS += \
    src/view/dialogcadastrarexercicios.ui \
    src/view/dialogcadastrartreino.ui \
    src/view/dialogmostrarusuarios.ui \
    src/view/dialogmostrartreino.ui \
    src/view/dialogcadastro.ui \
    src/view/login.ui \
    src/view/teladeusuario.ui \
    src/view/teladopersonal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    banco_imagem.qrc
