#include "comp_dissi.h"

void comp_dissi::setSocketcomp(const std::string &value)
{
    socketcomp = value;
}

void comp_dissi::setLiquido(bool value)
{
    liquido = value;
}

std::string comp_dissi::getSocketcomp() const
{
    return socketcomp;
}

bool comp_dissi::getLiquido() const
{
    return liquido;
}

std::string comp_dissi::toString() const
{
    return "Socket Compatibili: " + socketcomp + "\nE' a Liquido? " + (liquido?"sì":"no");
}

std::string comp_dissi::etichettaXml() const
{
    return "DISSI";
}

void comp_dissi::stampaContenutoXml(QXmlStreamWriter & stampatore ) const
{
    stampatore.writeTextElement("socketcomp", QString::fromStdString(getSocketcomp()));
    stampatore.writeTextElement("liquido", QString::fromStdString(getLiquido()? "true":"false"));
}

void comp_dissi::importaDettagliXml(std::string & tag , QString cont)
{
    if(tag=="nome" || tag=="prezzo" ||tag=="consumo")
        componente::importaDettagliXml(tag,cont);

    if(tag=="socketcomp")
        socketcomp = cont.toStdString();;
    if(tag=="liquido")
        liquido = cont.toStdString()=="true"?true:false;

}
