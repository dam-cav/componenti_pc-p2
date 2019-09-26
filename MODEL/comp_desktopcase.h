#ifndef COMP_DESKTOPCASE_H
#define COMP_DESKTOPCASE_H
#include "componente.h"

class comp_desktopcase: virtual public componente
{
private:
    std::string formFactor;
    unsigned int nFan;
    unsigned int nUsb;
    std::string tipoUsb;
    unsigned int nJack;
    std::string tipoJack;

    unsigned int n35;
    unsigned int n25;
    unsigned int nMast;
    unsigned int nSsd;
    unsigned int nPci;

public:
    comp_desktopcase(std::string n="NA", double p=0, unsigned int cons=0, std::string ff="NA", unsigned int nf=0, unsigned int nu=0, std::string tu="NA", unsigned int nj=0, std::string tj="NA", unsigned int n35p=0, unsigned int n25p=0, unsigned int nm=0, unsigned int ns=0, unsigned int np=0)
        :componente(n, p,cons),formFactor(ff), nFan(nf), nUsb(nu), tipoUsb(tu), nJack(nj), tipoJack(tj), n35(n35p), n25(n25p), nMast(nm), nSsd(ns), nPci(np){};

    //setters e getters
    void setFormFactor(const std::string &value);
    void setNFan(unsigned int value);
    void setNUsb(unsigned int value);
    void setTipoUsb(const std::string &value);
    void setNJack(unsigned int value);
    void setTipoJack(const std::string &value);
    void setN35(unsigned int value);
    void setN25(unsigned int value);
    void setNMast(unsigned int value);
    void setNSsd(unsigned int value);
    void setNPci(unsigned int value);
    std::string getFormFactor() const;
    unsigned int getNFan() const;
    unsigned int getNUsb() const;
    std::string getTipoUsb() const;
    unsigned int getNJack() const;
    std::string getTipoJack() const;
    unsigned int getN35() const;
    unsigned int getN25() const;
    unsigned int getNMast() const;
    unsigned int getNSsd() const;
    unsigned int getNPci() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_DESKTOPCASE_H
