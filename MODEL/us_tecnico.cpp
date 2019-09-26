#include "us_tecnico.h"


bool us_tecnico::gestisceCatalogo() const{
    return true;
}

bool us_tecnico::gestisceUtenti() const{
    return false;
}

std::string us_tecnico::etichettaXml() const
{
    return "TECNICO";
}
