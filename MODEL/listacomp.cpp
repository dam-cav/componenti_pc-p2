#include "listacomp.h"
//using namespace std;

QString listacomp::nomeFile = "catalogo.xml";

QString listacomp::getNomeFile() const
{
    return nomeFile;
}

componente* listacomp::cercaNome(std::string name) const{
    for(auto it=contenuto.begin();it!=contenuto.end();++it){
        if((*it)->getNome()== name) return *it;
    }
    return nullptr;
}

void listacomp::addComp(componente* nuovo){
    if(doppioni || !cercaNome(nuovo->getNome()) ) {
        contenuto.push_back(nuovo);
    }
}

void listacomp::clearAll(bool definitiva)
{    
    if(!contenuto.empty()){
        if (definitiva) for(auto it: contenuto) delete it;
        contenuto.clear();
    }
}

unsigned int listacomp::remMatch(std::string name,bool tutti, bool definitiva)
{
    unsigned int rem=0;
    for(std::vector<componente*>::const_iterator it=contenuto.begin();it!=contenuto.end() &&  (rem==0 || tutti) ;++it){
        if((*it)->getNome()== name) {
            if (definitiva) delete *it;
            contenuto.erase(it);
            ++rem;
            --it;
           }
    }
    return rem;
}

double listacomp::PrezzoTotale() const
{
    double tot=0;
    for(std::vector<componente*>::const_iterator it=contenuto.begin();it!=contenuto.end();++it){
        tot+=(*it)->getPrezzo();
    }
    return tot;
}

void listacomp::ordinaNome()
{
        std::sort(contenuto.begin(), contenuto.end(), [](const componente* a, const componente* b) { return a->getNome() < b->getNome(); });
}

void listacomp::ordinaPrezzo()
{
        std::sort(contenuto.begin(), contenuto.end(), [](const componente* a, const componente* b) { return a->getPrezzo() < b->getPrezzo(); });
}


void listacomp::stampaXml(const std::string& tag) const{
    QFile xml(getNomeFile());
    xml.open(QIODevice::WriteOnly);
    QXmlStreamWriter scrittore(&xml);
    scrittore.setAutoFormatting(true);
    scrittore.writeStartDocument();

    scrittore.writeStartElement(QString::fromStdString(tag));
    //if(!contenuto.empty())
    for(std::vector<componente*>::const_iterator it=contenuto.begin();it!=contenuto.end();++it){
        (*it)->stampaElementoXml(scrittore);
    }
    scrittore.writeEndElement();
    xml.close();
}

void listacomp::stampNomiXml(QXmlStreamWriter & stampatore, const std::string& tag) const{
    if(!contenuto.empty()){
        stampatore.writeStartElement(QString::fromStdString(tag));
        for(std::vector<componente*>::const_iterator it=contenuto.begin();it!=contenuto.end();++it){
            (*it)->stampaNomeXml(stampatore);
        }
        stampatore.writeEndElement();
   }
}


void listacomp::popolaListaDaXml()
{

    std::string tipo;
    QFile xml(getNomeFile()); //da mettere nome file generico
    if (xml.open(QFile::ReadOnly | QFile::Text))
    {
        componente* inseriscimi;
        std::string stringanormale;
        QXmlStreamReader xmlInput(&xml);
        while(xmlInput.readNextStartElement()){
        //Salta semplicemente l'lemento che indica inizio lista
            while(xmlInput.readNextStartElement()){
                //scorre il tipo di elemento dentro <tipo>
                inseriscimi = preparaoggetti::getOggettoPulito(xmlInput.name().toString());

                while(xmlInput.readNextStartElement()){
                    //riempie gli oggetti e li aggiunge in lista
                    stringanormale = (xmlInput.name().toString()).toStdString();
                    inseriscimi->importaDettagliXml(stringanormale, xmlInput.readElementText());

                }
                addComp(inseriscimi);
            }
        }
    }
    xml.close();


}

std::vector<componente*>::const_iterator listacomp::begin() const
{
   return contenuto.begin();
}
std::vector<componente*>::const_iterator listacomp::end() const
{
    return contenuto.end();
}
