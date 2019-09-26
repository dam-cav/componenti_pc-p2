#include "comp_cpu.h"


void comp_cpu::setClock(double value)
{
    clock = value;
}

void comp_cpu::setClockT(double value)
{
    clockT = value;
}

void comp_cpu::setCore(unsigned int value)
{
    core = value;
}

void comp_cpu::setThread(unsigned int value)
{
    thread = value;
}

void comp_cpu::setCache(double value)
{
    cache = value;
}

void comp_cpu::setSocket(const std::string &value)
{
    socket = value;
}

void comp_cpu::setTipoRam(const std::string &value)
{
    tipoRam = value;
}

void comp_cpu::setRamF(unsigned int value)
{
    ramF = value;
}

void comp_cpu::setRamC(unsigned int value)
{
    ramC = value;
}

void comp_cpu::setVPci(const std::string &value)
{
    vPci = value;
}

double comp_cpu::getClock() const
{
    return clock;
}

double comp_cpu::getClockT() const
{
    return clockT;
}

int comp_cpu::getCore() const
{
    return core;
}

int comp_cpu::getThread() const
{
    return thread;
}

double comp_cpu::getCache() const
{
    return cache;
}

std::string comp_cpu::getSocket() const
{
    return socket;
}

std::string comp_cpu::getTipoRam() const
{
    return tipoRam;
}

int comp_cpu::getRamF() const
{
    return ramF;
}

int comp_cpu::getRamC() const
{
    return ramC;
}

std::string comp_cpu::getVPci() const
{
    return vPci;
}

std::string comp_cpu::toString() const
{
    return "Clock: " +  std::to_string(clock) + " MHz\nClock Turbo: " +  std::to_string(clockT) + " MHz\nNumero Di Core: " +  std::to_string(core) + "\nNumero di Thread: " +  std::to_string(thread) + "\nCache: " +  std::to_string(cache) + " kB\nSocket: " + socket + "\nRam Supportata: " +tipoRam
             + "\nFrequenza Ram: " +  std::to_string(ramF) + "\nNumero Canali Ram: " +  std::to_string(ramC) + "\nVersione Pci: " + vPci;
}

std::string comp_cpu::etichettaXml() const
{
    return "CPU";
}

void comp_cpu::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    /*stampatore.writeTextElement("nome", QString::number(getNome()));
    stampatore.writeTextElement("prezzo", QString::number(getPrezzo()));
    stampatore.writeTextElement("consumo", QString::number(getConsumo()));*/
    stampatore.writeTextElement("clock", QString::number(getClock()));
    stampatore.writeTextElement("clockT", QString::number(getClockT()));
    stampatore.writeTextElement("core", QString::number(getCore()));
    stampatore.writeTextElement("thread", QString::number(getThread()));
    stampatore.writeTextElement("cache", QString::number(getCache()));
    stampatore.writeTextElement("socket", QString::fromStdString(getSocket()));

    stampatore.writeTextElement("tipoRam", QString::fromStdString(getTipoRam()));
    stampatore.writeTextElement("ramF", QString::number(getRamF()));
    stampatore.writeTextElement("ramC", QString::number(getRamC()));
    stampatore.writeTextElement("vPci", QString::fromStdString(getVPci()));

}

void comp_cpu::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);
    else if(tag=="clock")
        clock = std::stod(cont.toStdString());
    else if(tag=="clockT")
        clockT = std::stod(cont.toStdString());
    else if(tag=="core")
        core =  std::stoi(cont.toStdString());
    else if(tag=="thread")
        thread = std::stoi(cont.toStdString());
    else if(tag=="cache")
        cache = std::stod(cont.toStdString());
    else if(tag=="socket")
        socket = cont.toStdString();
    else if(tag=="tipoRam")
        tipoRam= cont.toStdString();
    else if(tag=="ramF")
        ramF = std::stoi(cont.toStdString());
    else if(tag=="ramC")
        ramC = std::stoi(cont.toStdString());
    else if(tag=="vPci")
        vPci= cont.toStdString();
}
