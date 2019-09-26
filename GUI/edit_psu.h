#ifndef EDIT_PSU_H
#define EDIT_PSU_H

#include "edit_componente.h"

class edit_psu : virtual public edit_componente
{
private:
	QHBoxLayout * separaOpzioni;
	QFormLayout * sinistro;
	QFormLayout * destro;

    QLabel * labeltipo;
    QLabel * labelcertificazione;
    QLabel * labelmodulare;
    QLabel * labelventola;
    QLabel * labelpotenza;
    QLabel * labelnAtx20;
    QLabel * labelnAtx24;
    QLabel * labelnEps4e4;
    QLabel * labelnEps4;
    QLabel * labelnPcie6;
    QLabel * labelnPcie6e2;
    QLabel * labelnMolex;
    QLabel * labelnSata;

    QLineEdit * edittipo;
    QLineEdit * editcertificazione;
    QCheckBox * editmodulare;
    QCheckBox * editventola;
    QLineEdit * editpotenza;
    QSpinBox * editnAtx20;
    QSpinBox * editnAtx24;
    QSpinBox * editnEps4e4;
    QSpinBox * editnEps4;
    QSpinBox * editnPcie6;
    QSpinBox * editnPcie6e2;
    QSpinBox * editnMolex;
    QSpinBox * editnSata;

public:
    edit_psu(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_PSU_H
