#ifndef PREPARAOGGETTI_H
#define PREPARAOGGETTI_H


#include "comp_cpugpu.h"
#include "comp_casepsu.h"
#include "comp_dissi.h"
#include "comp_hdd.h"
#include "comp_mobo.h"
#include "comp_ram.h"


class preparaoggetti
{
public:
    static componente* getOggettoPulito(const QString&);
    virtual ~preparaoggetti()=0;
};

#endif // PREPARAOGGETTI_H
