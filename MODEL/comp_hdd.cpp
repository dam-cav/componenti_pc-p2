#include "comp_hdd.h"

void comp_hdd::setTipo(const std::string &value)
{
    tipo = value;
}

void comp_hdd::setForma(const std::string &value)
{
    forma = value;
}

void comp_hdd::setCapacitaSsd(unsigned int value)
{
    capacitaSsd = value;
}

void comp_hdd::setCapacitaHdd(unsigned int value)
{
    capacitaHdd = value;
}

void comp_hdd::setInterfaccia(const std::string &value)
{
    interfaccia = value;
}

void comp_hdd::setRpm(unsigned int value)
{
    rpm = value;
}

void comp_hdd::setScrittura(double value)
{
    scrittura = value;
}

void comp_hdd::setLettura(double value)
{
    lettura = value;
}

std::string comp_hdd::getTipo() const
{
    return tipo;
}

std::string comp_hdd::getForma() const
{
    return forma;
}

unsigned int comp_hdd::getCapacitaSsd() const
{
    return capacitaSsd;
}

unsigned int comp_hdd::getCapacitaHdd() const
{
    return capacitaHdd;
}

std::string comp_hdd::getInterfaccia() const
{
    return interfaccia;
}

unsigned int comp_hdd::getRpm() const
{
    return rpm;
}

double comp_hdd::getScrittura() const
{
    return scrittura;
}

double comp_hdd::getLettura() const
{
    return lettura;
}

std::string comp_hdd::toString() const{

    return "Tipo di Memoria: " +tipo +"\nForm Factor: " +forma +"\nCapacità Memoria Elettrica: " +std::to_string(capacitaSsd) +"GB\nCapacità Memoria Meccanica: " +std::to_string(capacitaHdd) +"GB\nInterfaccia: " +interfaccia +"\nGiri al Minuto: " +std::to_string(rpm) +"rpm\nVelocità scrittura (se dichiarata): " +std::to_string(scrittura) +"\nVelocità lettura (se dichiarata): " +std::to_string(lettura);
}

std::string comp_hdd::etichettaXml() const
{
    return "HDD";
}

void comp_hdd::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("tipo", QString::fromStdString(getTipo()));
    stampatore.writeTextElement("forma", QString::fromStdString(getForma()));
    stampatore.writeTextElement("capacitaSsd", QString::number(getCapacitaSsd()));
    stampatore.writeTextElement("capacitaHdd", QString::number(getCapacitaHdd()));
    stampatore.writeTextElement("interfaccia", QString::fromStdString(getInterfaccia()));
    stampatore.writeTextElement("rpm", QString::number(getRpm()));
    stampatore.writeTextElement("scrittura", QString::number(getScrittura()));
    stampatore.writeTextElement("lettura", QString::number(getLettura()));

}

void comp_hdd::importaDettagliXml(std::string & tag , QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="tipo")
        tipo = cont.toStdString();
    else if(tag=="forma")
        forma = cont.toStdString();
    else if(tag=="capacitaSsd")
        capacitaSsd = std::stoi(cont.toStdString());
    else if(tag=="capacitaHdd")
        capacitaHdd = std::stoi(cont.toStdString());
    else if(tag=="interfaccia")
        interfaccia = cont.toStdString();
    else if(tag=="rpm")
        rpm = std::stoi(cont.toStdString());
    else if(tag=="scrittura")
        scrittura = std::stod(cont.toStdString());
    else if(tag=="lettura")
        lettura = std::stod(cont.toStdString());
}
