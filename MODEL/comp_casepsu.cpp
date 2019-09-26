#include "comp_casepsu.h"

std::string comp_casepsu::toString() const
{
    return "CARATTERISTICHE CASE: \n" +comp_desktopcase::toString() + "\nCARATTERISTICHE ALIMENTATORE: \n" +comp_psu::toString();
}

std::string comp_casepsu::etichettaXml() const
{
    return "CASE_PSU";
}

void comp_casepsu::stampaContenutoXml(QXmlStreamWriter & stampatore) const
{
    //componente::stampaContenutoXml(stampatore);
    comp_desktopcase::stampaContenutoXml(stampatore);
    comp_psu::stampaContenutoXml(stampatore);
}

void comp_casepsu::importaDettagliXml(std::string & tag, QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    else if(tag=="formFactor" || tag=="nFan" || tag=="nUsb" || tag=="tipoUsb" || tag=="nJack" || tag=="tipoJack" || tag=="n35" || tag=="n25" || tag=="nMast" || tag=="nSsd" || tag=="nPci")
        comp_desktopcase::importaDettagliXml(tag,cont);

    else if(tag=="tipo" || tag=="certificazione" || tag=="modulare" || tag=="ventola" || tag=="potenza" || tag=="nAtx20" || tag=="nAtx24" || tag=="nEps4e4" || tag=="nEps4" || tag=="nPcie6" || tag=="nPcie6e2" || tag=="nMolex" || tag=="nSata")
        comp_psu::importaDettagliXml(tag,cont);
}
