#ifndef US_TECNICO_H
#define US_TECNICO_H
#include "utente.h"

class us_tecnico: public utente
{
public:
    us_tecnico(std::string id="user", std::string n="user", std::string c="user", std::string pass="pass"):utente(id,n,c,pass){};

    bool gestisceCatalogo() const;
    bool gestisceUtenti() const;

    virtual std::string etichettaXml() const;
};

#endif // US_TECNICO_H
