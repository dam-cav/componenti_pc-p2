#ifndef EDIT_DESKTOPCASE_H
#define EDIT_DESKTOPCASE_H

#include "edit_componente.h"



class edit_desktopcase : virtual public edit_componente
{

private:
	QHBoxLayout * separaOpzioni;
	QFormLayout * sinistro;
	QFormLayout * destro;

    QLabel * labelformFactor;
    QLabel * labelnFan;
    QLabel * labelnUsb;
    QLabel * labeltipoUsb;
    QLabel * labelnJack;
    QLabel * labeltipoJack;
    QLabel * labeln35;
    QLabel * labeln25;
    QLabel * labelnMast;
    QLabel * labelnSsd;
    QLabel * labelnPci;

    QComboBox * editformFactor;
    QSpinBox * editnFan;
    QSpinBox * editnUsb;
    QLineEdit * edittipoUsb;
    QSpinBox * editnJack;
    QLineEdit * edittipoJack;
    QSpinBox * editn35;
    QSpinBox * editn25;
    QSpinBox * editnMast;
    QSpinBox * editnSsd;
    QSpinBox * editnPci;

    
public:
    edit_desktopcase(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_DESKTOPCASE_H
