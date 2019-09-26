#ifndef US_CLIENTE_H
#define US_CLIENTE_H
#include "utente.h"
#include "componente.h"

class us_cliente: public utente
{
public:
    us_cliente(std::string id="user", std::string n="user", std::string c="user", std::string pass="pass"):utente(id,n,c,pass){};

    bool gestisceCatalogo() const;
    bool gestisceUtenti() const;

    virtual std::string etichettaXml() const;
};

#endif // US_CLIENTE_H
