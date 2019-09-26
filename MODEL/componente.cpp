#include "componente.h"

void componente::setNome(const std::string &value)
{
    nome = value;
}

void componente::setPrezzo(double value)
{
    prezzo = value;
}

void componente::setConsumo(unsigned int value)
{
    consumo = value;
}

std::string componente::getNome() const
{
    return nome;
}

double componente::getPrezzo() const{
    return prezzo;
}
unsigned int componente::getConsumo() const{
    return consumo;
}

std::string componente::toString() const
{
    return "Nome: " + nome + "\nPrezzo: " + std::to_string(prezzo) + " €\nConsumo: "+ std::to_string(consumo) + " W";
}

std::string componente::stampaTutto() const
{
    return componente::toString() + "\n" + toString();
}


void componente::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("nome", QString::fromStdString(getNome()));
    stampatore.writeTextElement("prezzo", QString::number(getPrezzo()));
    stampatore.writeTextElement("consumo", QString::number(getConsumo()));
}

void componente::stampaNomeXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("nome", QString::fromStdString(getNome()));
}

void componente::stampaElementoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeStartElement(QString::fromStdString(etichettaXml()));
    componente::stampaContenutoXml(stampatore);
    stampaContenutoXml(stampatore);
    stampatore.writeEndElement();
}

void componente::importaDettagliXml(std::string& tag, QString cont)
{
    if(tag=="nome")
         nome = cont.toStdString();
    if(tag=="prezzo")
         prezzo = std::stod(cont.toStdString());
    if(tag=="consumo")
         consumo = std::stoi(cont.toStdString());

}
