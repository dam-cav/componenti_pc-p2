#include "preparaoggetti.h"

componente *preparaoggetti::getOggettoPulito(const QString & tipo)
{
    if(tipo=="CPU") return new comp_cpu();
    else if(tipo=="CPU_GPU") return new comp_cpugpu();
    else if(tipo=="CASE_PSU") return new comp_casepsu();
    else if(tipo=="DESKTOPCASE") return new comp_desktopcase();
    else if(tipo=="DISSI") return new comp_dissi();
    else if(tipo=="GPU") return new comp_gpu();
    else if(tipo=="HDD") return new comp_hdd();
    else if(tipo=="MOBO") return new comp_mobo();
    else if(tipo=="PSU") return new comp_psu();
    else if(tipo=="RAM") return new comp_ram();
    else return 0;
}
