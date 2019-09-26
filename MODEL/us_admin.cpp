#include "us_admin.h"

bool us_admin::gestisceCatalogo() const{
    return true;
}

bool us_admin::gestisceUtenti() const{
    return true;
}

std::string us_admin::etichettaXml() const
{
    return "SUPERADMIN";
}
