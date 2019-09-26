#ifndef LISTACOMP_H
#define LISTACOMP_H
#include <vector>
#include <QFile>
#include "preparaoggetti.h"

class listacomp
{
private:
    bool doppioni; //se true accetta più di un oggetto con stesso nome
    std::vector<componente*> contenuto;

    //per xml
    static QString nomeFile;
    QString getNomeFile() const;
public:    
    listacomp(bool d=true):doppioni(d){};

    componente* cercaNome(std::string) const;
    void addComp(componente*);
    void clearAll(bool=false);
    unsigned int remMatch(std::string, bool, bool=false);

    double PrezzoTotale() const;
    void ordinaNome();
    void ordinaPrezzo();

    //metodi xml
    void stampaXml(const std::string& ="LISTA") const;
    void stampNomiXml(QXmlStreamWriter &, const std::string& ="LISTA") const;
    void popolaListaDaXml();

    //iteratori
    std::vector<componente*>::const_iterator begin() const;
    std::vector<componente*>::const_iterator end() const;
};

#endif // LISTACOMP_H
