#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <string>
#include <QXmlStreamWriter>



class componente{
    std::string nome;
    double prezzo;
    unsigned int consumo;

public:
    componente(std::string n="NA", double p=0, unsigned int cons=0):nome(n),prezzo(p),consumo(cons){};
    virtual ~componente(){};

    //setters e getters
    void setNome(const std::string &value);
    void setPrezzo(double value);
    void setConsumo(unsigned int value);
    std::string getNome() const;
    double getPrezzo() const;
    unsigned int getConsumo() const;

    //metodi stampa
    virtual std::string toString() const;
    std::string stampaTutto() const;

    //metodi xml
    virtual std::string etichettaXml() const=0;    
    virtual void stampaContenutoXml(QXmlStreamWriter&) const;
    void stampaNomeXml(QXmlStreamWriter&) const;
    void stampaElementoXml(QXmlStreamWriter &) const;
    virtual void importaDettagliXml(std::string&, QString);
};

#endif // COMPONENTE_H
