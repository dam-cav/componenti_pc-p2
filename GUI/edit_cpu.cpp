#include "edit_cpu.h"



edit_cpu::edit_cpu(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_cpu* pezzo_cpu= dynamic_cast<comp_cpu*>(pezzo);
    if(pezzo_cpu){
		separaOpzioni = new QHBoxLayout();
		sinistro= new QFormLayout();
		destro= new QFormLayout();
		
        labelclock = new QLabel ("Clock Cpu(in MHz)");
        labelclockT = new QLabel ("Clock Turbo Cpu (in MHz)");
        labelcore = new QLabel ("Numero di Core");
        labelthread = new QLabel ("Numero di Thread");
        labelcache = new QLabel ("Cache Cpu (in kB)");
        labelsocket = new QLabel ("Tipo Socket");
        labeltipoRam = new QLabel ("Tipo Ram");
        labelramF = new QLabel ("Frequenza Massima Ram (in MHz)");
        labelramC = new QLabel ("Numero di canali Ram");
        labelvPci = new QLabel ("Versione PCI");

        editclock = new QLineEdit(QString::number(pezzo_cpu->getClock()));
        editclock->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editclockT = new QLineEdit(QString::number(pezzo_cpu->getClockT()));
        editclockT->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
        editcore = new QSpinBox();
        editcore->setValue(pezzo_cpu->getCore());
        editcore->setMinimum(0);
        editthread = new QSpinBox();
        editthread->setValue(pezzo_cpu->getThread());
        editthread->setMinimum(0);
        editcache = new QLineEdit(QString::number(pezzo_cpu->getCache()));
        editcache->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
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
        editsocket->setCurrentText(QString::fromStdString(pezzo_cpu->getSocket()));       
        edittipoRam = new QComboBox;
        edittipoRam->addItem("SDR");
        edittipoRam->addItem("DDR");
        edittipoRam->addItem("DDR2");
        edittipoRam->addItem("DDR3");
        edittipoRam->addItem("DDR4");
        editsocket->setCurrentText(QString::fromStdString(pezzo_cpu->getTipoRam()));
        editramF = new QLineEdit(QString::number(pezzo_cpu->getRamF()));
        editramF->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));
        editramC = new QSpinBox;
        editramC->setValue(pezzo_cpu->getRamC());
        editramC->setMinimum(0);
        editvPci = new QLineEdit(QString::fromStdString(pezzo_cpu->getVPci()));//da cambiare



        sinistro->addRow(labelclock, editclock);
        sinistro->addRow(labelclockT, editclockT);
        sinistro->addRow(labelcore, editcore);
        sinistro->addRow(labelthread, editthread);
        sinistro->addRow(labelcache, editcache);
        
        destro->addRow(labelsocket, editsocket);
        destro->addRow(labeltipoRam, edittipoRam);
        destro->addRow(labelramF, editramF);
        destro->addRow(labelramC, editramC);
        destro->addRow(labelvPci, editvPci);
        
        separaOpzioni->addLayout(sinistro);
        separaOpzioni->addLayout(destro);
        vLayout->addRow(separaOpzioni);

        
        vLayout->addRow(conferma);       
        

        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));
    }

}

void edit_cpu::aggiornaPezzo()
{
    comp_cpu* pezzo_cpu= dynamic_cast<comp_cpu*>(pezzo);
    if(pezzo_cpu){
         edit_componente::aggiornaPezzo();
         pezzo_cpu->setClock(editclock->text().toDouble());
         pezzo_cpu->setClockT(editclockT->text().toDouble());
         pezzo_cpu->setCore(editcore->text().toInt());
         pezzo_cpu->setThread(editthread->text().toInt());
         pezzo_cpu->setCache(editcache->text().toDouble());
         pezzo_cpu->setSocket(editsocket->currentText().toStdString());
         pezzo_cpu->setTipoRam(edittipoRam->currentText().toStdString());
         pezzo_cpu->setRamF(editramF->text().toInt());
         pezzo_cpu->setRamC(editramC->text().toInt());
         pezzo_cpu->setVPci(editvPci->text().toStdString());
    }
}

bool edit_cpu::campiCorretti()
{
    return edit_componente::campiCorretti() && editclock->text()!="" && editclockT->text()!="" && editcore->text()!="" && editthread->text()!="" && editcache->text()!="" && editramF->text()!="" && editramC->text()!="" && editvPci->text()!="";
}
