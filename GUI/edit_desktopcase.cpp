#include "edit_desktopcase.h"


edit_desktopcase::edit_desktopcase(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{

    //editcache = new QLineEdit(QString::number(pezzo_cpu->getCache()));
    //editsocket = new QLineEdit(QString::fromStdString(pezzo_cpu->getSocket()));//da cambiare

    comp_desktopcase* pezzo_case= dynamic_cast<comp_desktopcase*>(pezzo);
    if(pezzo_case){
		separaOpzioni = new QHBoxLayout();
		sinistro= new QFormLayout();
		destro= new QFormLayout();
		
        labelformFactor = new QLabel ("Form Factor");
        labelnFan = new QLabel ("Numero Ventole");
        labelnUsb = new QLabel ("Numero Porte USB");
        labeltipoUsb = new QLabel ("Tipo Porte  USB");
        labelnJack = new QLabel ("Numero Jack Audio");
        labeltipoJack = new QLabel ("Tipi di Jack Audio");
        labeln35 = new QLabel ("Spazi per periferiche da 3.5\"");
        labeln25 = new QLabel ("Spazi per periferiche da 2.5\"");
        labelnMast = new QLabel ("Spazi per Masterizzatori");
        labelnSsd = new QLabel ("Spazi per unità SSD");
        labelnPci = new QLabel ("Numero slot per periferiche PCI");

        editformFactor = new QComboBox(); //(QString::fromStdString(pezzo_case->getFormFactor()));
        editformFactor->addItem("Full-Tower");
        editformFactor->addItem("Mid-Tower");
        editformFactor->addItem("Mini-Tower");
        editformFactor->addItem("Slim-Tower");
        editformFactor->addItem("Case SFF");
        editformFactor->setCurrentText(QString::fromStdString(pezzo_case->getFormFactor()));
        editnFan = new QSpinBox();
        editnFan->setValue(pezzo_case->getNFan());
        editnFan->setMinimum(0);
        editnUsb = new QSpinBox();
        editnUsb->setValue(pezzo_case->getNUsb());
        editnUsb->setMinimum(0);
        edittipoUsb = new QLineEdit(QString::fromStdString(pezzo_case->getTipoUsb()));
        editnJack = new QSpinBox();
        editnJack->setValue(pezzo_case->getNJack());
        editnJack->setMinimum(0);
        edittipoJack = new QLineEdit(QString::fromStdString(pezzo_case->getTipoJack()));
        editn35 = new QSpinBox();
        editn35->setValue(pezzo_case->getN35());
        editn35->setMinimum(0);
        editn25 = new QSpinBox();
        editn25->setValue(pezzo_case->getN25());
        editn25->setMinimum(0);
        editnMast = new QSpinBox();
        editnMast->setValue(pezzo_case->getNMast());
        editnMast->setMinimum(0);
        editnSsd = new QSpinBox();
        editnSsd->setValue(pezzo_case->getNSsd());
        editnSsd->setMinimum(0);
        editnPci = new QSpinBox();
        editnPci->setValue(pezzo_case->getNPci());
        editnPci->setMinimum(0);

        sinistro->addRow(labelformFactor, editformFactor);
        sinistro->addRow(labelnFan, editnFan);
        sinistro->addRow(labelnUsb, editnUsb);
        sinistro->addRow(labeltipoUsb, edittipoUsb);
        sinistro->addRow(labelnJack, editnJack);
        sinistro->addRow(labeltipoJack, edittipoJack);
        
        destro->addRow(labeln35, editn35);
        destro->addRow(labeln25, editn25);
        destro->addRow(labelnMast, editnMast);
        destro->addRow(labelnSsd, editnSsd);
        destro->addRow(labelnPci, editnPci);
		
		separaOpzioni->addLayout(sinistro);
        separaOpzioni->addLayout(destro);
        vLayout->addRow(separaOpzioni);

        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }
}

void edit_desktopcase::aggiornaPezzo()
{
    comp_desktopcase* pezzo_case= dynamic_cast<comp_desktopcase*>(pezzo);
    if(pezzo_case){
        edit_componente::aggiornaPezzo();
        pezzo_case->setFormFactor(editformFactor->currentText().toStdString());
        pezzo_case->setNFan(editnFan->text().toInt());
        pezzo_case->setNUsb(editnUsb->text().toInt());
        pezzo_case->setTipoUsb(edittipoUsb->text().toStdString());
        pezzo_case->setNJack(editnJack->text().toInt());
        pezzo_case->setTipoJack(edittipoJack->text().toStdString());
        pezzo_case->setN35(editn35->text().toInt());
        pezzo_case->setN25(editn25->text().toInt());
        pezzo_case->setNMast(editnMast->text().toInt());
        pezzo_case->setNSsd(editnSsd->text().toInt());
        pezzo_case->setNPci(editnPci->text().toInt());
    }
}

bool edit_desktopcase::campiCorretti()
{
    return edit_componente::campiCorretti() &&  editnFan->text()!="" && edittipoUsb->text()!="" && editnJack->text()!="" && editn35->text()!="" && editn25->text()!="" && editnMast->text()!="" && editnSsd->text()!="" && editnPci->text()!="";
}
