#include "mainwindow.h"

//apre semplicemente la finestra di gestione utenti (o di cambio password qualora non si abbiano i poteri)
void MainWindow::aprigestioneutenti(){
    gestioneu->show();
}

//apre la finestra per la creazione di un nuovo componente, richiede che sia staato applicato un filtro dal quale ricava il tipo
void MainWindow::crea_nuovo(){
    componente* temp=nullptr;
    if(filtraTipo->currentText()!="Nessun Filtro"){// non ha senso fare tutti i successivi controlli se già questo non passa
        if(filtraTipo->currentText()=="Processore") temp= new comp_cpu();
        else if(filtraTipo->currentText()=="Processore con Gpu") temp= new comp_cpugpu();
        else if(filtraTipo->currentText()=="Case con Alimentatore") temp= new comp_casepsu();
        else if(filtraTipo->currentText()=="Case") temp= new comp_desktopcase();
        else if(filtraTipo->currentText()=="Dissipatore") temp= new comp_dissi();
        else if(filtraTipo->currentText()=="Scheda Video") temp= new comp_gpu();
        else if(filtraTipo->currentText()=="Memoria") temp= new comp_hdd();
        else if(filtraTipo->currentText()=="Scheda Madre") temp= new comp_mobo();
        else if(filtraTipo->currentText()=="Alimentatore") temp= new comp_psu();
        else if(filtraTipo->currentText()=="Memoria Ram") temp= new comp_ram();
    }
    else statInfo->setText("Devi filtrare la lista per tipo per poter creare un nuovo componente!");
    if(temp){
        editcomp= preparaEditor::getEditorCorretto(temp,catalogo,true);
        editcomp->setAttribute(Qt::WA_DeleteOnClose);
        connect(editcomp,SIGNAL(closed(componente*)),this,SLOT(aggiungi_catalogo(componente*)));
        editcomp->show();
    }
}

//logout, riporta alla schermata di login
void MainWindow::logout_utente()
{
    delete gestioneu;
    emit(chiusura());
    this->close();
}

//rimuove dalla wishlist il componente selezionato
void MainWindow::rimuovi_wish(){
    if(listaDx->currentItem()){
        uscarr->remMatch((listaDx->currentItem()->text()).toStdString(),false);
        listaDx->clear();
        infoDx->setText("Nessun oggetto selezionato.");
        imgDx->setPixmap(preparacolore::getImmagineCorrettaComp(nullptr).scaled(60,60));
        popolaDestra(uscarr);
        statInfo->setText("Operazione effettuata correttamente");
    }
    else statInfo->setText("Per rimuovere un componente devi prima selezionarlo nella wishlist!");
}

//aggiunge alla wishlist il componente selezionato sul catalogo
void MainWindow::catalogo_to_wish(){
    if(listaSx->currentItem()){
        uscarr->addComp(catalogo->cercaNome((listaSx->currentItem()->text()).toStdString()));
        listaDx->clear();
        popolaDestra(uscarr);
        statInfo->setText("Operazione effettuata correttamente");
    }
    else statInfo->setText("Devi selezionare un oggetto dal catalogo per poterlo aggiungere alla wishist!");
}


//svuota la wishtlist con un solo click
void MainWindow::svuota_wish()
{
    uscarr->clearAll();
    listaDx->clear();
    infoDx->setText("Nessun oggetto selezionato.");
    imgDx->setPixmap(preparacolore::getImmagineCorrettaComp(nullptr).scaled(60,60));
    popolaDestra(uscarr);
    statInfo->setText("Operazione effettuata correttamente");

}

//slot che si occupa di recuperare il tipo di widget corretto da usare in base al componente che si desidera modificare
void MainWindow::modifica_selezionato(){
    if(listaSx->currentItem()){
        editcomp= preparaEditor::getEditorCorretto(catalogo->cercaNome(listaSx->currentItem()->text().toStdString()) , catalogo);
        editcomp->setAttribute(Qt::WA_DeleteOnClose); //non rimarrà in memoria una volta chiusa
        editcomp->setWindowIcon(QIcon(QPixmap(":/IMG/icon.svg")));
        connect(editcomp,SIGNAL(closed(componente*)),this,SLOT(refreshListe()));
        editcomp->show();
        statInfo->setText("Aperta finestra di modifica");
    }
    else statInfo->setText("Devi selezionare un oggetto dal catalogo per poterlo modificare!");
}

//aggiunge al catalogo un nuovo oggetto se riceve un puntatore non nullo
void MainWindow::aggiungi_catalogo(componente * inseriscimi){
    if(inseriscimi) {
        catalogo->addComp(inseriscimi);
        cambia_ordine();
    }
}

//elimina definitivamente il componente slelzionato dal catalogo ovunque esso sia (catalogo e wishlist)
void MainWindow::elimina_selezionato(){
    if(listaSx->currentItem()){
        for(auto it=registrati->begin();it!=registrati->end();++it){
            (*it)->suaWishlist()->remMatch((listaSx->currentItem()->text()).toStdString(),true);
        }
        catalogo->remMatch((listaSx->currentItem()->text()).toStdString(),true,true);//rimozione definitiva, distrugge l'oggetto
        refreshListe();
        statInfo->setText("Operazione effettuata correttamente, l'operazione si ripercuote anche sulle wishlist degli utenti, fai attenzione!");
    }
    else statInfo->setText("Devi selezionare un oggetto dal catalogo per poterlo eliminare definitivamente!");
}

//applica tutti i filtri (ricerca per nome e tipo) e mostra il risultato nel catalogo
void MainWindow::filtra(){
    listaSx->clear();
    if (filtraTipo->currentText()=="Nessun Filtro")popolaSinistra(catalogo);//Valore di default della funzione è "NA", in caso di aggiunte usare coppia di lettere diversa
    else if(filtraTipo->currentText()=="Case") popolaSinistra(catalogo,"CA");
    else if(filtraTipo->currentText()=="Processore") popolaSinistra(catalogo,"PR");
    else if(filtraTipo->currentText()=="Dissipatore") popolaSinistra(catalogo,"DI");
    else if(filtraTipo->currentText()=="Scheda Video") popolaSinistra(catalogo,"SV");
    else if(filtraTipo->currentText()=="Memoria") popolaSinistra(catalogo,"ME");
    else if(filtraTipo->currentText()=="Scheda Madre") popolaSinistra(catalogo,"SM");
    else if(filtraTipo->currentText()=="Alimentatore") popolaSinistra(catalogo,"AL");
    else if(filtraTipo->currentText()=="Memoria Ram") popolaSinistra(catalogo,"MR");
    else if(filtraTipo->currentText()=="Processore con Gpu") popolaSinistra(catalogo,"PR+SV");
    else if(filtraTipo->currentText()=="Case con Alimentatore") popolaSinistra(catalogo,"CA+AL");


    for(int i=0; i!=listaSx->count();++i){
        if(cerca->text()!=""){
            if((listaSx->item(i)->text()).indexOf(cerca->text(), 0, Qt::CaseInsensitive) != -1)
                listaSx->setRowHidden(i, false);
            else listaSx->setRowHidden(i, true);
        }
        else listaSx->setRowHidden(i, false);
    }

    infoSx->setText("Nessun oggetto selezionato.");
    imgSx->setPixmap(preparacolore::getImmagineCorrettaComp(nullptr).scaled(60,60));
}

//resettala ricerca senza dover cancellare manualmente sulla casella di testo
void MainWindow::pulisci_ricerca()
{
    cerca->setText("");
    filtra();
}

//modifica l'ordine del catalogo in base a quello selezionato
void MainWindow::cambia_ordine()
{
    if(ordineAlfa->isChecked()) catalogo->ordinaNome();
    else if(ordinePrezzo->isChecked()) catalogo->ordinaPrezzo();
    filtra();
}

//2 slot che si occupano di tenere aggiornate le label con le info ma mano che si selezionano componenti
void MainWindow::infoSin(){
    componente* trovato = catalogo->cercaNome((listaSx->currentItem()->text()).toStdString());
    if(trovato){
        infoSx->setText(QString::fromStdString((trovato->stampaTutto())));
        imgSx->setPixmap(preparacolore::getImmagineCorrettaComp(trovato).scaled(60,60));
    }
}
void MainWindow::infoDes(){
    componente* trovato = catalogo->cercaNome((listaDx->currentItem()->text()).toStdString());
    if(trovato){
        infoDx->setText(QString::fromStdString((trovato->stampaTutto())));
        imgDx->setPixmap(preparacolore::getImmagineCorrettaComp(trovato).scaled(60,60));
    }
}

//riporta tutta la finesta alle condizioni base (nessun filtro, nessuna ricerca, liste aggiornate, niente di selezionato)
void MainWindow::refreshListe(){
    filtraTipo->setCurrentText("Nessun Filtro");
    listaDx->clear();
    popolaDestra(uscarr);
    listaSx->clear();
    popolaSinistra(catalogo);
    infoSx->setText("Nessun oggetto selezionato.");
    infoDx->setText("Nessun oggetto selezionato.");
    imgSx->setPixmap(preparacolore::getImmagineCorrettaComp(nullptr).scaled(60,60));
    imgDx->setPixmap(preparacolore::getImmagineCorrettaComp(nullptr).scaled(60,60));
    pulisci_ricerca();
    cambia_ordine();
}

//COSTRUTTORE

MainWindow::MainWindow(listacomp* cat , listautenti*  re , utente* logged,QWidget *parent)
    : QMainWindow(parent), catalogo(cat),registrati(re), us(logged)
{
    //Detagli della Finestra
    setWindowTitle("Progetto_ComponentiPC");
    this->setAttribute(Qt::WA_DeleteOnClose); //non rimane in memoria quando chiusa
    this->setWindowIcon(QIcon(QPixmap(":/IMG/icon.svg")));
    w_principale = new QWidget();

    stat= new QStatusBar();
    statInfo= new QLabel("Benvenuto");
    stat->addWidget(statInfo);
    this->setStatusBar(stat);

    //Preparo puntatore diretto alla wishlist dell'utente loggato
    uscarr= us->suaWishlist();

    //Prima "Riga", finestra principale
    bottonifunzioni = new QHBoxLayout;
    bottoneUser= new QPushButton ("Gestione Utente");
    bottoneLogout= new QPushButton ("Logout");
    bottonifunzioni->addWidget(bottoneUser);
    bottonifunzioni->addWidget(bottoneLogout);
    connect(bottoneUser,SIGNAL(clicked()),this,SLOT(aprigestioneutenti()));
    connect(bottoneLogout,SIGNAL(clicked()),this,SLOT(logout_utente()));

    //Seconda "Riga", Intestazione delle Liste
    QHBoxLayout *nomiliste = new QHBoxLayout;
    nomeSx= new QLabel("CATALOGO");
    nomeDx= new QLabel("WISHLIST");
    nomiliste->addWidget(nomeSx);
    nomiliste->addWidget(nomeDx);

    //Label che mostrano Info delle componenti selezionate
    infoImgSx = new QVBoxLayout;
    infoImgDx = new QVBoxLayout;    
    imgSx = new QLabel;
    imgDx = new QLabel;
    imgSx->setFixedHeight(70);
    imgDx->setFixedHeight(70);
    infoSx = new QLabel("Nessun oggetto selezionato.");
    infoDx = new QLabel("Nessun oggetto selezionato.");
    infoSx->setAlignment(Qt::AlignTop);
    infoDx->setAlignment(Qt::AlignTop);
    infoSx->setFixedHeight(580);
    infoDx->setFixedHeight(580);
    infoSx->setFixedWidth(250);
    infoDx->setFixedWidth(250);
    infoSx->setWordWrap(true); //le righe troppo lunghervanno a capo (utile per esempio nei dissipatori con tanti socket
    infoDx->setWordWrap(true);
    infoImgSx->addWidget(imgSx);
    infoImgSx->addWidget(infoSx);
    infoImgDx->addWidget(imgDx);
    infoImgDx->addWidget(infoDx);


    //Colonna dei bottoncini che gestiscono le liste
    comandiListe = new QVBoxLayout;
    addWishButton = new QPushButton ("-->");
    remWishButton = new QPushButton ("<--");
    delWishButton = new QPushButton ("X<-");
    comandiListe->addWidget(addWishButton);
    comandiListe->addWidget(remWishButton);
    comandiListe->addWidget(delWishButton);
    connect(addWishButton,SIGNAL(clicked()),this,SLOT(catalogo_to_wish()));
    connect(remWishButton,SIGNAL(clicked()),this,SLOT(rimuovi_wish()));
    connect(delWishButton,SIGNAL(clicked()),this,SLOT(svuota_wish()));
    //Comandi disponibili solo a chi ha i permessi di gestione catalogo
    if(us->gestisceCatalogo()){
        editButton = new QPushButton ("Edit");
        delButton= new QPushButton ("X");
        createButton= new QPushButton ("+");
        comandiListe->addWidget(editButton);
        comandiListe->addWidget(delButton);
        comandiListe->addWidget(createButton);
        connect(editButton,SIGNAL(clicked()),this,SLOT(modifica_selezionato()));
        connect(delButton,SIGNAL(clicked()),this,SLOT(elimina_selezionato()));
        connect(createButton,SIGNAL(clicked()),this,SLOT(crea_nuovo()));
    }

    //Liste che mostrano i componenti
    liste = new QHBoxLayout;
    listaDx= new QListWidget();
    listaDx->setMinimumWidth(320);
    listaSx= new QListWidget();
    listaSx->setMinimumWidth(320);
    connect(listaSx,SIGNAL(itemSelectionChanged()),this,SLOT(infoSin()));
    connect(listaDx,SIGNAL(itemSelectionChanged()),this,SLOT(infoDes()));

    //Riempimento terza "riga" con label info, liste e loro bottoni
    liste->addLayout(infoImgSx);
    liste->addWidget(listaSx);
    liste->addLayout(comandiListe);
    liste->addWidget(listaDx);
    liste->addLayout(infoImgDx);

    //Ricerca e Ordinamento
    ordineRicerca = new QHBoxLayout;
    reset = new QPushButton("Reset");
    cerca = new QLineEdit();
    ordineAlfa= new QRadioButton("A↓");
    ordineAlfa->setChecked(true);
    ordinePrezzo= new QRadioButton("€↓");
    connect(reset,SIGNAL(clicked(bool)),this,SLOT(pulisci_ricerca()));
    connect(cerca,SIGNAL(textChanged(QString)),this,SLOT(filtra()));
    connect(ordineAlfa,SIGNAL(clicked(bool)),this,SLOT(cambia_ordine()));
    connect(ordinePrezzo,SIGNAL(clicked(bool)),this,SLOT(cambia_ordine()));
    ordineRicerca->addWidget(reset);
    ordineRicerca->addWidget(cerca);
    ordineRicerca->addWidget(ordineAlfa);
    ordineRicerca->addWidget(ordinePrezzo);


    /*ComboBox utilizzata sia per filtrare la lista catalogo per tipo che per scegliere
    il tipo di elemento in caso di un nuovo inserimento*/
    filtraTipo = new QComboBox();
    filtraTipo->addItem("Nessun Filtro");
    filtraTipo->addItem("Alimentatore");
    filtraTipo->addItem("Case");
    filtraTipo->addItem("Case con Alimentatore");
    filtraTipo->addItem("Dissipatore");
    filtraTipo->addItem("Memoria");
    filtraTipo->addItem("Memoria Ram");
    filtraTipo->addItem("Processore");
    filtraTipo->addItem("Processore con Gpu");
    filtraTipo->addItem("Scheda Madre");
    filtraTipo->addItem("Scheda Video");
    connect(filtraTipo,SIGNAL(currentTextChanged(QString)),this,SLOT(filtra()));

    //LAYOUT PRINCIPALE: Riunisce gli altri layout in un unico blocco
    l_principale = new QVBoxLayout;
    l_principale->addLayout(bottonifunzioni);
    l_principale->addLayout(nomiliste);
    l_principale->addLayout(liste);
    l_principale->addLayout(ordineRicerca);
    l_principale->addWidget(filtraTipo);

    //Assegno il layout principale al Widget della MainWindow
    w_principale->setLayout(l_principale);
    this->setCentralWidget(w_principale);

    //Funzioni che riempiono le liste disegnate precedentemente
    refreshListe();

    //costruisco già la finestra di gestione utenti, ma la mostro solo- quando richiesto dall'utente
    gestioneu= new gestioneutenti(registrati, us);
}

//FUNZIONI POPOLAMENTO LISTE

void MainWindow::popolaSinistra(listacomp * listaSin, const std::string& filtro)
{
    QListWidgetItem *riga;
    if(filtro=="NA") for(auto it: *listaSin){ //Caso lista non filtrata per tipo
        riga= new QListWidgetItem;
        riga->setText(QString::fromStdString(it->getNome()));
        riga->setForeground(preparacolore::getColoreCorrettoComp(it));
        listaSx->addItem(riga);
    }
    //Tutti gli altri casi:
    else if(filtro=="PR+SV") {for(auto it: *listaSin) if(dynamic_cast<comp_cpugpu*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="CA+AL") {for(auto it: *listaSin) if(dynamic_cast<comp_casepsu*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="PR") {for(auto it: *listaSin) if(dynamic_cast<comp_cpu*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="CA") {for(auto it: *listaSin) if(dynamic_cast<comp_desktopcase*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="DI") {for(auto it: *listaSin) if(dynamic_cast<comp_dissi*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="SV") {for(auto it: *listaSin) if(dynamic_cast<comp_gpu*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="ME") {for(auto it: *listaSin) if(dynamic_cast<comp_hdd*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="SM") {for(auto it: *listaSin) if(dynamic_cast<comp_mobo*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="AL") {for(auto it: *listaSin) if(dynamic_cast<comp_psu*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}
    else if(filtro=="MR") {for(auto it: *listaSin) if(dynamic_cast<comp_ram*>(it))listaSx->addItem(QString::fromStdString(it->getNome()));}

    catalogo->stampaXml(); //spesso richiamata dopo modifiche a lista, ottima occasione di aggiornare xml
}

void MainWindow::popolaDestra(listacomp * listaDes)
{
    QListWidgetItem *riga;
    for(auto it: *listaDes){ //Caso lista non filtrata
        riga= new QListWidgetItem;
        riga->setText(QString::fromStdString(it->getNome()));
        riga->setForeground(preparacolore::getColoreCorrettoComp(it));
        listaDx->addItem(riga);
    }
    nomeDx->setText("WISHLIST (" +QString::number(uscarr->PrezzoTotale()) + " €)");

    registrati->stampaXml(); //spesso richiamata dopo modifiche a lista, ottima occasione di aggiornare xml
}
