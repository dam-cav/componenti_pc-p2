#include "comp_desktopcase.h"

void comp_desktopcase::setFormFactor(const std::string &value)
{
    formFactor = value;
}

void comp_desktopcase::setNFan(unsigned int value)
{
    nFan = value;
}

void comp_desktopcase::setNUsb(unsigned int value)
{
    nUsb = value;
}

void comp_desktopcase::setTipoUsb(const std::string &value)
{
    tipoUsb = value;
}

void comp_desktopcase::setNJack(unsigned int value)
{
    nJack = value;
}

void comp_desktopcase::setTipoJack(const std::string &value)
{
    tipoJack = value;
}

void comp_desktopcase::setN35(unsigned int value)
{
    n35 = value;
}

void comp_desktopcase::setN25(unsigned int value)
{
    n25 = value;
}

void comp_desktopcase::setNMast(unsigned int value)
{
    nMast = value;
}

void comp_desktopcase::setNSsd(unsigned int value)
{
    nSsd = value;
}

void comp_desktopcase::setNPci(unsigned int value)
{
    nPci = value;
}

std::string comp_desktopcase::getFormFactor() const
{
    return formFactor;
}

unsigned int comp_desktopcase::getNFan() const
{
    return nFan;
}

unsigned int comp_desktopcase::getNUsb() const
{
    return nUsb;
}

std::string comp_desktopcase::getTipoUsb() const
{
    return tipoUsb;
}

unsigned int comp_desktopcase::getNJack() const
{
    return nJack;
}

std::string comp_desktopcase::getTipoJack() const
{
    return tipoJack;
}

unsigned int comp_desktopcase::getN35() const
{
    return n35;
}

unsigned int comp_desktopcase::getN25() const
{
    return n25;
}

unsigned int comp_desktopcase::getNMast() const
{
    return nMast;
}

unsigned int comp_desktopcase::getNSsd() const
{
    return nSsd;
}

unsigned int comp_desktopcase::getNPci() const
{
    return nPci;
}

std::string comp_desktopcase::toString() const
{
    return "Form Factor: " +formFactor +
            "\nNumero Ventole: " +std::to_string(nFan) +
            "\nNumero Porte USB: " + std::to_string(nUsb) +
            "\nTipo Porte  USB: " +tipoUsb +
            "\nNumero Jack Audio: " +std::to_string(nJack) +
            "\nTipi di Jack Audio: " +tipoJack +
            "\nSpazi per periferiche da 3.5\": " +std::to_string(n35) +
            "\nSpazi per periferiche da 2.5\": " +std::to_string(n25) +
            "\nSpazi per Masterizzatori: " +std::to_string(nMast) +
            "\nSpazi per unità SSD: " +std::to_string(nSsd) +
            "\nNumero slot per periferiche PCI: " +std::to_string(nPci);
}

std::string comp_desktopcase::etichettaXml() const
{
    return "DESKTOPCASE";
}

void comp_desktopcase::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("formFactor", QString::fromStdString(getFormFactor()));
    stampatore.writeTextElement("nFan", QString::number(getNFan()));
    stampatore.writeTextElement("nUsb", QString::number(getNUsb()));
    stampatore.writeTextElement("tipoUsb", QString::fromStdString(getTipoUsb()));
    stampatore.writeTextElement("nJack", QString::number(getNJack()));
    stampatore.writeTextElement("tipoJack", QString::fromStdString(getTipoJack()));

    stampatore.writeTextElement("n35", QString::number(getN35()));
    stampatore.writeTextElement("n25", QString::number(getN25()));
    stampatore.writeTextElement("nMast", QString::number(getNMast()));
    stampatore.writeTextElement("nSsd", QString::number(getNSsd()));
    stampatore.writeTextElement("nPci", QString::number(getNPci()));

}

void comp_desktopcase::importaDettagliXml(std::string & tag, QString cont )
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="formFactor")
        formFactor = cont.toStdString();
    else if(tag=="nFan")
        nFan = std::stoi(cont.toStdString());
    else if(tag=="nUsb")
        nUsb = std::stoi(cont.toStdString());
    else if(tag=="tipoUsb")
        tipoUsb = cont.toStdString();
    else if(tag=="nJack")
        nJack = std::stoi(cont.toStdString());
    else if(tag=="tipoJack")
        tipoJack = cont.toStdString();
    else if(tag=="n35")
        n35 = std::stoi(cont.toStdString());
    else if(tag=="n25")
        n25 = std::stoi(cont.toStdString());
    else if(tag=="nMast")
        nMast = std::stoi(cont.toStdString());
    else if(tag=="nSsd")
        nSsd = std::stoi(cont.toStdString());
    else if(tag=="nPci")
        nPci = std::stoi(cont.toStdString());
}
