#ifndef PREPARAEDITOR_H
#define PREPARAEDITOR_H

#include "../MODEL/componente.h"
#include "edit_cpu.h"
#include "edit_cpugpu.h"
#include "edit_desktopcase.h"
#include "edit_casepsu.h"
#include "edit_dissi.h"
#include "edit_gpu.h"
#include "edit_hdd.h"
#include "edit_mobo.h"
#include "edit_psu.h"
#include "edit_ram.h"

class preparaEditor
{
public:
    static edit_componente* getEditorCorretto(componente*, listacomp*, bool=false);
    virtual ~preparaEditor()=0;
};

#endif // PREPARAEDITOR_H
