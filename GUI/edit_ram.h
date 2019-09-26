#ifndef EDIT_RAM_H
#define EDIT_RAM_H

#include "edit_componente.h"

class edit_ram : public edit_componente
{
private:
    QLabel * labeltipoMemoria;
    QLabel * labelmemoria;
    QLabel * labelvoltaggio;

    QComboBox * edittipoMemoria;
    QLineEdit * editmemoria;
    QLineEdit * editvoltaggio;

public:
    edit_ram(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_RAM_H
