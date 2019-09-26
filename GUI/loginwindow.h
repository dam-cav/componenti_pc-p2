#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "../MODEL/listacomp.h"
#include "../MODEL/listautenti.h"
#include "mainwindow.h"



class loginwindow: public QWidget
{
    Q_OBJECT

private:

    listacomp* catalogo;
    listautenti* registrati;
    MainWindow *mw;

    QVBoxLayout * l_principale;
    QHBoxLayout * l_totale;
    QVBoxLayout * l_login;
    QVBoxLayout * l_registrazione;

    QLabel * labelID;
    QLabel * labelPassword;
    QLineEdit * editID;
    QLineEdit * editPassword;

    QLabel * labelNome;
    QLabel * labelCognome;
    QLineEdit * editNome;
    QLineEdit * editCognome;

    QPushButton * buttonLogin;
    QPushButton * buttonSignin;

    QLabel * errori;


private slots:
    void tentaLogin();
    void tentaRegistrazione();
    void mostra_finestra();

public:
     loginwindow(listacomp*, listautenti*);

};

#endif // LOGINWINDOW_H
