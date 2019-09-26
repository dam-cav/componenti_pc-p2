#ifndef EDIT_HDD_H
#define EDIT_HDD_H

#include "edit_componente.h"


class edit_hdd : public edit_componente
{
private:
    QLabel * labeltipo;
    QLabel * labelforma;
    QLabel * labelcapacitaSsd;
    QLabel * labelcapacitaHdd;
    QLabel * labelinterfaccia;
    QLabel * labelrpm;
    QLabel * labelscrittura;
    QLabel * labellettura;

    QComboBox * edittipo;
    QComboBox * editforma;
    QLineEdit * editcapacitaSsd;
    QLineEdit * editcapacitaHdd;
    QComboBox * editinterfaccia;
    QLineEdit * editrpm;
    QLineEdit * editscrittura;
    QLineEdit * editlettura;

public:
    edit_hdd(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_HDD_H
