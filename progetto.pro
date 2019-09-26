#-------------------------------------------------
#
# Progetto di Cavazzana Damiano 1122246
#
#-------------------------------------------------
QT += core gui
QT += widgets

TARGET = progetto
TEMPLATE = app
CONFIG += c++11
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resources.qrc


SOURCES += \
        main.cpp \
    GUI/mainwindow.cpp \
    GUI/edit_componente.cpp \
    GUI/edit_cpu.cpp \
    GUI/edit_desktopcase.cpp \
    GUI/edit_dissi.cpp \
    GUI/edit_hdd.cpp \
    GUI/edit_mobo.cpp \
    GUI/edit_psu.cpp \
    GUI/edit_ram.cpp \
    GUI/edit_gpu.cpp \
    GUI/preparaeditor.cpp \
    GUI/gestioneutenti.cpp \
    GUI/edit_cpugpu.cpp \
    GUI/edit_casepsu.cpp \
    GUI/preparacolore.cpp \
    GUI/loginwindow.cpp \
    MODEL/componente.cpp \
    MODEL/listacomp.cpp \
    MODEL/listautenti.cpp \
    MODEL/preparaoggetti.cpp \
    MODEL/us_admin.cpp \
    MODEL/us_cliente.cpp \
    MODEL/us_tecnico.cpp \
    MODEL/comp_casepsu.cpp \
    MODEL/comp_cpu.cpp \
    MODEL/comp_cpugpu.cpp \
    MODEL/comp_desktopcase.cpp \
    MODEL/comp_dissi.cpp \
    MODEL/comp_gpu.cpp \
    MODEL/comp_hdd.cpp \
    MODEL/comp_mobo.cpp \
    MODEL/comp_psu.cpp \
    MODEL/comp_ram.cpp \
    MODEL/utente.cpp

HEADERS += \
        GUI/mainwindow.h \
    GUI/edit_componente.h \
    GUI/edit_cpu.h \
    GUI/edit_desktopcase.h \
    GUI/edit_dissi.h \
    GUI/edit_hdd.h \
    GUI/edit_mobo.h \
    GUI/edit_psu.h \
    GUI/edit_ram.h \
    GUI/edit_gpu.h \
    GUI/preparaeditor.h \
    GUI/gestioneutenti.h \
    GUI/edit_cpugpu.h \
    GUI/edit_casepsu.h \
    GUI/preparacolore.h \
    GUI/loginwindow.h \
    MODEL/componente.h \
    MODEL/listacomp.h \
    MODEL/listautenti.h \
    MODEL/preparaoggetti.h \    
    MODEL/us_admin.h \
    MODEL/us_tecnico.h \
    MODEL/us_cliente.h \
    MODEL/comp_casepsu.h \
    MODEL/comp_cpu.h \
    MODEL/comp_cpugpu.h \
    MODEL/comp_desktopcase.h \
    MODEL/comp_dissi.h \
    MODEL/comp_gpu.h \
    MODEL/comp_hdd.h \
    MODEL/comp_mobo.h \
    MODEL/comp_psu.h \
    MODEL/comp_ram.h \
    MODEL/utente.h