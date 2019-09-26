#include "edit_cpugpu.h"


void edit_cpugpu::aggiornaPezzo()
{
    edit_cpu::aggiornaPezzo();
    edit_gpu::aggiornaPezzo();
}

bool edit_cpugpu::campiCorretti()
{
    return edit_cpu::campiCorretti() && edit_gpu::campiCorretti();
}
