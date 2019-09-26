#ifndef COMP_DISSI_H
#define COMP_DISSI_H
#include "componente.h"

class comp_dissi: public componente
{
private:
   std::string socketcomp;
   bool liquido;

public:
    comp_dissi(std::string n="NA", double p=0, unsigned int cons=0, std::string sc="NA", bool l=false)
        :componente(n, p,cons), socketcomp(sc), liquido(l){};

    //setters e getters
    void setSocketcomp(const std::string &value);
    void setLiquido(bool value);
    std::string getSocketcomp() const;
    bool getLiquido() const;

    //metodi stampa
    virtual std::string toString() const;

    //metodi stampa
    virtual std::string etichettaXml() const;
    virtual void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_DISSI_H
