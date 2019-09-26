#include "edit_mobo.h"


edit_mobo::edit_mobo(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_mobo* pezzo_mobo= dynamic_cast<comp_mobo*>(pezzo);
    if(pezzo_mobo){
		separaOpzioni = new QHBoxLayout();
		sinistro= new QFormLayout();
		destro= new QFormLayout();		
		
        labelsocket = new QLabel ("Socket");
        labelchipset = new QLabel ("Chipset");
        labelramSlot = new QLabel ("Numero di Slot per Ram");
        labeltipiRam = new QLabel ("Tipo di RAM");
        labelramMaxFreq = new QLabel ("Frequenza Massima RAM");
        labelnSata = new QLabel ("Numero Porte SATA");
        labeltipoSataInt = new QLabel ("Tipi di Porte SATA");
        labelnM2 = new QLabel ("Numero di M2 Shield");
        labelaudio = new QLabel ("Scheda Audio Integrata");
        labelnUsbInt = new QLabel ("Numero USB Interne");
        labeltipoUsbInt = new QLabel ("Tipi di USB Interne");
        labelnPciex16 = new QLabel ("Numero Porte PCIe formato x16");
        labelnPciex1 = new QLabel ("Numero Porte PCIe formato x1");
        labeldettagliPci = new QLabel ("Ulteriori PCIe o Dettagli");
        labelnPs2 = new QLabel ("Numero Porte PS2");
        labelnUsbEst = new QLabel ("Numero USB Esterne");
        labeltipoUsbEst = new QLabel ("Tipi di USB Esterne");
        labelnLan = new QLabel ("Numero Porte LAN");
        labelnHdmi = new QLabel ("Numero Porte HDMI");
        labelnDisplayPort = new QLabel ("Numero Porte DisplayPort");
        labelnDvi = new QLabel ("Numero Porte DVI");
        labelnVga = new QLabel ("Numero Porte BGA");
        labelaudioJack = new QLabel ("Numero Porte Audio Jack");
        labelnOpt = new QLabel ("Numero Porte Audio ottico");
        labelneSata = new QLabel ("Numero Porte eSata Esterne");
        labelwifi = new QLabel ("WIFI Integrato?");
        labelextra = new QLabel ("Ulteriori Dettagli");

        editsocket = new QComboBox();
        editsocket->addItem("LGA 2066");
        editsocket->addItem("Socket TR4");
        editsocket->addItem("Socket SP3	");
        editsocket->addItem("Socket AM4");
        editsocket->addItem("LGA 3647");
        editsocket->addItem("LGA 1151");
        editsocket->addItem("Socket AM1");
        editsocket->addItem("Socket FM2+");
        editsocket->addItem("Socket G3");
        editsocket->addItem("LGA 1150");
        editsocket->addItem("Socket FM2");
        editsocket->addItem("Socket AM3+");
        editsocket->addItem("Socket FS1");
        editsocket->addItem("Socket FM1");
        editsocket->addItem("rPGA 988B");
        editsocket->addItem("LGA 2011");
        editsocket->addItem("LGA 1155");
        editsocket->addItem("Socket C32");
        editsocket->addItem("Socket G34");
        editsocket->addItem("LGA 1156");
        editsocket->addItem("Socket AM3");
        editsocket->addItem("rPGA 988A");
        editsocket->addItem("LGA 1366");
        editsocket->addItem("Socket 441");
        editsocket->addItem("Socket P");
        editsocket->addItem("Socket AM2+");
        editsocket->addItem("Socket F");
        editsocket->addItem("Socket AM2");
        editsocket->addItem("Socket S1");
        editsocket->addItem("LGA 771");
        editsocket->addItem("Socket M");
        editsocket->addItem("LGA 775");
        editsocket->addItem("Socket 939");
        editsocket->addItem("Socket 479");
        editsocket->addItem("Socket 940");
        editsocket->addItem("Socket 754");
        editsocket->addItem("Socket 604");
        editsocket->addItem("Socket 563");
        editsocket->addItem("Socket 603");
        editsocket->addItem("PAC418");
        editsocket->addItem("Socket 495");
        editsocket->setCurrentText(QString::fromStdString(pezzo_mobo->getSocket()));
        editchipset = new QLineEdit(QString::fromStdString(pezzo_mobo->getChipset()));
        editramSlot = new QSpinBox();
        editramSlot->setValue(pezzo_mobo->getRamSlot());
        editramSlot->setMinimum(0);
        edittipiRam = new QComboBox();
        edittipiRam->addItem("SDR");
        edittipiRam->addItem("DDR");
        edittipiRam->addItem("DDR2");
        edittipiRam->addItem("DDR3");
        edittipiRam->addItem("DDR4");
        edittipiRam->setCurrentText(QString::fromStdString(pezzo_mobo->getTipiRam()));
        editramMaxFreq = new QLineEdit(QString::number(pezzo_mobo->getRamMaxFreq()));
        editramMaxFreq->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editnSata = new QSpinBox();
        editnSata->setValue(pezzo_mobo->getNSata());
        editnSata->setMinimum(0);
        edittipoSataInt = new QLineEdit(QString::fromStdString(pezzo_mobo->getTipoSataInt()));
        editnM2 = new QSpinBox();
        editnM2->setValue(pezzo_mobo->getNM2());
        editnM2->setMinimum(0);
        editaudio = new QLineEdit(QString::fromStdString(pezzo_mobo->getAudio()));
        editnUsbInt = new QSpinBox();
        editnUsbInt->setValue(pezzo_mobo->getNUsbInt());
        editnUsbInt->setMinimum(0);
        edittipoUsbInt = new QLineEdit(QString::fromStdString(pezzo_mobo->getTipoUsbInt()));
        editnPciex16 = new QSpinBox();
        editnPciex16->setValue(pezzo_mobo->getNPciex16());
        editnPciex16->setMinimum(0);
        editnPciex1 = new QSpinBox();
        editnPciex1->setValue(pezzo_mobo->getNPciex1());
        editnPciex1->setMinimum(0);
        editdettagliPci = new QLineEdit(QString::fromStdString(pezzo_mobo->getDettagliPci()));
        editnPs2 = new QSpinBox();
        editnPs2->setValue(pezzo_mobo->getNPs2());
        editnPs2->setMinimum(0);
        editnUsbEst = new QSpinBox();
        editnUsbEst->setValue(pezzo_mobo->getNUsbEst());
        editnUsbEst->setMinimum(0);
        edittipoUsbEst = new QLineEdit(QString::fromStdString(pezzo_mobo->getTipoUsbEst()));
        editnLan = new QSpinBox();
        editnLan->setValue(pezzo_mobo->getNLan());
        editnLan->setMinimum(0);
        editnHdmi = new QSpinBox();
        editnHdmi->setValue(pezzo_mobo->getNHdmi());
        editnHdmi->setMinimum(0);
        editnDisplayPort = new QSpinBox();
        editnDisplayPort->setValue(pezzo_mobo->getNDisplayPort());
        editnDisplayPort->setMinimum(0);
        editnDvi = new QSpinBox();
        editnDvi->setValue(pezzo_mobo->getNDvi());
        editnDvi->setMinimum(0);
        editnVga = new QSpinBox();
        editnVga->setValue(pezzo_mobo->getNOpt());
        editnVga->setMinimum(0);
        editaudioJack = new QSpinBox();
        editaudioJack->setValue(pezzo_mobo->getAudioJack());
        editaudioJack->setMinimum(0);
        editnOpt = new QSpinBox();
        editnOpt->setValue(pezzo_mobo->getNOpt());
        editnOpt->setMinimum(0);
        editneSata = new QSpinBox();
        editneSata->setValue(pezzo_mobo->getNSata());
        editneSata->setMinimum(0);
        editwifi = new QCheckBox();
        editwifi->setChecked(pezzo_mobo->getWifi());
        editextra = new QLineEdit(QString::fromStdString(pezzo_mobo->getExtra()));
	
        sinistro->addRow(labelsocket, editsocket);
        sinistro->addRow(labelchipset, editchipset);
        sinistro->addRow(labelramSlot, editramSlot);
        sinistro->addRow(labeltipiRam, edittipiRam);
        sinistro->addRow(labelramMaxFreq, editramMaxFreq);
        sinistro->addRow(labelnSata, editnSata);
        sinistro->addRow(labeltipoSataInt, edittipoSataInt);
        sinistro->addRow(labelnM2, editnM2);
        sinistro->addRow(labelaudio, editaudio);
        sinistro->addRow(labelnUsbInt, editnUsbInt);
        sinistro->addRow(labeltipoUsbInt, edittipoUsbInt);
        sinistro->addRow(labelnPciex16, editnPciex16);
        sinistro->addRow(labelnPciex1, editnPciex1);
        sinistro->addRow(labeldettagliPci, editdettagliPci);
        
        destro->addRow(labelnPs2, editnPs2);
        destro->addRow(labelnUsbEst, editnUsbEst);
        destro->addRow(labeltipoUsbEst, edittipoUsbEst);
        destro->addRow(labelnLan, editnLan);
        destro->addRow(labelnHdmi, editnHdmi);
        destro->addRow(labelnDisplayPort, editnDisplayPort);
        destro->addRow(labelnDvi, editnDvi);
        destro->addRow(labelnVga, editnVga);
        destro->addRow(labelaudioJack, editaudioJack);
        destro->addRow(labelnOpt, editnOpt);
        destro->addRow(labelneSata, editneSata);
        destro->addRow(labelwifi, editwifi);
        destro->addRow(labelextra, editextra);
        
        separaOpzioni->addLayout(sinistro);
        separaOpzioni->addLayout(destro);
        vLayout->addRow(separaOpzioni);

        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }
}

void edit_mobo::aggiornaPezzo()
{
    comp_mobo* pezzo_mobo= dynamic_cast<comp_mobo*>(pezzo);
    if(pezzo_mobo){
        edit_componente::aggiornaPezzo();
        pezzo_mobo->setSocket(editsocket->currentText().toStdString());
        pezzo_mobo->setChipset(editchipset->text().toStdString());
        pezzo_mobo->setRamSlot(editramSlot->text().toInt());
        pezzo_mobo->setTipiRam(edittipiRam->currentText().toStdString());
        pezzo_mobo->setRamMaxFreq(editramMaxFreq->text().toInt());
        pezzo_mobo->setNSata(editnSata->text().toInt());
        pezzo_mobo->setTipoSataInt(edittipoSataInt->text().toStdString());
        pezzo_mobo->setNM2(editnM2->text().toInt());
        pezzo_mobo->setAudio(editaudio->text().toStdString());
        pezzo_mobo->setNUsbInt(editnUsbInt->text().toInt());
        pezzo_mobo->setTipoUsbInt(edittipoUsbInt->text().toStdString());
        pezzo_mobo->setNPciex16(editnPciex16->text().toInt());
        pezzo_mobo->setNPciex1(editnPciex1->text().toInt());
        pezzo_mobo->setDettagliPci(editdettagliPci->text().toStdString());
        pezzo_mobo->setNPs2(editnPs2->text().toInt());
        pezzo_mobo->setNUsbEst(editnUsbEst->text().toInt());
        pezzo_mobo->setTipoUsbEst(edittipoUsbEst->text().toStdString());
        pezzo_mobo->setNLan(editnLan->text().toInt());
        pezzo_mobo->setNHdmi(editnHdmi->text().toInt());
        pezzo_mobo->setNDisplayPort(editnDisplayPort->text().toInt());
        pezzo_mobo->setNDvi(editnDvi->text().toInt());
        pezzo_mobo->setNVga(editnVga->text().toInt());
        pezzo_mobo->setAudioJack(editaudioJack->text().toInt());
        pezzo_mobo->setNOpt(editnOpt->text().toInt());
        pezzo_mobo->setNeSata(editneSata->text().toInt());
        pezzo_mobo->setWifi(editwifi->isChecked()?true:false);
        pezzo_mobo->setExtra(editextra->text().toStdString());

    }
}

bool edit_mobo::campiCorretti()
{
    return edit_componente::campiCorretti() && editchipset->text()!="" && editramSlot->text()!="" && editramMaxFreq->text()!="" && editnSata->text()!="" &&
            edittipoSataInt->text()!="" && editnM2->text()!="" && editnUsbInt->text()!="" && editnPciex16->text()!="" &&
            editnPciex1->text()!="" &&  editnPs2->text()!="" && editnUsbEst->text()!="" && editnLan->text()!="" &&
            editnHdmi->text()!="" && editnDisplayPort->text()!="" && editnDvi->text()!="" && editnVga->text()!="" && editaudioJack->text()!="" && editnOpt->text()!="" &&
            editneSata->text()!="";
}
