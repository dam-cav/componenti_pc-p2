#include "comp_mobo.h"


void comp_mobo::setSocket(const std::string &value)
{
    socket = value;
}

void comp_mobo::setChipset(const std::string &value)
{
    chipset = value;
}

void comp_mobo::setRamSlot(unsigned int value)
{
    ramSlot = value;
}

void comp_mobo::setTipiRam(const std::string &value)
{
    tipiRam = value;
}

void comp_mobo::setRamMaxFreq(unsigned int value)
{
    ramMaxFreq = value;
}

void comp_mobo::setNSata(unsigned int value)
{
    nSata = value;
}

void comp_mobo::setTipoSataInt(const std::string &value)
{
    tipoSataInt = value;
}

void comp_mobo::setNM2(unsigned int value)
{
    nM2 = value;
}

void comp_mobo::setAudio(const std::string &value)
{
    audio = value;
}

void comp_mobo::setNUsbInt(unsigned int value)
{
    nUsbInt = value;
}

void comp_mobo::setTipoUsbInt(const std::string &value)
{
    tipoUsbInt = value;
}

void comp_mobo::setNPciex16(unsigned int value)
{
    nPciex16 = value;
}

void comp_mobo::setNPciex1(unsigned int value)
{
    nPciex1 = value;
}

void comp_mobo::setDettagliPci(const std::string &value)
{
    dettagliPci = value;
}

void comp_mobo::setNPs2(unsigned int value)
{
    nPs2 = value;
}

void comp_mobo::setNUsbEst(unsigned int value)
{
    nUsbEst = value;
}

void comp_mobo::setTipoUsbEst(const std::string &value)
{
    tipoUsbEst = value;
}

void comp_mobo::setNLan(unsigned int value)
{
    nLan = value;
}

void comp_mobo::setNHdmi(unsigned int value)
{
    nHdmi = value;
}

void comp_mobo::setNDisplayPort(unsigned int value)
{
    nDisplayPort = value;
}

void comp_mobo::setNDvi(unsigned int value)
{
    nDvi = value;
}

void comp_mobo::setNVga(unsigned int value)
{
    nVga = value;
}

void comp_mobo::setAudioJack(unsigned int value)
{
    audioJack = value;
}

void comp_mobo::setNOpt(unsigned int value)
{
    nOpt = value;
}

void comp_mobo::setNeSata(unsigned int value)
{
    neSata = value;
}

void comp_mobo::setWifi(bool value)
{
    wifi = value;
}

void comp_mobo::setExtra(const std::string &value)
{
    extra = value;
}

std::string comp_mobo::getSocket() const
{
    return socket;
}

std::string comp_mobo::getChipset() const
{
    return chipset;
}

unsigned int comp_mobo::getRamSlot() const
{
    return ramSlot;
}

std::string comp_mobo::getTipiRam() const
{
    return tipiRam;
}

unsigned int comp_mobo::getRamMaxFreq() const
{
    return ramMaxFreq;
}

unsigned int comp_mobo::getNSata() const
{
    return nSata;
}

std::string comp_mobo::getTipoSataInt() const
{
    return tipoSataInt;
}

unsigned int comp_mobo::getNM2() const
{
    return nM2;
}

std::string comp_mobo::getAudio() const
{
    return audio;
}

unsigned int comp_mobo::getNUsbInt() const
{
    return nUsbInt;
}

std::string comp_mobo::getTipoUsbInt() const
{
    return tipoUsbInt;
}

unsigned int comp_mobo::getNPciex16() const
{
    return nPciex16;
}

unsigned int comp_mobo::getNPciex1() const
{
    return nPciex1;
}

std::string comp_mobo::getDettagliPci() const
{
    return dettagliPci;
}

unsigned int comp_mobo::getNPs2() const
{
    return nPs2;
}

unsigned int comp_mobo::getNUsbEst() const
{
    return nUsbEst;
}

std::string comp_mobo::getTipoUsbEst() const
{
    return tipoUsbEst;
}

unsigned int comp_mobo::getNLan() const
{
    return nLan;
}

unsigned int comp_mobo::getNHdmi() const
{
    return nHdmi;
}

unsigned int comp_mobo::getNDisplayPort() const
{
    return nDisplayPort;
}

unsigned int comp_mobo::getNDvi() const
{
    return nDvi;
}

unsigned int comp_mobo::getNVga() const
{
    return nVga;
}

unsigned int comp_mobo::getAudioJack() const
{
    return audioJack;
}

unsigned int comp_mobo::getNOpt() const
{
    return nOpt;
}

unsigned int comp_mobo::getNeSata() const
{
    return neSata;
}

bool comp_mobo::getWifi() const
{
    return wifi;
}

std::string comp_mobo::getExtra() const
{
    return extra;
}

std::string comp_mobo::toString() const
{
    return "Socket: " +socket +
            "\nChipset: " +chipset +
            "\nNumero di Slot per Ram: " +std::to_string(ramSlot) +
            "\nTipo di RAM: " +tipiRam +
            "\nFrequenza Massima RAM: " +std::to_string(ramMaxFreq) +
            "\nNumero Porte SATA: " +std::to_string(nSata) +
            "\nTipi di Porte SATA: " +tipoSataInt +
            "\nNumero di M2 Shield: " +std::to_string(nM2) +
            "\nScheda Audio Integrata: " +audio +
            "\nNumero USB Interne: " +std::to_string(nUsbInt) +
            "\nTipi di USB Interne: " +tipoUsbInt +
            "\nNumero Porte PCIe formato x16: " +std::to_string(nPciex16) +
            "\nNumero Porte PCIe formato x1: " +std::to_string(nPciex1) +
            "\nUlteriori PCIe o Dettagli: " +dettagliPci +
            "\nNumero Porte PS2: " +std::to_string(nPs2) +
            "\nNumero USB Esterne: " +std::to_string(nUsbEst) +
            "\nTipi di USB Esterne: " +tipoUsbEst +
            "\nNumero Porte LAN: " +std::to_string(nLan) +
            "\nNumero Porte HDMI: " +std::to_string(nHdmi) +
            "\nNumero Porte DisplayPort: " +std::to_string(nDisplayPort) +
            "\nNumero Porte DVI: " +std::to_string(nDvi) +
            "\nNumero Porte VGA: " +std::to_string(nVga) +
            "\nNumero Porte Audio Jack: " +std::to_string(audioJack) +
            "\nNumero Porte Audio ottico: " +std::to_string(nOpt) +
            "\nNumero Porte eSata Esterne: " +std::to_string(neSata) +
            "\nWIFI Integrato?: " +(wifi?"si":"no") +
            "\nUlteriori Dettagli: " +extra;
}

std::string comp_mobo::etichettaXml() const
{
    return "MOBO";
}

void comp_mobo::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    stampatore.writeTextElement("socket", QString::fromStdString(getSocket()));
    stampatore.writeTextElement("chipset", QString::fromStdString(getChipset()));
    stampatore.writeTextElement("ramSlot", QString::number(getRamSlot()));
    stampatore.writeTextElement("tipiRam", QString::fromStdString(getTipiRam()));
    stampatore.writeTextElement("ramMaxFreq", QString::number(getRamMaxFreq()));
    stampatore.writeTextElement("nSata", QString::number(getNSata()));
    stampatore.writeTextElement("tipoSataInt", QString::fromStdString(getTipoSataInt()));
    stampatore.writeTextElement("nM2", QString::number(getNM2()));
    stampatore.writeTextElement("audio", QString::fromStdString(getAudio()));    
    stampatore.writeTextElement("nUsbInt", QString::number(getNUsbInt()));
    //10
    stampatore.writeTextElement("tipoUsbInt", QString::fromStdString(getTipoUsbInt()));
    stampatore.writeTextElement("nPciex16", QString::number(getNPciex16()));
    stampatore.writeTextElement("nPciex1", QString::number(getNPciex1()));
    stampatore.writeTextElement("dettagliPci", QString::fromStdString(getDettagliPci()));
    stampatore.writeTextElement("nPs2", QString::number(getNPs2()));
    stampatore.writeTextElement("nUsbEst", QString::number(getNUsbEst()));
    stampatore.writeTextElement("tipoUsbEst", QString::fromStdString(getTipoUsbEst()));
    stampatore.writeTextElement("nLan", QString::number(getNLan()));
    stampatore.writeTextElement("nHdmi", QString::number(getNHdmi()));
    stampatore.writeTextElement("nDisplayPort", QString::number(getNDisplayPort()));
    //10
    stampatore.writeTextElement("nDvi", QString::number(getNDvi()));
    stampatore.writeTextElement("nVga", QString::number(getNVga()));
    stampatore.writeTextElement("audioJack", QString::number(getAudioJack()));
    stampatore.writeTextElement("nOpt", QString::number(getNOpt()));
    stampatore.writeTextElement("neSata", QString::number(getNeSata()));
    stampatore.writeTextElement("wifi", QString::fromStdString(getWifi()?"true":"false"));
    stampatore.writeTextElement("extra", QString::fromStdString(getExtra()));
    //7
}

void comp_mobo::importaDettagliXml(std::string&  tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="socket")
        socket = cont.toStdString();
    else if(tag=="chipset")
        chipset = cont.toStdString();
    else if(tag=="ramSlot")
        ramSlot = std::stoi(cont.toStdString());
    else if(tag=="tipiRam")
        tipiRam = cont.toStdString();
    else if(tag=="ramMaxFreq")
        ramMaxFreq = std::stoi(cont.toStdString());
    else if(tag=="nSata")
        nSata = std::stoi(cont.toStdString());
    else if(tag=="tipoSataInt")
        tipoSataInt = cont.toStdString();
    else if(tag=="nM2")
        nM2 = std::stoi(cont.toStdString());
    else if(tag=="audio")
        audio = cont.toStdString();
    else if(tag=="nUsbInt")
        nUsbInt = std::stoi(cont.toStdString());

    else if(tag=="tipoUsbInt")
        tipoUsbInt = cont.toStdString();
    else if(tag=="nPciex16")
        nPciex16 = std::stoi(cont.toStdString());
    else if(tag=="nPciex1")
        nPciex1 = std::stoi(cont.toStdString());
    else if(tag=="dettagliPci")
        dettagliPci = cont.toStdString();
    else if(tag=="nPs2")
        nPs2 = std::stoi(cont.toStdString());
    else if(tag=="nUsbEst")
        nUsbEst = std::stoi(cont.toStdString());
    else if(tag=="tipoUsbEst")
        tipoUsbEst = cont.toStdString();
    else if(tag=="nLan")
        nLan = std::stoi(cont.toStdString());
    else if(tag=="nHdmi")
        nHdmi = std::stoi(cont.toStdString());
    else if(tag=="nDisplayPort")
        nDisplayPort = std::stoi(cont.toStdString());

    else if(tag=="nDvi")
        nDvi = std::stoi(cont.toStdString());
    else if(tag=="nVga")
        nVga = std::stoi(cont.toStdString());
    else if(tag=="audioJack")
        audioJack = std::stoi(cont.toStdString());
    else if(tag=="nOpt")
        nOpt = std::stoi(cont.toStdString());
    else if(tag=="neSata")
        neSata = std::stoi(cont.toStdString());
    else if(tag=="wifi")
        wifi = (cont=="true"?true:false);
    else if(tag=="extra")
        extra = cont.toStdString();
}
