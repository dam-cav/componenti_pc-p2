#ifndef EDIT_DISSI_H
#define EDIT_DISSI_H

#include "edit_componente.h"
#include "../MODEL/comp_dissi.h"

class edit_dissi : public edit_componente
{
    
private:

    std::string generaCampoSocket();
    void riempiCheck(QString);

    QVBoxLayout* SocketIntel;
    QVBoxLayout* SocketAmd;
    QHBoxLayout* Socket;

    //QLabel * labelsocketcomp;
    QLabel * labelliquido;

    //QLineEdit * editsocketcomp;
    QCheckBox* editliquido;

    //Socket Intel
    QCheckBox* compSocket2066;
    QCheckBox* compLGA3647;
    QCheckBox* compLGA1151;
    QCheckBox* compSocketG3;
    QCheckBox* compLGA1150;
    QCheckBox* comprPGA988B;
    QCheckBox* compLGA2011;
    QCheckBox* compLGA1155;
    QCheckBox* compLGA1156;
    QCheckBox* comprPGA988A;
    QCheckBox* compLGA1366;
    QCheckBox* compSocket441;
    QCheckBox* compSocketP;
    QCheckBox* compLGA771;
    QCheckBox* compSocketM;
    QCheckBox* compLGA775;
    QCheckBox* compSocket479;
    QCheckBox* compSocket604;
    QCheckBox* compSocket603;
    QCheckBox* compPAC418;
    QCheckBox* compSocket495;

    //Socket AMD
    QCheckBox* compSocketTR4;
    QCheckBox* compSocketSP3;
    QCheckBox* compSocketAM4;
    QCheckBox* compSocketAM1;
    QCheckBox* compSocketFM2p;
    QCheckBox* compSocketFM2;
    QCheckBox* compSocketAM3p;
    QCheckBox* compSocketFS1;
    QCheckBox* compSocketFM1;
    QCheckBox* compSocketC32;
    QCheckBox* compSocketG34;
    QCheckBox* compSocketAM3;
    QCheckBox* compSocketAM2p;
    QCheckBox* compSocketF;
    QCheckBox* compSocketAM2;
    QCheckBox* compSocketS1;
    QCheckBox* compSocket939;
    QCheckBox* compSocket940;
    QCheckBox* compSocket754;
    QCheckBox* compSocket563;

public:
    edit_dissi(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_DISSI_H
