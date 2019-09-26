#ifndef COMP_PSU_H
#define COMP_PSU_H
#include "componente.h"

class comp_psu: virtual public componente{
private:
    std::string tipo;
    std::string certificazione;
    bool modulare;
    bool ventola;
    unsigned int potenza;

    //connettori
    unsigned int nAtx20;
    unsigned int nAtx24;
    unsigned int nEps4e4;
    unsigned int nEps4;
    unsigned int nPcie6;
    unsigned int nPcie6e2;
    unsigned int nMolex;
    unsigned int nSata;
public:
    comp_psu(std::string n="NA", double p=0, unsigned int cons=0, std::string t="NA", std::string c="NA", bool m=false, bool v=false, unsigned int pow=0, unsigned int n20=0, unsigned int n24=0, unsigned int n4e4=0, unsigned int n4=0, unsigned int n6=0, unsigned int n6e2=0, unsigned int nmx=0, unsigned int nsa=0):
        componente(n, p,cons), tipo(t), certificazione(c), modulare(m), ventola(v), potenza(pow), nAtx20(n20), nAtx24(n24), nEps4e4(n4e4), nEps4(n4), nPcie6(n6), nPcie6e2(n6e2), nMolex(nmx), nSata(nsa){};

    //setters e getters
    void setTipo(const std::string &value);
    void setCertificazione(const std::string &value);
    void setModulare(bool value);
    void setVentola(bool value);
    void setPotenza(unsigned int value);
    void setNAtx20(unsigned int value);
    void setNAtx24(unsigned int value);
    void setNEps4e4(unsigned int value);
    void setNEps4(unsigned int value);
    void setNPcie6(unsigned int value);
    void setNPcie6e2(unsigned int value);
    void setNMolex(unsigned int value);
    void setNSata(unsigned int value);
    std::string getTipo() const;
    std::string getCertificazione() const;
    bool getModulare() const;
    bool getVentola() const;
    unsigned int getPotenza() const;
    unsigned int getNAtx20() const;
    unsigned int getNAtx24() const;
    unsigned int getNEps4e4() const;
    unsigned int getNEps4() const;
    unsigned int getNPcie6() const;
    unsigned int getNPcie6e2() const;
    unsigned int getNMolex() const;
    unsigned int getNSata() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_PSU_H
