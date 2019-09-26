#include "preparacolore.h"


QColor preparacolore::getColoreCorrettoComp(componente * c)
{
    if(dynamic_cast<comp_cpugpu*>(c))
        return QColor(255, 102, 134);//rosetto
    if(dynamic_cast<comp_casepsu*>(c))
        return QColor(62, 148, 51);//verde scuro
    if(dynamic_cast<comp_cpu*>(c))
        return QColor(255, 0, 23);//rosso
    if(dynamic_cast<comp_desktopcase*>(c))
        return QColor(25, 204, 32);//verde
    if(dynamic_cast<comp_dissi*>(c))
        return QColor(32, 177, 162);//azzurro/verdeacqua
    if(dynamic_cast<comp_gpu*>(c))
       return QColor(185, 0, 255);//viola
    if(dynamic_cast<comp_hdd*>(c))
        return QColor(76, 76, 76);//grigio
    if(dynamic_cast<comp_mobo*>(c))
        return QColor(176, 178, 25);//giallo
    if(dynamic_cast<comp_psu*>(c))
        return QColor(255, 142, 0);//arancio
    if(dynamic_cast<comp_ram*>(c))
        return QColor(0, 34, 255);//blu
    else return QColor(255,255,255);//bianco
}

QColor preparacolore::getColoreCorrettoUser(utente * u)
{
    if(dynamic_cast<us_cliente*>(u))
        return QColor(0, 0, 0);//nero standard
    if(dynamic_cast<us_tecnico*>(u))
        return QColor(0, 34, 255);//blu
    if(dynamic_cast<us_admin*>(u))
        return QColor(255, 0, 23);//rosso
    else return QColor(0, 0, 0);//nero standard
}

QPixmap preparacolore::getImmagineCorrettaComp(componente * c)
{
    QPixmap img;
    if(!c) img.load(":/IMG/nothing.svg");
    else if(dynamic_cast<comp_cpugpu*>(c))
        img.load(":/IMG/cpu.svg");
    else if(dynamic_cast<comp_casepsu*>(c))
        img.load(":/IMG/desktopcase.svg");
    else if(dynamic_cast<comp_cpu*>(c))
        img.load(":/IMG/cpu.svg");
    else if(dynamic_cast<comp_desktopcase*>(c))
        img.load(":/IMG/desktopcase.svg");
    else if(dynamic_cast<comp_dissi*>(c))
        img.load(":/IMG/dissi.svg");
    else if(dynamic_cast<comp_gpu*>(c))
        img.load(":/IMG/gpu.svg");
    else if(dynamic_cast<comp_hdd*>(c))
        img.load(":/IMG/hdd.svg");
    else if(dynamic_cast<comp_mobo*>(c))
        img.load(":/IMG/mobo.svg");
    else if(dynamic_cast<comp_psu*>(c))
        img.load(":/IMG/psu.svg");
    else if(dynamic_cast<comp_ram*>(c))
        img.load(":/IMG/ram.svg");
    else img.load(":/IMG/nothing.svg");
    return img;
}

