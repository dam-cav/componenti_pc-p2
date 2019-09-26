#ifndef COMP_CPU_H
#define COMP_CPU_H
#include "componente.h"

class comp_cpu: virtual public componente{
private:
    double clock; //clock in megahertz
    double clockT; //clock turbo in megahertz
    unsigned int core; //numero di core
    unsigned int thread; //numero di thread
    double cache; //cache in kilobyte
    std::string socket; //sigla del socket

    std::string tipoRam; //versione DDR o simili
    unsigned int ramF; //frequenza ram in mhz
    unsigned int ramC; //numero canali ram
    std::string vPci; //sigla versione pci
public:
    comp_cpu(std::string n="NA", double p=0, unsigned int cons=0, double c=0, double ct=0, unsigned int co=0, unsigned int th=0, double ca=0, std::string sock="NA", std::string tpr="NA", unsigned int rf=0, unsigned int rc=0, std::string vpc="NA")
        :componente(n, p,cons),clock(c),clockT(ct),core(co), thread(th),cache(ca), socket(sock), tipoRam(tpr), ramF(rf), ramC(rc), vPci(vpc){};

    //setters e getters
    void setClock(double value);
    void setClockT(double value);
    void setCore(unsigned int value);
    void setThread(unsigned int value);
    void setCache(double value);
    void setSocket(const std::string &value);
    void setTipoRam(const std::string &value);
    void setRamF(unsigned int value);
    void setRamC(unsigned int value);
    void setVPci(const std::string &value);
    double getClock() const;
    double getClockT() const;
    int getCore() const;
    int getThread() const;
    double getCache() const;
    std::string getSocket() const;
    std::string getTipoRam() const;
    int getRamF() const;
    int getRamC() const;
    std::string getVPci() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);


};

#endif // COMP_CPU_H
