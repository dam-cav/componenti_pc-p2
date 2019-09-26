
#include <QApplication>
#include <QMessageBox>
#include "MODEL/listacomp.h"
#include "MODEL/listautenti.h"
#include "GUI/loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Creazione liste vuote
    listacomp* catalogo= new listacomp(false);
    listautenti* registrati= new listautenti;

    //Popolamento Liste da file
    catalogo->popolaListaDaXml();
    if(!registrati->popolaListaDaXml(*catalogo)){
        QMessageBox primapertura;
        primapertura.setText("Errore nel caricamento degli utenti o prima apertura dell'applicazione, creato utente amministratore di default con ID=\"admin\" e password=\"admin\".\nAssicurati di non manomettere mai i file xml.");
        primapertura.setWindowTitle("Prima apertura?");
        primapertura.setWindowIcon(QIcon(QPixmap(":/IMG/icon.svg")));
        primapertura.exec();
    }

    loginwindow *log = new loginwindow(catalogo, registrati);
    log->show();
    return a.exec();
}
