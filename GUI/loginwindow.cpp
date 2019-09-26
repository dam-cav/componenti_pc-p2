#include "loginwindow.h"


void loginwindow::tentaLogin()
{
    if(editID->text()!="" && editPassword->text()!=""){
        utente* log = registrati->cercaId(editID->text().toStdString());
        if(log)
            if(log->getPassword()==editPassword->text().toStdString()){
            mw = new MainWindow(catalogo, registrati, log);
            mw->setAttribute(Qt::WA_DeleteOnClose);
            connect(mw,SIGNAL(chiusura()),this,SLOT(mostra_finestra()));
            mw->show();
            this->hide();
            editID->setText("");
            editPassword->setText("");
            editNome->setText("");
            editCognome->setText("");
            errori->setText("");
        }
        else errori->setText("ID o Password incorretti!");
        else errori->setText("ID o Password incorretti!");
    }
    else errori->setText("ID o Password richiesti!");
}

void loginwindow::tentaRegistrazione()
{
    if(editID->text()!="" && editPassword->text()!="" && editNome->text()!="" && editCognome->text()!=""){
        utente* log = registrati->cercaId(editID->text().toStdString());
        if(!log){ log= new us_cliente(editID->text().toStdString(), editNome->text().toStdString(), editCognome->text().toStdString(), editPassword->text().toStdString());
             registrati->addUser(log);
             mw = new MainWindow(catalogo, registrati, log);
             mw->setAttribute(Qt::WA_DeleteOnClose);
             connect(mw,SIGNAL(chiusura()),this,SLOT(mostra_finestra()));
             registrati->stampaXml();
             mw->show();
             this->hide();
             editID->setText("");
             editPassword->setText("");
             editNome->setText("");
             editCognome->setText("");
             registrati->ordinaNome();
             errori->setText("");
        }
        else errori->setText("ID già utilizzato!");
    }
    else errori->setText("Riempi tutti i campi!");
}

void loginwindow::mostra_finestra(){
        this->show();
}

loginwindow::loginwindow(listacomp * cat, listautenti * reg): catalogo(cat), registrati(reg)
{
    setWindowTitle("Progetto_ComponentiPC");
    this->setWindowIcon(QIcon(QPixmap(":/IMG/icon.svg")));
    this->setMinimumSize(400, 155);
    this->setMaximumSize(600, 155);

    catalogo->ordinaNome();

    l_principale = new QVBoxLayout();
    l_totale = new QHBoxLayout();
    l_login = new QVBoxLayout();
    l_registrazione = new QVBoxLayout();
    l_totale->addLayout(l_login);
    l_totale->addLayout(l_registrazione);

    l_principale->addLayout(l_totale);

    labelID = new QLabel("ID");
    labelPassword = new QLabel("Password");
    editID = new QLineEdit();
    editPassword = new QLineEdit();
    editPassword->setEchoMode(QLineEdit::Password);
    buttonLogin = new QPushButton("Login");
    connect(buttonLogin,SIGNAL(clicked()),this,SLOT(tentaLogin()));
    l_login->addWidget(labelID);
    l_login->addWidget(editID);
    l_login->addWidget(labelPassword);
    l_login->addWidget(editPassword);
    l_login->addWidget(buttonLogin);

    labelNome = new QLabel("Nome");    
    labelCognome = new QLabel("Cognome");
    editNome= new QLineEdit();
    editCognome= new QLineEdit();
    editNome->setPlaceholderText(QString("Solo Registrazione"));
    editCognome->setPlaceholderText(QString("Solo Registrazione"));
    buttonSignin = new QPushButton("Registrami");
    connect(buttonSignin,SIGNAL(clicked()),this,SLOT(tentaRegistrazione()));
    l_registrazione->addWidget(labelNome);
    l_registrazione->addWidget(editNome);
    l_registrazione->addWidget(labelCognome);
    l_registrazione->addWidget(editCognome);
    l_registrazione->addWidget(buttonSignin);

    errori = new QLabel("");
    l_principale->addWidget(errori);

    this->setLayout(l_principale);
}
