#include "utente.h"

void utente::setID(const std::string &value)
{
    ID = value;
}

void utente::setNome(const std::string &value)
{
    nome = value;
}

void utente::setCognome(const std::string &value)
{
    cognome = value;
}

void utente::setPassword(const std::string &value)
{
    password = value;
}

std::string utente::getID() const{
    return ID;
}
std::string utente::getNome() const{
    return nome;
}
std::string utente::getCognome() const{
    return cognome;
}
std::string utente::getPassword() const{
    return password;
}

listacomp* utente::suaWishlist() const
{
    return wishlist;
}

void utente::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("ID", QString::fromStdString(getID()));
    stampatore.writeTextElement("nome", QString::fromStdString(getNome()));
    stampatore.writeTextElement("cognome", QString::fromStdString(getCognome()));
    stampatore.writeTextElement("password", QString::fromStdString(getPassword()));
    wishlist->stampNomiXml(stampatore,"WISHLIST");
}

void utente::stampaElementoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeStartElement(QString::fromStdString(etichettaXml()));
    utente::stampaContenutoXml(stampatore);
    stampatore.writeEndElement();
}

void utente::importaDettagliXml(std::string& tag, QString cont)
{
    if(tag=="ID")
        ID = cont.toStdString();
    if(tag=="nome")
        nome = cont.toStdString();
    if(tag=="cognome")
        cognome = cont.toStdString();
    if(tag=="password")
        password = cont.toStdString();

}

