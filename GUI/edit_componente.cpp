#include "edit_componente.h"

void edit_componente::confermaModifiche()
{
    if(campiCorretti()){
        nuovoInserimento=false;
        aggiornaPezzo();
        this->close();
        emit(closed(pezzo));
    }
    else errori->setText("Campi non corretti o nome già presente! Ricontrolla!");

}

edit_componente::edit_componente(componente * com, listacomp * cat, bool nuovOgg): pezzo(com), catalogo(cat), nuovoInserimento(nuovOgg)
{
    setWindowTitle("Editor");
    errori = new QLabel("Creazione nuovo componente.");
    labelNome = new QLabel ("Nome");
    editNome = new QLineEdit(QString::fromStdString(pezzo->getNome()));
    labelPrezzo = new QLabel ("Prezzo (in €)") ;
    editPrezzo = new QLineEdit(QString::number(pezzo->getPrezzo()));;
    editPrezzo->setValidator(new QRegExpValidator(QRegExp("[0-9]?[0-9]?[0-9]?(.[0-9][0-9]?)?"), this));
    labelConsumo = new QLabel ("Consumo (in W)");
    editConsumo = new QLineEdit(QString::number(pezzo->getConsumo()));;
    editConsumo->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,5}"), this));

    conferma= new QPushButton("conferma");

    vLayout = new QFormLayout(this);
    vLayout->addRow(errori);
    vLayout->addRow(labelNome, editNome);
    vLayout->addRow(labelPrezzo, editPrezzo);
    vLayout->addRow(labelConsumo,editConsumo);

    this->setLayout(vLayout);

}

void edit_componente::aggiornaPezzo()
{
    pezzo->setNome(editNome->text().toStdString());
    pezzo->setPrezzo(editPrezzo->text().toDouble());
    pezzo->setConsumo(editConsumo->text().toInt());
}

bool edit_componente::campiCorretti()
{
    return editNome->text()!="" && editNome->text()!="NA"  && editPrezzo->text()!="" && editConsumo->text()!="" && (!catalogo->cercaNome(editNome->text().toStdString()) || editNome->text().toStdString()==pezzo->getNome());
}

void edit_componente::closeEvent(QCloseEvent *event)
{
    if(nuovoInserimento) {
        delete pezzo;
        pezzo= nullptr;
    }
    QWidget::closeEvent(event);
}
