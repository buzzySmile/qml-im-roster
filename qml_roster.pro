TARGET = qml_roster
QT += core gui qml quick
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

HEADERS = \
    $$PWD/mainwindow.h \
    $$PWD/singletone/call_once.h \
    $$PWD/singletone/singleton.h \
    $$PWD/QImDataStorage.h \
    $$PWD/common/qimobjectinterface.h \
    $$PWD/common/QImContact.h \
    $$PWD/model/QImAbstractListModel.h \
    $$PWD/model/QImContactsModel.h

SOURCES = \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/QImDataStorage.cpp \
    $$PWD/common/QImContact.cpp \
    $$PWD/model/QImAbstractListModel.cpp \
    $$PWD/model/QImContactsModel.cpp

RESOURCES += components.qrc

OTHER_FILES = \
    $$files(qml/*.qml, true)
#    $$PWD/qml/*.qml

# DEV DEPLOYMENT
OBJECTS_DIR = $$OUT_PWD/_build/obj
MOC_DIR     = $$OUT_PWD/_build/moc
RCC_DIR     = $$OUT_PWD/_build/rcc
UI_DIR      = $$OUT_PWD/_build/ui

# RELEASE DEPLOYMENT
target.path = $$[PWD]/bin/
INSTALLS += target
