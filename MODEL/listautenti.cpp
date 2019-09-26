#include "listautenti.h"

QString listautenti::nomeFile = "registrati.xml";

QString listautenti::getNomeFile() const
{
    return nomeFile;
}

void listautenti::addUser(utente * nuovo)
{
    if(!cercaId(nuovo->getID())) registrati.push_back(nuovo);
}

void listautenti::remMatch(std::string name)
{
    for(std::vector<utente*>::const_iterator it=registrati.begin();it!=registrati.end();++it){
        if((*it)->getID() == name) {
            delete *it;
            registrati.erase(it);
            --it;
           }
    }
}

void listautenti::ordinaNome()
{
        std::sort(registrati.begin(), registrati.end(), [](const utente* a, const utente* b) { return a->getNome() < b->getNome(); });
}


utente* listautenti::cercaId(std::string id) const{
    for(std::vector<utente*>::const_iterator it=registrati.begin();it!=registrati.end();++it){
        if((*it)->getID()== id) return *it;
    }
    return nullptr;
}

void listautenti::stampaXml() const
{
    QFile xml(getNomeFile());
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter scrittore(&xml);
    scrittore.setAutoFormatting(true);
    scrittore.writeStartDocument();

    scrittore.writeStartElement(QString::fromStdString("UTENTI"));
    for(std::vector<utente*>::const_iterator it=registrati.begin();it!=registrati.end();++it){
        (*it)->stampaElementoXml(scrittore);
    }
    scrittore.writeEndElement();
    xml.close();
}

bool listautenti::popolaListaDaXml(listacomp& completa)
{
    bool ok=true;
    std::string tipo;
    QFile xml(getNomeFile()); //da mettere nome file generico
    if (xml.open(QFile::ReadOnly | QFile::Text))
    {
        utente* inseriscimi;
        //componente* oggettocarrello;
        std::string stringanormale;
        QXmlStreamReader xmlInput(&xml);
        while(xmlInput.readNextStartElement()){
        //Salta semplicemente l'lemento che indica inizio lista
            while(xmlInput.readNextStartElement()){
                //scorre il tipo di elemento dentro <tipo>
                tipo= (xmlInput.name().toString()).toStdString();
                if(tipo=="CLIENTE") inseriscimi = new us_cliente();
                else if(tipo=="TECNICO") inseriscimi =  new us_tecnico();
                else if(tipo=="SUPERADMIN") inseriscimi =  new us_admin();
                else inseriscimi = 0;


                while(xmlInput.readNextStartElement()){
                    //riempie gli oggetti e li aggiunge in lista
                    stringanormale = (xmlInput.name().toString()).toStdString();
                    if(stringanormale!="WISHLIST") inseriscimi->importaDettagliXml(stringanormale, xmlInput.readElementText());
                    else{
                        while(xmlInput.readNextStartElement()){
                            tipo= xmlInput.readElementText().toStdString();
                            inseriscimi->suaWishlist()->addComp(completa.cercaNome(tipo));
                        }
                    }
                }
                addUser(inseriscimi);
            }
        }
    }
    else{
        us_admin* primoassoluto = new us_admin("admin","admin","admin","admin");
        addUser(primoassoluto);
        ok=false;
    }

    xml.close();
    return ok;
}

std::vector<utente*>::const_iterator listautenti::begin() const
{
   return registrati.begin();
}
std::vector<utente*>::const_iterator listautenti::end() const
{
   return registrati.end();
}
