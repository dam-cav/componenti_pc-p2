#ifndef COMP_CASEPSU_H
#define COMP_CASEPSU_H


#include "comp_desktopcase.h"
#include "comp_psu.h"

class comp_casepsu: public comp_desktopcase, public comp_psu
{

public:
    comp_casepsu(std::string n="NA", double p=0, unsigned int cons=0, std::string ff="NA", unsigned int nf=0, unsigned int nu=0, std::string tu="NA", unsigned int nj=0,
                 std::string tj="NA", unsigned int n35p=0, unsigned int n25p=0, unsigned int nm=0, unsigned int ns=0, unsigned int np=0, std::string t="NA", std::string c="NA", bool m=false, bool v=false, unsigned int pow=0, unsigned int n20=0, unsigned int n24=0,
                 unsigned int n4e4=0, unsigned int n4=0, unsigned int n6=0, unsigned int n6e2=0, unsigned int nmx=0, unsigned int nsa=0):
        componente(n, p,cons),comp_desktopcase(n,p,cons,ff,nf,nu,tu,nj,tj,n35p,n25p,nm,ns,np),comp_psu(n,p,cons,t,c,m,v,pow,n20,n24,n4e4,n4,n6,n6e2,nmx,nsa){};

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_CASEPSU_H
