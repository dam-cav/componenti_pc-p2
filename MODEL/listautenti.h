#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H
#include <vector>
#include <QFile>
#include "componente.h"
#include "us_cliente.h"
#include "us_tecnico.h"
#include "us_admin.h"


class listautenti
{
private:
    std::vector<utente*> registrati;

    static QString nomeFile;
    QString getNomeFile() const;
public:
    listautenti(){};

    //aggiunta, rimozione, ordinamento, ricerca
    void addUser(utente*);
    void remMatch(std::string);
    void ordinaNome();
    utente* cercaId(std::string) const;

    //metodi per l'xml
    void stampaXml() const;
    bool popolaListaDaXml(listacomp&);

    //iteratori
    std::vector<utente*>::const_iterator begin() const;
    std::vector<utente*>::const_iterator end() const;


};

#endif // LISTAUTENTI_H
