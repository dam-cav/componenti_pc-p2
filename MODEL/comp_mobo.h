#ifndef COMP_MOBO_H
#define COMP_MOBO_H
#include "componente.h"

class comp_mobo: public componente{
private:
    //CARATTERISTICHE PRINCIPALI
    std::string socket;
    std::string chipset;

    //RAM
    unsigned int ramSlot;
    std::string tipiRam;
    unsigned int ramMaxFreq;

    //PORTE INTERNE
    unsigned int nSata;
    std::string tipoSataInt; //predisposto per eventuali future Sata4
    unsigned int nM2; //tipico esempio di come il programma abbia bisogno di aggiornamenti dati dalle novità
    std::string audio;
    unsigned int nUsbInt;
    std::string tipoUsbInt; //predisposto per eventuali future Usb4
    unsigned int nPciex16;
    unsigned int nPciex1;
    std::string dettagliPci;

    //PORTE ESTERNE
    unsigned int nPs2;
    unsigned int nUsbEst;
    std::string tipoUsbEst; //predisposto per eventuali future Usb4
    unsigned int nLan;
    unsigned int nHdmi;
    unsigned int nDisplayPort;
    unsigned int nDvi;
    unsigned int nVga;
    unsigned int audioJack;
    unsigned int nOpt; //audio uscita ottica
    unsigned int neSata;
    bool wifi;

    std::string extra; //ulteriori caratteristiche non-standard

public:
    comp_mobo(std::string n="NA", double p=0, unsigned int cons=0,std::string sock="NA", std::string chip="NA", unsigned int nram=0, std::string tpr="NA", unsigned int rmf=0, unsigned int ns=0,
              std::string tpsi="NA", unsigned int nm=0, std::string aud="NA", unsigned int nui=0, std::string tui="NA", unsigned int npci16=0, unsigned int npci1=0,
              std::string detpci="NA", unsigned int nps2=0, unsigned int nue=0, std::string tue="NA", unsigned int nl=0, unsigned int nh=0, unsigned int ndp=0,
         unsigned int nd=0, unsigned int nv=0, unsigned int aj=0, unsigned int ao=0, unsigned int nes=0, bool w=false, std::string ex="NA")
        :componente(n, p,cons),socket(sock), chipset(chip), ramSlot(nram), tipiRam(tpr), ramMaxFreq(rmf), nSata(ns), tipoSataInt(tpsi), nM2(nm), audio(aud), nUsbInt(nui), tipoUsbInt(tui),nPciex16(npci16),
          nPciex1(npci1), dettagliPci(detpci), nPs2(nps2), nUsbEst(nue), tipoUsbEst(tue), nLan(nl), nHdmi(nh), nDisplayPort(ndp), nDvi(nd), nVga(nv), audioJack(aj), nOpt(ao),neSata(nes), wifi(w), extra(ex){};

    //setters e getters
    void setSocket(const std::string &value);
    void setChipset(const std::string &value);
    void setRamSlot(unsigned int value);
    void setTipiRam(const std::string &value);
    void setRamMaxFreq(unsigned int value);
    void setNSata(unsigned int value);
    void setTipoSataInt(const std::string &value);
    void setNM2(unsigned int value);
    void setAudio(const std::string &value);
    void setNUsbInt(unsigned int value);
    void setTipoUsbInt(const std::string &value);
    void setNPciex16(unsigned int value);
    void setNPciex1(unsigned int value);
    void setDettagliPci(const std::string &value);
    void setNPs2(unsigned int value);
    void setNUsbEst(unsigned int value);
    void setTipoUsbEst(const std::string &value);
    void setNLan(unsigned int value);
    void setNHdmi(unsigned int value);
    void setNDisplayPort(unsigned int value);
    void setNDvi(unsigned int value);
    void setNVga(unsigned int value);
    void setAudioJack(unsigned int value);
    void setNOpt(unsigned int value);
    void setNeSata(unsigned int value);
    void setWifi(bool value);
    void setExtra(const std::string &value);
    std::string getSocket() const;
    std::string getChipset() const;
    unsigned int getRamSlot() const;
    std::string getTipiRam() const;
    unsigned int getRamMaxFreq() const;
    unsigned int getNSata() const;
    std::string getTipoSataInt() const;
    unsigned int getNM2() const;
    std::string getAudio() const;
    unsigned int getNUsbInt() const;
    std::string getTipoUsbInt() const;
    unsigned int getNPciex16() const;
    unsigned int getNPciex1() const;
    std::string getDettagliPci() const;
    unsigned int getNPs2() const;
    unsigned int getNUsbEst() const;
    std::string getTipoUsbEst() const;
    unsigned int getNLan() const;
    unsigned int getNHdmi() const;
    unsigned int getNDisplayPort() const;
    unsigned int getNDvi() const;
    unsigned int getNVga() const;
    unsigned int getAudioJack() const;
    unsigned int getNOpt() const;
    unsigned int getNeSata() const;
    bool getWifi() const;
    std::string getExtra() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_MOBO_H
