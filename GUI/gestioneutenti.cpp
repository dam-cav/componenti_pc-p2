#include "gestioneutenti.h"

void gestioneutenti::leggiDettagli()
{
    if(listaUtenti->currentItem()){
        errori->setText("Letti dettagli utente");
        trovato = registrati->cercaId((listaUtenti->currentItem()->text()).toStdString());
        editComp->setCheckable(true);
        editUser->setCheckable(true);
        editUser->setChecked(trovato->gestisceUtenti());
        editComp->setChecked(trovato->gestisceCatalogo());
        if(attuale==trovato) {
            editComp->setCheckable(false);
            editUser->setCheckable(false);
        }
        editID->setText(QString::fromStdString(trovato->getID()));
        editNome->setText(QString::fromStdString(trovato->getNome()));
        editCognome->setText(QString::fromStdString(trovato->getCognome()));
        editPass->setPlaceholderText(QString("Immutata"));

        editID->setReadOnly(false);
        editNome->setReadOnly(false);
        editCognome->setReadOnly(false);
        editPass->setReadOnly(false);
    }
    else errori->setText("Seleziona un utente!");
}

void gestioneutenti::applicaDettagli()
{
    bool modifiche=false;
    if(!attuale->gestisceUtenti() && editPass->text()!="") {
        attuale->setPassword(editPass->text().toStdString());
        editPass->setText("");
        this->hide();
    }
    else {
        if(attuale->gestisceUtenti() && listaUtenti->currentItem()){
            if(editID->text()!="" && editNome->text()!="" && editCognome->text()!="" && (!registrati->cercaId(editID->text().toStdString()) || registrati->cercaId(editID->text().toStdString())==trovato)){               
                trovato->setID(editID->text().toStdString());
                trovato->setNome(editNome->text().toStdString());
                trovato->setCognome(editCognome->text().toStdString());
                if(editPass->text()!="")trovato->setPassword(editPass->text().toStdString());
                listaUtenti->clear();
                popolaListaU(registrati);

                editID->setReadOnly(true);
                editNome->setReadOnly(true);
                editCognome->setReadOnly(true);
                editPass->setReadOnly(true);

                editID->setText("");
                editNome->setText("");
                editCognome->setText("");
                editPass->setText("");
                editPass->setPlaceholderText("");
                modifiche=true;
                errori->setText("Modificato correttamente");
                if(attuale!=trovato && (editUser->isChecked()!=trovato->gestisceUtenti() || editComp->isChecked()!=trovato->gestisceCatalogo()) ){
                    utente* nuovo;
                    if(editUser->isChecked())nuovo= new us_admin(trovato->getID(),trovato->getNome(),trovato->getCognome(),trovato->getPassword()); //SUPERADMIN
                    else{
                        if (editComp->isChecked()) nuovo= new us_tecnico(trovato->getID(),trovato->getNome(),trovato->getCognome(),trovato->getPassword()); //MAGAZZINIERE
                        else nuovo= new us_cliente(trovato->getID(),trovato->getNome(),trovato->getCognome(),trovato->getPassword()); //CLIENTE
                    }

                    for(auto it=trovato->suaWishlist()->begin();it!=trovato->suaWishlist()->end();++it){
                        nuovo->suaWishlist()->addComp(*it);
                    }
                    registrati->remMatch(trovato->getID());
                    registrati->addUser(nuovo);
                    registrati->ordinaNome();
                }
            }
            else errori->setText("Campi non corretti o ID coincidenti!");

        }
        if(modifiche) {trovato=nullptr; refreshListe();}

    }


    registrati->stampaXml();

}

void gestioneutenti::eliminaUtente()
{
    if(attuale!=trovato && listaUtenti->currentItem()){
        registrati->remMatch(trovato->getID());
        refreshListe();
        editID->setText("");
        editNome->setText("");
        editCognome->setText("");
        editPass->setText("");
        editPass->setPlaceholderText("");
        trovato=nullptr;
        registrati->stampaXml();
        editID->setReadOnly(true);
        editNome->setReadOnly(true);
        editCognome->setReadOnly(true);
        editPass->setReadOnly(true);
        errori->setText("Utente Eliminato");
    }
    else errori->setText("Non puoi cancellare nessuno o te stesso!");
}

void gestioneutenti::tuttiPermessi()
{
    if(editUser->isChecked()) editComp->setChecked(true);
}

gestioneutenti::gestioneutenti(listautenti*& reg, utente*& att): registrati(reg), attuale(att)
{
    setWindowTitle("Gestione Utenti");
    this->setWindowIcon(QIcon(QPixmap(":/IMG/user.svg")));
    this->setMinimumWidth(350);
    this->setMaximumWidth(400);

    //LAYOUT PRINCIPALE
    l_principale = new QVBoxLayout();
    this->setLayout(l_principale);

    //Layout Contenente l'area di modifica delle stringhe utente (ID-Nome-Cognome-Password)
    areaMod = new QVBoxLayout();

    //Layout che riunisce permessi e stringhe
    userEdit = new QHBoxLayout();
    userEdit->addLayout(areaMod);
    l_principale->addLayout(userEdit);

    //Opzioni disponibili a tutti gli utenti (con permessi e non)
    labelPass = new QLabel("Password");
    editPass = new QLineEdit();
    editPass->setEchoMode(QLineEdit::Password);
    conferma = new QPushButton("Conferma");
    connect(conferma,SIGNAL(clicked()),this,SLOT(applicaDettagli()));
    l_principale->addWidget(conferma);

    //Opzioni disponibili solo a chi possiede i permessi di amministrazione
    if(attuale->gestisceUtenti()){
        labelID = new QLabel("ID");
        labelNome = new QLabel("Nome");
        labelCognome = new QLabel("Cognome");
        editID = new QLineEdit();
        editNome = new QLineEdit();
        editCognome = new QLineEdit();
        editID->setReadOnly(true);
        editNome->setReadOnly(true);
        editCognome->setReadOnly(true);
        editPass->setReadOnly(true); //il campo password si comporta in modo differente per chi amministra

        //riempimento del layout con l'editor stringhe nell'ordine corretto
        areaMod->addWidget(labelID);
        areaMod->addWidget(editID);
        areaMod->addWidget(labelNome);
        areaMod->addWidget(editNome);
        areaMod->addWidget(labelCognome);
        areaMod->addWidget(editCognome);

        //Layout Contenente le opzioni riguardo i permessi da consentire
        areaPerm = new QVBoxLayout();
        userEdit->addLayout(areaPerm);
        editUser = new QCheckBox("Admin");
        editComp = new QCheckBox("Gestisce Catalogo");
        cancella = new QPushButton("Cancella Utente");
        connect(editUser,SIGNAL(clicked(bool)),this,SLOT(tuttiPermessi()));
        connect(cancella,SIGNAL(clicked()),this,SLOT(eliminaUtente()));
        areaPerm->addWidget(editUser);
        areaPerm->addWidget(editComp);
        areaPerm->addWidget(cancella);

        //lista degli utenti registrati
        listaUtenti = new QListWidget();
        connect(listaUtenti,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(leggiDettagli()));
        popolaListaU(registrati);
        l_principale->addWidget(listaUtenti);

        errori = new QLabel("");
        l_principale->addWidget(errori);
    }
    else {
        editPass->setPlaceholderText(QString("Immutata")); //il campo password si comporta in modo differente per chi NON amministra
        setMaximumHeight(100);
    }

    //posizioni i campi disponibili a tutti nell'ordine corretto
    areaMod->addWidget(labelPass);
    areaMod->addWidget(editPass);

}

void gestioneutenti::popolaListaU(listautenti * reg)
{
    QListWidgetItem *riga;
    for(auto it: *reg){
        riga= new QListWidgetItem;
        riga->setText(QString::fromStdString(it->getID()));
        riga->setForeground(preparacolore::getColoreCorrettoUser(it));
        listaUtenti->addItem(riga);
    }
}

void gestioneutenti::refreshListe()
{
    listaUtenti->clear();
    popolaListaU(registrati);
}
