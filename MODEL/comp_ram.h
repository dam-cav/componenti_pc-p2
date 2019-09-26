#ifndef COMP_RAM_H
#define COMP_RAM_H
#include "componente.h"

class comp_ram: public componente {
private:
    std::string tipoMemoria;
    unsigned int memoria;
    double voltaggio;
public:
    comp_ram(std::string n="NA", double p=0, unsigned int cons=0, std::string tm="NA", unsigned int m=0, double volt=0): componente(n,p,cons), tipoMemoria(tm), memoria(m), voltaggio(volt){};

    //setters e getters
    void setTipoMemoria(const std::string &value);
    void setMemoria(unsigned int value);
    void setVoltaggio(double value);
    std::string getTipoMemoria() const;
    unsigned int getMemoria() const;
    double getVoltaggio() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_RAM_H
