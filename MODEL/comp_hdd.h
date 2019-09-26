#ifndef COMP_HDD_H
#define COMP_HDD_H
#include "componente.h"

class comp_hdd: public componente
{
private:
    std::string tipo;
    std::string forma;
    unsigned int capacitaSsd;
    unsigned int capacitaHdd;
    std::string interfaccia;
    unsigned int rpm;
    double scrittura;
    double lettura;

public:
    comp_hdd(std::string n="NA", double p=0, unsigned int cons=0,std::string t ="NA", std::string f="NA", unsigned int cssd=0, unsigned int chdd=0, std::string i="NA", unsigned int rm=0, double w=0, double r=0)
        :componente(n, p,cons), tipo(t), forma(f), capacitaSsd(cssd), capacitaHdd(chdd), interfaccia(i), rpm(rm), scrittura(w), lettura(r){};

    //setters e getters
    void setTipo(const std::string &value);
    void setForma(const std::string &value);
    void setCapacitaSsd(unsigned int value);
    void setCapacitaHdd(unsigned int value);
    void setInterfaccia(const std::string &value);
    void setRpm(unsigned int value);
    void setScrittura(double value);
    void setLettura(double value);
    std::string getTipo() const;
    std::string getForma() const;
    unsigned int getCapacitaSsd() const;
    unsigned int getCapacitaHdd() const;
    std::string getInterfaccia() const;
    unsigned int getRpm() const;
    double getScrittura() const;
    double getLettura() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_HDD_H
