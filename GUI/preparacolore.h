#ifndef PREPARACOLORE_H
#define PREPARACOLORE_H

#include <QColor>
#include <QPixmap>
#include "../MODEL/comp_dissi.h"
#include "../MODEL/comp_hdd.h"
#include "../MODEL/comp_mobo.h"
#include "../MODEL/comp_ram.h"
#include "../MODEL/comp_cpugpu.h"
#include "../MODEL/comp_casepsu.h"
#include "../MODEL/utente.h"
#include "../MODEL/us_cliente.h"
#include "../MODEL/us_tecnico.h"
#include "../MODEL/us_admin.h"

class preparacolore
{
public:
    static QColor getColoreCorrettoComp(componente*);
    static QColor getColoreCorrettoUser(utente*);
    static QPixmap getImmagineCorrettaComp(componente*);
    virtual ~preparacolore()=0;
};

#endif // PREPARACOLORE_H
