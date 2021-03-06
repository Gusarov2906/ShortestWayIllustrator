QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatingmanager.cpp \
    createconnectiondialog.cpp \
    graph.cpp \
    graphspace.cpp \
    identifiedobject.cpp \
    main.cpp \
    mainwindow.cpp \
    toolstateobject.cpp \
    vertex.cpp \
    verticesconnection.cpp

HEADERS += \
    calculatingmanager.h \
    createconnectiondialog.h \
    graph.h \
    graphspace.h \
    identifiedobject.h \
    mainwindow.h \
    toolstateobject.h \
    vertex.h \
    verticesconnection.h

FORMS += \
    mainwindow.ui \
    createconnectiondialog.ui

TRANSLATIONS += \
    ShortestWayIllustrator_en_001.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
