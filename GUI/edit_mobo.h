#ifndef EDIT_MOBO_H
#define EDIT_MOBO_H

#include "edit_componente.h"

class edit_mobo : public edit_componente
{

private:
	QHBoxLayout * separaOpzioni;
	QFormLayout * sinistro;
	QFormLayout * destro;

    QLabel * labelsocket;
    QLabel * labelchipset;
    QLabel * labelramSlot;
    QLabel * labeltipiRam;
    QLabel * labelramMaxFreq;
    QLabel * labelnSata;
    QLabel * labeltipoSataInt;
    QLabel * labelnM2;
    QLabel * labelaudio;
    QLabel * labelnUsbInt;
    QLabel * labeltipoUsbInt;
    QLabel * labelnPciex16;
    QLabel * labelnPciex1;
    QLabel * labeldettagliPci;
    QLabel * labelnPs2;
    QLabel * labelnUsbEst;
    QLabel * labeltipoUsbEst;
    QLabel * labelnLan;
    QLabel * labelnHdmi;
    QLabel * labelnDisplayPort;
    QLabel * labelnDvi;
    QLabel * labelnVga;
    QLabel * labelaudioJack;
    QLabel * labelnOpt;
    QLabel * labelneSata;
    QLabel * labelwifi;
    QLabel * labelextra;

    QComboBox * editsocket;
    QLineEdit * editchipset;
    QSpinBox * editramSlot;
    QComboBox * edittipiRam;
    QLineEdit * editramMaxFreq;
    QSpinBox * editnSata;
    QLineEdit * edittipoSataInt;
    QSpinBox * editnM2;
    QLineEdit * editaudio;
    QSpinBox * editnUsbInt;
    QLineEdit * edittipoUsbInt;
    QSpinBox * editnPciex16;
    QSpinBox * editnPciex1;
    QLineEdit * editdettagliPci;
    QSpinBox * editnPs2;
    QSpinBox * editnUsbEst;
    QLineEdit * edittipoUsbEst;
    QSpinBox * editnLan;
    QSpinBox * editnHdmi;
    QSpinBox * editnDisplayPort;
    QSpinBox * editnDvi;
    QSpinBox * editnVga;
    QSpinBox * editaudioJack;
    QSpinBox * editnOpt;
    QSpinBox * editneSata;
    QCheckBox * editwifi;
    QLineEdit * editextra;

public:
    edit_mobo(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_MOBO_H
