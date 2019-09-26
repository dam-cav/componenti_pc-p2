#ifndef GESTIONEUTENTI_H
#define GESTIONEUTENTI_H

#include "../MODEL/listautenti.h"
#include "preparacolore.h"

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QCheckBox>

class gestioneutenti: public QWidget
{
    Q_OBJECT

private:

    //informazioni utili
    listautenti* registrati;
    utente* attuale;
    utente* trovato=nullptr;

    //layout principale
    QVBoxLayout *  l_principale;
    QHBoxLayout *  userEdit;

    QVBoxLayout *  areaMod;
    QLabel * labelID;    
    QLabel * labelNome;    
    QLabel * labelCognome;
    QLineEdit * editID;
    QLineEdit * editNome;
    QLineEdit * editCognome;

    QLabel * labelPass;
    QLineEdit * editPass;    

    QVBoxLayout *  areaPerm;
    QCheckBox * editUser;
    QCheckBox * editComp;
    QPushButton * cancella;

    QPushButton * conferma;
    QListWidget * listaUtenti;

    QLabel * errori;

    void cambiaPermessi();

private slots:
    void leggiDettagli();
    void applicaDettagli();
    void eliminaUtente();
    void tuttiPermessi();

public:
    gestioneutenti(listautenti*& , utente*&);
    void popolaListaU(listautenti *);
    void refreshListe();



};

#endif // GESTIONEUTENTI_H
