#ifndef EDIT_CPU_H
#define EDIT_CPU_H

#include "edit_componente.h"

class edit_cpu : virtual public edit_componente
{

private:
	QHBoxLayout * separaOpzioni;
	QFormLayout * sinistro;
	QFormLayout * destro;

    QLabel * labelclock;
    QLabel * labelclockT;
    QLabel * labelcore;
    QLabel * labelthread;
    QLabel * labelcache;
    QLabel * labelsocket;
    QLabel * labeltipoRam;
    QLabel * labelramF;
    QLabel * labelramC;
    QLabel * labelvPci;

    QLineEdit * editclock;
    QLineEdit * editclockT;
    QSpinBox * editcore;
    QSpinBox * editthread;
    QLineEdit * editcache;
    QComboBox * editsocket;
    QComboBox * edittipoRam;
    QLineEdit * editramF;
    QSpinBox * editramC;
    QLineEdit * editvPci;


public:
    edit_cpu(componente *, listacomp* , bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_CPU_H
