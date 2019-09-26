#ifndef EDIT_CASEPSU_H
#define EDIT_CASEPSU_H


#include "edit_desktopcase.h"
#include "edit_psu.h"

class edit_casepsu: public edit_desktopcase, public edit_psu
{
public:
    edit_casepsu(componente * com, listacomp* cat , bool nuovOgg=false):edit_componente(com,cat,nuovOgg),edit_desktopcase(com,cat,nuovOgg),edit_psu(com,cat,nuovOgg){};
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_CASEPSU_H
