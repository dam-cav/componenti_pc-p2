#ifndef UTENTE_H
#define UTENTE_H
#include <string>
#include <vector>
#include <QXmlStreamWriter>
#include "listacomp.h"

using std::vector;

class utente{
    private:
        std::string ID;
        std::string nome;
        std::string cognome;
        std::string password;
        listacomp* wishlist;


    public:
        utente(std::string id="user", std::string n="user", std::string c="user", std::string pass="pass"):ID(id),nome(n),cognome(c),password(pass) {
            wishlist = new listacomp();
        };
        virtual ~utente(){delete wishlist;};

        //setters e getters
        void setID(const std::string &value);
        void setNome(const std::string &value);
        void setCognome(const std::string &value);
        void setPassword(const std::string &value);
        std::string getID() const;
        std::string getNome() const;
        std::string getCognome() const;
        std::string getPassword() const;
        listacomp* suaWishlist() const;

        //permessi
        virtual bool gestisceCatalogo() const = 0;
        virtual bool gestisceUtenti() const = 0;

        //metodi per l'xml
        virtual std::string etichettaXml() const = 0;
        void stampaContenutoXml(QXmlStreamWriter &) const;
        void stampaElementoXml(QXmlStreamWriter &) const;
        virtual void importaDettagliXml(std::string& tag, QString cont);

};

#endif // UTENTE_H






