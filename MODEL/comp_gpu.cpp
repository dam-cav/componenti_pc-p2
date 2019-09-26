#include "comp_gpu.h"

void comp_gpu::setClockBase(double value)
{
    clockBase = value;
}

void comp_gpu::setClockBoost(double value)
{
    clockBoost = value;
}

void comp_gpu::setMemoria(double value)
{
    memoria = value;
}

void comp_gpu::setVelMemoria(double value)
{
    velMemoria = value;
}

void comp_gpu::setTipoMem(const std::string &value)
{
    tipoMem = value;
}

void comp_gpu::setBandaMem(int value)
{
    bandaMem = value;
}

void comp_gpu::setBus(const std::string &value)
{
    bus = value;
}

void comp_gpu::setSliCross(bool value)
{
    sliCross = value;
}

void comp_gpu::setN6pin(unsigned int value)
{
    n6pin = value;
}

void comp_gpu::setN6e2pin(unsigned int value)
{
    n6e2pin = value;
}

void comp_gpu::setNHdmi(unsigned int value)
{
    nHdmi = value;
}

void comp_gpu::setNVga(unsigned int value)
{
    nVga = value;
}

void comp_gpu::setNDvi(unsigned int value)
{
    nDvi = value;
}

void comp_gpu::setNDisplayPort(unsigned int value)
{
    nDisplayPort = value;
}

double comp_gpu::getClockBase() const
{
    return clockBase;
}

double comp_gpu::getClockBoost() const
{
    return clockBoost;
}

double comp_gpu::getMemoria() const
{
    return memoria;
}

double comp_gpu::getVelMemoria() const
{
    return velMemoria;
}

std::string comp_gpu::getTipoMem() const
{
    return tipoMem;
}

int comp_gpu::getBandaMem() const
{
    return bandaMem;
}

std::string comp_gpu::getBus() const
{
    return bus;
}

bool comp_gpu::getSliCross() const
{
    return sliCross;
}

unsigned int comp_gpu::getN6pin() const
{
    return n6pin;
}

unsigned int comp_gpu::getN6e2pin() const
{
    return n6e2pin;
}

unsigned int comp_gpu::getNHdmi() const
{
    return nHdmi;
}

unsigned int comp_gpu::getNVga() const
{
    return nVga;
}

unsigned int comp_gpu::getNDvi() const
{
    return nDvi;
}

unsigned int comp_gpu::getNDisplayPort() const
{
    return nDisplayPort;
}

std::string comp_gpu::toString() const
{
    return "Clock Base: " + std::to_string(clockBase) + "MHz\nClock Boost: " + std::to_string(clockBoost) + "Mhz\nMemoria: " + std::to_string(memoria) + "MB\nVelocità Memoria: "+
            std::to_string(velMemoria) + "Mbps\nTipo Memoria: " + tipoMem + "\nBanda Memoria: " + std::to_string(bandaMem) + "MB/s\nBus:" + bus + "\nSupporto SLI/Crossfire?" + (sliCross?"Si":"No")+
            "\nN# Connettori Alimentatore 6pin: " + std::to_string(n6pin) + "\nN# Connettori Alimentatore 8pin: " + std::to_string(n6e2pin) + "\nNumero Porte HDMI: "+ std::to_string(nHdmi) +
            "\nNumero Porte VGA: " + std::to_string(nVga) + "\nNumero Porte DVI: "+  std::to_string(nDvi) +"\nNumero Porte DisplayPort: " + std::to_string(nDisplayPort);
}

std::string comp_gpu::etichettaXml() const
{
    return "GPU";
}

void comp_gpu::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("clockBase", QString::number(getClockBase()));
    stampatore.writeTextElement("clockBoost", QString::number(getClockBoost()));
    stampatore.writeTextElement("memoria", QString::number(getMemoria()));
    stampatore.writeTextElement("velMemoria", QString::number(getVelMemoria()));
    stampatore.writeTextElement("tipoMem", QString::fromStdString(getTipoMem()));
    stampatore.writeTextElement("bandaMem", QString::number(getBandaMem()));
    stampatore.writeTextElement("bus", QString::fromStdString(getBus()));
    stampatore.writeTextElement("sliCross", QString::fromStdString(getSliCross()? "true":"false"));
    stampatore.writeTextElement("n6pin", QString::number(getN6pin()));
    stampatore.writeTextElement("n6e2pin", QString::number(getN6e2pin()));
    stampatore.writeTextElement("nHdmi", QString::number(getNHdmi()));
    stampatore.writeTextElement("nVga", QString::number(getNVga()));
    stampatore.writeTextElement("nDvi", QString::number(getNDvi()));
    stampatore.writeTextElement("nDisplayPort", QString::number(getNDisplayPort()));
}

void comp_gpu::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="clockBase")
        clockBase = std::stod(cont.toStdString());
    else if(tag=="clockBoost")
        clockBoost = std::stod(cont.toStdString());
    else if(tag=="memoria")
        memoria = std::stod(cont.toStdString());
    else if(tag=="velMemoria")
        velMemoria = std::stod(cont.toStdString());
    else if(tag=="tipoMem")
        tipoMem = cont.toStdString();
    else if(tag=="bandaMem")
        bandaMem = std::stoi(cont.toStdString());
    else if(tag=="bus")
        bus = cont.toStdString();
    else if(tag=="sliCross")
        sliCross = (cont.toStdString()=="true"?true:false);
    else if(tag=="n6pin")
        n6pin = std::stoi(cont.toStdString());
    else if(tag=="n6e2pin")
        n6e2pin = std::stoi(cont.toStdString());
    else if(tag=="nHdmi")
        nHdmi = std::stoi(cont.toStdString());
    else if(tag=="nVga")
        nVga = std::stoi(cont.toStdString());
    else if(tag=="nDvi")
        nDvi = std::stoi(cont.toStdString());
    else if(tag=="nDisplayPort")
        nDisplayPort = std::stoi(cont.toStdString());
}
