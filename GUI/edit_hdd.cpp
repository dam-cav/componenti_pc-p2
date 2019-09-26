#include "edit_hdd.h"


edit_hdd::edit_hdd(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_hdd* pezzo_hdd= dynamic_cast<comp_hdd*>(pezzo);
    if(pezzo_hdd){
        labeltipo = new QLabel ("Tipo di Memoria");
        labelforma = new QLabel ("Form Factor");
        labelcapacitaSsd = new QLabel ("Capacità Memoria Elettrica (in GB)");
        labelcapacitaHdd = new QLabel ("Capacità Memoria Meccanica (in GB)");
        labelinterfaccia = new QLabel ("Interfaccia");
        labelrpm = new QLabel ("Giri al Minuto (rpm)");
        labelscrittura = new QLabel ("Velocità scrittura (se dichiarata)");
        labellettura = new QLabel ("Velocità lettura (se dichiarata)");

        edittipo = new QComboBox();
        edittipo->addItem("HDD");
        edittipo->addItem("SSD");
        edittipo->addItem("SSHD");
        edittipo->addItem("SSD-M2");
        edittipo->addItem("SSD-PCI");
        edittipo->setCurrentText(QString::fromStdString(pezzo_hdd->getTipo()));
        editforma = new QComboBox();
        editforma->addItem("3.5 Pollici");
        editforma->addItem("2.5 Pollici");
        editforma->addItem("Altro");
        editforma->setCurrentText(QString::fromStdString(pezzo_hdd->getForma()));
        editcapacitaSsd = new QLineEdit(QString::number(pezzo_hdd->getCapacitaSsd()));
        editcapacitaSsd->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editcapacitaHdd = new QLineEdit(QString::number(pezzo_hdd->getCapacitaHdd()));
        editcapacitaSsd->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editinterfaccia = new QComboBox();
        editinterfaccia->addItem("SATA 3");
        editinterfaccia->addItem("SATA 2");
        editinterfaccia->addItem("M2");
        editinterfaccia->addItem("PCIe");
        editinterfaccia->setCurrentText(QString::fromStdString(pezzo_hdd->getInterfaccia()));
        editrpm = new QLineEdit(QString::number(pezzo_hdd->getRpm()));
        editrpm->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editscrittura = new QLineEdit(QString::number(pezzo_hdd->getScrittura()));
        editscrittura->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editlettura = new QLineEdit(QString::number(pezzo_hdd->getLettura()));
        editlettura->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));

        vLayout->addRow(labeltipo, edittipo);
        vLayout->addRow(labelforma, editforma);
        vLayout->addRow(labelcapacitaSsd, editcapacitaSsd);
        vLayout->addRow(labelcapacitaHdd, editcapacitaHdd);
        vLayout->addRow(labelinterfaccia, editinterfaccia);
        vLayout->addRow(labelrpm, editrpm);
        vLayout->addRow(labelscrittura, editscrittura);
        vLayout->addRow(labellettura, editlettura);

        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }
}

void edit_hdd::aggiornaPezzo()
{
    comp_hdd* pezzo_hdd= dynamic_cast<comp_hdd*>(pezzo);
    if(pezzo_hdd){
        edit_componente::aggiornaPezzo();
        pezzo_hdd->setTipo(edittipo->currentText().toStdString());
        pezzo_hdd->setForma(editforma->currentText().toStdString());
        pezzo_hdd->setCapacitaSsd(editcapacitaSsd->text().toInt());
        pezzo_hdd->setCapacitaHdd(editcapacitaHdd->text().toInt());
        pezzo_hdd->setInterfaccia(editinterfaccia->currentText().toStdString());
        pezzo_hdd->setRpm(editrpm->text().toInt());
        pezzo_hdd->setScrittura(editscrittura->text().toInt());
        pezzo_hdd->setLettura(editlettura->text().toInt());
    }
}

bool edit_hdd::campiCorretti()
{
    return edit_componente::campiCorretti() && editcapacitaSsd->text()!="" && editcapacitaHdd->text()!="" && editrpm->text()!="" && editscrittura->text()!="" && editlettura->text()!="";
}
