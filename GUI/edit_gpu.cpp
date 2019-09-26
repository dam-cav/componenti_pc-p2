#include "edit_gpu.h"


edit_gpu::edit_gpu(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_gpu* pezzo_gpu= dynamic_cast<comp_gpu*>(pezzo);
    if(pezzo_gpu){
		separaOpzioni = new QHBoxLayout();
		sinistro= new QFormLayout();
		destro= new QFormLayout();
		
        labelclockBase = new QLabel ("Clock Base Gpu(in MHz)");
        labelclockBoost = new QLabel ("Clock Boost Gpu (in MHz)");
        labelmemoria = new QLabel ("Memoria (in MB)");
        labelvelMemoria = new QLabel ("Velocità Memoria (in Mbps)");
        labeltipoMem = new QLabel ("Tipo Memoria");
        labelbandaMem = new QLabel ("Banda Memoria (in MB/s)");
        labelbus = new QLabel ("Tipo Bus");
        labelsliCross = new QLabel ("compatibilità SLI/CrossFire");
        labeln6pin = new QLabel ("N# Connettori Alimentatore 6pin");
        labeln6e2pin = new QLabel ("N# Connettori Alimentatore 8pin");
        labelnHdmi = new QLabel ("Numero Porte HDMI");
        labelnVga = new QLabel ("Numero Porte VGA");
        labelnDvi = new QLabel ("Numero Porte DVI");
        labelnDisplayPort = new QLabel ("Numero Porte DisplayPort");

        editclockBase = new QLineEdit(QString::number(pezzo_gpu->getClockBase()));
        editclockBase->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editclockBoost = new QLineEdit(QString::number(pezzo_gpu->getClockBoost()));
        editclockBoost->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editmemoria = new QLineEdit(QString::number(pezzo_gpu->getMemoria()));
        editmemoria->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editvelMemoria = new QLineEdit(QString::number(pezzo_gpu->getVelMemoria()));
        editvelMemoria->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        edittipoMem = new QLineEdit(QString::fromStdString(pezzo_gpu->getTipoMem()));//DA CAMBIARE
        editbandaMem = new QLineEdit(QString::number(pezzo_gpu->getBandaMem()));
        editbandaMem->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,5}"), this));
        editbus = new QLineEdit(QString::fromStdString(pezzo_gpu->getBus()));
        editsliCross = new QCheckBox();
        editsliCross->setChecked(pezzo_gpu->getSliCross());
        editn6pin = new QSpinBox();
        editn6pin->setValue(pezzo_gpu->getN6pin());
        editn6pin->setMinimum(0);
        editn6e2pin = new QSpinBox();
        editn6e2pin->setValue(pezzo_gpu->getN6e2pin());
        editn6e2pin->setMinimum(0);
        editnHdmi = new QSpinBox();
        editn6e2pin->setValue(pezzo_gpu->getN6e2pin());
        editn6e2pin->setMinimum(0);
        editnVga = new QSpinBox();
        editnVga->setValue(pezzo_gpu->getNVga());
        editnVga->setMinimum(0);
        editnDvi = new QSpinBox();
        editnDvi->setValue(pezzo_gpu->getNDvi());
        editnDvi->setMinimum(0);
        editnDisplayPort = new QSpinBox();
        editnDisplayPort->setValue(pezzo_gpu->getNDisplayPort());
        editnDisplayPort->setMinimum(0);

        sinistro->addRow(labelclockBase, editclockBase);
        sinistro->addRow(labelclockBoost, editclockBoost);
        sinistro->addRow(labelmemoria, editmemoria);
        sinistro->addRow(labelvelMemoria, editvelMemoria);
        sinistro->addRow(labeltipoMem, edittipoMem);
        sinistro->addRow(labelbandaMem, editbandaMem);
        sinistro->addRow(labelbus, editbus);
        
        destro->addRow(labelsliCross, editsliCross);
        destro->addRow(labeln6pin, editn6pin);
        destro->addRow(labeln6e2pin, editn6e2pin);
        destro->addRow(labelnHdmi, editnHdmi);
        destro->addRow(labelnVga, editnVga);
        destro->addRow(labelnDvi, editnDvi);
        destro->addRow(labelnDisplayPort, editnDisplayPort);
        
        separaOpzioni->addLayout(sinistro);
        separaOpzioni->addLayout(destro);
        vLayout->addRow(separaOpzioni);


        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }

}

void edit_gpu::aggiornaPezzo()
{
    comp_gpu* pezzo_gpu= dynamic_cast<comp_gpu*>(pezzo);
    if(pezzo_gpu){
        edit_componente::aggiornaPezzo();
        pezzo_gpu->setClockBase(editclockBase->text().toDouble());
        pezzo_gpu->setClockBoost(editclockBoost->text().toDouble());
        pezzo_gpu->setMemoria(editmemoria->text().toDouble());
        pezzo_gpu->setVelMemoria(editvelMemoria->text().toDouble());
        pezzo_gpu->setTipoMem(edittipoMem->text().toStdString());
        pezzo_gpu->setBandaMem(editbandaMem->text().toInt());
        pezzo_gpu->setBus(editbus->text().toStdString());
        pezzo_gpu->setSliCross(editsliCross->isChecked()?true:false);
        pezzo_gpu->setN6pin(editn6pin->text().toInt());
        pezzo_gpu->setN6e2pin(editn6e2pin->text().toInt());
        pezzo_gpu->setNHdmi(editnHdmi->text().toInt());
        pezzo_gpu->setNVga(editnVga->text().toInt());
        pezzo_gpu->setNDvi(editnDvi->text().toInt());
        pezzo_gpu->setNDisplayPort(editnDisplayPort->text().toInt());
    }

}

bool edit_gpu::campiCorretti()
{
    return edit_componente::campiCorretti() && editclockBase->text()!="" && editclockBoost->text()!="" && editmemoria->text()!="" && editvelMemoria->text()!="" && edittipoMem->text()!="" && editbandaMem->text()!="" && editbus->text()!="" && editn6pin->text()!="" && editn6e2pin->text()!="" && editnHdmi->text()!="" && editnVga->text()!="" && editnDvi->text()!="" && editnDisplayPort->text()!="";
}
