#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<string>

#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QListView>
#include <QLabel>
#include <QStatusBar>
#include <QRadioButton>

#include "gestioneutenti.h"
#include "edit_componente.h"
#include "preparaeditor.h"
#include "preparacolore.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void chiusura();

private:

    //Informazioni necessarie
    listacomp* catalogo;
    listautenti* registrati;
    utente* us;
    listacomp * uscarr;

    //Altre Finestre
    gestioneutenti* gestioneu;
    edit_componente* editcomp;

    //oggetti principali
    QWidget* w_principale;
    QVBoxLayout * l_principale;
    QStatusBar* stat;
    QLabel* statInfo;

    //Prima "Riga" finestra principale
    QHBoxLayout* bottonifunzioni;
    QPushButton* bottoneUser;
    QPushButton* bottoneLogout;

    //Seconda "Riga", Intestazione delle Liste
    QHBoxLayout* nomiliste;
    QLabel* nomeSx;
    QLabel* nomeDx;
    QLineEdit * ptotWish;
    QVBoxLayout* infoImgSx;
    QVBoxLayout* infoImgDx;
    QLabel* imgSx;
    QLabel* imgDx;
    QLabel* infoSx;
    QLabel* infoDx;

    //Colonna dei bottoncini che gestiscono le liste
    QVBoxLayout* comandiListe;
    QPushButton* addWishButton;
    QPushButton* remWishButton;
    QPushButton* delWishButton;
    QPushButton* editButton;
    QPushButton* delButton;
    QPushButton* createButton;

    //Liste Effettive
    QHBoxLayout* liste;
    QListWidget* listaSx;
    QListWidget* listaDx;

    //Ordine e Ricerca
    QHBoxLayout* ordineRicerca;
    QPushButton* reset;
    QLineEdit* cerca;
    QRadioButton* ordineAlfa;
    QRadioButton* ordinePrezzo;

    //Selettore filtro
    QComboBox * filtraTipo;

private slots:
    //apertura Finestre
    void aprigestioneutenti();
    void crea_nuovo();
    void logout_utente();

    //gestione wishlist
    void rimuovi_wish();
    void catalogo_to_wish();
    void svuota_wish();

    //gestione catalogo
    void modifica_selezionato();
    void aggiungi_catalogo(componente*);
    void elimina_selezionato();
    void filtra();
    void pulisci_ricerca();
    void cambia_ordine();

    //reazioni su liste
    void infoSin();
    void infoDes();
    void refreshListe();



public:
    MainWindow(listacomp*, listautenti*, utente*, QWidget *parent = 0);
    ~MainWindow(){};
    void popolaSinistra(listacomp*, const std::string& ="NA");
    void popolaDestra(listacomp*);

};

#endif // MAINWINDOW_H
