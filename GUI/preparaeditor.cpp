#include "preparaeditor.h"

edit_componente* preparaEditor::getEditorCorretto(componente* c, listacomp* cat, bool tipoModifica)
{
    if(dynamic_cast<comp_cpugpu*>(c))
        return new edit_cpugpu(c,cat,tipoModifica);
    if(dynamic_cast<comp_casepsu*>(c))
        return new edit_casepsu(c,cat,tipoModifica);
    if(dynamic_cast<comp_cpu*>(c))
        return new edit_cpu(c,cat,tipoModifica);
    if(dynamic_cast<comp_desktopcase*>(c))
        return new edit_desktopcase(c,cat,tipoModifica);
    if(dynamic_cast<comp_dissi*>(c))
        return new edit_dissi(c,cat,tipoModifica);
    if(dynamic_cast<comp_gpu*>(c))
        return new edit_gpu(c,cat,tipoModifica);
    if(dynamic_cast<comp_hdd*>(c))
        return new edit_hdd(c,cat,tipoModifica);
    if(dynamic_cast<comp_mobo*>(c))
        return new edit_mobo(c,cat,tipoModifica);
    if(dynamic_cast<comp_psu*>(c))
        return new edit_psu(c,cat,tipoModifica);
    if(dynamic_cast<comp_ram*>(c))
        return new edit_ram(c,cat,tipoModifica);
    return nullptr;
}
