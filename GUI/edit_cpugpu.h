#ifndef EDIT_CPUGPU_H
#define EDIT_CPUGPU_H

#include "edit_cpu.h"
#include "edit_gpu.h"

class edit_cpugpu: public edit_cpu, public edit_gpu
{
public:
    edit_cpugpu(componente * com, listacomp* cat , bool nuovOgg=false):edit_componente(com,cat,nuovOgg),edit_cpu(com,cat,nuovOgg),edit_gpu(com,cat,nuovOgg){};
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();
};

#endif // EDIT_CPUGPU_H
