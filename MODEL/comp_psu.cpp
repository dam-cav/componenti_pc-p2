#include "comp_psu.h"

void comp_psu::setTipo(const std::string &value)
{
    tipo = value;
}

void comp_psu::setCertificazione(const std::string &value)
{
    certificazione = value;
}

void comp_psu::setModulare(bool value)
{
    modulare = value;
}

void comp_psu::setVentola(bool value)
{
    ventola = value;
}

void comp_psu::setPotenza(unsigned int value)
{
    potenza = value;
}

void comp_psu::setNAtx20(unsigned int value)
{
    nAtx20 = value;
}

void comp_psu::setNAtx24(unsigned int value)
{
    nAtx24 = value;
}

void comp_psu::setNEps4e4(unsigned int value)
{
    nEps4e4 = value;
}

void comp_psu::setNEps4(unsigned int value)
{
    nEps4 = value;
}

void comp_psu::setNPcie6(unsigned int value)
{
    nPcie6 = value;
}

void comp_psu::setNPcie6e2(unsigned int value)
{
    nPcie6e2 = value;
}

void comp_psu::setNMolex(unsigned int value)
{
    nMolex = value;
}

void comp_psu::setNSata(unsigned int value)
{
    nSata = value;
}

std::string comp_psu::getTipo() const
{
    return tipo;
}

std::string comp_psu::getCertificazione() const
{
    return certificazione;
}

bool comp_psu::getModulare() const
{
    return modulare;
}

bool comp_psu::getVentola() const
{
    return ventola;
}

unsigned int comp_psu::getPotenza() const
{
    return potenza;
}

unsigned int comp_psu::getNAtx20() const
{
    return nAtx20;
}

unsigned int comp_psu::getNAtx24() const
{
    return nAtx24;
}

unsigned int comp_psu::getNEps4e4() const
{
    return nEps4e4;
}

unsigned int comp_psu::getNEps4() const
{
    return nEps4;
}

unsigned int comp_psu::getNPcie6() const
{
    return nPcie6;
}

unsigned int comp_psu::getNPcie6e2() const
{
    return nPcie6e2;
}

unsigned int comp_psu::getNMolex() const
{
    return nMolex;
}

unsigned int comp_psu::getNSata() const
{
    return nSata;
}

std::string comp_psu::toString() const
{
    return "Tipo: " +tipo +
            "\nCertificazione: " +certificazione +
            "\nE' Modulare? " +(modulare?"true":"false") +
            "\nHa Ventole? " +(ventola?"true":"false") +
            "\nPotenza Massima: " +std::to_string(potenza) +
            "W\nNumero Connettori ATX 20pin: " +std::to_string(nAtx20) +
            "\nNumero Connettori ATX 20+4pin: " +std::to_string(nAtx24) +
            "\nNumero Connettori EPS 4+4pin: " +std::to_string(nEps4e4) +
            "\nNumero Connettori EPS 4pin: " +std::to_string(nEps4) +
            "\nNumero Connettori PCIE 6pin: " +std::to_string(nPcie6) +
            "\nNumero Connettori PCIE 6+2pin: " +std::to_string(nPcie6e2) +
            "\nNumero Connettori MOLEX 4pin: " +std::to_string(nMolex) +
            "\nNumero Connettori SATA: " +std::to_string(nSata);
}

std::string comp_psu::etichettaXml() const
{
    return "PSU";
}

void comp_psu::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("tipo", QString::fromStdString(getTipo()));
    stampatore.writeTextElement("certificazione", QString::fromStdString(getCertificazione()));
    stampatore.writeTextElement("modulare", QString::fromStdString(getModulare()?"true":"false"));
    stampatore.writeTextElement("ventola", QString::fromStdString(getVentola()?"true":"false"));
    stampatore.writeTextElement("potenza", QString::number(getPotenza()));
    stampatore.writeTextElement("nAtx20", QString::number(getNAtx20()));
    stampatore.writeTextElement("nAtx24", QString::number(getNAtx24()));
    stampatore.writeTextElement("nEps4e4", QString::number(getNEps4e4()));
    stampatore.writeTextElement("nEps4", QString::number(getNEps4()));
    stampatore.writeTextElement("nPcie6", QString::number(getNPcie6()));
    stampatore.writeTextElement("nPcie6e2", QString::number(getNPcie6e2()));
    stampatore.writeTextElement("nMolex", QString::number(getNMolex()));
    stampatore.writeTextElement("nSata", QString::number(getNSata()));

}

void comp_psu::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="tipo")
        tipo = cont.toStdString();
    else if(tag=="certificazione")
        certificazione = cont.toStdString();
    else if(tag=="modulare")
        modulare = (cont=="true"?true:false);
    else if(tag=="ventola")
        ventola = (cont=="true"?true:false);
    else if(tag=="potenza")
        potenza = std::stoi(cont.toStdString());
    else if(tag=="nAtx20")
        nAtx20 = std::stoi(cont.toStdString());
    else if(tag=="nAtx24")
        nAtx24 = std::stoi(cont.toStdString());
    else if(tag=="nEps4e4")
        nEps4e4 = std::stoi(cont.toStdString());
    else if(tag=="nEps4")
        nEps4 = std::stoi(cont.toStdString());
    else if(tag=="nPcie6")
        nPcie6 = std::stoi(cont.toStdString());
    else if(tag=="nPcie6e2")
        nPcie6e2 = std::stoi(cont.toStdString());
    else if(tag=="nMolex")
        nMolex = std::stoi(cont.toStdString());
    else if(tag=="nSata")
        nSata = std::stoi(cont.toStdString());
}
