#include "edit_casepsu.h"

void edit_casepsu::aggiornaPezzo()
{
    edit_desktopcase::aggiornaPezzo();
    edit_psu::aggiornaPezzo();
}

bool edit_casepsu::campiCorretti()
{
    return edit_desktopcase::campiCorretti() && edit_psu::campiCorretti();
}
