#ifndef COMP_GPU_H
#define COMP_GPU_H
#include "componente.h"


class comp_gpu: virtual public componente{
private:
    double clockBase; // in megahertz
    double clockBoost; // in megahertz
    double memoria; // in megabyte
    double velMemoria; //in megabit/secondo
    std::string tipoMem;
    int bandaMem; //in megabyte/secondo
    std::string bus;
    bool sliCross;
    unsigned int n6pin;
    unsigned int n6e2pin;

    unsigned int nHdmi;
    unsigned int nVga;
    unsigned int nDvi;
    unsigned int nDisplayPort;
public:
    comp_gpu(std::string n="NA", double p=0, unsigned int cons=0, double cba=0, double cbo=0, double m=0, double vm=0, std::string tm="NA", int bm=0, std::string bu="NA",
        bool sc=false, unsigned int n6=0, unsigned int n6e2=0, unsigned int nh=0, unsigned int nv=0, unsigned int nd=0, unsigned int ndp=0)
        :componente(n,p,cons),clockBase(cba),clockBoost(cbo), memoria(m),velMemoria(vm), tipoMem(tm), bandaMem(bm), bus(bu), sliCross(sc), n6pin(n6), n6e2pin(n6e2),nHdmi(nh), nVga(nv), nDvi(nd), nDisplayPort(ndp){};

    //setters e getters
    void setClockBase(double value);
    void setClockBoost(double value);
    void setMemoria(double value);
    void setVelMemoria(double value);
    void setTipoMem(const std::string &value);
    void setBandaMem(int value);
    void setBus(const std::string &value);
    void setSliCross(bool value);
    void setN6pin(unsigned int value);
    void setN6e2pin(unsigned int value);
    void setNHdmi(unsigned int value);
    void setNVga(unsigned int value);
    void setNDvi(unsigned int value);
    void setNDisplayPort(unsigned int value);
    double getClockBase() const;
    double getClockBoost() const;
    double getMemoria() const;
    double getVelMemoria() const;
    std::string getTipoMem() const;
    int getBandaMem() const;
    std::string getBus() const;
    bool getSliCross() const;
    unsigned int getN6pin() const;
    unsigned int getN6e2pin() const;
    unsigned int getNHdmi() const;
    unsigned int getNVga() const;
    unsigned int getNDvi() const;
    unsigned int getNDisplayPort() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_GPU_H
