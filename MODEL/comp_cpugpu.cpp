#include "comp_cpugpu.h"



std::string comp_cpugpu::toString() const
{
    return "CARATTERISTICHE CPU: \n" +comp_cpu::toString() + "\nCARATTERISTICHE GPU: \n" + comp_gpu::toString();
}

std::string comp_cpugpu::etichettaXml() const
{
    return "CPU_GPU";
}

void comp_cpugpu::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    //componente::stampaContenutoXml(stampatore);
    comp_cpu::stampaContenutoXml(stampatore);
    comp_gpu::stampaContenutoXml(stampatore);
}

void comp_cpugpu::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="clock" || tag=="clockT" ||tag=="core" || tag=="thread" || tag=="cache" ||tag=="socket" || tag=="tipoRam" ||tag=="ramF" || tag=="ramC" || tag=="vPci")
        comp_cpu::importaDettagliXml(tag,cont);

    else if(tag=="clockBase" || tag=="clockBoost" || tag=="memoria" ||tag=="velMemoria" || tag=="tipoMem" ||tag=="bandaMem" ||tag=="bus" ||tag=="sliCross" || tag=="n6pin" || tag=="n6e2pin"|| tag=="nHdmi" ||tag=="nVga" ||tag=="nDvi" ||tag=="nDisplayPort")
        comp_gpu::importaDettagliXml(tag,cont);
}
