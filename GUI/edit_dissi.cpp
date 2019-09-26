#include "edit_dissi.h"

std::string edit_dissi::generaCampoSocket()
{
    std::string socket="";
    if(compSocket2066->isChecked()) socket=socket+"/LGA 2066";
    if(compLGA3647->isChecked()) socket=socket+"/LGA 3647";
    if(compLGA1151->isChecked()) socket=socket+"/LGA 1151";
    if(compSocketG3->isChecked()) socket=socket+"/Socket G3";
    if(compLGA1150->isChecked()) socket=socket+"/LGA 1150";
    if(comprPGA988B->isChecked()) socket=socket+"/rPGA 988B";
    if(compLGA2011->isChecked()) socket=socket+"/LGA 2011";
    if(compLGA1155->isChecked()) socket=socket+"/LGA 1155";
    if(compLGA1156->isChecked()) socket=socket+"/LGA 1156";
    if(comprPGA988A->isChecked()) socket=socket+"/rPGA 988A";
    if(compLGA1366->isChecked()) socket=socket+"/LGA 1366";
    if(compSocket441->isChecked()) socket=socket+"/Socket 441";
    if(compSocketP->isChecked()) socket=socket+"/Socket P";
    if(compLGA771->isChecked()) socket=socket+"/LGA 771";
    if(compSocketM->isChecked()) socket=socket+"/Socket M";
    if(compLGA775->isChecked()) socket=socket+"/LGA 775";
    if(compSocket479->isChecked()) socket=socket+"/Socket 479";
    if(compSocket604->isChecked()) socket=socket+"/Socket 604";
    if(compSocket603->isChecked()) socket=socket+"/Socket 603";
    if(compPAC418->isChecked()) socket=socket+"/PAC418";
    if(compSocket495->isChecked()) socket=socket+"/Socket 495";


    if(compSocketTR4->isChecked()) socket=socket+"/Socket TR4";
    if(compSocketSP3->isChecked()) socket=socket+"/Socket SP3";
    if(compSocketAM4->isChecked()) socket=socket+"/Socket AM4";
    if(compSocketAM1->isChecked()) socket=socket+"/Socket AM1";
    if(compSocketFM2p->isChecked()) socket=socket+"/Socket FM2+";
    if(compSocketFM2->isChecked()) socket=socket+"/Socket FM2";
    if(compSocketAM3p->isChecked()) socket=socket+"/Socket AM3+";
    if(compSocketFS1->isChecked()) socket=socket+"/Socket FS1";
    if(compSocketFM1->isChecked()) socket=socket+"/Socket FM1";
    if(compSocketC32->isChecked()) socket=socket+"/Socket C32";
    if(compSocketG34->isChecked()) socket=socket+"/Socket G34";
    if(compSocketAM3->isChecked()) socket=socket+"/Socket AM3";
    if(compSocketAM2p->isChecked()) socket=socket+"/Socket AM2+";
    if(compSocketF->isChecked()) socket=socket+"/Socket F";
    if(compSocketAM2->isChecked()) socket=socket+"/Socket AM2";
    if(compSocketS1->isChecked()) socket=socket+"/Socket S1";
    if(compSocket939->isChecked()) socket=socket+"/Socket 939";
    if(compSocket940->isChecked()) socket=socket+"/Socket 940";
    if(compSocket754->isChecked()) socket=socket+"/Socket 754";
    if(compSocket563->isChecked()) socket=socket+"/Socket 563";
    return socket;
}

void edit_dissi::riempiCheck(QString listSock)
{
    QStringList list1= listSock.split('/');
    for (int i = 0; i < list1.size(); ++i){
        if(list1.at(i)=="LGA 2066") compSocket2066->setChecked(true);
        else if(list1.at(i)=="Socket TR4") compSocketTR4->setChecked(true);
        else if(list1.at(i)=="Socket SP3") compSocketSP3->setChecked(true);
        else if(list1.at(i)=="Socket AM4") compSocketAM4->setChecked(true);
        else if(list1.at(i)=="LGA 3647") compLGA3647->setChecked(true);
        else if(list1.at(i)=="LGA 1151") compLGA1151->setChecked(true);
        else if(list1.at(i)=="Socket AM1") compSocketAM1->setChecked(true);
        else if(list1.at(i)=="Socket FM2+") compSocketFM2p->setChecked(true);
        else if(list1.at(i)=="Socket G3") compSocketG3->setChecked(true);
        else if(list1.at(i)=="LGA 1150") compLGA1150->setChecked(true);
        else if(list1.at(i)=="Socket FM2") compSocketFM2->setChecked(true);
        else if(list1.at(i)=="Socket AM3+") compSocketAM3p->setChecked(true);
        else if(list1.at(i)=="Socket FS1") compSocketFS1->setChecked(true);
        else if(list1.at(i)=="Socket FM1") compSocketFM1->setChecked(true);
        else if(list1.at(i)=="rPGA 988B") comprPGA988B->setChecked(true);
        else if(list1.at(i)=="LGA 2011") compLGA2011->setChecked(true);
        else if(list1.at(i)=="LGA 1155") compLGA1155->setChecked(true);
        else if(list1.at(i)=="Socket C32") compSocketC32->setChecked(true);
        else if(list1.at(i)=="Socket G34") compSocketG34->setChecked(true);
        else if(list1.at(i)=="LGA 1156") compLGA1156->setChecked(true);
        else if(list1.at(i)=="Socket AM3") compSocketAM3->setChecked(true);
        else if(list1.at(i)=="rPGA 988A") comprPGA988A->setChecked(true);
        else if(list1.at(i)=="LGA 1366") compLGA1366->setChecked(true);
        else if(list1.at(i)=="Socket 441") compSocket441->setChecked(true);
        else if(list1.at(i)=="Socket P") compSocketP->setChecked(true);
        else if(list1.at(i)=="Socket AM2+") compSocketAM2p->setChecked(true);
        else if(list1.at(i)=="Socket F") compSocketF->setChecked(true);
        else if(list1.at(i)=="Socket AM2") compSocketAM2->setChecked(true);
        else if(list1.at(i)=="Socket S1") compSocketS1->setChecked(true);
        else if(list1.at(i)=="LGA 771") compLGA771->setChecked(true);
        else if(list1.at(i)=="Socket M") compSocketM->setChecked(true);
        else if(list1.at(i)=="LGA 775") compLGA775->setChecked(true);
        else if(list1.at(i)=="Socket 939") compSocket939->setChecked(true);
        else if(list1.at(i)=="Socket 479") compSocket479->setChecked(true);
        else if(list1.at(i)=="Socket 940") compSocket940->setChecked(true);
        else if(list1.at(i)=="Socket 754") compSocket754->setChecked(true);
        else if(list1.at(i)=="Socket 604") compSocket604->setChecked(true);
        else if(list1.at(i)=="Socket 563") compSocket563->setChecked(true);
        else if(list1.at(i)=="Socket 603") compSocket603->setChecked(true);
        else if(list1.at(i)=="PAC418") compPAC418->setChecked(true);
        else if(list1.at(i)=="Socket 495") compSocket495->setChecked(true);
    }
}

edit_dissi::edit_dissi(componente * com, listacomp * cat, bool nuovOgg):edit_componente(com,cat,nuovOgg)
{
    comp_dissi* pezzo_dissi= dynamic_cast<comp_dissi*>(pezzo);
    if(pezzo_dissi){

        Socket = new QHBoxLayout();
        SocketIntel = new QVBoxLayout();
        SocketAmd = new QVBoxLayout();

        labelliquido = new QLabel("A Liquido?");
        editliquido = new QCheckBox();
        editliquido->setChecked(pezzo_dissi->getLiquido());
        vLayout->addRow(labelliquido, editliquido);
        vLayout->addRow(Socket);
        vLayout->addRow(conferma);
        connect(conferma,SIGNAL(clicked()),this,SLOT(confermaModifiche()));

        compSocket2066= new QCheckBox("LGA 2066");
        compLGA3647= new QCheckBox("LGA 3647");
        compLGA1151= new QCheckBox("LGA 1151");
        compSocketG3= new QCheckBox("Socket G3");
        compLGA1150= new QCheckBox("LGA 1150");
        comprPGA988B= new QCheckBox("rPGA 988B");
        compLGA2011= new QCheckBox("LGA 2011");
        compLGA1155= new QCheckBox("LGA 1155");
        compLGA1156= new QCheckBox("LGA 1156");
        comprPGA988A= new QCheckBox("rPGA 988A");
        compLGA1366= new QCheckBox("LGA 1366");
        compSocket441= new QCheckBox("Socket 441");
        compSocketP= new QCheckBox("Socket P");
        compLGA771= new QCheckBox("LGA 771");
        compSocketM= new QCheckBox("Socket M");
        compLGA775= new QCheckBox("LGA 775");
        compSocket479= new QCheckBox("Socket 479");
        compSocket604= new QCheckBox("Socket 604");
        compSocket603= new QCheckBox("Socket 603");
        compPAC418= new QCheckBox("PAC418");
        compSocket495= new QCheckBox("Socket 495");
        SocketIntel->addWidget(compSocket2066);
        SocketIntel->addWidget(compLGA3647);
        SocketIntel->addWidget(compLGA1151);
        SocketIntel->addWidget(compSocketG3);
        SocketIntel->addWidget(compLGA1150);
        SocketIntel->addWidget(comprPGA988B);
        SocketIntel->addWidget(compLGA2011);
        SocketIntel->addWidget(compLGA1155);
        SocketIntel->addWidget(compLGA1156);
        SocketIntel->addWidget(comprPGA988A);
        SocketIntel->addWidget(compLGA1366);
        SocketIntel->addWidget(compSocket441);
        SocketIntel->addWidget(compSocketP);
        SocketIntel->addWidget(compLGA771);
        SocketIntel->addWidget(compSocketM);
        SocketIntel->addWidget(compLGA775);
        SocketIntel->addWidget(compSocket479);
        SocketIntel->addWidget(compSocket604);
        SocketIntel->addWidget(compSocket603);
        SocketIntel->addWidget(compPAC418);
        SocketIntel->addWidget(compSocket495);


        compSocketTR4= new QCheckBox("Socket TR4");
        compSocketSP3= new QCheckBox("Socket SP3");
        compSocketAM4= new QCheckBox("Socket AM4");
        compSocketAM1= new QCheckBox("Socket AM1");
        compSocketFM2p= new QCheckBox("Socket FM2+");
        compSocketFM2= new QCheckBox("Socket FM2");
        compSocketAM3p= new QCheckBox("Socket AM3+");
        compSocketFS1= new QCheckBox("Socket FS1");
        compSocketFM1= new QCheckBox("Socket FM1");
        compSocketC32= new QCheckBox("Socket C32");
        compSocketG34= new QCheckBox("Socket G34");
        compSocketAM3= new QCheckBox("Socket AM3");
        compSocketAM2p= new QCheckBox("Socket AM2+");
        compSocketF= new QCheckBox("Socket F");
        compSocketAM2= new QCheckBox("Socket AM2");
        compSocketS1= new QCheckBox("Socket S1");
        compSocket939= new QCheckBox("Socket 939");
        compSocket940= new QCheckBox("Socket 940");
        compSocket754= new QCheckBox("Socket 754");
        compSocket563= new QCheckBox("Socket 563");
        SocketAmd->addWidget(compSocketTR4);
        SocketAmd->addWidget(compSocketSP3);
        SocketAmd->addWidget(compSocketAM4);
        SocketAmd->addWidget(compSocketAM1);
        SocketAmd->addWidget(compSocketFM2p);
        SocketAmd->addWidget(compSocketFM2);
        SocketAmd->addWidget(compSocketAM3p);
        SocketAmd->addWidget(compSocketFS1);
        SocketAmd->addWidget(compSocketFM1);
        SocketAmd->addWidget(compSocketC32);
        SocketAmd->addWidget(compSocketG34);
        SocketAmd->addWidget(compSocketAM3);
        SocketAmd->addWidget(compSocketAM2p);
        SocketAmd->addWidget(compSocketF);
        SocketAmd->addWidget(compSocketAM2);
        SocketAmd->addWidget(compSocketS1);
        SocketAmd->addWidget(compSocket939);
        SocketAmd->addWidget(compSocket940);
        SocketAmd->addWidget(compSocket754);
        SocketAmd->addWidget(compSocket563);
        Socket->addLayout(SocketIntel);
        Socket->addLayout(SocketAmd);

        riempiCheck(QString::fromStdString(pezzo_dissi->getSocketcomp()));
    }

}

void edit_dissi::aggiornaPezzo()
{
    comp_dissi* pezzo_dissi= dynamic_cast<comp_dissi*>(pezzo);
    if(pezzo_dissi){
        edit_componente::aggiornaPezzo();
        pezzo_dissi->setSocketcomp(generaCampoSocket());
        pezzo_dissi->setLiquido(editliquido->isChecked()?true:false);
    }
}

bool edit_dissi::campiCorretti()
{
    return edit_componente::campiCorretti();
}
