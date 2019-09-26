#include "comp_ram.h"

void comp_ram::setTipoMemoria(const std::string &value)
{
    tipoMemoria = value;
}

void comp_ram::setMemoria(unsigned int value)
{
    memoria = value;
}

void comp_ram::setVoltaggio(double value)
{
    voltaggio = value;
}

std::string comp_ram::getTipoMemoria() const
{
    return tipoMemoria;
}

unsigned int comp_ram::getMemoria() const
{
    return memoria;
}

double comp_ram::getVoltaggio() const
{
    return voltaggio;
}

std::string comp_ram::toString() const
{
    return "Tipo di Memoria: " + tipoMemoria +
    "\nQuantità Memoria: " + std::to_string(memoria) +
    "GB\nVoltaggio: " + std::to_string(voltaggio) +
    "V";
}

std::string comp_ram::etichettaXml() const
{
    return "RAM";
}

void comp_ram::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("tipoMemoria", QString::fromStdString(getTipoMemoria()));
    stampatore.writeTextElement("memoria", QString::number(getMemoria()));
    stampatore.writeTextElement("voltaggio", QString::number(getVoltaggio()));
}

void comp_ram::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="tipoMemoria")
        tipoMemoria = cont.toStdString();
    else if(tag=="memoria")
        memoria = std::stoi(cont.toStdString());
    else if(tag=="voltaggio")
        voltaggio = std::stod(cont.toStdString());
}
