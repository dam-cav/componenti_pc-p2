#ifndef COMP_CPUGPU_H
#define COMP_CPUGPU_H
#include "comp_cpu.h"
#include "comp_gpu.h"

class comp_cpugpu: public comp_cpu, public comp_gpu
{

public:
    comp_cpugpu(std::string n="NA", double p=0, unsigned int cons=0, double c=0, double ct=0, unsigned  int co=0, unsigned int th=0, double ca=0, std::string sock="NA", std::string tpr="NA", int rf=0,
                int rc=0, std::string vpc="NA", double cba=0, double cbo=0, double m=0, double vm=0, std::string tm="NA", int bm=0, std::string bu="NA",
                bool sc=false, unsigned int n6=0, unsigned int n6e2=0, unsigned int nh=0, unsigned int nv=0, unsigned int nd=0, unsigned int ndp=0):
        componente(n, p,cons), comp_cpu(n,p,cons,c,ct,co,th,ca,sock,tpr,rf,rc,vpc), comp_gpu(n,p,cons,cba,cbo,m,vm,tm,bm,bu,sc,n6,n6e2,nh,nv,nd,ndp){};

    //metodi stampa
    virtual std::string toString() const;

    //metodi xml
    virtual std::string etichettaXml() const;
    void stampaContenutoXml(QXmlStreamWriter&) const;
    virtual void importaDettagliXml(std::string&, QString);

};

#endif // COMP_CPUGPU_H
