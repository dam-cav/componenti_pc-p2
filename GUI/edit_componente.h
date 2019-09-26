#ifndef EDIT_COMPONENTE_H
#define EDIT_COMPONENTE_H

#include "../MODEL/componente.h"
#include "../MODEL/listacomp.h"

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QCheckBox>

class edit_componente :  public QWidget
{
    Q_OBJECT

signals:
    void closed(componente*);

private slots:
    void confermaModifiche();

protected:
    QFormLayout *  vLayout;
    QPushButton* conferma;
    componente* pezzo;
    listacomp* catalogo;

private:
    bool nuovoInserimento;
    QLabel * errori;
    QLabel * labelNome;
    QLineEdit * editNome;
    QLabel * labelPrezzo;
    QLineEdit * editPrezzo;
    QLabel * labelConsumo;
    QLineEdit * editConsumo;

public:
    edit_componente(componente *, listacomp*, bool=false);
    virtual void aggiornaPezzo();
    virtual bool campiCorretti();

    void closeEvent(QCloseEvent *event);
};

#endif // EDIT_COMPONENTE_H
