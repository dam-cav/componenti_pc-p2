#ifndef EDIT_GPU_H
#define EDIT_GPU_H

#include "edit_componente.h"


class edit_gpu  : virtual public edit_componente
{

private:
	QHBoxLayout * separaOpzioni;
	QFormLayout * sinistro;
	QFormLayout * destro;

    QLabel * labelclockBase;
    QLabel * labelclockBoost;
    QLabel * labelmemoria;
    QLabel * labelvelMemoria;
    QLabel * labeltipoMem;
    QLabel * labelbandaMem;
    QLabel * labelbus;
    QLabel * labelsliCross;
    QLabel * labeln6pin;
    QLabel * labeln6e2pin;
    QLabel * labelnHdmi;
    QLabel * labelnVga;
    QLabel * labelnDvi;
    QLabel * labelnDisplayPort;

    QLineEdit * editclockBase;
    QLineEdit * editclockBoost;
    QLineEdit * editmemoria;
    QLineEdit * editvelMemoria;
    QLineEdit * edittipoMem;
    QLineEdit * editbandaMem;
    QLineEdit * editbus;
    QCheckBox * editsliCross;
    QSpinBox * editn6pin;
    QSpinBox * editn6e2pin;
    QSpinBox * editnHdmi;
    QSpinBox * editnVga;
    QSpinBox * editnDvi;
    QSpinBox * editnDisplayPort;

public:
    edit_gpu(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_GPU_H
