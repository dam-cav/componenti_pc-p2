#include "edit_ram.h"

edit_ram::edit_ram(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_ram* pezzo_ram= dynamic_cast<comp_ram*>(pezzo);
    if(pezzo_ram){
        labeltipoMemoria = new QLabel ("Tipo di Memoria");
        labelmemoria = new QLabel ("Quantità Memoria (in GB)");
        labelvoltaggio = new QLabel ("Voltaggio (in V)");

        edittipoMemoria = new QComboBox();
        edittipoMemoria->addItem("SDR");
        edittipoMemoria->addItem("DDR");
        edittipoMemoria->addItem("DDR2");
        edittipoMemoria->addItem("DDR3");
        edittipoMemoria->addItem("DDR4");
        edittipoMemoria->setCurrentText(QString::fromStdString(pezzo_ram->getTipoMemoria()));
        editmemoria = new QLineEdit(QString::number(pezzo_ram->getMemoria()));
        editmemoria->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editvoltaggio = new QLineEdit(QString::number(pezzo_ram->getVoltaggio()));
        editvoltaggio->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));

        vLayout->addRow(labeltipoMemoria, edittipoMemoria);
        vLayout->addRow(labelmemoria, editmemoria);
        vLayout->addRow(labelvoltaggio, editvoltaggio);

        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }

}

void edit_ram::aggiornaPezzo()
{
    comp_ram* pezzo_ram= dynamic_cast<comp_ram*>(pezzo);
    if(pezzo_ram){
        edit_componente::aggiornaPezzo();
        pezzo_ram->setTipoMemoria(edittipoMemoria->currentText().toStdString());
        pezzo_ram->setMemoria(editmemoria->text().toInt());
        pezzo_ram->setVoltaggio(editvoltaggio->text().toDouble());
    }

}

bool edit_ram::campiCorretti()
{
    return edit_componente::campiCorretti() && editmemoria->text()!="" &&  editvoltaggio->text()!="";
}
