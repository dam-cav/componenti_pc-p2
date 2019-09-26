#ifndef US_ADMIN_H
#define US_ADMIN_H

#include "utente.h"

class us_admin: public utente
{
public:
    us_admin(std::string id="user", std::string n="user", std::string c="user", std::string pass="pass"):utente(id,n,c,pass){};

    bool gestisceCatalogo() const;
    bool gestisceUtenti() const;

    virtual std::string etichettaXml() const;
};

#endif // US_ADMIN_H
