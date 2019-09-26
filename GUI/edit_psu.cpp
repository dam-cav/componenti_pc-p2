#include "edit_psu.h"

edit_psu::edit_psu(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_psu* pezzo_psu= dynamic_cast<comp_psu*>(pezzo);
    if(pezzo_psu){
		separaOpzioni = new QHBoxLayout();
		sinistro= new QFormLayout();
		destro= new QFormLayout();
		
        labeltipo = new QLabel ("Formato Alimentatore");
        labelcertificazione = new QLabel ("Certificazione");
        labelmodulare = new QLabel ("E' Modulare?");
        labelventola = new QLabel ("Ha Ventole?");
        labelpotenza = new QLabel ("Potenza Massima");
        labelnAtx20 = new QLabel ("Numero Connettori ATX 20pin");
        labelnAtx24 = new QLabel ("Numero Connettori ATX 20+4pin");
        labelnEps4e4 = new QLabel ("Numero Connettori EPS 4+4pin");
        labelnEps4 = new QLabel ("Numero Connettori EPS 4pin");
        labelnPcie6 = new QLabel ("Numero Connettori PCIE 6pin");
        labelnPcie6e2 = new QLabel ("Numero Connettori PCIE 6+2pin");
        labelnMolex = new QLabel ("Numero Connettori MOLEX 4pin");
        labelnSata = new QLabel ("Numero Connettori SATA");

        edittipo = new QLineEdit(QString::fromStdString(pezzo_psu->getTipo()));
        editcertificazione = new QLineEdit(QString::fromStdString(pezzo_psu->getCertificazione()));
        editmodulare = new QCheckBox();
        editmodulare->setChecked(pezzo_psu->getModulare());
        editventola = new QCheckBox();
        editventola->setChecked(pezzo_psu->getVentola());
        editpotenza = new QLineEdit(QString::number(pezzo_psu->getPotenza()));
        editpotenza->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editnAtx20 = new QSpinBox();
        editnAtx20->setValue(pezzo_psu->getNAtx20());
        editnAtx20->setMinimum(0);
        editnAtx24 = new QSpinBox();
        editnAtx24->setValue(pezzo_psu->getNAtx24());
        editnAtx24->setMinimum(0);
        editnEps4e4 = new QSpinBox();
        editnEps4e4->setValue(pezzo_psu->getNEps4e4());
        editnEps4e4->setMinimum(0);
        editnEps4 = new QSpinBox();
        editnEps4->setValue(pezzo_psu->getNEps4());
        editnEps4->setMinimum(0);
        editnPcie6 = new QSpinBox();
        editnPcie6 ->setValue(pezzo_psu->getNPcie6());
        editnPcie6->setMinimum(0);
        editnPcie6e2 = new QSpinBox();
        editnPcie6e2->setValue(pezzo_psu->getNPcie6e2());
        editnPcie6e2->setMinimum(0);
        editnMolex = new QSpinBox();
        editnMolex->setValue(pezzo_psu->getNMolex());
        editnMolex->setMinimum(0);
        editnSata = new QSpinBox();
        editnSata->setValue(pezzo_psu->getNSata());
        editnSata->setMinimum(0);

        sinistro->addRow(labeltipo, edittipo);
        sinistro->addRow(labelcertificazione, editcertificazione);
        sinistro->addRow(labelmodulare, editmodulare);
        sinistro->addRow(labelventola, editventola);
        sinistro->addRow(labelpotenza, editpotenza);
        sinistro->addRow(labelnAtx20, editnAtx20);
        sinistro->addRow(labelnAtx24, editnAtx24);
        sinistro->addRow(labelnEps4e4, editnEps4e4);
        
        destro->addRow(labelnEps4, editnEps4);
        destro->addRow(labelnPcie6, editnPcie6);
        destro->addRow(labelnPcie6e2, editnPcie6e2);
        destro->addRow(labelnMolex, editnMolex);
        destro->addRow(labelnSata, editnSata);
        
        separaOpzioni->addLayout(sinistro);
        separaOpzioni->addLayout(destro);
        vLayout->addRow(separaOpzioni);

        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }
}

void edit_psu::aggiornaPezzo()
{
    comp_psu* pezzo_psu= dynamic_cast<comp_psu*>(pezzo);
    if(pezzo_psu){
        edit_componente::aggiornaPezzo();
        pezzo_psu->setTipo(edittipo->text().toStdString());
        pezzo_psu->setCertificazione(editcertificazione->text().toStdString());
        pezzo_psu->setModulare(editmodulare->isChecked()?true:false);
        pezzo_psu->setVentola(editventola->isChecked()?true:false);
        pezzo_psu->setPotenza(editpotenza->text().toInt());
        pezzo_psu->setNAtx20(editnAtx20->text().toInt());
        pezzo_psu->setNAtx24(editnAtx24->text().toInt());
        pezzo_psu->setNEps4e4(editnEps4e4->text().toInt());
        pezzo_psu->setNEps4(editnEps4->text().toInt());
        pezzo_psu->setNPcie6(editnPcie6->text().toInt());
        pezzo_psu->setNPcie6e2(editnPcie6e2->text().toInt());
        pezzo_psu->setNMolex(editnMolex->text().toInt());
        pezzo_psu->setNSata(editnSata->text().toInt());
    }
}

bool edit_psu::campiCorretti()
{
    return edit_componente::campiCorretti() && edittipo->text()!="" && editcertificazione->text()!="" && editpotenza->text()!="" && editnAtx20->text()!="" && editnAtx24->text()!="" && editnEps4e4->text()!="" && editnEps4->text()!="" && editnPcie6->text()!="" && editnPcie6e2->text()!="" && editnMolex->text()!="" && editnSata->text()!="";
}
